using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2015ProgD
{
   class qrProgS
   {
      public const string cInputFile = "C:\\Dev\\2015\\Qualify\\qrD\\D-small-attempt2.in";
      public const string cOutputFile = "C:\\Dev\\2015\\Qualify\\qrD\\out.txt";
      public const string cExampleAnswerFile = "C:\\Dev\\2015\\Qualify\\qrD\\ea.txt";

      static void Main(string[] args)
      {
         try
         {
            using (StreamWriter writer = new StreamWriter(cOutputFile))
            {
               using (StreamReader reader = new StreamReader(cInputFile))
               {
                  int numberOfTestCases = int.Parse(reader.ReadLine());

                  for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                  {
                     string line = reader.ReadLine();
                     int x = int.Parse(line.Split(' ')[0]);
                     int r = int.Parse(line.Split(' ')[1]);
                     int c = int.Parse(line.Split(' ')[2]);

                     const string cGABRIEL = "GABRIEL";
                     const string cRICHARD = "RICHARD";

                     string winner = "";

                     int gridArea = r * c;
                     int modVal = gridArea % x;

                     //Gabriel can fit a 1 block anywhere
                     if (x == 1)
                     {
                        winner = cGABRIEL;
                     }
                     //If X is 7 or higher Richard can create a donut block 
                     //which makes it impossible to fill.
                     //richards block must also be divisible by the area.
                     else if (modVal == 0 &&  x < 7 && (x <= r || x <= c))
                     {
                        //since the board is an even area a 1 by 2 block can fill the board
                        if (x == 2)
                        {
                           winner = cGABRIEL;
                        }
                        else if (x == 3)
                        {
                           //Richard can make his block so it won't fit on the board.
                           if (r == 1 || c == 1)
                           {
                              winner = cRICHARD;
                           }
                           else
                           {
                              winner = cGABRIEL;
                           }
                        }
                        else if (x == 4)
                        {
                           //Richard can make his block so it won't fit on the board.
                           if ((r == 1 || c == 1) || Math.Abs(r - c) >= 2)
                           {
                              winner = cRICHARD;
                           }
                           else
                           {
                              winner = cGABRIEL;
                           }
                        }
                     }
                     else
                     {
                        winner = cRICHARD;
                     }



                     string outputString = winner;

                     //Output testcase 
                     string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + outputString;

                     Console.WriteLine(outputLine);
                     writer.WriteLine(outputLine);
                  }
               }
            }
         }
         catch (Exception exc)
         {
            Console.WriteLine(exc);
         }
         ///CompareResultWithExample();
      }
   }
}
