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

            string textFile = @"C:\Users\Rikuto\Downloads\B-small-attempt1.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            var enc = Encoding.GetEncoding("shift_jis");
            var lines = File.ReadAllLines(textFile, enc);
            int n = int.Parse(lines[0]);
            var ans = new string[n];
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = "Case #" + i + ": ";
                int d = int.Parse(lines[i * 2 - 1]);
                int[] p = IntArray(lines[i * 2]);
                int[] s = new int[1001];
                int max = 0;
                foreach (int j in p)
                {
                    ++s[j];
                    max = Math.Max(max, j);
                }

                ans[i - 1] += loop(s, max, 0);
            }

            File.WriteAllLines(filePath, ans, enc);
        }
        public static int loop(int[] s, int max, int time)
        {
            int i = max;
            for (; i > 0; --i)
                if (s[i] > 0)
                    break;

            if (i == 1)
                return time + 1;

            if (s[i] > i)
                return time + i;

            int[] res = new int[s.Length];
            for (int j = 0; j < i; ++j)
                res[j] = s[j + 1];

            --res[i - 1];
            if (i % 2 == 0)
                res[i / 2] += 2;
            else
            {
                res[i / 2] += 1;
                res[i / 2 + 1] += 1;
            }
            return Math.Min(loop(res, i, time + 1), time + i);

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
