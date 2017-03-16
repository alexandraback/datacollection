using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Codejamb
{
    class Program
    {
        static int[] v;
        static int e,r,n;

        static int GetMax(int from, int energy)
        {
            if (from == n - 1)
                return energy * v[from];
            int max = int.MinValue;
            for (int ec = 0; ec <= energy; ec++)
            {
                int nextE = (energy - ec) + r;
                if (nextE > e)
                    nextE = e;
                int result = GetMax(from + 1, nextE) + ec * v[from];
                if (result >= max)
                {
                    max = result;
                }
            }
            return max;
        }

        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int test = 1; test <= tests; test++)
            {
                string[] data = Console.ReadLine().Split(' ');
                e = int.Parse(data[0]);
                r = int.Parse(data[1]);
                n = int.Parse(data[2]);
                v = new int[n];
                data = Console.ReadLine().Split(' ');
                for (int i = 0; i < n; i++)
                    v[i] = int.Parse(data[i]);
                int result = GetMax(0, e);
                Console.WriteLine("Case #{0}: {1}", test, result);
            }
        }
    }
}
