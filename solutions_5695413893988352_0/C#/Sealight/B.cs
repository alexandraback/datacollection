using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace CodeJamApp._20160430.B
{
    public class Program
    {
        const string INPUT_FILE = "..\\..\\20160430\\B\\B-small.in";

        public void Solve()
        {
            var t = Scanner.ReadInt();
            int caseNo = 1;
            while (caseNo <= t)
            {
                string sa = Scanner.ReadToken();
                string sb = Scanner.ReadToken();
                string oa = string.Empty;
                string ob = string.Empty;

                int conflict = 0;
                for (int i = 0; i < sa.Length; i++)
                {
                    if (sa[i] == '?' && sb[i] == '?')
                    {
                        if (conflict == 0)
                        {
                            oa += '0'; ob += '0';
                        }
                        else if (conflict == -1)
                        {
                            oa += '0'; ob += '9';
                        }
                        else
                        {
                            oa += '9'; ob += '0';
                        }
                    }
                    else if (sa[i] != '?' && sb[i] != '?' && sa[i] == sb[i])
                    {
                        oa += sa[i]; ob += sb[i];
                    }
                    else if (sa[i] != '?' && sb[i] == '?')
                    {
                        oa += sa[i];
                        if (conflict == 0)
                            ob += sa[i];
                        else if (conflict == -1)
                            ob += '9';
                        else
                            ob += '0';
                    }
                    else if (sa[i] == '?' && sb[i] != '?')
                    {
                        ob += sb[i];
                        if (conflict == 0)
                            oa += sb[i];
                        else if (conflict == -1)
                            oa += '0';
                        else
                            oa += '9';
                    }
                    else
                    {   //Conflict
                        oa += sa[i];
                        ob += sb[i];
                        if (conflict == 0)
                        {
                            int a = sa[i] - '0';
                            int b = sb[i] - '0';

                            if (a < b)
                                conflict = +1;
                            else
                                conflict = -1;

                            if (Math.Abs(b - a) >= 5)
                            {
                                //See if can change left digit
                                string output;
                                string tempa = oa; string tempb=ob;

                                if (conflict < 0)
                                {
                                    if (Leftchanged(conflict, i - 1, sa, oa, out output))
                                    {
                                        tempa = output;
                                        conflict = conflict * -1;
                                    }
                                    else if (Leftchanged(conflict * -1, i - 1, sb, ob, out output))
                                    {
                                        tempb = output;
                                        conflict = conflict * -1;
                                    }
                                }
                                else
                                {
                                    if (Leftchanged(conflict * -1, i - 1, sb, ob, out output))
                                    {
                                        tempb = output;
                                        conflict = conflict * -1;
                                    }
                                    else if(Leftchanged(conflict, i - 1, sa, oa, out output))
                                    {
                                        tempa = output;
                                        conflict = conflict * -1;
                                    }
                                }

                                if (string.Compare(tempa,oa)<0)
                                {
                                    oa = tempa;ob = tempb;
                                }
                                else if (string.Compare(tempa, oa) == 0 && string.Compare(tempb, ob)<0)
                                {
                                    oa = tempa; ob = tempb;
                                }
                                else if (Math.Abs(b - a)>5)
                                {
                                    oa = tempa; ob = tempb;
                                }
                            }
                        }
                    }
                } //for int i

                Scanner.Writer.WriteLine("Case #{0}: {1} {2}", caseNo++, oa, ob);
            }
        }

        static bool Leftchanged(int conflict, int i, string sa, string oa, out string output)
        {
            output = null;
            bool leftchanged = false;
            char[] tempA = oa.ToCharArray();
            for (int k = i; k >= 0; k--)
            {
                if (conflict == -1)
                {
                    if (sa[k] == '?' && tempA[k] != '0')
                    {
                        leftchanged = true;
                        tempA[k] = (char)(tempA[k] - 1);
                        output = string.Join("", tempA);
                        break;
                    }
                    else if (sa[k] == '?' && tempA[k] == '0')
                        tempA[k] = '9';
                }
                else if (conflict == 1)
                {
                    if (sa[k] == '?' && tempA[k] != '9')
                    {
                        leftchanged = true;
                        tempA[k] = (char)(tempA[k] + 1);
                        output = string.Join("", tempA);
                        break;
                    }
                    else if (sa[k] == '?' && tempA[k] == '9')
                        tempA[k] = '0';
                }
            }
            return leftchanged;
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
