using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TicTacToe
{
    class Program
    {
        static IList<long> palindroms = new List<long>{1,4,9};
        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        public static bool IsPalindrom(long num)
        {
            return num.ToString() == Reverse(num.ToString());
        }
        static void Main(string[] args)
        {
            long range = (int) Math.Sqrt(1000);
            for(long i =10;i<= range; i++)
            {
                long sq = i * i;
                if (IsPalindrom(i) && IsPalindrom(sq))
                    palindroms.Add(sq);

            }

            IList<string> resultsOfCases = GetInputsFromFile("C-small-attempt0.in");

            using (System.IO.StreamWriter file = new System.IO.StreamWriter("Output.txt"))
            {
                foreach (string line in resultsOfCases)
                {
                    file.WriteLine(line);
                }
            }
        }

        private static IList<string> GetInputsFromFile(string fileName)
        {
            IList<string> results = new List<string>();

            string[] lines = System.IO.File.ReadAllLines(fileName);
            for (int i = 1; i < lines.Count(); )
            {
                int lowerLimit = Int32.Parse(lines[i].Split(' ')[0]);
                int upperLimit = Int32.Parse(lines[i].Split(' ')[1]);

                int result = GetFairPalindrom(lowerLimit, upperLimit);
                results.Add("Case #" + i + ": " + result);
                i = i + 1;
            }

            return results; ;
        }

        private static int GetFairPalindrom(int lowerLimit, int upperLimit)
        {

            return palindroms.Count(x => x >= lowerLimit && x <= upperLimit);
        }


    }
}
