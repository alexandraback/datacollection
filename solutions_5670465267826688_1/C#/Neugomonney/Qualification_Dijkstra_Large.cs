using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.IO;
using System.Net.Mail;
using System.Runtime.InteropServices;
using System.Text;

namespace GoogleCodeJam_2015
{
    internal class Qualification_Dijkstra_Large
    {
        private const string ModuleName = "Qualification_Dijkstra";
        private static Library.DataSize ModuleDataSize = Library.DataSize.Large;
        private static int _moduleReportingSize = 1;
        private static Hashtable _lookup = new Hashtable();

        public static void Process()
        {
            // Build lookup
            _lookup.Add(new Tuple<char, char>('1', '1'), new Tuple<int, char>(1, '1'));
            _lookup.Add(new Tuple<char, char>('1', 'i'), new Tuple<int, char>(1, 'i'));
            _lookup.Add(new Tuple<char, char>('1', 'j'), new Tuple<int, char>(1, 'j'));
            _lookup.Add(new Tuple<char, char>('1', 'k'), new Tuple<int, char>(1, 'k'));

            _lookup.Add(new Tuple<char, char>('i', '1'), new Tuple<int, char>(1, 'i'));
            _lookup.Add(new Tuple<char, char>('i', 'i'), new Tuple<int, char>(-1, '1'));
            _lookup.Add(new Tuple<char, char>('i', 'j'), new Tuple<int, char>(1, 'k'));
            _lookup.Add(new Tuple<char, char>('i', 'k'), new Tuple<int, char>(-1, 'j'));

            _lookup.Add(new Tuple<char, char>('j', '1'), new Tuple<int, char>(1, 'j'));
            _lookup.Add(new Tuple<char, char>('j', 'i'), new Tuple<int, char>(-1, 'k'));
            _lookup.Add(new Tuple<char, char>('j', 'j'), new Tuple<int, char>(-1, '1'));
            _lookup.Add(new Tuple<char, char>('j', 'k'), new Tuple<int, char>(1, 'i'));

            _lookup.Add(new Tuple<char, char>('k', '1'), new Tuple<int, char>(1, 'k'));
            _lookup.Add(new Tuple<char, char>('k', 'i'), new Tuple<int, char>(1, 'j'));
            _lookup.Add(new Tuple<char, char>('k', 'j'), new Tuple<int, char>(-1, 'i'));
            _lookup.Add(new Tuple<char, char>('k', 'k'), new Tuple<int, char>(-1, '1'));

            var input = Library.GetFilePath(Library.DataInputType.Input, ModuleDataSize, ModuleName);

            Console.WriteLine("###> Processing {0} @ {1}", input, DateTime.Now.ToLongTimeString());
            Console.WriteLine();
            var watch = new Stopwatch();
            watch.Start();

            var caseLineCount = 2;
            var lines = Library.GetAllLines(input);
            var totalCount = int.Parse(lines[0]);

            var output = Library.GetFilePath(Library.DataInputType.Output, ModuleDataSize, ModuleName);
            Library.DeleteFile(output);

            for (var i = 0; i < totalCount; i++)
            {
                Library.AppendLine(output, ProcessCase(i + 1, lines.Skip(1 + i * caseLineCount).Take(caseLineCount).ToList()));
            }
            Library.WriteToFile(output, Library.GetContents(output).Trim());
            watch.Stop();
            Console.WriteLine("###> Finished @ {0}, processed {1} cases in {2:N1} seconds", DateTime.Now.ToLongTimeString(), totalCount, watch.ElapsedMilliseconds / 1000.0);

            if (Library.HasExpectedResult(ModuleDataSize, ModuleName))
            {
                Console.WriteLine("###> Output is{0} as expected", Library.CompareResultToExpected(ModuleDataSize, ModuleName) ? "" : " NOT");
            }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
        }

        private static string ProcessCase(int id, List<string> parameters)
        {
            if (id % _moduleReportingSize == 0) Console.WriteLine("===> Processing case {0}", id);

            var config = parameters[0].Split(new[] { ' ' }).Select(long.Parse).ToList();
            var chars = parameters[1].Substring(0, (int) config[0]);
            var res = Solution(chars.ToCharArray(), config[1]);

            return String.Format("Case #{0}: {1}", id, res);
        }

