using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class C
    {
        private static ThreadStart s_threadStart = new C().Go;
        private static bool s_time = false;

        long[,] pow;
        long[] add;

        private void Test(int tt)
        {
            int N = GetInt();
            int J = GetInt();

            pow = new long[11, N];
            for (int p = 2; p < 11; p++)
            {
                pow[p, 0] = 1;
                for (int q = 1; q < N; q++)
                {
                    pow[p, q] = pow[p, q - 1] * p;
                }
            } 
            

            add = new long[11];
            for (int i = 2; i < 11; i++)
                add[i] = 1 + pow[i, N - 1];

            Dictionary<string, long[]> ans = new Dictionary<string, long[]>();
            long x = -1;
            while (ans.Count < J)
            {
                x++;
                string s = Convert.ToString(x, 2);
                long value;
                long[] li = Check(s, out value);
                if (li != null)
                {
                    s = Convert.ToString(value, 2);
                    ans.Add(s, li);
                    //Console.WriteLine(ans.Count);
                }
            }

            Wl(tt, "");
            foreach(var s in ans.Keys)
            {
                Console.Write(s);
                for (int p = 0; p < 9; p++)
                {
                    Console.Write(" " + ans[s][p]);   
                }
                Console.WriteLine();
            }
        }

        public static long Factor(long n)
        {
            for (long p = 2L; p * p <= n; ++p)
                if (n % p == 0)
                    return p;

            return 0;
        }

        public long[] Check(string s, out long value)
        {
            int n = s.Length;
            long[] ans = new long[9];
            for (int p = 2; p < 11; p++)
            {
                ans[p-2] += add[p];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    for (int p = 2; p < 11; p++)
                    {
                        ans[p-2] += pow[p, n-i];
                    }
                }
            }
            value = ans[0];
            for (int p = 2; p < 11; p++)
            {
                long factor = Factor(ans[p-2]);
                if (factor == 0) return null;

                ans[p-2] = factor;
            }

            return ans;
        }


        #region Template

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 1 * 1024 * 1024 * 1024);
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
            do
            {
                while (ioEnum == null || !ioEnum.MoveNext())
                {
                    ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
                }
            } while (string.IsNullOrEmpty(ioEnum.Current));

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