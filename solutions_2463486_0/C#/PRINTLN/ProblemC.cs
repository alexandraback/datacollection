using System;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

public class ProblemC
{
    public static void Main(String[] args)
    {
        StreamReader reader = new StreamReader(@"D:\codejam\C-small-attempt0.in");
        StreamWriter writer = new StreamWriter(@"D:\codejam\C-small-attempt0.out");
        var inputPool = reader.ReadToEnd()
                              .Trim()
                              .Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                              .ToArray();

        var index = 0;
        int T = Int32.Parse(inputPool[index++]);
        for (int t = 1; t <= T; t++)
        {
            BigInteger A = BigInteger.Parse(inputPool[index++]);
            BigInteger B = BigInteger.Parse(inputPool[index++]);

            BigInteger from = Sqrt(A) - BigInteger.One;
            BigInteger to = Sqrt(B) + BigInteger.One;
            int count = 0;
            BigInteger n = from;
            while (n <= to)
            {
                if (IsPalindrome(n.ToString()))
                {
                    var square = n * n;
                    if (IsPalindrome(square.ToString()) && square >= A && square <= B)
                    {
                        count++;
                    }
                }
                n = BigInteger.Parse(NextPalindrome(n.ToString()));
            }
            writer.WriteLine(String.Format("Case #{0}: {1}", t, count));
        }

        writer.Flush();
        writer.Close();
        reader.Close();
    }

    public static BigInteger Sqrt(BigInteger n)
    {
        if (n == 0) return 0;
        if (n > 0)
        {
            int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
            BigInteger root = BigInteger.One << (bitLength / 2);

            while (!IsSqrt(n, root))
            {
                root += n / root;
                root /= 2;
            }

            return root;
        }

        throw new ArithmeticException("NaN");
    }

    private static Boolean IsSqrt(BigInteger n, BigInteger root)
    {
        BigInteger lowerBound = root * root;
        BigInteger upperBound = (root + 1) * (root + 1);

        return (n >= lowerBound && n < upperBound);
    }

    public static bool IsPalindrome(String number)
    {
        int half = number.Length / 2;
        int length = number.Length;
        for (int i = 0; i < half; i++)
        {
            if (number[i] != number[length - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    public static String NextPalindrome(string number)
    {
        StringBuilder buffer = new StringBuilder();
        var half = number.Length / 2;
        if (AllNine(number))
        {
            return String.Format("1{0}1", new String('0', number.Length - 1));
        }
        else if (number.Length == 1)
        {
            return String.Format("{0}", (char)(number[0] + 1));
        }

        else if (IsLeftReverseLargerThanRight(number))
        {
            var zeros = new string('0', number.Length / 2 - half);
            var c = number[half - 1];
            buffer.Append(number.Substring(0, half - 1));
            buffer.Append(c);
            buffer.Append(zeros);

            // middle one
            if (number.Length % 2 != 0)
            {
                buffer.Append(number[half]);
            }
            buffer.Append(zeros);
            buffer.Append(c);
            buffer.Append(number.Substring(0, half - 1).Reverse().ToArray());
            return buffer.ToString();
        }
        else if (number.Length % 2 != 0 && number[half] < '9')
        {
            var zeros = new string('0', number.Length / 2 - half);
            var c = (char)(number[half - 1]);
            buffer.Append(number.Substring(0, half - 1));
            buffer.Append(c);
            buffer.Append(zeros);

            // middle one
            if (number.Length % 2 != 0)
            {
                buffer.Append((char)(number[half] + 1));
            }
            buffer.Append(zeros);
            buffer.Append(c);
            buffer.Append(number.Substring(0, half - 1).Reverse().ToArray());
        }
        else
        {
            var zeros = new string('0', number.Length / 2 - (half - GetLeftSuccessiveNinesCount(number)));
            var index = half - GetLeftSuccessiveNinesCount(number) - 1;
            var c = (char)(number[index] + 1);
            buffer.Append(number.Substring(0, index));
            buffer.Append(c);
            buffer.Append(zeros);
            if (number.Length % 2 != 0) buffer.Append('0');
            buffer.Append(zeros);
            buffer.Append(c);
            buffer.Append(number.Substring(0, index).Reverse().ToArray());
        }
        return buffer.ToString();
    }

    private static Boolean AllNine(String number)
    {
        foreach (var c in number)
        {
            if (c != '9')
            {
                return false;
            }
        }
        return true;
    }

    private static int GetLeftSuccessiveNinesCount(string s)
    {
        var i = s.Length / 2 - 1;
        while (i >= 0 && s[i] == '9') i--;
        return s.Length / 2 - 1 - i;
    }

    private static bool IsLeftReverseLargerThanRight(string number)
    {
        var n = number.Length / 2;
        var k = number.Length % 2 + n;
        for (var i = 0; i < n; i++)
        {
            var compareRsult = number[k + i].CompareTo(number[n - 1 - i]);
            if (compareRsult < 0)
            {
                return true;
            }
            if (compareRsult > 0)
            {
                return false;
            }
        }
        return false;
    }
}