using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SolverLib;
using System.Runtime.Remoting;
using ProblemHandler;

namespace Shell
{
   class Program
   {
      static void Main(string[] args)
      {
         string solverTypeName = args[0];
         string inputFile = args[1];
         string outputFile = Path.ChangeExtension(inputFile, ".out");

         ObjectHandle handle = Activator.CreateInstance("SolverLib", solverTypeName);
         ISolver solver = (ISolver)handle.Unwrap();

         using (StreamReader sr = new StreamReader(inputFile))
         using (StreamWriter sw = new StreamWriter(outputFile, false))
         {
            CaseProcessor caseProcessor = new CaseProcessor(solver);
            caseProcessor.Process(sr, sw);
         }
      }
   }
}
