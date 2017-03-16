using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJQC
{
    class Program
    {
        static bool isPalindrome(BigInteger n)
        { 
            var r = n;
            BigInteger reversed = 0;
            while (r > 0)
            {
                BigInteger digit;
                r = BigInteger.DivRem(r, 10, out digit);
                reversed = reversed * 10 + digit;
            }
            return n == reversed;
        }

        static List<List<BigInteger>> roots = new List<List<BigInteger>> { new List<BigInteger> { 0 }, new List<BigInteger> { 0, 1, 2, 3 } };
        static List<BigInteger> answers = new List<BigInteger> { 1, 4, 9 };
        static void expandAnswers(int rootLength)
        {
            for (int i = roots.Count; i <= rootLength; i++)
            {
                roots.Add(new List<BigInteger>());
                for (int d = 1; d <= 2; d++)
                    for (int k = i % 2; k < i; k += 2)
                        foreach (var baseNumber in roots[k])
                        {
                            var newCandidate = d * BigInteger.Pow(10, i - 1) + d + baseNumber * BigInteger.Pow(10, (i - k) / 2);
                            var square = newCandidate * newCandidate;
                            if (isPalindrome(square))
                            {
                                roots[i].Add(newCandidate);
                                answers.Add(square);
                            }
                        }
            }
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split();
                var a = BigInteger.Parse(parts[0]);
                var b = BigInteger.Parse(parts[1]);
                expandAnswers((parts[1].Length + 1) / 2);

                int left = answers.BinarySearch(a);
                if (left < 0)
                    left = ~left;
                int right = answers.BinarySearch(b);
                if (right < 0)
                    right = ~right - 1;
                long count = right - left + 1;

                Console.WriteLine("Case #{0}: {1}", testNumber, count);
            }
        }
    }
}
