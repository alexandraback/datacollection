using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2015ProgA
{
   class qrProgA
   {
      public const string cInputFile = "C:\\Dev\\2015\\Qualify\\qrA\\A-small-attempt1.in";
      public const string cOutputFile = "C:\\Dev\\2015\\Qualify\\qrA\\out.txt";
      public const string cExampleAnswerFile = "C:\\Dev\\2015\\Qualify\\qrA\\ea.txt";

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
                     string row = reader.ReadLine();

                     int maxShyLevel = int.Parse(row.Split(' ')[0]);
                     string digits = row.Split(' ')[1];
                    
                     long sum = 0;
                     long minFriends = 0;

                     for(int i = 0; i < digits.Length -1; i++)
                     {
                        int n = int.Parse(digits[i].ToString());
                        int n1 = int.Parse(digits[i+1].ToString());
                        sum = sum + n;

                        //how many to get next level up
                        if (sum < i + 1)
                        {
                           minFriends++;
                           sum++;
                        }
                     }


                     string outputString = minFriends.ToString();
   
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
      }
   }
}
