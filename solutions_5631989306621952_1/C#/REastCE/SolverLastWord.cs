using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolverLib
{
   class SolverLastWord : ISolver
   {
      public string Solve(string input)
      {
         string output = "";

         foreach(char ch in input)
         {
            if (output.Length == 0 || ch >= output[0])
            {
               output = ch + output;
            }
            else
            {
               output = output + ch;
            }
         }

         return output;
      }
   }
}
