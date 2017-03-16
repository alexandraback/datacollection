using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace CodeJamApp._20160430.A
{
    public class Program
    {
        const string INPUT_FILE = "..\\..\\20160430\\A\\A-small.in";




        public void Solve()
        {
            char[] keys = { 'Z', 'W', 'U', 'X', 'S', 'O', 'F', 'N', 'I', 'T' };
            string[] numbers = {"ZERO", "TWO", "FOUR", "SIX","SEVEN", "ONE",  "FIVE", "NINE", "EIGHT", "THREE" };
            int[] code = { 0, 2, 4, 6, 7, 1, 5, 9, 8, 3 };

            var t = Scanner.ReadInt();
            int caseNo = 1;
            while (caseNo <= t)
            {
                string word = Scanner.ReadToken();
                string result = string.Empty;
                int n = 0;
                while (word.Length>0)
                {
                    if (word.Contains(keys[n]))
                    {
                        result += code[n].ToString();
                        foreach (var l in numbers[n])
                        {
                            int x = word.IndexOf(l);
                            word = word.Remove(x, 1);
                        }
                    }
                    else
                        n++;
                }
                result = Alphabetize(result);
                
                Scanner.Writer.WriteLine("Case #{0}: {1}", caseNo++, result);
            }
        }

        public static string Alphabetize(string s)
        {
            // 1.
            // Convert to char array.
            char[] a = s.ToCharArray();

            // 2.
            // Sort letters.
            Array.Sort(a);

            // 3.
            // Return modified string.
            return new string(a);
        }

        static void Main()
        {
            var type = typeof(Program);
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            TextReader reader;
            TextWriter writer;

            Console.WriteLine($"[{type.Namespace} Started at {DateTime.Now:u}]");

            //reader = new StreamReader(Console.OpenStandardInput());
            reader = new StreamReader(INPUT_FILE);

            //writer = new StreamWriter(Console.OpenStandardOutput());
            writer = new StreamWriter(INPUT_FILE.Replace(".in", ".out"));

            Scanner.SetReaderAndWriter(reader, writer);
            new Program().Solve();

            reader.Close();
            writer.Close();

            sw.Stop();
            Console.WriteLine($"[{type.Namespace} Ended. Took {sw.Elapsed}]");
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();
        }
    }

    static class Scanner
    {
        public static TextReader Reader { get; set; }
        public static TextWriter Writer { get; set; }

        private static Queue<string> _currentLineTokens = new Queue<string>();
        private static string[] ReadAndSplitLine() { return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries); }

        public static void SetReaderAndWriter(TextReader reader, TextWriter writer) { Reader = reader; Writer = writer; }
        public static string ReadToken() { while (_currentLineTokens.Count == 0) _currentLineTokens = new Queue<string>(ReadAndSplitLine()); return _currentLineTokens.Dequeue(); }
        public static int ReadInt() { return int.Parse(ReadToken()); }
        public static long ReadLong() { return long.Parse(ReadToken()); }
        public static double ReadDouble() { return double.Parse(ReadToken(), CultureInfo.InvariantCulture); }
        public static int[] ReadIntArray() { return ReadAndSplitLine().Select(int.Parse).ToArray(); }
        public static long[] ReadLongArray() { return ReadAndSplitLine().Select(long.Parse).ToArray(); }
        public static double[] ReadDoubleArray() { return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray(); }
        public static string[] ReadLines(int quantity) { string[] lines = new string[quantity]; for (int i = 0; i < quantity; i++) lines[i] = Reader.ReadLine().Trim(); return lines; }
        public static void WriteArray<T>(IEnumerable<T> array) { Writer.WriteLine(string.Join(" ", array)); }
        public static void Write(params object[] array) { WriteArray(array); }
        public static void WriteLines<T>(IEnumerable<T> array) { foreach (var a in array) Writer.WriteLine(a); }
    }
}
