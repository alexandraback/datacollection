using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2015ProgB
{
   class qrProgB
   {
      public const string cInputFile = "C:\\Dev\\2015\\Qualify\\qrB\\B-small-attempt0.in";
      public const string cOutputFile = "C:\\Dev\\2015\\Qualify\\qrB\\out.txt";
      public const string cExampleAnswerFile = "C:\\Dev\\2015\\Qualify\\qrB\\ea.txt";

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
                     long numNonEmpty = long.Parse(reader.ReadLine());
                     List<long> numPancakesOnPlate = reader.ReadLine().Split(' ').Select(o => long.Parse(o)).ToList();

                     long numberOfSpecialMinutes = 0;
                    
                     long bestTime = numPancakesOnPlate.Max();
                     long absoluteWorstTime = bestTime;
                     long currentTime = 0;

                     long iter = 0;
                     while (iter < absoluteWorstTime)
                     {
                        
                        //If there is a diner with more than 2 pancakes it may make sense to split his cakes with someone else.
                        long maxPancakesOnPlate = numPancakesOnPlate.Max();
                        if (maxPancakesOnPlate > 2)
                        {
                           int indexWithMax = numPancakesOnPlate.FindIndex(o => o == maxPancakesOnPlate);

                           long amountOnCurrentPlate = maxPancakesOnPlate / 2;
                           long amountOnNewPlate = maxPancakesOnPlate - amountOnCurrentPlate;
                           numPancakesOnPlate[indexWithMax] = amountOnCurrentPlate;
                           numPancakesOnPlate.Add(amountOnNewPlate);

                           numberOfSpecialMinutes++;
                        }

                        currentTime = numPancakesOnPlate.Max() + numberOfSpecialMinutes;
                        if (currentTime < bestTime)
                        {
                           bestTime = currentTime;
                        }
                        iter++;
                     }


                     string outputString = bestTime.ToString();

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
