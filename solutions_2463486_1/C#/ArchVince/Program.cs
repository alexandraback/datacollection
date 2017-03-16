using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace CodeJamQualifications
{
    class Program
    {
        const string challenge = "FairAndSquare";
        const string outputFolder = @"C:\Users\Arch\Documents\CodeJam\Output\";

        static void Main(string[] args)
        {
            ClearFile();

            string[] lines = File.ReadAllLines(args[0]);
            int count = int.Parse(lines[0]);

            for (int i = 0; i < count; i++)
            {
                int found = 0;
                string[] vals = lines[i + 1].Split(new char[] { ' ' });
                BigInteger min = BigInteger.Parse(vals[0]);
                BigInteger max = BigInteger.Parse(vals[1]);

                //I'd rather not rely on the accuracy of the Sqrt function
                BigInteger minRoot = Sqrt(min);
                while (BigInteger.Pow(minRoot, 2) < min)
                    ++minRoot;
                BigInteger maxRoot = Sqrt(max);
                while (BigInteger.Pow(maxRoot, 2) <= max)
                    ++maxRoot;

                BigInteger h = minRoot;
                while (!IsPalindrome(h++)) ;
                h--;
                while(h < maxRoot)
                {
                    if (IsPalindrome(BigInteger.Pow(h, 2)))
                        ++found;
                    h = NextPalindrome(h);
                }
                Save("Case #" + (i + 1) + ": " + found + "\n");
            }

            /*for (int i = 0; i < count; i++)
            {
                int found = 0;
                string[] vals = lines[i + 1].Split(new char[] { ' ' });
                BigInteger min = BigInteger.Parse(vals[0]);
                BigInteger max = BigInteger.Parse(vals[1]);

                //I'd rather not rely on the accuracy of the Sqrt function
                BigInteger minRoot = Sqrt(min);
                while (BigInteger.Pow(minRoot, 2) < min)
                    ++minRoot;
                BigInteger maxRoot = Sqrt(max);
                while (BigInteger.Pow(maxRoot, 2) <= max)
                    ++maxRoot;

                for (BigInteger h = minRoot; h < maxRoot; h++)
                {
                    Console.WriteLine(h);
                    if (IsPalindrome(h) && IsPalindrome(BigInteger.Pow(h, 2)))
                        ++found;
                }
                Save("Case #" + i + ": " + found + "\n");
            }*/
        }

        private static BigInteger NextPalindrome(BigInteger num)
        {
            string str = num.ToString();
            if (str == new string('9', str.Length))
                return BigInteger.Parse("1" + new string('0', str.Length - 1) + "1");

            bool first = true;
            for (int i = (int)Math.Ceiling(str.Length / 2.0f) - 1; i >= 0; i--)
            {
                if (first && str.Length % 2 == 1)
                {
                    if (str[i] != '9')
                    {
                        str = str.Substring(0, i) + ((char)(str[i] + 1)).ToString() + str.Substring(Math.Min(str.Length, i + 1));
                        return BigInteger.Parse(str);
                    }
                    else
                        str = str.Substring(0, i) + "0" + str.Substring(i + 1);
                }
                else
                {
                    if (str[i] != '9')
                    {
                        str = str.Substring(0, i) + 
                              ((char)(str[i] + 1)).ToString() + 
                              str.Substring(i + 1, Math.Max(0, str.Length - 2 * (i + 1))) + 
                              ((char)(str[i] + 1)).ToString() + 
                              str.Substring(Math.Min(str.Length, str.Length - i));
                        return BigInteger.Parse(str);
                    }
                    else
                        str = str.Substring(0, i) + "0" + str.Substring(i + 1, Math.Max(0, str.Length - 2 * (i + 1))) + "0" + str.Substring(Math.Min(str.Length, str.Length - i));
                }
                first = false;                    
            }

            throw new IndexOutOfRangeException("No palindrome found");
        }

        private static bool IsPalindrome(BigInteger num)
        {
            return IsPalindrome(num.ToString());
        }

        private static bool IsPalindrome(string str)
        {
            for (int i = 0; i < str.Length / 2; i++)
            {
                if (str[i] != str[str.Length - 1 - i])
                    return false;
            }
            return true;
        }

        private static void Save(string toSave)
        {
            File.AppendAllText(outputFolder + challenge + ".out", toSave);
        }

        private static void ClearFile()
        {
            File.WriteAllText(outputFolder + challenge + ".out", "");
        }

        public static BigInteger Sqrt(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }
    }
}
