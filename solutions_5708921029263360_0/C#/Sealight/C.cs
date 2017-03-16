using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace CodeJamApp._20160508.C
{
    public class Program
    {
        const string INPUT_FILE = "..\\..\\20160508\\C\\C-small.in";

        class Comb
        {
            public int A; public int B; public int C;

            public override bool Equals(object obj)
            {
                return (((Comb)obj).A == A && ((Comb)obj).B == B && ((Comb)obj).C == C);
            }
        };

        public void Solve()
        {
            var t = Scanner.ReadInt();
            int caseNo = 1;
            while (caseNo <= t)
            {
                int na = Scanner.ReadInt();
                int nb = Scanner.ReadInt();
                int nc = Scanner.ReadInt();
                int k = Scanner.ReadInt();


                List<Comb> result = new List<Comb>();
                for (int c = nc; c >= 1; c--)
                for (int a = na; a >= 1; a--)
                    for (int b = nb; b >= 1; b--)
                    
                    {
                        Comb test = new Comb() { A = a, B = b, C = -1 };


                        int ab = result.Count(x => x.A == a && x.B == b);
                        if (ab >= k) continue;
                        
                        test.C = FindC(result, test, nc, k);

                        if (test.C > -1) result.Add(test);
                        /*
                        if (result.Contains(test)) continue;

                        int ac = result.Count(x => x.A == a && x.C == c);
                        if (ac >= k) continue;

                        int bc = result.Count(x => x.B == b && x.C == c);
                        if (bc >= k) continue;
                        */
                    }


                Scanner.Writer.WriteLine("Case #{0}: {1}", caseNo++, result.Count);
                foreach (var i in result)
                    Scanner.Writer.WriteLine($"{i.A} {i.B} {i.C}");
            }
        }

        int FindC(List<Comb> result, Comb test, int nc, int k)
        {
            int[] min = new int[nc];
            for (int c = nc; c >= 1; c--)
            {
                test.C = c;
                if (result.Contains(test)) { min[c-1] = int.MaxValue; continue; }

                int ab = result.Count(x => x.A == test.A && x.B == test.B);
                if (ab < k) min[c - 1] += ab; else { min[c - 1] = int.MaxValue; continue; }

                int ac = result.Count(x => x.A == test.A && x.C == test.C);
                if (ac < k) min[c - 1] += ac; else { min[c - 1] = int.MaxValue; continue; }

                int bc = result.Count(x => x.B == test.B && x.C == test.C);
                if (bc < k) min[c - 1] += bc; else { min[c - 1] = int.MaxValue; continue; }

            }
            int minIndex = Array.IndexOf(min, min.Min());
            return (min[minIndex] < int.MaxValue) ? minIndex+1 : -1;
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
            //Console.WriteLine("Press any key to continue");
            //Console.ReadKey();
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
