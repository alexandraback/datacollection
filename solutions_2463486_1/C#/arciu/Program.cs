using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FnS
{
    class Program
    {
        static void Main(string[] args)
        {
            List<long> s = new List<long>();
            for (long i = 1; i <= 10000000; i++)
            {
                long x = i;
                long z = 0;
                while (x > 0)
                {
                    z *= 10;
                    z += x % 10;
                    x /= 10;
                }
                if (z != i)
                    continue;


                x = i * i;                
                z = 0;
                while (x > 0)
                {
                    z *= 10;
                    z += x % 10;
                    x /= 10;
                }
                x = i * i;
                if (z == x)
                    s.Add(x);
            }

            int T;
            T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                long[] w = Console.ReadLine().Split(' ').Select(str => long.Parse(str)).ToArray();
                int result = 0;
                foreach (long num in s)                
                    if (w[0] <= num && num <= w[1])
                        result++;
                Console.WriteLine("Case #{0}: {1}", t, result);
                
            }

        }
    }
}
