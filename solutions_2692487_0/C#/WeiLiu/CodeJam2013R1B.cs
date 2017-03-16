using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam2012R2
{
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

            for (int i = 1; i <= T; ++i)
            {
                var ab = strAll[idx++].Split(
                    new[]
                    {
                        ' '
                    },
                    StringSplitOptions.RemoveEmptyEntries);
                int R = int.Parse(ab[0]);
                string sres = "Case #" + i + ": ";
                writer.WriteLine(sres);
                Console.WriteLine(sres);

                for (int j = 0; j < R; ++j)
                {
                    sres = Solve(strAll[idx++]);
                    writer.WriteLine(sres);
                    Console.WriteLine(sres);
                }
            }
        }

        private string Solve(string p)
        {
            throw new NotImplementedException();
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
            new A( ).Solve( dir + "A-small-attempt5.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C().Solve(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C().Solve(dir + "C-large.in", dir + "out.txt");

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
