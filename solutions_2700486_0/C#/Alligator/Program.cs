using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Globalization;
using System.Threading;

namespace AcmSolution
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            var tmp = Console.In;
            Console.SetIn(new StreamReader("B-small-attempt0.in"));
            Console.SetOut(new StreamWriter("out-B-small-attempt0.in.txt"));
            var tests = GetInt();

            for (int i = 1; i <= tests; ++i)
            {
                W(string.Format("Case #{0}: ", i));
                WriteDouble(Do());
                if (i != tests) WL("");
            }
            Console.In.Close();
            Console.Out.Close();
            Console.SetIn(tmp);
            //Console.ReadLine();
        }

        static int all = 0;
        static int cnt = 0;
        static int x = 0;
        static int y = 0;

        const int begX = 10;

        static bool[,] a = new bool[20, 10];
        private static double Do()
        {
            int n;
            GetInts(out n, out x, out y);

            x = Math.Abs(x);

            all = 0;
            cnt = 0;
            a = new bool[20, 10];
            go(n);

            return cnt * 1.0 / all;
        }

        private static void go(int n)
        {
            if (n == 0)
            {
                all++;
                if (begX + x < 20 && y < 10 && a[begX + x, y]) cnt++;
                return;
            }

            int dx, dy;

            if (GetRightXY(out dx, out dy))
            {
                a[dx, dy] = true;
                go(n - 1);
                a[dx, dy] = false;

                if (dx != begX)
                {
                    if (GetLeftXY(out dx, out dy))
                    {
                        a[dx, dy] = true;
                        go(n - 1);
                        a[dx, dy] = false;
                    }
                }
            }
            else
            {
                GetLeftXY(out dx, out dy);
                a[dx, dy] = true;
                go(n - 1);
                a[dx, dy] = false;
            }
        }

        private static bool GetRightXY(out int dx, out int dy)
        {
            dx = 0; dy = 0;

            if (!a[begX, 0]) { dx = begX; dy = 0; return true; }
            if (!a[begX + 2, 0]) { dx = begX + 2; dy = 0; return true; }
            if (!a[begX + 1, 1]) { dx = begX + 1; dy = 1; return true; }

            if (!a[begX, 2]) { if (!a[begX - 1, 1]) return false;  dx = begX; dy = 2; return true; }

            if (!a[begX + 4, 0]) { dx = begX + 4; dy = 0; return true; } // 11
            if (!a[begX + 3, 1]) { dx = begX + 3; dy = 1; return true; }
            if (!a[begX + 2, 2]) { dx = begX + 2; dy = 2; return true; }
            if (!a[begX + 1, 3]) { dx = begX + 1; dy = 3; return true; }

            if (!a[begX, 4]) { if (!a[begX - 1, 3]) return false; dx = begX; dy = 4; return true; }

            if (!a[begX + 6, 0]) { dx = begX + 6; dy = 0; return true; }
            if (!a[begX + 5, 1]) { dx = begX + 5; dy = 1; return true; }
            if (!a[begX + 4, 2]) { dx = begX + 4; dy = 2; return true; }
            if (!a[begX + 3, 3]) { dx = begX + 3; dy = 3; return true; }
            if (!a[begX + 2, 4]) { dx = begX + 2; dy = 4; return true; }
            if (!a[begX + 1, 5]) { dx = begX + 1; dy = 5; return true; }

            return false;
        }

        private static bool GetLeftXY(out int dx, out int dy)
        {
            dx = 0; dy = 0;

            if (!a[begX, 0]) { dx = begX; dy = 0; return true; }
            if (!a[begX - 2, 0]) { dx = begX - 2; dy = 0; return true; }
            if (!a[begX - 1, 1]) { dx = begX - 1; dy = 1; return true; }

            if (!a[begX, 2]) { if (!a[begX + 1, 1]) return false; dx = begX; dy = 2; return true; }

            if (!a[begX - 4, 0]) { dx = begX - 4; dy = 0; return true; } // 11
            if (!a[begX - 3, 1]) { dx = begX - 3; dy = 1; return true; }
            if (!a[begX - 2, 2]) { dx = begX - 2; dy = 2; return true; }
            if (!a[begX - 1, 3]) { dx = begX - 1; dy = 3; return true; }

            if (!a[begX, 4]) { if (!a[begX + 1, 3]) return false; dx = begX; dy = 4; return true; }

            if (!a[begX - 6, 0]) { dx = begX - 6; dy = 0; return true; }
            if (!a[begX - 5, 1]) { dx = begX - 5; dy = 1; return true; }
            if (!a[begX - 4, 2]) { dx = begX - 4; dy = 2; return true; }
            if (!a[begX - 3, 3]) { dx = begX - 3; dy = 3; return true; }
            if (!a[begX - 2, 4]) { dx = begX - 2; dy = 4; return true; }
            if (!a[begX - 1, 5]) { dx = begX - 1; dy = 5; return true; }

            return false;
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

        private static void GetLongs(out long a, out long b)
        {
            var q = GetLongs();
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

        private static long[] GetLongs()
        {
            return GetStrs().Select(long.Parse).ToArray();
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