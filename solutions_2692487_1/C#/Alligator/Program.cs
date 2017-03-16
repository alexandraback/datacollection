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
            Console.SetIn(new StreamReader("A-large (1).in"));
            Console.SetOut(new StreamWriter("out-A-large (1).in.txt"));
            var tests = GetInt();

            for (int i = 1; i <= tests; ++i)
            {
                W(string.Format("Case #{0}: ", i));
                Do();
                if (i != tests) WL("");
            }
            Console.In.Close();
            Console.Out.Close();
            Console.SetIn(tmp);
            //Console.ReadLine();
        }
      
        private static void Do()
        {
            int cur, n;
            GetInts(out cur, out n);

            var a = GetInts();
            Array.Sort(a);

            var d = new int[n + 1, n + 1]; // d[i, j] = max weight for first i elems and with j changes 
            d[0, 0] = cur;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j) if (d[i,j] > 0)
                {
                    if (d[i, j] > a[i])
                        d[i + 1, j] = Math.Max(d[i + 1, j], d[i, j] + a[i]);
                    else
                    {
                        // remove
                        d[i + 1, j + 1] = d[i, j];

                        // plus
                        int t = d[i, j];

                        if (t == 1) continue;
                        int cnt = 0;
                        while (t <= a[i])
                        {
                            t += t - 1;
                            cnt++;
                        }

                        if (j + cnt <= n)
                            d[i + 1, j + cnt] = Math.Max(d[i + 1, j + cnt], t + a[i]);
                    }
                }
            }

            for (int i = 0; i <= n; ++i)
                if (d[n, i] > 0)
                {
                    W(i);
                    break;
                }
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
            Console.WriteLine(string.Format("{0:0.000000000}", d).Replace(',', '.'));
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