using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace FairAndSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            int testsCount;
            var limitsList = FileReader.GetLimits(args[0], out testsCount);

            for (int index = 0; index < limitsList.Count; index++)
            {
                double result = 0;
                var limit = limitsList[index];

                var minSquareRoot = Math.Sqrt(limit.MinLimit);

                var trunkMinSquareRoot = Math.Truncate(minSquareRoot);

                if (trunkMinSquareRoot < minSquareRoot)
                    minSquareRoot = trunkMinSquareRoot + 1;

                var maxSquarRoot = Math.Truncate(Math.Sqrt(limit.MaxLimit));

                var palindrome = minSquareRoot;

                if (!IsPalindrome(palindrome))
                    palindrome = NextPalindrome(palindrome);

                while (palindrome <= maxSquarRoot)
                {
                    if (IsPalindrome(Math.Pow(palindrome, 2)))
                        result++;
                    palindrome = NextPalindrome(palindrome);
                }

                //for (var number = minSquareRoot; number <= maxSquarRoot; number++)
                //{
                //    if (IsPolindrome(number) && IsPolindrome(Math.Pow(number, 2)))
                //        result++;
                //}

                Console.WriteLine("Case #{0}: {1}", index + 1, result);
            }

            Console.ReadKey();
        }

        private static bool IsPalindrome(double input)
        {
            var original = input;
            double rev = 0;
            while (input > 0)
            {
                var dig = input % 10;
                rev = rev * 10 + dig;
                input = Math.Truncate(input / 10);
            }

            return original == rev;
        }

        public static double NextPalindrome(double input)
        {
            var inputString = input.ToString(CultureInfo.InvariantCulture);
            var halfLength = (inputString.Length + 1)/2;
            string firstHalf = inputString.Substring(0, halfLength);
            var secondHalf = halfLength<inputString.Length? inputString.Substring(halfLength, inputString.Length - halfLength) : string.Empty;
            string incrementedFirstHalf = (double.Parse(firstHalf) + 1).ToString(CultureInfo.InvariantCulture);
            var candidates = new List<string>();
            if(secondHalf != firstHalf)
                candidates.Add(firstHalf + new String(firstHalf.Reverse().ToArray()));
            candidates.Add(firstHalf + new String(firstHalf.Reverse().Skip(1).ToArray()));
            candidates.Add(incrementedFirstHalf + new String(incrementedFirstHalf.Reverse().ToArray()));
            candidates.Add(incrementedFirstHalf + new String(incrementedFirstHalf.Reverse().Skip(1).ToArray()));
            candidates.Add("1" + new String('0', inputString.Length - 1) + "1");
            return candidates.Select(s => double.Parse(s))
                      .Where(i => i > input)
                      .OrderBy(i => i)
                      .First();
        }
    }
}
