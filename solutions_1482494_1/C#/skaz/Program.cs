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
            int moves = 0;
            int stars = 0;

            int numLevels = int.Parse(line[0]);
            List<Record> levelReqs = new List<Record>(numLevels);

            for (int i = 0; i < numLevels; i++)
            {
                line = Console.ReadLine().Split(' ');
                Record a = new Record();
                a.a = int.Parse(line[0]);
                a.b = int.Parse(line[1]);
                a.c = false;
                levelReqs.Add(a);
            }

            levelReqs = levelReqs.OrderByDescending(i => i.b).ThenByDescending(i => i.a).ToList();

            bool found = false;
            bool overallFound = true;
            while (levelReqs.Count() > 0)
            {
                overallFound = true;
                found = false;
                
                moves++;

                for (int i = 0; i < levelReqs.Count(); i++)
                {
                    // Any you can do right off?
                    if (!levelReqs[i].c && levelReqs[i].b <= stars)
                    {
                        found = true;
                        levelReqs.RemoveAt(i);
                        stars+=2;
                        break;
                    }
                }

                if (!found)
                {
                    for (int i = 0; i < levelReqs.Count(); i++)
                    {
                        // Any partially complete?
                        if (levelReqs[i].c && levelReqs[i].b <= stars)
                        {
                            found = true;
                            levelReqs.RemoveAt(i);
                            stars++;
                            break;
                        }
                    }
                    // If not, find the index of the biggest gap and do that one?
                    if(!found)
                    {
                        int? gap = null;
                        int index = -1;

                        for (int i = 0; i < levelReqs.Count(); i++)
                        {
                            // Find the one with the biggest gap
                            if (!levelReqs[i].c && levelReqs[i].a <= stars)
                            {
                                if (!gap.HasValue || gap.Value < levelReqs[i].b - levelReqs[i].a)
                                {
                                    gap = levelReqs[i].b - levelReqs[i].a;
                                    index = i;
                                }
                            }

                            if (gap.HasValue)
                            {
                                found = true;
                                levelReqs[index].c = true;
                                stars++;

                                break;
                            }
                        }
                    }
                        
                }

                if (!found)
                {
                    overallFound = false;
                    break;
                }
            }

            





            

            Console.WriteLine("Case #{0}: {1}", caseNumber, (overallFound ? moves.ToString() : "Too Bad"));
        }

        public class Record
        {
            public int a;
            public int b;
            public bool c;
        }
    }
}
