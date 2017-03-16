using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.IO;

namespace QualificationC
{
    class Program
    {
        static bool IsPalindrome(ulong n)
        {
            ulong p = n, p2 = 0;
            while (p>0)
            {
                p2 = p2 * 10 + p % 10;
                p /= 10;
            }
            return n == p2;
        }

        static void Main(string[] args)
        {
            List<ulong> nums = new List<ulong>();
            for (ulong i = 0; i < 100000000; i++)
            {
                if (IsPalindrome(i) && IsPalindrome(i * i)) nums.Add(i*i);
            }

            Console.WriteLine("stage 1 done");

            StreamReader sr = new StreamReader(@"..\..\input.txt");
            StreamWriter sw = new StreamWriter(@"..\..\output.txt");

            int cnt = int.Parse(sr.ReadLine());
            for (int t = 1; t <= cnt; t++)
            {
                var input = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries), ulong.Parse);
                ulong a = input[0], b = input[1];
                sw.WriteLine("Case #{0}: {1}", t, nums.Count(x => a <= x && x <= b));
            }

            sr.Close();
            sw.Close();
        }
    }
}
