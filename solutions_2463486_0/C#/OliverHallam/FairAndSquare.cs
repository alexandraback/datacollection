using System;
using System.IO;
using System.Linq;
using System.Numerics;

namespace FairAndSquare
{
    public class FairAndSquare
    {
        public struct Palindrome
        {
            public BigInteger LeftHalf;
            public bool Even;

            public Palindrome(BigInteger left, bool even)
            {
                this.LeftHalf = left;
                this.Even = even;
            }

            public void Next(ref BigInteger nextPowerOf10)
            {
                this.LeftHalf++;

                if (this.LeftHalf == nextPowerOf10)
                {
                    if (this.Even)
                    {
                        this.Even = false;
                        nextPowerOf10 *= 10;
                    }
                    else
                    {
                        this.Even = true;
                        this.LeftHalf /= 10;
                    }
                }
            }
            public void Previous(ref BigInteger prevPowerOf10)
            {
                if (this.LeftHalf == prevPowerOf10)
                {
                    if (this.Even)
                    {
                        this.LeftHalf *= 10;
                        this.Even = false;
                    }
                    else
                    {
                        prevPowerOf10 /= 10;
                        this.Even = true;
                    }
                }

                this.LeftHalf--;
            }

            public BigInteger GetValue()
            {
                var leftString = this.LeftHalf.ToString();
                var length = leftString.Length * 2;
                if (!this.Even) length--;

                var chars = new char[length];
                var i = 0;
                var j = length - 1;
                while (i <= j)
                {
                    chars[i] = chars[j] = leftString[i];
                    i++;
                    j--;
                }
                return BigInteger.Parse(new string(chars));
            }
        }

        public class PalindromeRange
        {
            public BigInteger nextPowerOf10;

            public Palindrome current;
            public Palindrome last;

            public PalindromeRange(Palindrome startPalindrome, Palindrome endPalindrome)
            {
                this.current = startPalindrome;
                this.last = endPalindrome;
                this.nextPowerOf10 = FairAndSquare.NextPowerOf10(this.current.LeftHalf);
            }

            public bool IsEmpty
            {
                get
                {
                    return (this.current.Even == this.last.Even && this.current.LeftHalf == this.last.LeftHalf);
                }
            }

            public bool Next()
            {
                this.current.Next(ref this.nextPowerOf10);
                if (this.IsEmpty)  return false;
                return true;
            }
        }

        static void Main(string[] args)
        {
            using (var reader = new StreamReader("in.txt"))
            using (var writer = new StreamWriter("out.txt"))
            {
                reader.ReadLine();

                int caseID = 1;
                while (!reader.EndOfStream)
                {
                    var range = ReadRange(reader);
                    var result = FairAndSquareInRange(range.Item1, range.Item2);
                    writer.WriteLine("Case #{0}: {1}", caseID, result);
                    caseID++;
                }
            }
        }

        private static BigInteger SquareRootRoundDown(BigInteger x)
        {
            var sqrt = new BigInteger(Math.Sqrt((double)x));
            while (sqrt * sqrt > x) sqrt--;
            return sqrt;
        }

        private static BigInteger SquareRootRoundUp(BigInteger x)
        {
            var sqrt = new BigInteger(Math.Sqrt((double)x));
            while (sqrt * sqrt < x) sqrt++;
            return sqrt;
        }

        public static int FairAndSquareInRange(BigInteger min, BigInteger max)
        {
            var palindromes = PalindromesInRange(SquareRootRoundUp(min) - 1, SquareRootRoundDown(max) + 1);
            if (palindromes == null || palindromes.IsEmpty) return 0;

            int count = 0;
            do
            {
                var current = palindromes.current.GetValue();
                var square = current * current;
                if (IsPalindrome(square)) count++;
            }
            while (palindromes.Next());

            return count;
        }

        public static PalindromeRange PalindromesInRange(BigInteger start, BigInteger end)
        {
            var startPalindrome = GetNextPalindrome(start);
            var endPalindrome = GetNextPalindrome(end);
            var range = new PalindromeRange(startPalindrome, endPalindrome);
            if (range.current.GetValue() == start)
            {
                if (!range.Next()) return null;
            }
            return range;
        }

        public static Palindrome GetNextPalindrome(BigInteger x)
        {
            var stringValue = x.ToString();
            var left = stringValue.Substring(0, (stringValue.Length + 1) / 2);
            var candidate = new Palindrome(BigInteger.Parse(left), stringValue.Length % 2 == 0);
            if (candidate.GetValue() < x)
            {
                var nextPower = NextPowerOf10(candidate.LeftHalf);
                candidate.Next(ref nextPower);
            }
            return candidate;
        }

        public static BigInteger NextPowerOf10(BigInteger x)
        {
            var nextPower = 10;
            while (nextPower <= x)
            {
                nextPower *= 10;
            }
            return nextPower;
        }


        public static bool IsPalindrome(BigInteger x)
        {
            var stringValue = x.ToString();
            var i = 0;
            var j = stringValue.Length - 1;

            while (i < j)
            {
                if (stringValue[i] != stringValue[j]) return false;
                i++;
                j--;
            }
            return true;
        }

        private static Tuple<BigInteger, BigInteger> ReadRange(StreamReader reader)
        {
            var range = reader.ReadLine().Split(' ').Select(BigInteger.Parse).ToArray();
            return Tuple.Create(range[0], range[1]);
        }
    }
}
