using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace MainApp
{
    public static class CodeJamExtensions
    {
        public static IEnumerable<string> ReadDataLines(this StreamReader reader)
        {
            int lineCount = reader.ReadLine().ToInt32();
            return reader.ReadLines(lineCount);

        }

        public static IEnumerable<string> ReadLines(this StreamReader reader, int lineCount)
        {
            for (int i = 0; i < lineCount; i++)
            {
                yield return reader.ReadLine();
            }
        }

        public static int ToInt32(this string str)
        {
            return int.Parse(str);
        }

        public static List<string> Split(this string str)
        {
            return str.Split(' ').ToList();
        }

        private static int caseIndex = 0;

        public static void WriteCaseOutput(this StreamWriter writer, params object[] values)
        {
            writer.Write("Case #{0}:", caseIndex + 1);
            foreach (var val in values)
            {
                writer.Write(" ");
                writer.Write(val);                
            }
            writer.WriteLine();
            caseIndex++;
        }

    }

    class Program
    {
        static string ToOutputFileName(string fileName)
        {
            return Path.GetFileNameWithoutExtension(fileName) + ".out";
        }

        static void Main(string[] args)
        {
            var nums = new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            var cs = new List<Tuple<char, int>>
            { 
                Tuple.Create('Z', 0),
                Tuple.Create('X', 6),
                Tuple.Create('U', 4),
                Tuple.Create('G', 8),
                Tuple.Create('W', 2),
                Tuple.Create('H', 3),
                Tuple.Create('F', 5),
                Tuple.Create('I', 9),
                Tuple.Create('V', 7),
                Tuple.Create('N', 1),
            };

            string inputFileName = args[0];
            var reader = new StreamReader(inputFileName);
            int caseCount = reader.ReadLine().ToInt32();
            var writer = new StreamWriter(ToOutputFileName(inputFileName));
            for (int i = 0; i < caseCount; i++)
            {
                var case0 = reader.ReadLine();
                //var cb = new StringBuilder(case0);
                var result = new List<int>();
                foreach (var c in cs)
                {
                    while (case0.IndexOf(c.Item1) >= 0)
                    {
                        foreach (var a in nums[c.Item2])
                        {
                            case0 = case0.Remove(case0.IndexOf(a), 1);
                        }
                        result.Add(c.Item2);
                    }
                }
                result.Sort();
                writer.WriteCaseOutput(string.Join("", result.Select(ii => ii.ToString())));
            }
            reader.Close();
            writer.Close();

            // show explorer to access output file
            Process.Start("Explorer", Environment.CurrentDirectory);
        }
    }
}
