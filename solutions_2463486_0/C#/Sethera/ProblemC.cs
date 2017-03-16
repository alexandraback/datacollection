using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace CodeJam2013
{
    class ProblemC
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader(new FileStream(@"test.txt", FileMode.Open)));

            int problemCount = int.Parse(Console.In.ReadLine());

            //GenerateFairSquares();

            //List<BigInteger> allSquares = ReadGeneratedFairSquares();

            for (int i = 0; i < problemCount; i++)
            {
                String[] rangeParts = Console.In.ReadLine().Split(' ');
                BigInteger A = BigInteger.Parse(rangeParts[0]);
                BigInteger B = BigInteger.Parse(rangeParts[1]);

                //solveC(i + 1, A, B, allSquares);
                solveC(i + 1, A, B);
            }

            Console.Out.Flush();
        }


        public static void solveC(int caseNumber, BigInteger A, BigInteger B, List<BigInteger> allSquares)
        {   
            int start = 0;
            int end = allSquares.Count;

            for (int i = 0; i < end; i++)
            {
                if (allSquares[i] < A)
                {
                    start = i + 1;
                }

                if (allSquares[i] > B)
                {
                    end = i;
                    break;
                }
            }

            int count = end - start;           

            Console.Out.WriteLine("Case #" + caseNumber.ToString() + ": " + count.ToString());
        }

        public static List<BigInteger> ReadGeneratedFairSquares()
        {
            String[] lines = System.IO.File.ReadAllLines(@"fairsquares.txt");

            List<BigInteger> generatedFairSquares = new List<BigInteger>();

            foreach (String line in lines)
            {
                generatedFairSquares.Add(BigInteger.Parse(line));
            }

            return generatedFairSquares;
        }

        public static void solveC(int caseNumber, BigInteger A, BigInteger B)
        {
            BigInteger aSqrt = BigSqrt(A, true);
            BigInteger bSqrt = BigSqrt(B, false);

            BigInteger aStart = NearestPalindrome(aSqrt, true);
            BigInteger bEnd = NearestPalindrome(bSqrt, false);

            int count = 0;

            BigInteger currPalindrome = aStart;

            while (currPalindrome <= bEnd)
            {
                BigInteger potentialFairSquare = BigInteger.Pow(currPalindrome, 2);

                if (IsPalindrome(potentialFairSquare))
                {
                    count++;
                }

                currPalindrome = NextPalindrome(currPalindrome, true);
            }

            Console.Out.WriteLine("Case #" + caseNumber.ToString() + ": " + count.ToString());
        }

        public static BigInteger BigSqrt(BigInteger bi, bool above)
        {
            if (bi == BigInteger.One)
            {
                return bi;
            }

            int digits = (bi.ToString().Length + 1) / 2;

            BigInteger TEN = new BigInteger(10);
            BigInteger TWO = new BigInteger(2);

            BigInteger high = BigInteger.Pow(TEN, digits);
            BigInteger low = BigInteger.Pow(TEN, digits - 1);

            while (high - low > BigInteger.One)
            {
                BigInteger mid = (high + low) / TWO;
                BigInteger midSquared = BigInteger.Pow(mid, 2);

                if (midSquared > bi)
                {
                    high = mid;
                }
                else if (midSquared < bi)
                {
                    low = mid;
                }
                else
                {
                    return mid;
                }
            }

            if (above)
            {
                return high;
            }
            else
            {
                return low;
            }
        }

        public static BigInteger NearestPalindrome(BigInteger bi, bool above)
        {
            char[] charRep = bi.ToString().ToCharArray();

            for (int i = 0; i < charRep.Length / 2; i++)
            {
                charRep[charRep.Length - 1 - i] = charRep[i];
            }

            BigInteger nearest = BigInteger.Parse(new String(charRep));

            if ((above && nearest < bi)
                || (!above && nearest > bi))
            {
                nearest = NextPalindrome(nearest, above);
            }

            return nearest;
        }

        public static BigInteger NextPalindrome(BigInteger bi, bool above)
        {
            String stringRep = bi.ToString();

            BigInteger TWO = new BigInteger(2);

            if (!above && stringRep.StartsWith("1") && stringRep.EndsWith("1") && stringRep.Substring(1, stringRep.Length - 2).Trim('0') == "")
            {
                return bi - TWO;
            }

            if (above && stringRep.Trim('9') == "")
            {
                return bi + TWO;
            }

            int numCount = stringRep.Length / 2;

            BigInteger modVal = BigInteger.Parse("1" + new String('0', numCount));

            BigInteger closeVal;
            if (above)
            {
                closeVal = bi + modVal;
            }
            else
            {
                closeVal = bi - modVal;
            }

            char[] closeCharRep = closeVal.ToString().ToCharArray();

            for (int i = 0; i < closeCharRep.Length / 2; i++)
            {
                closeCharRep[closeCharRep.Length - 1 - i] = closeCharRep[i];
            }

            return BigInteger.Parse(new String(closeCharRep));
        }

        public static bool IsPalindrome(BigInteger bi)
        {
            char[] charRep = bi.ToString().ToCharArray();

            bool isPalindrome = true;
            for (int i = 0; i < charRep.Length / 2; i++)
            {
                if (charRep[charRep.Length - 1 - i] != charRep[i])
                {
                    isPalindrome = false;
                    break;
                }
            }

            return isPalindrome;
        }

        public static void GenerateFairSquares()
        {
            List<BigInteger> allSquares = new List<BigInteger>();

            int cap = 25;
            int capPow = int.Parse(BigInteger.Pow(2, cap).ToString());

            allSquares.Add(new BigInteger(1));
            allSquares.Add(new BigInteger(4));
            allSquares.Add(new BigInteger(9));

            for (int i = 1; i < capPow; i++)
            {
                String halfString = Convert.ToString(i, 2);
                String reversedHalfString = new String(halfString.Reverse().ToArray());

                BigInteger potential = BigInteger.Parse(halfString + reversedHalfString);
                BigInteger square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "0" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "1" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "2" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
            }

            for (int i = 0; i < cap; i++)
            {
                String halfString = "2" + new String('0', i);
                String reversedHalfString = new String(halfString.Reverse().ToArray());

                BigInteger potential = BigInteger.Parse(halfString + reversedHalfString);
                BigInteger square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "0" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "1" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }
                potential = BigInteger.Parse(halfString + "2" + reversedHalfString);
                square = BigInteger.Pow(potential, 2);
                if (IsPalindrome(square))
                {
                    allSquares.Add(square);
                }

            }

            allSquares.Sort(new BigComp());



            foreach (BigInteger bi in allSquares)
            {
                Console.Out.WriteLine(bi.ToString());
            }

        }

        private class BigComp : Comparer<BigInteger>
        {
            public override int Compare(BigInteger x, BigInteger y)
            {
                return BigInteger.Compare(x, y);
            }
        }
    }
}
