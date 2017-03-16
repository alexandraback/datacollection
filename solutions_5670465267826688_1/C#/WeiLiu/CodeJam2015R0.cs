using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam
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
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToIA(strSplit);
        }

        public static int[] StringToIA(string s, char c)
        {
            return StringToIA(s, new char[] { c });
        }

        public static int[] StringToIA(string s)
        {
            return StringToIA(s, new char[] { ' ' });
        }

        public static long[] StringToLongA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToLongA(strSplit);
        }

        public static long[] StringToLongA(string s, char c)
        {
            return StringToLongA(s, new char[] { c });
        }

        public static long[] StringToLongA(string s)
        {
            return StringToLongA(s, new char[] { ' ' });
        }

        public static string[] StringToSA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return strSplit;
        }

        public static string[] StringToSA(string s, char c)
        {
            return StringToSA(s, new char[] { c });
        }

        public static string[] StringToSA(string s)
        {
            return StringToSA(s, new char[] { ' ' });
        }
        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;
        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Wrapping(string input, string output)
        {
            string filename = input;
            writer = new System.IO.StreamWriter(output);
            string[] strAll = System.IO.File.ReadAllText(filename).Split(
                new char[] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries);

            ParseAndSolve(strAll);
            writer.Flush();
        }

        virtual public void ParseAndSolve(string[] strAll)
        {
            throw new NotImplementedException();
        }
    }

    public class Z : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
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

    public class A : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";

                var s = StringToSA(strAll[idx++], ' ');
                sres += Solve(s[1]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string s)
        {
            int need = 0;
            int sofar = s[0] - '0';
            for (int i = 1; i < s.Length; ++i)
            {
                if (sofar < i)
                {
                    need = Math.Max(need, i - sofar);
                }

                sofar += s[i] - '0';
            }

            return need + "";
        }
    }

    public class B : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";

                idx++;
                var s = StringToIA(strAll[idx++], ' ');
                sres += Solve(s);
                writer.WriteLine(strAll[idx - 1]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        // Slow!
        private string Solve(int[] data)
        {
            int best = INF;
            int at = 0;

            for (int i = 1; i < 2000; ++i)
            {
                int sofar = i;
                foreach (var a in data)
                {
                    sofar += a / i;
                    if (a % i == 0)
                    {
                        --sofar;
                    }
                }

                if (best > sofar)
                {
                    at = i;
                }

                best = Math.Min(best, sofar);
            }

            return best + "@" + at;
        }
    }

    public class C : SolverBase
    {
        private enum Alpha
        {
            One = 0,
            OneNeg = 1,
            I = 2,
            INeg = 3,
            J = 4,
            JNeg = 5,
            K = 6,
            KNeg = 7,
        }

        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            Pre();

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += SolveA(strAll[idx++], strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string SolveA(string aa, string bb)
        {
            var split = StringToLongA(aa);
            long L = split[0];
            long X = split[1];

            if (!CheckProd(bb, X))
            {
                return "NO";
            }

            var s = string.Empty;
            for (int i = 0; i < 4; ++i)
            {
                s += bb;
            }

            var ineed = INeed(s);
            var kneed = KNeed(s);

            if (ineed > 0 && kneed > 0 && ineed + kneed < L * X)
            {
                return "YES";
            }

            return "NO";
        }

        static Dictionary<Tuple<Alpha, Alpha>, Alpha> lookup = new Dictionary<Tuple<Alpha, Alpha>, Alpha>();
        static Dictionary<string, Alpha> toAlpha = new Dictionary<string, Alpha>();
        static Dictionary<Alpha, string> fromAlpha = new Dictionary<Alpha, string>();

        private static void Pre()
        {
            var mul = new Dictionary<string, string>();
            mul["11"] = "1";
            mul["1i"] = "i";
            mul["1j"] = "j";
            mul["1k"] = "k";

            mul["i1"] = "i";
            mul["ii"] = "-1";
            mul["ij"] = "k";
            mul["ik"] = "-j";

            mul["j1"] = "j";
            mul["ji"] = "-k";
            mul["jj"] = "-1";
            mul["jk"] = "i";

            mul["k1"] = "k";
            mul["ki"] = "j";
            mul["kj"] = "-i";
            mul["kk"] = "-1";

            toAlpha = new Dictionary<string, Alpha>();
            toAlpha["1"] = Alpha.One;
            toAlpha["-1"] = Alpha.OneNeg;
            toAlpha["i"] = Alpha.I;
            toAlpha["-i"] = Alpha.INeg;
            toAlpha["j"] = Alpha.J;
            toAlpha["-j"] = Alpha.JNeg;
            toAlpha["k"] = Alpha.K;
            toAlpha["-k"] = Alpha.KNeg;

            fromAlpha = new Dictionary<Alpha, string>();
            foreach (var kvp in toAlpha)
            {
                fromAlpha[kvp.Value] = kvp.Key;
            }

            lookup = new Dictionary<Tuple<Alpha, Alpha>, Alpha>();
            foreach (var kvpa in fromAlpha)
            {
                foreach (var kvpb in fromAlpha)
                {
                    var a = kvpa.Key;
                    var b = kvpb.Key;
                    var key = new Tuple<Alpha, Alpha>(a, b);
                    int checkSign = kvpa.Value.Length + kvpb.Value.Length;
                    var adjusted = kvpa.Value.Last() + "" + kvpb.Value.Last();
                    var prep = mul[adjusted];
                    if (checkSign % 2 == 1)
                    {
                        if (prep.Length % 2 == 1)
                        {
                            prep = "-" + prep;
                        }
                        else
                        {
                            prep = prep.Last() + "";
                        }
                    }

                    lookup[key] = toAlpha[prep];
                }
            }
        }

        private Alpha Multiply(Alpha a, Alpha b)
        {
            return lookup[new Tuple<Alpha, Alpha>(a, b)];
        }

        private long INeed(string s)
        {
            var curr = Alpha.One;
            for (int i = 0; i < s.Length; ++i)
            {
                curr = Multiply(curr, toAlpha[s[i] + string.Empty]);
                if (curr == Alpha.I)
                {
                    return i + 1;
                }
            }

            return -1;
        }

        private long KNeed(string sa)
        {
            var s = sa.Reverse().ToArray();
            var curr = Alpha.One;
            for (int i = 0; i < s.Length; ++i)
            {
                curr = Multiply(toAlpha[s[i] + string.Empty], curr);
                if (curr == Alpha.K)
                {
                    return i + 1;
                }
            }

            return -1;
        }

        private bool CheckProd(string s, long X)
        {
            long a = X % 4;
            if (a == 0)
            {
                return false;
            }

            string tt = string.Empty;
            for (int i = 0; i < a; ++i)
            {
                tt += s;
            }

            var curr = Alpha.One;
            for (int i = 0; i < tt.Length; ++i)
            {
                curr = Multiply(curr, toAlpha[tt[i] + string.Empty]);
            }

            return curr == Alpha.OneNeg;
        }
    }

    public class D : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
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
        static void Main(string[] args)
        {
            string dir = "..\\..\\";

            //new A().Wrapping(dir + "ASample.txt", dir + "out.txt");
            //new A().Wrapping(dir + "A-small-attempt0.in", dir + "out.txt");
            //new A().Wrapping(dir + "A-large.in", dir + "out.txt");

            //new B().Wrapping(dir + "BSample.txt", dir + "out.txt");
            //new B().Wrapping(dir + "B-small-attempt2.in", dir + "out.txt");
            //new B().Wrapping(dir + "B-large.in", dir + "out.txt");

            //new C().Wrapping(dir + "CSample.txt", dir + "out.txt");
            //new C().Wrapping(dir + "C-small-attempt0.in", dir + "out.txt");
            new C().Wrapping(dir + "C-large.in", dir + "out.txt");

            //new D().Wrapping(dir + "DSample.txt", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt0.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-large.in", dir + "out.txt");
        }
    }
}
