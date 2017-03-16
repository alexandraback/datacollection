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
        public static long[] ten, one;
        static void Main()
        {
//            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            string textFile = @"C:\Users\Rikuto\Downloads\A-small-attempt1.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] lines = File.ReadAllLines(textFile, enc);
            int t = int.Parse(lines[0]);
            var ans = new string[t];
            ten = new long[16];
            one = new long[16];
            ten[0] = 1;
            one[0] = 1;
            for (int i = 1; i < 16; i++)
            {
                one[i] = one[i - 1] * 10 + 1;
                ten[i] = ten[i - 1] * 10;
            }
            for (int i = 0; i < t; i++)
            {
                ans[i] = "Case #" + (i + 1) + ": " + res(long.Parse(lines[i + 1]));
            }
            
            File.WriteAllLines(filePath, ans, enc);

        }
        static long res(long n)
        {
            if (n % 10 == 0)
                return res(n - 1) + 1;
            if (n > mirror(n))
                return res(mirror(n));

            long ni = (n.ToString()[0] - '0') * ten[n.ToString().Length - 1] + 1;
            long mi = mirror(ni);
            if (ni == mi)
                return count(mi) + n - ni;
            else
                return count(mi) + n - ni + 1;
        }
        static long count(long ni)
        {
            if (ni < 20)
                return ni;

            return one[ni.ToString().Length - 2] + (ni.ToString().Length - 1) * 9 + ni % 10;
        }
        static long mirror(long n)
        {
            char[] c = n.ToString().ToCharArray();
            Array.Reverse(c);
            return long.Parse(new string(c));
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
        public void Multi(out int a, out int b, out int c, out int d) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; }
        public void Multi(out int a, out int b, out int c, out int d, out int e) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; e = arr[4]; }
        public void Multi(out long a, out long b) { var arr = LongArr; a = arr[0]; b = arr[1]; }
        public void Multi(out long a, out long b, out long c) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; }
        public void Multi(out long a, out long b, out long c, out long d) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; }
        public void Multi(out long a, out long b, out long c, out long d, out long e) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; e = arr[4]; }
        public void Multi(out string a, out string b) { var arr = StrArr; a = arr[0]; b = arr[1]; }
        public void Multi(out long a, out double b, out double c) { var arr = DoubleArr; a = (long)arr[0]; b = arr[1]; c = arr[2]; }
    }
}