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

        double origH;
        double H;
        int N;
        int M;
        double time;
        int[, ,] maze;

        private double Rec(int x, int y)
        {
            double oldH = H;
            double oldTime = time;

            if (x == N-1 && y == M-1) return time;

            double getL = int.MaxValue;
            if (x < N - 1)
            {
                double adjH = maze[x + 1, y, 1];
                double thisH = maze[x, y, 1];
                double adjF = maze[x + 1, y, 0];
                double thisF = maze[x, y, 0];

                if (adjH - adjF >= 50 && adjH - thisF >= 50 && thisH - adjF >= 50)
                {
                    double waitTime = Math.Max(0, H - (adjH - 50)) / 10.0;
                    H -= 10.0 * waitTime;
                    time += waitTime;
                    if (H != origH)
                    {
                        waitTime = (((H - thisF) >= 20.0) ? 1.0 : 10.0);
                        H -= 10.0 * waitTime;
                        time += waitTime;
                    }
                    getL = Rec(x + 1, y);
                    H = oldH;
                    time = oldTime;
                }
            }

            double getD = int.MaxValue;
            if (y < M - 1)
            {
                double adjH = maze[x, y + 1, 1];
                double thisH = maze[x, y , 1];
                double adjF = maze[x, y + 1, 0];
                double thisF = maze[x, y, 0];

                if (adjH - adjF >= 50 && adjH - thisF >= 50 && thisH - adjF >= 50)
                {
                    double waitTime = Math.Max(0, H - (adjH - 50)) / 10.0;
                    H -= 10.0 * waitTime;
                    time += waitTime;
                    if (H != origH)
                    {
                        waitTime = (((H - thisF) >= 20.0) ? 1.0 : 10.0);
                        H -= 10.0 * waitTime;
                        time += waitTime;
                    }
                    getD = Rec(x, y + 1);
                    H = oldH;
                    time = oldTime;
                }
            }

            return Math.Min(getL, getD);
        }

        private void Go()
        {
            int TT = GetInt();
            for (int tt = 1; tt <= TT; tt++)
            {
                H = GetInt();
                origH = H;
                N = GetInt();
                M = GetInt();
                time = 0.0;
                maze = new int[N, M, 2];
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        maze[i, j, 1] = GetInt();
                    }
                }
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        maze[i, j, 0] = GetInt();
                    }
                }

                Wl(tt, Rec(0, 0));
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