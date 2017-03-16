using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TicTacToe
{
    class Program
    {
        static void Main(string[] args)
        {
            IList<string> resultsOfCases = GetInputsFromFile("B-small-attempt0.in");

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
            int caseCount = 1;
            for(int i = 1; i < lines.Count();)
            {
                List<List<int>> aCase = new List<List<int>>();
                int rowsOfCase = Int32.Parse(lines[i].Split(' ')[0]);
                for (int j = 1; j <= rowsOfCase; j++)
                {
                    aCase.Add(new List<int>(lines[i + j].Split(' ').Select(k => Int32.Parse(k))));
                }
                string result = GetTheResultOfCase(aCase);
                results.Add("Case #" + caseCount +": " + result);
                caseCount++;
                i = i + rowsOfCase + 1;
            }
            
            return results; ;
        }

        private static string GetTheResultOfCase(List<List<int>> aCase)
        {
            for (int i = 0; i < aCase.Count; i++)
            {
               int maxInRow = aCase[i].Max();
               for (int j = 0; j < aCase[i].Count; j++)
               {
                   if (aCase[i][j] < maxInRow)
                   {
                       for (int k = 0; k < aCase.Count; k++)
                       {
                           if (aCase[k][j] > aCase[i][j])
                               return "NO";
                       }
                   }
               }
            }

            return "YES";

        }

   }
}
