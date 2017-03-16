using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace OneAFirstProblem
{
    class Program
    {
        static void Main(string[] args)
        {
            int test = int.Parse(Console.ReadLine());
            for (int tt = 1; tt <= test; tt++) {
                string[] line = Console.ReadLine().Split();
                BigInteger r = new BigInteger(long.Parse(line[0]));
                BigInteger t = new BigInteger(long.Parse(line[1]));
                BigInteger left = new BigInteger(0);
                BigInteger right = new BigInteger(1000000000);
                BigInteger best = 0;
                while (left < right) {
                    BigInteger mid = (left + right) / 2;
                    BigInteger sum = ((4 * r + 4 * mid - 2) * mid) / 2;
                    if (sum > t)
                        right = mid;
                    else if (sum < t)
                    {
                        best = mid;
                        left = mid + 1;
                    }
                    else
                    {
                        best = mid;
                        break;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", tt, best);
            }
        }
    }
}