        private static string Solution(char[] letters, long times)
        {
            if (letters.Distinct().Count() == 1) return "NO";

            // Forward
            var forwards = new Tuple<int, char>[letters.Length * 6];
            var iEnds = new List<int>();
            var cur = new Tuple<int, char>(1, letters[0]);
            forwards[0] = cur;
            if (cur.Item2 == 'i') iEnds.Add(0);
            for (var i = 1; i < letters.Length; i++)
            {
                cur = Multiply(cur, new Tuple<int, char>(1, letters[i]));
                forwards[i] = cur;
                if (cur.Item2 == 'i' && cur.Item1 == 1)
                {
                    iEnds.Add(i);
                }
            }
            var lastForward = cur;
            var lastIsMinus1 = lastForward.Item2 == '1' && cur.Item1 == -1;
            var forBackwards = new List<char> (letters);
            if (times == 1)
            {
                // We must have at least on i and end with -1
                if (iEnds.Count == 0 || !lastIsMinus1) return "NO";
            }
            else
            {
                // i * j * k = - 1. If we have more than 1 times, this only happens if there are even number of "times" but not divisible by 4
                // or last forward is -1 and there are odd number of "times"
                if ((lastIsMinus1 && times % 2 != 1) || (!lastIsMinus1 && (times % 2 != 0 || times % 4 == 0)))
                    return "NO";

                // Add extra segments depending on forward last
                var extra = 0;
                if (lastIsMinus1)
                    extra = 2; // We must have at least 3 from tests above
                else
                {
                    // Take 6 if we have, otherwise take 2
                    if (times >= 6)
                        extra = 5;
                    else
                        extra = 1;
                }
                for (var t = 0; t < extra; t++)
                    forBackwards.AddRange(letters);

                // Scan for more i's
                var last = lastForward;
                for (var t = 0; t < extra; t++)
                {
                    for (var i = 0; i < letters.Length; i++)
                    {
                        cur = Multiply(cur, forwards[i]);
                        if (cur.Item2 == 'i' && cur.Item1 == 1) iEnds.Add(letters.Length * (t + 1) + i);
                    }
                    last = cur;
                }
            }

            var backLen = forBackwards.Count;
            var backwards = new Tuple<int, char>[backLen];
            var kStarts = new List<int>();
            cur = new Tuple<int, char>(1, forBackwards[backLen - 1]);
            backwards[backLen - 1] = cur;
            if (cur.Item2 == 'k') kStarts.Add(backLen - 1);
            for (var i = backLen - 2; i >= 0; i--)
            {
                cur = Multiply(new Tuple<int, char>(1, forBackwards[i]), cur);
                backwards[i] = cur;
                if (cur.Item2 == 'k' && cur.Item1 == 1) kStarts.Add(i);
            }

            foreach (var iEnd in iEnds)
            {
                if (kStarts.Any(k => k > iEnd)) return "YES";
            }
            return "NO";
        }

        private static Tuple<int, char> Multiply(Tuple<int, char> left, Tuple<int, char> right)
        {
            var mult = (Tuple<int, char>)_lookup[new Tuple<char, char>(left.Item2, right.Item2)];
            return new Tuple<int, char>(left.Item1 * right.Item1 * mult.Item1, mult.Item2);
        }

















        private class Library
        {
            public enum DataInputType
            {
                Input,
                Output,
                Expected
            };

            public enum DataSize
            {
                Test,
                Small,
                Large
            };

            public static string Folder = @"D:\Projects\GoogleCodeJam\Data";
            public static Hashtable Cache = new Hashtable();

            public static object GetCachedObject(object key)
            {
                return Cache[key];
            }

            public static void SetCachedObject(object key, object value)
            {
                if (!Cache.ContainsKey(key)) Cache.Add(key, value);
            }

            public static string GetFilePath(DataInputType inputType, DataSize dataSize, string module)
            {
                return Path.Combine(Folder,
                    module + "_"
                    + (dataSize == DataSize.Test ? "test" : (dataSize == DataSize.Small ? "small" : "large"))
                    +
                    (inputType == DataInputType.Input
                        ? ".in"
                        : (inputType == DataInputType.Output ? ".out" : ".expected")));
            }

