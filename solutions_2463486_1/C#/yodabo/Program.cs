using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace FairAndSquare
{
    class Program
    {
        static bool isFair(BigInteger num)
        {
            String numAsDecimal = "" + num;
            List<char> temp = new List<char>(numAsDecimal.Reverse());
            return (new String(temp.ToArray()) == numAsDecimal);
        }

        static BigInteger GetNthFairNumber(BigInteger n)
        {
            // steal a bit to determine whether we have an even or odd set of numbers
            bool fSkipRepeatingLastDigit = n.IsEven;
            n = n>>1;
            // n is currently a number >= 0.  we are going to repeat this number after itself, but have the second part flipped
            String numAsDecimal = "" + n;
            List<char> temp = new List<char>(numAsDecimal.Reverse().Skip(fSkipRepeatingLastDigit ? 1 : 0));
            numAsDecimal = numAsDecimal + new String(temp.ToArray());
            return BigInteger.Parse(numAsDecimal);
        }

        static void Main(string[] args)
        {
            // bigint version requires adding a reference to System.Numerics to the project.  Add it by right-clicking on references, add reference, and click the checkbox.
            // there don't appear to be many fair-and-square numbers, so lets precalculate them
            List<BigInteger> cache = new List<BigInteger>();
            BigInteger n = GetNthFairNumber(1);
            for (BigInteger i = 1; n < BigInteger.Pow(10, 8); ++i)
            {
                n = GetNthFairNumber(i);
                if (isFair(n * n))
                {
                    cache.Add(n*n);
                }
            }
            cache.Sort();

            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] nums = Console.ReadLine().Split(' ');
                BigInteger start = BigInteger.Parse(nums[0]);
                BigInteger end = BigInteger.Parse(nums[1]);
                int count = 0;
                for (int j = 0; j < cache.Count; ++j)
                {
                    if (cache[j] >= start && cache[j] <= end)
                    {
                        count++;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, count);
            }
        }
    }
}
