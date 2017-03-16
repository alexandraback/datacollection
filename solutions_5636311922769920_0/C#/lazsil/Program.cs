using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace codejam_d_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int num_of_testcases = int.Parse(Console.ReadLine());
            for (int t = 1; t <= num_of_testcases; ++t)
            {
                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                long k = arr[0], c=arr[1], s=arr[2];
                Console.Write("Case #" + t + ": ");

                if (k == s)
                {
                    BigInteger mul = BigInteger.Pow(k, (int)(c - 1));
                    for (BigInteger i = 0; i < k; i++)
                    {
                        Console.Write((i * mul + 1) + " ");
                    }
                }

                Console.WriteLine();
            }
        }
    }
}
