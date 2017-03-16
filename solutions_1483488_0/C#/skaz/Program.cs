using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SpeakingInTongues
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());

            for (int i = 0; i < testCaseCount; i++)
                ProcessTestCase(i + 1);
        }

        private Dictionary<char, char> map = new Dictionary<char, char>();

        private static void ProcessTestCase(int caseNumber)
        {
            // Read in the next line of the program
            string[] line = Console.ReadLine().Split(' ');

            int a = int.Parse(line[0]);
            int b = int.Parse(line[1]);

            int matches = 0;

            for (int i = a; i <= b; i++)
            {
                string x = i.ToString();

                List<string> matchesForThisI = new List<string>();

                for(int j = 1; j < x.Length; j++)
                {
                    string sub = x.Substring(0, j);
                    string sub2 = x.Substring(j, x.Length - j);

                    string newVal = sub2 + sub;

                    int newvalInt = int.Parse(newVal);

                    if (newvalInt <= b &&  newvalInt > i && !matchesForThisI.Contains(newVal))
                    {
                        matchesForThisI.Add(newVal);
                        matches ++;
                    }
                }
            }

        
            Console.WriteLine("Case #{0}: {1}", caseNumber, matches);
        }
    }
}
