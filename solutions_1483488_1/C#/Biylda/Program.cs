using System;
using System.Collections.Generic;
using System.Text;

namespace Recycled_Numbers
{
    class Program
    {
        static long recycled(int a, int b)
        {
            long r = 0;
            for (int n = a; n <= b; ++n)
            {
                int m = n;
                int length = (int)Math.Log10(n);
                int shifter = (int)Math.Pow(10, length);
                do
                {
                    int d = m % 10;
                    m /= 10;
                    m += d * shifter;
                    if (n < m && m <= b)
                        ++r;
                } while (m != n);
            }
            return r;
        }

        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] tokens = Console.ReadLine().Split(' ');
                int A = Int32.Parse(tokens[0]);
                int B = Int32.Parse(tokens[1]);
                Console.WriteLine("Case #{0}: {1}", i, recycled(A, B));
            }
        }
    }
}
