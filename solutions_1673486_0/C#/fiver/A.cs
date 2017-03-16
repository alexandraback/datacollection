using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codeforces
{
    class A
    {
        private static ThreadStart s_threadStart = new A().Go;
        private static bool s_time = false;

        private void Go()
        {
            int TT = GetInt();
            for (int tt = 1; tt <= TT; tt++)
            {
                int n = GetInt();
                int B = GetInt();
                List<double> p = new List<double>();
                for (int i = 0; i < n; i++)
                {
                    p.Add(GetDouble());
                }

                for (int i = 1; i < n; i++)
                {
                    p[i] *= p[i - 1];
                }

                double[] exp = new double[n];
                for (int back = 0; back < n; back++)
                {
                    exp[back] = p[n - back - 1] * (B - n + 2 * back + 1) + (1 - p[n - back - 1]) * (B - n + 2 * back + 1 + B + 1);
                }

                double ans = B+2;
                for (int i = 0; i < n; i++)
                {
                    if (exp[i] < ans) ans = exp[i];
                }

                Wl(tt, ans);
            }
        }

        #region Template

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 512 * 1024 * 1024);
            timer.Start();
            main.Start();
            main.Join();
            timer.Stop();
            if (s_time)
                Console.WriteLine(timer.ElapsedMilliseconds);
        }

        private static IEnumerator<string> ioEnum;
        private static string GetString()
        {
            while (ioEnum == null || !ioEnum.MoveNext())
            {
                ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
            }

            return ioEnum.Current;
        }

        private static int GetInt()
        {
            return int.Parse(GetString());
        }

        private static long GetLong()
        {
            return long.Parse(GetString());
        }

        private static double GetDouble()
        {
            return double.Parse(GetString());
        }

        private static List<int> GetIntArr(int n)
        {
            List<int> ret = new List<int>(n);
            for (int i = 0; i < n; i++)
            {
                ret.Add(GetInt());
            }
            return ret;
        }

        private static void Wl<T>(int testCase, T o)
        {
            Console.WriteLine("Case #{0}: {1}", testCase, o.ToString());
        }

        private static void Wl<T>(int testCase, IEnumerable<T> enumerable)
        {
            Wl(testCase, string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}