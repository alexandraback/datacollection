using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int test = 1; test <= tests; test++)
            {
                string[] data = Console.ReadLine().Split(' ');
                ulong r = ulong.Parse(data[0]);
                ulong t = ulong.Parse(data[1]);
                ulong result = 0;
                ulong current = r + 1;
                
                while (t >= current * current - (current - 1) * (current - 1))
                {
                    t -= current * current - (current - 1) * (current - 1);
                    result++;
                    current += 2;
                }
                Console.WriteLine("Case #{0}: {1}", test, result);
            }
        }
    }
}
