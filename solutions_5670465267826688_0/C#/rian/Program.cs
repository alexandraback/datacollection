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

            string textFile = @"C:\Users\Rikuto\Downloads\C-small-attempt0.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            var enc = Encoding.GetEncoding("shift_jis");
            var lines = File.ReadAllLines(textFile, enc);
            int n = int.Parse(lines[0]);
            var ans = new string[n];
            for (int i = 1; i <= n; ++i)
            {
                ans[i - 1] = "Case #" + i + ": ";
                int[] lx = IntArray(lines[i * 2 - 1]);
                int l = lx[0], x = lx[1];
                if (l * x < 3)
                {
                    ans[i - 1] += "NO";
                    continue;
                }
                string s = lines[i * 2];
                int kx = 1;
                for (int j = 0; j < l; ++j)
                {
                    int p = s[j] - 'g';
                    kx = ijk(kx, p);
                }
                int count = 0;
                int ic = 0, jc = 0;
                int k = 1;
                int h = 0;
                for (; ic < 6; ++h)
                {
                    if (h == l)
                    {
                        ++ic;
                        ++count;
                        h = 0;
                    }

                    int p = s[h] - 'g';
                    k = ijk(k, p);
                    if (k == 2)
                        break;
                }
                ++h;
                k = 1;
                for (; jc < 6; ++h)
                {
                    if (h >= l)
                    {
                        ++jc;
                        ++count;
                        h %= l;
                    }

                    int p = s[h] - 'g';
                    k = ijk(k, p);
                    if (k == 3)
                        break;
                }
                if (ic > 5 || jc > 5 || count > x)
                {
                    ans[i - 1] += "NO";
                    continue;
                }
                ++h;
                k = 1;
                for (; h < l; ++h)
                {
                    int p = s[h] - 'g';
                    k = ijk(k, p);
                }
                for (int j = 0; j < (x - count - 1) % 4; ++j)
                    k = ijk(k, kx);
                
                if (k == 4)
                    ans[i - 1] += "YES";
                else
                    ans[i - 1] += "NO";
            }

            File.WriteAllLines(filePath, ans, enc);
        }
        public static int ijk(int x, int y)
        {
            if (x < 0)
                return -ijk(-x, y);
            if (y < 0)
                return -ijk(x, -y);

            int[,] table = new int[,] {
                { 0, 0, 0, 0, 0 }, 
                { 0, 1, 2, 3, 4 },
                { 0, 2, -1, 4, -3 }, 
                { 0, 3, -4, -1, 2 }, 
                { 0, 4, 3, -2, -1 }
            };
            return table[x, y];
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
