using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace Solver
{
    class Program
    {
        const int M = 1000000007;
        static void Main()
        {
            /*
            var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Scan sc = new Scan();
            sw.WriteLine();
            sw.Flush();
            */

            string textFile = @"C:\Users\Rikuto\Downloads\D-small-attempt2.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            var enc = Encoding.GetEncoding("shift_jis");
            var lines = File.ReadAllLines(textFile, enc);
            int n = int.Parse(lines[0]);
            var ans = new string[n];
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = "Case #" + i + ": ";
                int[] xrc = IntArray(lines[i]);
                int x = xrc[0], r = xrc[1], c = xrc[2];
                if (x > 6 || (x + 1) / 2 > r || (x + 1) / 2 > c || r * c % x > 0)
                {
                    ans[i - 1] += "RICHARD";
                    continue;
                }
                if (x == 5 && (r == 3 || c == 3))
                {
                    ans[i - 1] += "RICHARD";
                    continue;
                }
                if (x == 4 && (r == 2 || c == 2))
                {
                    ans[i - 1] += "RICHARD";
                    continue;
                }

                if (x == 3 && r * c == x)
                {
                    ans[i - 1] += "RICHARD";
                    continue;
                }
                ans[i - 1] += "GABRIEL";
            }

                File.WriteAllLines(filePath, ans, enc);
        }
        public static int[] IntArray(string s)
        {
            return s.Trim().Split().Select(int.Parse).ToArray();
        }

    }

    class Scan
    {
        public int Int()
        {
            return int.Parse(Console.ReadLine().Trim());
        }
        public long Long()
        {
            return long.Parse(Console.ReadLine().Trim());
        }
        public string Str()
        {
            return Console.ReadLine().Trim();
        }

        public int[] IntArray()
        {
            return Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();
        }
        public void IntTwi(out int a, out int b)
        {
            int[] arr = IntArray();
            a = arr[0];
            b = arr[1];
        }
        public void LongTwi(out long a, out long b)
        {
            long[] arr = LongArray();
            a = arr[0];
            b = arr[1];
        }
        public void StrTwi(out string a, out string b)
        {
            string[] arr = StrArray();
            a = arr[0];
            b = arr[1];
        }

        public long[] LongArray()
        {
            return Console.ReadLine().Trim().Split().Select(long.Parse).ToArray();
        }
        public string[] StrArray()
        {
            return Console.ReadLine().Trim().Split();
        }
    }
}
