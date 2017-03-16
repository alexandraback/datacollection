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
        const string FilePath = "A/A-large";

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

        static long GCD(long a, long b)
        {
            while (a != 0 && b != 0)
            {
                if (a >= b)
                    a %= b;
                else
                    b %= a;
            }
            return a + b;
        }

        private static void Do()
        {
            var s = GetStr().Split('/').Select(long.Parse).ToArray();
            long a = s[0];
            long b = s[1];
            long gcd = GCD(a, b);
            a /= gcd;
            b /= gcd;

            bool ok = true;

            long cnt = 0;

            long bb = b;
            while (bb % 2 == 0)
            {
                bb /= 2;
                cnt++;
            }
            if (bb != 1)
                ok = false;

            long ans;
            if (a == 1)
                ans = cnt;
            else
            {
                ans = 1;

                b = b / 2;
                while (a < b)
                {
                    b = b / 2;
                    ans++;
                }
            }

            if (ok)
                W(ans);
            else
                W("impossible");
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