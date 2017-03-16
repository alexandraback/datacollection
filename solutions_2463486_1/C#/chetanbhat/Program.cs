using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
namespace FairSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            var table = GetTable(1, BigInteger.Pow(10, 20));
            var T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var input = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => BigInteger.Parse(s)).ToArray();
                var A = input[0];
                var B = input[1];
                var count = table.Where(x => x >= A && x <= B).Count();
                Console.WriteLine("Case #{0}: {1}", t + 1, count);
            }
        }

        static List<BigInteger> GetTable(BigInteger A, BigInteger B)
        {
            var list = new List<BigInteger>();

            var sqrtA = BigInteger.Pow(10, (int)Math.Floor(BigInteger.Log10(A) / 2.0));
            var sqrtB = BigInteger.Pow(10, (int)Math.Ceiling(BigInteger.Log10(B) / 2.0)) - 1;


            // Console.WriteLine("Input: {0}, {1}", A, B);
            // Console.WriteLine("Sqrt: {0}, {1}", sqrtA, sqrtB);

            var sqrtAStr = sqrtA.ToString();
            var quarA = long.Parse(sqrtAStr.Substring(0, (int)Math.Ceiling(sqrtAStr.Length / 2.0)));

            var sqrtBStr = sqrtB.ToString();
            var quarB = long.Parse(sqrtBStr.Substring(0, (int)Math.Ceiling(sqrtBStr.Length / 2.0)));

            // Console.WriteLine("Quart: {0}, {1}", quarA, quarB);

            long count = 0;
            for (var i = quarA; i <= quarB; i++)
            {
                var str = i.ToString();
                var strLen = str.Length;
                {
                    var sb1 = new StringBuilder(str.Length * 2);
                    sb1.Append(str);
                    var charArray = str.ToCharArray();
                    Array.Reverse(charArray);
                    sb1.Append(charArray);
                    var b1 = BigInteger.Parse(sb1.ToString());
                    var bb = b1 * b1;
                    if (bb >= A && bb <= B && IsPalindrome(bb.ToString()))
                    {
                        count++;
                        list.Add(bb);
                    }
                }

                {
                    var sb2 = new StringBuilder(str.Length * 2);
                    sb2.Append(str);
                    var charArray = str.Substring(0, strLen - 1).ToCharArray();
                    Array.Reverse(charArray);
                    sb2.Append(charArray);
                    var b2 = BigInteger.Parse(sb2.ToString());
                    var bb = b2 * b2;
                    if (bb >= A && bb <= B && IsPalindrome(bb.ToString()))
                    {
                        count++;
                        list.Add(bb);
                    }
                }
            }
            return list;
        }

        static bool IsPalindrome(string s)
        {
            var N = s.Length;
            for (int i = 0; i < s.Length / 2; i++)
            {
                if (s[i] != s[N - i - 1])
                    return false;
            }
            return true;
        }
    }
}
