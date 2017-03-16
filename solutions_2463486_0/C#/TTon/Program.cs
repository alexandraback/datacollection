using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FairAndSquare
{
    internal class Program
    {
        public static List<string> ParseInput(string[] lines)
        {
            int caseCount = 0;

            List<string> paramSet = new List<string>();
            for (int index = 0; index < lines.Length; index++)
            {
                string line = lines[index];

                if (index == 0)
                {
                    if (!Int32.TryParse(line, out caseCount))
                    {
                        Console.WriteLine("Invalid line {0}:{1}", index, line);
                        break;
                    }
                }
                else
                {
                    paramSet.Add(line);
                }
            }

            if (paramSet.Count != caseCount)
            {
                Console.WriteLine("Invalid case count");
            }

            return paramSet;
        }

        private static void Main(string[] args)
        {
            string[] rawInput = System.IO.File.ReadAllLines(args[0]);
            List<string> problems = ParseInput(rawInput);

            for (int caseIndex = 0; caseIndex < problems.Count; caseIndex++)
            {
                string input = problems[caseIndex];
                string[] param = input.Split(' ');
                int begin = int.Parse(param[0]);
                int end = int.Parse(param[1]);

                int palindromeCount = 0;
                int sqrtBegin = (int)Math.Ceiling(Math.Sqrt(begin));
                int sqrtEnd = (int)Math.Sqrt(end);
                for (int i = sqrtBegin; i <= sqrtEnd; i++)
                {
                    if (isPalindrome(i) && isPalindrome(i * i))
                    {
                        ++palindromeCount;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", caseIndex + 1, palindromeCount);
            }
        }

        private static bool isPalindrome(int ii)
        {
            string str = ii.ToString();
            int i = 0;
            int j = str.Length - 1;

            while (i < j)
            {
                if (str[i] != str[j])
                    return false;
                ++i;
                --j;
            }

            return true;
        }
    }
}