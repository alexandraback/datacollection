using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Numerics;

namespace Solver
{
    class Program
    {
        const int M = 1000000007;
        static void Main()
        {
//            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            string textFile = @"C:\Users\Rikuto\Downloads\B-small-attempt1.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] lines = File.ReadAllLines(textFile, enc);
            int t = int.Parse(lines[0]);
            var ans = new string[t];
            int c = 0;
            for (int i = 0; i < t; i++)
            {
                ans[i] = "Case #" + (i + 1) + ": ";
                ++c;
                var arr = lines[c].Split();
                int k = int.Parse(arr[0]), l = int.Parse(arr[1]), s = int.Parse(arr[2]);
                ++c;
                var keyboard = lines[c];
                ++c;
                var target = lines[c];
                var keys = new int[26];
                foreach (var item in keyboard)
                    ++keys[item - 'A'];

                int loop = l;
                for (int j = 1; j < l; j++)
                {
                    int m = 0;
                    for (; j + m < l; m++)
                        if (target[m] != target[j + m])
                            break;

                    if (j + m == l)
                    {
                        loop = j;
                        break;
                    }
                }
                var dp = new double[s + 1];
                dp[l] = 1;
                foreach (var item in target)
                    dp[l] *= (keys[item - 'A'] / (double)k);

                if (dp[l] == 0)
                {
                    ans[i] += "0";
                    continue;
                }
                double d = 1;
                for (int j = l - loop; j < l; j++)
                    d *= (keys[target[j] - 'A'] / (double)k);

                for (int j = l; j <= s; j++)
                    dp[j] = dp[j - 1] + d;

                int max = (s - l) / loop + 1;
                ans[i] += (max - dp[s]);
            }

            File.WriteAllLines(filePath, ans, enc);
        }
    }
    class Scan
    {
        public int Int { get { return int.Parse(Console.ReadLine().Trim()); } }
        public long Long { get { return long.Parse(Console.ReadLine().Trim()); } }
        public string Str { get { return Console.ReadLine().Trim(); } }
        public int[] IntArr { get { return Console.ReadLine().Trim().Split().Select(int.Parse).ToArray(); } }
        public long[] LongArr { get { return Console.ReadLine().Trim().Split().Select(long.Parse).ToArray(); } }
        public double[] DoubleArr { get { return Console.ReadLine().Split().Select(double.Parse).ToArray(); } }
        public string[] StrArr { get { return Console.ReadLine().Trim().Split(); } }
        public List<int> IntList { get { return Console.ReadLine().Trim().Split().Select(int.Parse).ToList(); } }
        public List<long> LongList { get { return Console.ReadLine().Trim().Split().Select(long.Parse).ToList(); } }
        public void Multi(out int a, out int b) { var arr = IntArr; a = arr[0]; b = arr[1]; }
        public void Multi(out int a, out int b, out int c) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; }
        public void Multi(out long a, out long b) { var arr = LongArr; a = arr[0]; b = arr[1]; }
        public void Multi(out string a, out string b) { var arr = StrArr; a = arr[0]; b = arr[1]; }
    }
}