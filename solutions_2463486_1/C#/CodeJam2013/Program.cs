using System.Collections.Generic;
using System.Globalization;

namespace FairAndSquare
{
    using System;
    using System.IO;
    using System.Linq;
    using System.Numerics;

    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(args[0] + ".in"))
            using (var writer = new StreamWriter(args[0] + ".out"))
            {
                int T = Int32.Parse(reader.ReadLine());
                for (int x = 1; x <= T; ++x)
                {
                    int y = 0;

                    var range = reader.ReadLine().Split(' ').Select(BigInteger.Parse).ToArray();

                    BigInteger min = Sqrt(range[0]);
                    if (min * min < range[0])
                        ++min;
                    BigInteger max = Sqrt(range[1]);

                    IEnumerable<BigInteger> palindromes = CalculatePalindromes(min, max);
                    foreach (BigInteger palindrome in palindromes)
                    {
                        if (IsPalidrome(palindrome*palindrome))
                            ++y;
                    }

                    Console.WriteLine("Case #{0}: {1}", x, y);
                    writer.WriteLine("Case #{0}: {1}", x, y);
                }

                writer.Close();
            }
        }

        static bool IsPalidrome(BigInteger n)
        {
            string number = n.ToString(CultureInfo.InvariantCulture);
            for (int i = 0; i <= number.Length / 2; ++i)
            {
                if (number[i] != number[number.Length - i - 1])
                    return false;
            }

            return true;
        }

        static BigInteger Sqrt(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!IsSqrt(n, root))
                {
                    root += n / root;
                    root >>= 1;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean IsSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root*root;
            BigInteger upperBound = (root + 1)*(root + 1);

            return (n >= lowerBound && n < upperBound);
        }

        static IEnumerable<BigInteger> CalculatePalindromes(BigInteger min, BigInteger max)
        {
            var result = new List<BigInteger>();

            for (BigInteger i = min; i <= 9 && i <= max; ++i)
                result.Add(i);

            BigInteger n = 1;
            while (true)
            {
                BigInteger even = BigInteger.Parse(n.ToString() + new string(n.ToString().ToCharArray().Reverse().ToArray()));
                if (even > max)
                    break;
                if (even >= min)
                    result.Add(even);

                for (int m = 0; m <= 9; ++m)
                {
                    BigInteger odd = BigInteger.Parse(n.ToString() + m.ToString(CultureInfo.InvariantCulture) + new string(n.ToString().ToCharArray().Reverse().ToArray()));
                    if (odd >= min && odd <= max)
                        result.Add(odd);
                }

                ++n;
            }

            return result;
        }
    }
}
