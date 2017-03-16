using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace FairAndSquare
{
    class Program
    {
        static List<long> GenerateFairAndSquare()
        {
            List<long> l1 = new List<long>();
            List<long> l2 = new List<long>();

            for (long i = 0; i <= 10000000; i++)
            {

                if (IsPalindrome(i.ToString()))
                {
                    long sq = i * i;
                    if (IsPalindrome(sq.ToString()))
                    {
                        l1.Add(i);
                        l2.Add(sq);
                    }

                }
            }

            return l2;
        }

        static bool IsPalindrome(string str)
        {
            for (int i = 0; i < str.Length / 2; i++)
            {
                if (str[i] != str[str.Length - 1 - i]) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\C-small-attempt0.in");
            StreamWriter sw = new StreamWriter("D:\\C-small-attempt0.out");

            //StreamReader sr = new StreamReader("D:\\B-large.in");
            //StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());

            List<long> fairAndSquareNumbersLarge1 = GenerateFairAndSquare();

            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                long A = Convert.ToInt64(str[0]);
                long B = Convert.ToInt64(str[1]);

                int num = 0;

                foreach (long l in fairAndSquareNumbersLarge1)
                {
                    if (l >= A && l <= B)
                        num++;
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(num);
                sw.WriteLine();

            }
            sw.Close();
        }
    }
}
