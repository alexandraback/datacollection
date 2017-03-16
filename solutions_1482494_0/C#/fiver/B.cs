using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codeforces
{
    class B
    {
        private static ThreadStart s_threadStart = new B().Go;
        private static bool s_time = false;

        private void Go()
        {
            int TT = GetInt();
            for (int tt = 1; tt <= TT; tt++)
            {
                int n = GetInt();
                List<int[]> levels = new List<int[]>();
                List<int[]> sorted0 = new List<int[]>();
                List<int[]> sorted1 = new List<int[]>();
                for (int i = 0; i < n; i++)
                {
                    levels.Add(new int[] { GetInt(), GetInt() });
                    sorted0.Add(new int[] { i, levels[i][0] });
                    sorted1.Add(new int[] { i, levels[i][1] });
                }
                bool[] solved0 = new bool[n];
                bool[] solved1 = new bool[n];
                sorted0.Sort((a, b) => a[1].CompareTo(b[1]));
                sorted1.Sort((a, b) => a[1].CompareTo(b[1]));

                int ret = 0;
                int power = 0;
                bool inc = true;
                bool ok = true;
                while (ok)
                {
                    int min = -1;
                    inc = true;
                    while (inc)
                    {
                        inc = false;
                        for (int pos = 0; pos < n; pos++)
                        {
                            if (!solved1[sorted1[pos][0]])
                            {
                                if (sorted1[pos][1] > power)
                                {
                                    min = sorted1[pos][1];
                                    break;
                                }

                                power += solved0[sorted1[pos][0]] ? 1 : 2;
                                ret++;
                                solved1[sorted1[pos][0]] = true;
                                solved0[sorted1[pos][0]] = true;
                                inc = true;
                            }
                        }
                    }
                    if (power == 2 * n)
                    {
                        Wl(tt, ret);
                        ok = false;
                    }
                    inc = true;
                    while (inc && power < min)
                    {
                        inc = false;
                        for (int pos = n-1; pos >= 0 && power < min; pos--)
                        {
                            if (!solved0[sorted1[pos][0]])
                            {
                                //if (sorted0[pos][1] > power)
                                //{
                                //    break;
                                //}
                                if (levels[sorted1[pos][0]][0] <= power)
                                {
                                    solved0[sorted1[pos][0]] = true;
                                    ret++;
                                    power += 1;
                                    inc = true;
                                }
                            }
                        }
                    }
                    if (power < min)
                    {
                        Wl(tt, "Too Bad");
                        ok=false;
                    }
                }
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