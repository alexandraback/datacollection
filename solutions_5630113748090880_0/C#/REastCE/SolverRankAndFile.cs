using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolverLib
{
   class SolverRankAndFile : ISolver
   {
      private static char[] _splitCharSpace = new char[] { ' ' };

      public string Solve(string input)
      {
         string output = "";

         string[] inputSplit = input.Split('\n');

         Dictionary<int, int> values = new Dictionary<int, int>();

         for (int i = 1; i < inputSplit.Length; i++)
         {
            foreach (string str in inputSplit[i].Split(_splitCharSpace, StringSplitOptions.RemoveEmptyEntries))
            {
               int num = int.Parse(str);
               if (!values.ContainsKey(num))
               {
                  values.Add(num, 1);
               }
               else
               {
                  values[num]++;
               }
            }
         }

         List<int> oddValues = new List<int>();

         foreach(KeyValuePair<int,int> pair in values)
         {
            if (pair.Value % 2 == 1)
            {
               oddValues.Add(pair.Key);
            }
         }

         oddValues.Sort();
         
         for(int i = 0; i < oddValues.Count; i++)
         {
            output = output + oddValues[i].ToString() + ' ';
         }
         
         output = output.Trim();

         return output;

         /*
         int size = int.Parse(inputSplit[0]);

         int[,] intSets = new int[size, 2 * size - 1];

         for(int i = 1; i < inputSplit.Length; i++)
         {
            string[] setSplit = inputSplit[i].Split(_splitCharSpace, StringSplitOptions.RemoveEmptyEntries);

            for (int j = 0; j < setSplit.Length; j++)
            {
               intSets[j,i-1] = int.Parse(setSplit[j]);
            }
         }

         for(int i = 0; i < intSets.Length; i++)
         {
            for(int j = 0; j <  )            
             intSets[i];
         }

         return output;
         */
      }
   }
}
