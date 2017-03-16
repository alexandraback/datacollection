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
            string textFile = @"C:\Users\Rikuto\Downloads\C-small-attempt0.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] lines = File.ReadAllLines(textFile, enc);
            int t = int.Parse(lines[0]);
            var ans = new string[t];
            int count = 0;
            for (int i = 0; i < t; i++)
            {
                ans[i] = "Case #" + (i + 1) + ": ";
                ++count;
                var arr = lines[count].Split();
                int c = int.Parse(arr[0]), d = int.Parse(arr[1]), v = int.Parse(arr[2]);
                ++count;
                int[] vs = lines[count].Split().Select(int.Parse).ToArray();
                Array.Sort(vs);
                long able = 0;
                var list = new List<long>();
                for (int j = 0; j < vs.Length; j++)
                {
                    while (vs[j] > able + 1 && able <= v)
                    {
                        list.Add(able + 1);
                        able += (able + 1) * c; 
                    }
                    able += vs[j] * c;
                    list.Add(vs[j]);
                }
                ans[i] += (list.Count - d);
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