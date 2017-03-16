using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CodeJam;

namespace _2012_Round1A_B
{
    class Program
    {
        private class LevelStarCount
        {
            public LevelStarCount (short[] times)
            {
                oneStar = times[0];
                twoStar = times[1];
                oneComplete = false;
                twoComplete = false;
            }

            public bool CanGetTwoStars ()
            {
                return oneComplete == false && twoComplete == false;
            }

            public bool IsOneComplete ()
            {
                return oneComplete;
            }

            public bool IsTwoComplete ()
            {
                return twoComplete;
            }

            public void CompleteOne ()
            {
                oneComplete = true;
            }

            public void CompleteTwo ()
            {
                twoComplete = true;
                CompleteOne();
            }

            public short GetOneStarCount ()
            {
                return oneStar;
            }

            public short GetTwoStarCount ()
            {
                return twoStar;
            }

            private short oneStar;
            private short twoStar;
            private bool oneComplete;
            private bool twoComplete;
        }

        static void Main (string[] args)
        {
            string fileName;

            // Retrieve the filename for the input file.
            if (args == null || args.Length == 0)
            {
                Console.WriteLine("Enter the file name for the input file.");
                fileName = Console.ReadLine();
            }
            else
            {
                fileName = args[0];
            }

            // Try and solve the problem!
            try
            {
                using (CodeJamHelper jam = new CodeJamHelper(fileName))
                {
                    short numberOfInputs = jam.ReadLineInt16();

                    while (numberOfInputs-- > 0)
                    {
                        short numberOfLevels = jam.ReadLineInt16();
                        LevelStarCount[] starsOfLevels = new LevelStarCount[numberOfLevels];
                        short starCount = 0;
                        short levelCount = 0;

                        for (short i = 0; i < numberOfLevels; i++)
                        {
                            starsOfLevels[i] = new LevelStarCount(jam.ReadInt16Array());
                        }

                        // Now we have all level times.  Cycle through to find most efficient way to complete all levels with two stars.
                        bool progress = true;

                        while (progress)
                        {
                            progress = false;

                            // See if there's a two-star level we can grab.
                            for (short i = 0; i < numberOfLevels; i++)
                            {
                                if (starsOfLevels[i].CanGetTwoStars() && starsOfLevels[i].GetTwoStarCount() <= starCount)
                                {
                                    starCount += 2;
                                    levelCount++;
                                    progress = true;
                                    starsOfLevels[i].CompleteTwo();
                                }
                            }

                            if (progress == false)
                            {
                                // Complete a two-star level for 1 star
                                for (short i = 0; i < numberOfLevels; i++)
                                {
                                    if (starsOfLevels[i].IsTwoComplete() == false && starsOfLevels[i].GetTwoStarCount() <= starCount)
                                    {
                                        starCount++;
                                        levelCount++;
                                        progress = true;
                                        starsOfLevels[i].CompleteTwo();
                                        break; // Make sure we don't accidentally capture too many 1-star levels
                                    }
                                }
                            }

                            if (progress == false)
                            {
                                short locationOfBest = -1;
                                short highestStarCount = -1;

                                // See if there's a one-star level we can grab.
                                for (short i = 0; i < numberOfLevels; i++)
                                {
                                    if (starsOfLevels[i].IsOneComplete() == false && 
                                        starsOfLevels[i].GetOneStarCount() <= starCount &&
                                        starsOfLevels[i].GetTwoStarCount() > highestStarCount)
                                    {
                                        locationOfBest = i;
                                        highestStarCount = starsOfLevels[i].GetTwoStarCount();
                                    }
                                }

                                if (locationOfBest != -1)
                                {
                                    starCount++;
                                    levelCount++;
                                    progress = true;
                                    starsOfLevels[locationOfBest].CompleteOne();
                                }
                            }
                        }

                        // See if we failed or succeeded.
                        for (short i = 0; i < numberOfLevels; i++)
                        {
                            if (starsOfLevels[i].IsTwoComplete() == false)
                            {
                                progress = true;
                                break;
                            }
                        }

                        if (progress == false)
                        {
                            jam.WriteInt16(levelCount);
                        }
                        else
                        {
                            jam.WriteLine("Too Bad");
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.WriteLine("Complete!");
            Console.ReadLine();
        }
    }
}
