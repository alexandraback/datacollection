using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    class Program
    {
        static string Expand(string seed, string plant)
        {
            string expandedPlant = "";
            foreach (char letter in plant)
            {
                if (letter == 'L')
                {
                    expandedPlant += seed;
                }
                else
                {
                    expandedPlant += new String('G', seed.Length);
                }
            }

            return expandedPlant;
        }

        static List<string> MakePossible(int size)
        {
            List<string> possible = new List<string>();

            if (size > 1)
            {
                var subPossible = MakePossible(size - 1);
                foreach (var subString in subPossible)
                {
                    possible.Add("L" + subString);
                    possible.Add("G" + subString);
                }
            }
            else 
            {
                possible.Add("L");
                possible.Add("G");
            }

            return possible;
        }

        static void Main(string[] args)
        {
            //var possible = MakePossible(3);
            //foreach (string seed in possible.OrderBy(x => x).Reverse())
            //{
            //    string secondTier = Expand(seed, seed);
            //    //Console.WriteLine(seed + ": " + secondTier);
            //    string thirdTier = Expand(seed, secondTier);
            //    //Console.WriteLine(seed + ": " + thirdTier);
            //    string fourthTier = Expand(seed, thirdTier);
            //    Console.WriteLine(seed + ": " + fourthTier);
            //}
            //return;

            string outputFrame = "Case #{0}: {1}";

            int caseCount = int.Parse(Console.ReadLine());
            for (int caseIdx = 1; caseIdx <= caseCount; caseIdx++)
            {
                string[] kcs = Console.ReadLine().Split(' ');
                int initialCount = int.Parse(kcs[0]);
                int complexity = int.Parse(kcs[1]);
                int unpaidGradStudents = int.Parse(kcs[2]);

                long[] locations;
                if (!CanVerifyGold(initialCount, complexity, unpaidGradStudents, out locations))
                {
                    Console.WriteLine(String.Format(outputFrame, caseIdx, "IMPOSSIBLE"));
                }
                else
                {
                    Console.WriteLine(String.Format(outputFrame, caseIdx, String.Join(" ", locations)));
                }
            }
        }

        static bool CanVerifyGold(int initialCount, int complexity, int unpaidGradStudents, out long[] locations)
        {
            locations = null;

            #region Degenerate Cases
            if (unpaidGradStudents == 0)
                return false;

            if (complexity == 1)
            {
                if (initialCount == unpaidGradStudents)
                {
                    List<long> locList = new List<long>();
                    for (int loc = 1; loc <= initialCount; loc++)
                        locList.Add(loc);

                    locations = locList.ToArray();
                    return true;
                }
                else
                {
                    return false;
                }
            }

            if (initialCount == 1)
            {
                locations = new long[] { 1 };
                return true;
            }
            else if (initialCount == 2)
            {
                locations = new long[] { 2 };
                return true;
            }
            else if (initialCount == 3)
            {
                if (complexity == 2)
                {
                    if (unpaidGradStudents < 2)
                        return false;

                    locations = new long[] { 2, 6 };
                    return true;
                }
                else 
                {
                    locations = new long[] { 2 };
                    return true;
                }
            }
            #endregion

            //Sorta degenerate-ish case.
            if (initialCount == unpaidGradStudents)
            {
                long tileSpan = 1;
                for (int compScale = 2; compScale <= complexity; compScale++)
                    tileSpan *= initialCount;

                List<long> locList = new List<long>();
                for (int tileBlock = 0; tileBlock < initialCount; tileBlock++)
                {
                    locList.Add((tileBlock * tileSpan) + 1);
                }

                locations = locList.ToArray();
                return true;
            }
            else 
            {
                //Start with #2, knocks out possibilities for first two tiles. Leaves N - 2 subset embedded. Complexity same?
                List<long> locList = new List<long>();
                locList.Add(2);

                long[] embeddedLocs;
                bool canVerifySubspace = CanVerifyGold(initialCount - 2, complexity, unpaidGradStudents - 1, out embeddedLocs);

                if (!canVerifySubspace)
                    return false;

                EmbedLocations(embeddedLocs, complexity, initialCount, initialCount - 2);
                locList.AddRange(embeddedLocs);

                locations = locList.ToArray();
                return true;
            }
        }

        static void EmbedLocations(long[] embeddedLocs, int complexity, int spaceSize, int subSpaceSize)
        {
            long fullSize = 1;
            long subSize = 1;
            for (int i = 1; i <= complexity; i++)
            {
                fullSize *= spaceSize;
                subSize *= subSpaceSize;
            }

            long subSkipSize = (fullSize / spaceSize) - (subSize / subSpaceSize);

            long embeddedSpaceBounds = subSpaceSize;
            for (int i = 1; i < complexity; i++)
                embeddedSpaceBounds *= spaceSize;

            long startOffset = fullSize - embeddedSpaceBounds;

            for (int locIndex = 0; locIndex < embeddedLocs.Length; locIndex++)
            {
                long loc = embeddedLocs[locIndex];
                long newLoc = startOffset;

                long skip = (loc / (subSize / subSpaceSize)) + 1;
                newLoc += skip * subSkipSize;

                embeddedLocs[locIndex] = newLoc + loc + 2;
            }
        }
    }
}
