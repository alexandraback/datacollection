using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

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

            //find all fair and square
            Int64 sqrtBegin = (Int64)Math.Ceiling(Math.Sqrt(1));
            Int64 sqrtEnd = (Int64)Math.Sqrt(100000000000000L);
            List<Int64> fairAndSquare = new List<long>();
            for (Int64 i = sqrtBegin; i <= sqrtEnd; i++)
            {
                if (isPalindrome(i))
                {
                    Int64 ii = i * i;
                    if (isPalindrome(ii))
                        fairAndSquare.Add(ii);
                }
            }

            for (int caseIndex = 0; caseIndex < problems.Count; caseIndex++)
            {
                string input = problems[caseIndex];
                string[] param = input.Split(' ');
                Int64 begin = Int64.Parse(param[0]);
                Int64 end = Int64.Parse(param[1]);

                int palindromeCount = 0;
                foreach (Int64 fs in fairAndSquare)
                {
                    if (begin <= fs && fs <= end)
                    {
                        ++palindromeCount;
                        if (fs > end)
                            break;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", caseIndex + 1, palindromeCount);
            }
        }

        private static bool isPalindrome(Int64 ii)
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