using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace QualA
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\C-large-1.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {

                int cases = int.Parse(sr.ReadLine());

                //Make a lookup list of squares and palindromes
                List<BigInteger> squares = new List<BigInteger>();
                double limit = Math.Pow(10,14);
                for (double r = 0; r < limit; r++)
                {
                    if (Palindrome(r.ToString()))
                    {
                        BigInteger a = new BigInteger(Math.Pow(r, 2));
                        if (Palindrome(a.ToString()))
                        {
                            squares.Add(a);
                            Console.WriteLine(squares.Count + "-%-" + a);
                        }
                        if (a > new BigInteger(limit)) break;
                    }
                }

                for (int i = 1; i <= cases; i++)
                {
                    string lineIn = sr.ReadLine();

                    BigInteger lower = BigInteger.Parse(lineIn.Split(' ').ElementAt(0));
                    BigInteger upper = BigInteger.Parse(lineIn.Split(' ').ElementAt(1));
                    int fairSquareCount = 0;

                    for (int j = 0; j < squares.Count; j++)
                    {
                        BigInteger k = squares[j];
                        if (k >= lower && k <= upper)
                            fairSquareCount++;
                    }

                    

                    string answer = "Case #" + i + ": " + fairSquareCount;
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.ReadLine();
        }

        private static bool Palindrome(string sq)
        {
            for (int k = 0; k < sq.Length / 2; k++)
                if (sq[k] != sq[sq.Length - k - 1]) return false;
            return true;
        }

    }
}
