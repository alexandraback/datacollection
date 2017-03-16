using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Globalization;
using System.Text;
using System.Threading;

namespace AcmSolution
{
    internal class Program
    {
        const string FilePath = "A/A-small-attempt0";

        private static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            Console.SetIn(new StreamReader(FilePath + ".in"));
            Console.SetOut(new StreamWriter(FilePath + ".out"));
            var tests = GetInt();

            for (int test = 1; test <= tests; ++test)
            {
                Console.Write(string.Format("Case #{0}: ", test));
                Do();
                if (test != tests)
                    Console.Write('\n');
            }
            Console.In.Close();
            Console.Out.Close();
        }

        static int[,] count = new int[100, 100];
        static string[] s = new string[100];
        static string[] w = new string[100];

        private static void Do()
        {
            var n = GetInt();

            for (int i = 0; i < n; ++i)
            {
                s[i] = GetStr();
                w[i] = Convert(i, s[i]);
            }

            var ok = true;
            for (int i = 0; i < n - 1; ++i)
                if (w[i] != w[i + 1])
                    ok = false;

            if (!ok)
                W("Fegla Won");
            else
            {
                long ans = 0;
                var cnt = w[0].Length;
                var a = new int[n];
                for (int t = 0; t < cnt; ++t)
                {
                    for (int i = 0; i < n; ++i)
                        a[i] = count[i, t];

                    long min = 239239239239239;
                    for (int x = 1; x <= 100; ++x)
                    {
                        long cur = 0;
                        for (int i = 0; i < n; ++i)
                        {
                            cur += Math.Abs(a[i] - x);
                        }
                        min = Math.Min(min, cur);
                    }
                    ans += min;
                }
                W(ans);
            }
        }

        private static string Convert(int index, string p)
        {
            var t = 0;
            var i = 0;
            var sb = new StringBuilder(); 

            while (i < p.Length)
            {
                var cnt = 1;
                var c = p[i];
                while (i + 1 < p.Length && p[i] == p[i + 1])
                {
                    ++i;
                    cnt++;
                }
                ++i;

                sb.Append(c); 
                count[index, sb.Length - 1] = cnt;
            }
            return sb.ToString();
        }

        #region Utils
        private const double Epsilon = 0.00000001;

        private static string GetStr()
        {
            return Console.ReadLine();
        }

        private static string[] GetStrs()
        {
            return GetStr().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] GetStrs(int cnt)
        {
            var s = new string[cnt];
            for (var i = 0; i < cnt; ++i)
                s[i] = GetStr();
            return s;
        }

        private static int GetInt()
        {
            return int.Parse(GetStr());
        }

        private static void GetInts(out int a, out int b)
        {
            var q = GetInts();
            a = q[0];
            b = q[1];
        }

        private static void GetInts(out int a, out int b, out int c)
        {
            var q = GetInts();
            a = q[0];
            b = q[1];
            c = q[2];
        }

        private static int[] GetInts()
        {
            var s = GetStrs();
            var a = new int[s.Length];
            for (var i = 0; i < s.Length; ++i)
                a[i] = int.Parse(s[i]);
            return a;
        }

        private static long GetLong()
        {
            return long.Parse(GetStr());
        }

        private static IEnumerable<long> GetLongs()
        {
            return GetStrs().Select(long.Parse);
        }

        private static IEnumerable<double> GetDoubles()
        {
            return GetStrs().Select(double.Parse);
        }

        private static void WriteDouble<T>(T d)
        {
            Console.Write(string.Format("{0:0.000000000}", d).Replace(',', '.'));
        }

        private static void WL<T>(T s)
        {
            Console.WriteLine(s);
        }

        private static void W<T>(T s)
        {
            Console.Write(s);
        }

        private static void Assert(bool b)
        {
            if (!b) throw new Exception();
        }

        private static void Swap<T>(ref T a, ref T b)
        {
            var temp = a;
            a = b;
            b = temp;
        }

        #endregion
    }
}