using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace Round1B2015Prob1
{
   class Round1BProb1
   {

      public const string cInputFile = "C:\\Dev\\2015\\Round1B\\Prob1\\A-small-attempt2.in";
      public const string cOutputFile = "C:\\Dev\\2015\\Round1B\\Prob1\\out.txt";
      public const string cExampleAnswerFile = "C:\\Dev\\2015\\Round1B\\Prob1\\ea.txt";

      static void Main(string[] args)
      {
         using (StreamWriter writer = new StreamWriter(cOutputFile))
         {
            using (StreamReader reader = new StreamReader(cInputFile))
            {
               int numberOfTestCases = int.Parse(reader.ReadLine());

               for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
               {
                  string testCase = reader.ReadLine();

                  int numRows = int.Parse(testCase.Split(' ')[0]);
                  int numCols = int.Parse(testCase.Split(' ')[1]);
                  int shipLength = int.Parse(testCase.Split(' ')[2]);


                  int shipPerRow = numCols / shipLength;
                  int perGrid = shipPerRow * numRows;
                  int spacesToEndOfRow =  numCols % shipLength;


                  int finalHit = spacesToEndOfRow + (shipLength - spacesToEndOfRow - 1);
                  if (spacesToEndOfRow != 0)
                  {
                     finalHit++;
                  }

                  int total = perGrid  + finalHit;


                  //Output testcase 
                  string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + total.ToString();

                  Console.WriteLine(outputLine);
                  writer.WriteLine(outputLine);
               }
            }
         }
         ///CompareResultWithExample();
      }
   }
}
