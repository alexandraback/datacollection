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
            string textFile = @"C:\Users\Rikuto\Downloads\A-large.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] lines = File.ReadAllLines(textFile, enc);
            int t = int.Parse(lines[0]);
            var ans = new string[t];
            for (int i = 0; i < t; i++)
            {
                ans[i] = "Case #" + (i + 1) + ": ";
                var arr = lines[i + 1].Split();
                int r = int.Parse(arr[0]), c = int.Parse(arr[1]), w = int.Parse(arr[2]);
                int p = c / w * r + w;
                if (c % w == 0)
                    --p;
                ans[i] += p;
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