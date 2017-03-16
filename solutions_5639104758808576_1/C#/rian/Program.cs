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

            string textFile = @"C:\Users\Rikuto\Downloads\A-large.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            var enc = Encoding.GetEncoding("shift_jis");
            var lines = File.ReadAllLines(textFile, enc);
            int n = int.Parse(lines[0]);
            var ans = new string[n];
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = "Case #" + i + ": ";
                string[] s = lines[i].Trim().Split();
                int m = int.Parse(s[0]);
                int p = 0;
                int k = 0;
                for (int j = 0; j <= m; ++j)
                {
                    int a = s[1][j] - '0';
                    if (a > 0)
                    {
                        if (j > p)
                        {
                            k += j - p;
                            p = j;
                        }
                        p += a;
                    }
                }
                ans[i - 1] += k;
            }

                File.WriteAllLines(filePath, ans, enc);
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
