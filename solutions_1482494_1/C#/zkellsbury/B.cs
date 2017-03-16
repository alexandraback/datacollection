using System;
using System.IO;
using System.Collections.Generic;

namespace GoogleCodeJam2012
{
    class MyPair
    {
        public char X { get; set; }
        public int Y { get; set; }
    }
    class A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("b.in");
            TextWriter fileOut = new StreamWriter("b.out");

            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 0; caseCount < countNum; caseCount++)
            {
                int levels = Int32.Parse(fileIn.ReadLine());
                int[,] starValues = new int[levels, 2];
                bool[,] starClaimed = new bool[levels, 2];
                
                // Initialize the arrays
                for(int i = 0; i < levels; i++)
                {
                    string[] vals = fileIn.ReadLine().Split(' ');
                    starValues[i, 0] = Int32.Parse(vals[0]);
                    starValues[i, 1] = Int32.Parse(vals[1]);
                    starClaimed[i, 0] = false;
                    starClaimed[i, 1] = false;
                }

                int starMax = 2 * levels;
                int starTotal = 0;
                int levelsPlayed = 0;
                bool starEarned = false;
                bool failFlag = false;

                while(starTotal < starMax)
                {
                    starEarned = false;
                    for (int i = 0; i < levels; i++)
                    {
                        // Try to grab the two-stars first
                        if (!starClaimed[i, 1] && starTotal >= starValues[i, 1])
                        {
                            starClaimed[i, 1] = true;
                            starTotal++;
                            levelsPlayed++;
                            
                            if (!starClaimed[i, 0])
                            {
                                starClaimed[i, 0] = true;
                                starTotal++;
                            }
                            starEarned = true;
                        }
                    }

                    // Preference is to the 2-star levels
                    if (!starEarned)
                    {
                        // Grab the 1-star least likely to be picked up with a two later on
                        int twoStarVal = 0;
                        int index = -1;

                        for (int i = 0; i < levels; i++)
                        {
                            if (!starClaimed[i, 0] && starTotal >= starValues[i, 0] && starValues[i, 1] > twoStarVal)
                            {
                                index = i;
                                twoStarVal = starValues[i, 1];
                            }
                        }

                        if (index != -1)
                        {
                            starClaimed[index, 0] = true;
                            starTotal++;
                            levelsPlayed++;
                            starEarned = true;
                        }
                        else
                        {
                            failFlag = true;
                            break;
                        }
                    }
                }

                string result = failFlag ? "Too Bad" : "" + levelsPlayed;

                fileOut.WriteLine("Case #" + (caseCount + 1) + ": " + result);
                Console.WriteLine("Case #" + (caseCount + 1) + " finished!");
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();
        }
    }
}
