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

        private static void ProcessTestCase(int caseNumber)
        {
            // Read in the next line of the program
            string[] line = Console.ReadLine().Split(' ');

            int charsTyped = int.Parse(line[0]);
            int totalChar = int.Parse(line[1]);

            List<decimal> probCorrect = new List<decimal>(charsTyped);

            line = Console.ReadLine().Split(' ');

            for (int i = 0; i < charsTyped; i++)
            {
                probCorrect.Add(decimal.Parse(line[i]));
            }

            decimal chanceCorrect = 1;
            decimal chanceInc = 1;

            foreach (decimal d in probCorrect)
            {
                chanceCorrect *= d;
            }

            chanceInc = 1 - chanceCorrect;

            decimal best = 0;
            int baselineKeysToFinish = totalChar - charsTyped + 1 + (totalChar + 1);
            
            // If I hit enter
            best = 2 + totalChar;
 
            // Now try to beat
            for (int bsps = 0; bsps <= charsTyped; bsps++)
            {
                chanceCorrect = 1;

                int i = 0;
                foreach (decimal d in probCorrect)
                {
                    if (i < charsTyped - bsps)
                        chanceCorrect *= d;

                    i++;
                }
                // Now we have the chance it is correct under these circumstances
                chanceInc = 1 - chanceCorrect;

                decimal rightOnFirstTry = chanceCorrect * (decimal)((decimal)totalChar - (decimal)charsTyped + 1 + (2 *bsps));
                decimal rightOnSecondTry = chanceInc * (decimal)(((decimal)totalChar - (decimal)charsTyped + 1 + (2 * bsps)) + (decimal)totalChar + 1);
                
                decimal total =  rightOnFirstTry + rightOnSecondTry;

                if (total < best)
                    best = total;
            }







            Console.WriteLine("Case #{0}: {1}", caseNumber, best);
        }
    }
}
