using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;

namespace FairandSquare
{
    class Program
    {
        static void Main()
        {

            Console.ReadKey();
            Challenge();
            Console.ReadKey();
        }

        public static void Challenge()
        {
            string output = "";
            string[] input = File.ReadAllLines("INPUT.txt");

            for (var i = 0; i < input.Length; i++)
            {
                string[] args = input[i].Trim().Split(' ');
                if (args.Length == 1)
                {
                    continue;
                }
                output += String.Format("Case #{0}: {1}\n", i, GenerateFairSquares(Convert.ToUInt64(args[0]), Convert.ToUInt64(args[1])));
            }

            Console.WriteLine(output);
            File.WriteAllText("OUTPUT.txt", output);
            Console.WriteLine("DONE");
            Console.ReadKey();
        }

        public static ulong SumSquaredDigits(ulong n)
        {
            ulong sum = 0;
            while (n != 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            return sum;
        }

        public static string Reverse(string text)
        {
            if (text == null) return null;

            // this was posted by petebob as well 
            char[] array = text.ToCharArray();
            Array.Reverse(array);
            return new String(array);
        }

        public static string ReverseXor(string s)
        {
            if (s == null) return null;
            char[] charArray = s.ToCharArray();
            int len = s.Length - 1;

            for (int i = 0; i < len; i++, len--)
            {
                charArray[i] ^= charArray[len];
                charArray[len] ^= charArray[i];
                charArray[i] ^= charArray[len];
            }

            return new string(charArray);
        }

        public static ulong GenerateFairSquares(ulong min, ulong max)
        {
            ulong count = 0;
            foreach (ulong palindrome in GeneratePalindromes((ulong)Math.Ceiling(Math.Sqrt((double)min)), (ulong)Math.Floor(Math.Sqrt((double)max))))
            {
                if (SumSquaredDigits(palindrome) < 10)
                {
                    count += 1;
                }
            }
            return count;
        }

        public static IEnumerable<ulong> GeneratePalindromes(ulong min, ulong max) 
        {
            string stringMin = min.ToString();
            ulong edge = 1;
            if (stringMin.Length == 1)
            {
                edge = 1;
            }

            else
            {
                edge = (ulong)Math.Pow(10, (stringMin.Length / 2) - 1);
            }

            for (var i = min; i <= Math.Min(9, max); i++)
            {
                if (i <= max && i >= min)
                {
                    yield return i;
                }
            }

            while (true)
            {
                string stringEdge = edge.ToString();
                string template = string.Format("{0}{{0}}{1}", stringEdge, Reverse(stringEdge));
                ulong result = Convert.ToUInt64(string.Format(template, ""));
                if (result > max)
                {
                    break;
                }

                if (result >= min)
                {
                    yield return result;
                }

                foreach (char character in "0123456789")
                {
                    result = Convert.ToUInt64(string.Format(template, character));
                    if (result <= max)
                    {
                        if (result >= min)
                        {
                            yield return result;
                        }
                    }

                    else
                    {
                        break;
                    }
                }

                edge += 1;
            }
        }
    }
}
