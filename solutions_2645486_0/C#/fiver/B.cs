using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class B
    {
        private static ThreadStart s_threadStart = new B().Go;
        private static bool s_time = false;

        private void Test(int tt)
        {
            int EE = GetInt();
            int R = GetInt();
            int N = GetInt();
            List<int> v = GetIntArr(N);

            int[] next = new int[N];
            for (int i = 0; i < N; i++)
            {
                next[i] = -1;
                for (int j = i + 1; j < N; j++)
                {
                    if (v[j] > v[i])
                    {
                        next[i] = j;
                        break;
                    }
                }
            }

            int E = EE;

            long ans = 0;
            for (int i = 0; i < N-1; i++)
            {
                if (v[i] <= v[i + 1])
                {
                    E += R;
                    if (E > EE)
                    {
                        ans += (E - EE) * v[i];
                        E = EE;
                    }
                }
                else
                {
                    int nextBigger = next[i];
                    if (nextBigger < 0)
                    {
                        ans += v[i] * E;
                        E = R;
                    }
                    else
                    {
                        int gain = (nextBigger - i) * R;
                        int shouldHave = EE - gain;
                        if (shouldHave < 0) shouldHave = 0;
                        if (shouldHave < E)
                        {
                            ans += v[i] * (E - shouldHave);
                            E = shouldHave;
                        }
                        E += R;
                        if (E > EE) E = EE;
                    }
                }
            }

            ans += E * v[N - 1];

            Wl(tt, ans);
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