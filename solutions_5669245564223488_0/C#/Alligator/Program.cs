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
        const string FilePath = "B/B-small-attempt1";

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

        private static string[] a;
        private static int[] s;

        static public void NextPerm()
        {
            int i = -1;
            int j = 0;

            for (int x = s.Length - 2; x >= 0; x--) if (s[x] < s[x + 1])
            {
                i = x;
                break;
            }

            if (i == -1) return;

            for (int x = s.Length - 1; x > i; x--) if (s[x] > s[i])
                {
                    j = x;
                    break;
                }

            // Swap i and j
            int temp = s[i]; s[i] = s[j]; s[j] = temp;

            Array.Reverse(s, i + 1, s.Length - (i + 1)); // Reverse after i
        }
        
        private static bool Check()
        {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < s.Length; ++i)
                sb.Append(a[s[i]]);

            var was = new bool['z' - 'a' + 1];

            for (int i = 0; i < sb.Length; ++i)
            {
                if (was[sb[i] - 'a'] && sb[i - 1] != sb[i]) 
                    return false;
                
                was[sb[i] - 'a'] = true;
            }

            return true;
        }

        private static void Do()
        {
            var n = GetInt();
            s = new int[n];
            long cnt = 1;
            for (int i = 1; i <= n; ++i)
            {
                s[i - 1] = i - 1;
                cnt *= i;
            }
            
            a = GetStrs();

            for (int q = 0; q < n; ++q)
            {
                var t = a[q];
                var b = new StringBuilder(t[0] + "");

                for (int i = 1; i < t.Length; ++i)
                {
                    if (t[i - 1] != t[i])
                        b.Append(t[i]);
                }
                a[q] = b.ToString();
            }

            long ans = 0;

            for (int i = 1; i <= cnt; ++i)
            {
                if (Check())
                    ans++;

                NextPerm();
            }

            Assert(ans <= cnt && ans <= 1000000007);

            W(ans);
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