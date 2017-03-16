using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            var primes = File.ReadAllText("primes.txt").Split(',').Select(int.Parse).ToArray();

            var N = 16;
            var J = 50;
            var iMin = (ulong)Math.Pow(2, N - 1);
            var iMax = (ulong)Math.Pow(2, N);

            var sols = new List<string>();
            for (ulong i = iMin + 1; i < iMax; i += 2)
            {
                var sol = new List<int>();
                BigInteger dst = 0;
                for (int baseN = 2; baseN <= 10; baseN++)
                {
                    dst = 0;
                    ulong src = i;
                    BigInteger multi = 1;
                    while (src != 0)
                    {
                        dst += (src % 2) * multi;
                        multi *= (ulong)baseN;
                        src /= 2;
                    }

                    var solFound = false;
                    foreach(var prime in primes)
                        if (dst % prime == 0)
                        {
                            if (dst == prime)
                                break;
                            sol.Add(prime);
                            solFound = true;
                            break;
                        }

                    if (!solFound)
                    {
                        sol = null;
                        break;
                    }
                }

                if (sol != null)
                {
                    sols.Add(dst.ToString() + " " + String.Join(" ", sol));
                    if (sols.Count >= J)
                        break;
                }
            }
            var resultStr = "Case #1: \r\n" + String.Join("\r\n", sols);
            Console.WriteLine(resultStr);
            File.WriteAllText("output.txt", resultStr);
        }
    }
}
