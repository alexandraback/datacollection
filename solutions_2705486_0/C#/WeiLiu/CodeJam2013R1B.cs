using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam2012R2
{
    using System.IO;
    using System.Numerics;

    public class SolverBase
    {
        #region Helper

        public static int[] SAToIA(string[] strSplit)
        {
            int[] nums = new int[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = int.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static long[] SAToLongA(string[] strSplit)
        {
            long[] nums = new long[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = long.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static int[] StringToIA(string s, char[] delim)
        {
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return SAToIA(strSplit);
        }

        public static int[] StringToIA(string s, char c)
        {
            return StringToIA(
                s,
                new char[]
                {
                    c
                });
        }

        public static int[] StringToIA(string s)
        {
            return StringToIA(
                s,
                new char[]
                {
                    ' '
                });
        }

        public static long[] StringToLongA(string s, char[] delim)
        {
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return SAToLongA(strSplit);
        }

        public static long[] StringToLongA(string s, char c)
        {
            return StringToLongA(
                s,
                new char[]
                {
                    c
                });
        }

        public static long[] StringToLongA(string s)
        {
            return StringToLongA(
                s,
                new char[]
                {
                    ' '
                });
        }

        public static string[] StringToSA(string s, char[] delim)
        {
            string[] strSplit = s.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            return strSplit;
        }

        public static string[] StringToSA(string s, char c)
        {
            return StringToSA(
                s,
                new char[]
                {
                    c
                });
        }

        public static string[] StringToSA(string s)
        {
            return StringToSA(
                s,
                new char[]
                {
                    ' '
                });
        }

        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;

        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Solve(string input, string output)
        {
            string filename = input;
            writer = new System.IO.StreamWriter(output);
            string[] strAll = System.IO.File.ReadAllText(filename).Split(
                new char[]
                {
                    '\r', '\n'
                },
                StringSplitOptions.RemoveEmptyEntries);

            ParseAndSolve(strAll);
            writer.Flush();
        }

        public virtual void ParseAndSolve(string[] strAll)
        {
            throw new NotImplementedException();
        }
    }

    public class A : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                var ab = StringToLongA(strAll[idx++]);
                long cur = ab[0];
                sres += Solve(cur, strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(long cur, string s)
        {
            var all = StringToLongA(s);
            if (cur == 1)
            {
                return all.Length + string.Empty;
            }

            Array.Sort(all);
            for (int i = 0; i < 101; ++i)
            {
                if (Can(cur, all, i))
                {
                    return i + string.Empty;
                }
            }

            throw new Exception();
        }

        private bool Can(long cur, long[] all, int tot)
        {
            for (int add = 0; add <= tot; ++add)
            {
                int remove = tot - add;
                if (CanAdd(cur, all.Take(all.Length - remove).ToArray(), add))
                {
                    return true;
                }
            }

            return false;
        }

        private bool CanAdd(long cur, long[] all, int n)
        {
            foreach (var a in all)
            {
                if (cur > a)
                {
                    cur += a;
                }
                else
                {
                    while (cur <= a)
                    {
                        if (n == 0)
                        {
                            return false;
                        }

                        --n;
                        cur += cur - 1;
                    }

                    cur += a;
                }
            }

            return true;
        }
    }

    public class B : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                int[] nm = StringToIA(strAll[idx++]);
                int E = nm[0];
                int R = nm[1];
                int n = nm[2];
                var vs = StringToIA(strAll[idx++]);

                string sres = "Case #" + i + ": ";
                sres += Solve(E, R, vs);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(int E, int R, int[] vs)
        {
            throw new NotImplementedException();
        }
    }

    public class C : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            GenerateDictionary();
            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private void GenerateDictionary()
        {
            dict = new HashSet<string>();
            var file = @"D:\MyProj\CodeJam\garbled_email_dictionary.txt";
            var lines = File.ReadAllLines(file);
            int maxL = 0;
            foreach (var line in lines)
            {
                AddLine(line, dict);
                maxL = Math.Max(maxL, line.Length);
            }

            Console.WriteLine("maxL = " + maxL);
            Console.WriteLine("words = " + dict.Count);
        }

        private void AddLine(string line, HashSet<string> dict)
        {
            dict.Add(line);
            var cc = line.ToCharArray();
            for (int i = 0; i < line.Length; ++i)
            {
                cc[i] = '*';
                dict.Add(new string(cc));
                cc[i] = line[i];
            }

            for (int i = 0; i < line.Length; ++i)
            {
                for (int j = i + 5; j < line.Length; ++j)
                {
                    cc[i] = '*';
                    cc[j] = '*';
                    dict.Add(new string(cc));
                    cc[i] = line[i];
                    cc[j] = line[j];
                }
            }
        }

        private HashSet<string> dict = new HashSet<string>();

        private int best = int.MaxValue;

        private int count = 0;

        private int totalLen = int.MaxValue;
        private string Solve0(string s)
        {
            best = int.MaxValue;
            count = 0;
            totalLen = s.Length;

            var cc = s.ToCharArray();
            if (Good(cc))
            {
                return "0";
            }

            for (int i = 0; i < s.Length; ++i)
            {
                cc[i] = '*';
                Calc(1, i, s, cc);
                cc[i] = s[i];
            }

            Console.WriteLine(count);
            return best + string.Empty;
        }

        private int[,] dp;
        private string Solve(string s)
        {
            totalLen = s.Length;
            dp = new int[totalLen,totalLen + 1];
            for (int i = 0; i < totalLen; ++i)
            {
                for (int j = 0; j <= totalLen; ++j)
                {
                    dp[i, j] = int.MaxValue;
                }
            }

            for (int i = 0; i < totalLen; ++i)
            {
                dp[i, 0] = 0;
            }

            for (int len = 1; len <= totalLen; ++len)
            {
                for (int i = 0; i < totalLen; ++i)
                {
                    int lb = GetBest(s, i, len);
                    for (int j = 1; j < len && i + j < totalLen; ++ j)
                    {
                        lb = Math.Min(lb, dp[i, j] + dp[i + j, len - j]);
                    }

                    dp[i, len] = lb;
                }
            }

            return dp[0, totalLen] + string.Empty;
        }

        private int GetBest(string s, int start, int len)
        {
            if (len > 10 || start + len > s.Length)
            {
                return int.MaxValue;
            }

            var line = s.Substring(start, len);
            var cc = line.ToCharArray();
            if (dict.Contains(line))
            {
                return 0;
            }

            bool good = false;
            for (int i = 0; i < line.Length; ++i)
            {
                cc[i] = '*';
                if (dict.Contains(new string(cc)))
                {
                    return 1;
                }

                cc[i] = line[i];
            }

            for (int i = 0; i < line.Length; ++i)
            {
                for (int j = i + 5; j < line.Length; ++j)
                {
                    cc[i] = '*';
                    cc[j] = '*';
                    if (dict.Contains(new string(cc)))
                    {
                        return 2;
                    }

                    cc[i] = line[i];
                    cc[j] = line[j];
                }
            }

            return int.MaxValue;
        }

        private void Calc(int errors, int lastErrorPos, string s, char[] cc)
        {
            ++count;
            if (errors >= best)
            {
                return;
            }

            if (Good(cc))
            {
                best = Math.Min(best, errors);
                return;
            }

            for (int i = lastErrorPos + 5; i < s.Length; ++i)
            {
                cc[i] = '*';
                Calc(errors + 1, i, s, cc);
                cc[i] = s[i];
            }
        }

        private bool Good(char[] cc)
        {
            return GoodCalc(cc, 0);
        }

        private bool GoodCalc(char[] cc, int sofar)
        {
            if (sofar >= totalLen)
            {
                return true;
            }

            if (totalLen - sofar <= 10 && dict.Contains(new string(cc, sofar, totalLen - sofar)))
            {
                return true;
            }

            bool good = false;
            for (int i = 1; i <= 10 && i <= totalLen - sofar; ++i)
            {
                if (dict.Contains(new string(cc, sofar, i)))
                {
                    if (GoodCalc(cc, sofar + i))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    public class D : SolverBase
    {
        public override void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            throw new NotImplementedException();
        }
    }

    public class RunMain
    {
        private static void Main(string[] args)
        {
            string dir = "D:\\MyProj\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt5.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            new C().Solve(dir + "C-small-attempt1.in", dir + "out.txt");
            //new C().Solve(dir + "C-large.in", dir + "out.txt");

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