            public static List<string> GetAllLines(DataSize dataType, string module)
            {
                return GetAllLines(GetFilePath(DataInputType.Input, dataType, module));
            }

            public static List<string> GetAllLines(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                var result = new List<string>();
                try
                {
                    while (!reader.EndOfStream)
                        result.Add(reader.ReadLine());
                }
                finally
                {
                    reader.Close();
                }
                return result;
            }

            public static IEnumerable<string> GetLines(DataSize dataSize, string module)
            {
                return GetLines(GetFilePath(DataInputType.Input, dataSize, module));
            }

            public static IEnumerable<string> GetLines(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    while (!reader.EndOfStream)
                        yield return reader.ReadLine();
                }
                finally
                {
                    reader.Close();
                }
            }

            public static string GetContents(DataInputType inputType, DataSize dataSize, string module)
            {
                return GetContents(GetFilePath(inputType, dataSize, module));
            }

            public static string GetContents(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    return reader.ReadToEnd();
                }
                finally
                {
                    reader.Close();
                }
            }

            /// <summary>
            /// Return a stream of List of strings of size lineCount although the last List returned may have lessa than lineCount elements
            /// </summary>
            public static IEnumerable<List<string>> GetLines(DataSize dataSize, string module, int lineCount)
            {
                return GetLines(GetFilePath(DataInputType.Input, dataSize, module), lineCount);
            }

            public static IEnumerable<List<string>> GetLines(string inputFile, int lineCount)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    var lines = new List<string>(lineCount);
                    while (!reader.EndOfStream)
                    {
                        lines.Add(reader.ReadLine());
                        if (lines.Count == lineCount)
                        {
                            yield return lines;
                            lines = new List<string>(lineCount);
                        }
                    }
                    if (lines.Count > 0) yield return lines;
                }
                finally
                {
                    reader.Close();
                }
            }

            public static void AppendLine(DataSize dataSize, string module, string line)
            {
                AppendLine(GetFilePath(DataInputType.Output, dataSize, module), line);

            }

            public static void AppendLine(string outputFile, string line)
            {
                AppendLines(outputFile, new List<string>() { line });
            }

            public static void AppendLines(DataSize dataSize, string module, List<string> lines)
            {
                AppendLines(GetFilePath(DataInputType.Output, dataSize, module), lines);
            }

            public static void AppendLines(string outputFile, List<string> lines)
            {
                File.AppendAllLines(outputFile, lines);
            }

            public static void WriteToFile(string outputFile, string content)
            {
                File.WriteAllText(outputFile, content);
            }

            public static void DeleteFile(string filePath)
            {
                if (File.Exists(filePath)) File.Delete(filePath);
            }

            public static void RenameFile(string filePath)
            {
                if (File.Exists(filePath))
                {
                    var i = 1;
                    var file = new FileInfo(filePath);
                    var dotIndex = filePath.LastIndexOf('.');
                    var part1 = dotIndex < 0 ? filePath : filePath.Substring(0, dotIndex);
                    var extension = dotIndex < filePath.Length - 1 ? filePath.Substring(dotIndex) : "";

                    var newFileFormat = part1 + "_{0}" + extension;
                    var newFile = String.Format(newFileFormat, i);
                    while (File.Exists(newFile))
                    {
                        i++;
                        newFile = String.Format(newFileFormat, i);
                    }
                    File.Move(filePath, newFile);
                }

            }

            public static bool HasExpectedResult(DataSize dataSize, string module)
            {
                return File.Exists(GetFilePath(DataInputType.Expected, dataSize, module));
            }

            public static bool CompareResultToExpected(DataSize dataSize, string module)
            {
                return GetContents(DataInputType.Output, dataSize, module) ==
                       GetContents(DataInputType.Expected, dataSize, module);
            }

            public static long Factorial(int value, int ceiling)
            {
                if (value < 2) return 1;
                return (value * (Factorial(value - 1, ceiling) % ceiling) % ceiling);
            }
        }
    }
}