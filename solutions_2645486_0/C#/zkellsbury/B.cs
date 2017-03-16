using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace GoogleCodeJam2013
{
    class Round1A_B
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("b.in");
            TextWriter fileOut = new StreamWriter("b.out");

            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 1; caseCount <= countNum; caseCount++)
            {
                string[] stringVals = fileIn.ReadLine().Split(' ');

                int maxenergy = Int32.Parse(stringVals[0]);
                int recharge = Int32.Parse(stringVals[1]);
                int events = Int32.Parse(stringVals[2]);

                int[] eventValue = new int[events];
                stringVals = fileIn.ReadLine().Split(' ');
                for (int i = 0; i < events; i++)
                {
                    eventValue[i] = Int32.Parse(stringVals[i]);
                }

                int energy = maxenergy, totalValue = 0, bestValue = 0, energytospend, j;
                for (int i = 0; i < events; i++)
                {
                    energytospend = 0;
                    j = i;
                    bestValue = eventValue[j];
                    while(bestValue >= eventValue[j++])
                    {
                        energytospend += recharge;
                        if (energytospend >= energy)
                        {
                            energytospend = energy;
                            break;
                        }

                        if (j == events)
                        {
                            energytospend = energy;
                            break;
                        }
                    }

                    totalValue += bestValue * energytospend;
                    energy += (recharge - energytospend);
                }


                fileOut.WriteLine("Case #" + caseCount + ": " + totalValue);
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();

        }
    }
}
