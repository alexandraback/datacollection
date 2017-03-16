using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamRound1AB
{
    class Program
    {
        static void Main(string[] args)
        {
            int numCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                int numLevels = int.Parse(Console.ReadLine());

                Tuple<int, int>[] levels = new Tuple<int, int>[numLevels];

                for (int j = 0; j < numLevels; j++)
                {
                    int[] levelData = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    levels[j] = Tuple.Create(levelData[0], levelData[1]);
                }

                Array.Sort(levels, (l1, l2) =>
                {
                    int r1 = -l1.Item2.CompareTo(l2.Item2);

                    if (r1 == 0)
                    {
                        return -l1.Item1.CompareTo(l2.Item1);
                    }

                    return r1;
                });

                int solved = Solve(levels);
                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, solved == -1 ? "Too Bad" : solved.ToString()));
            }
        }

        private static int Solve(Tuple<int, int>[] levels)
        {
            int numStars = 0;

            int games = 0;

            int[] starsCollected = new int[levels.Length];

            while (numStars < levels.Length * 2)
            {
                bool tooBad = true;

                for (int i = 0; i < levels.Length; i++)
                {
                    if (starsCollected[i] == 0 && numStars >= levels[i].Item2)
                    {
                        games++;
                        numStars += 2;
                        starsCollected[i] = 2;
                        tooBad = false;
                        break;
                    }
                }

                if (tooBad)
                {
                    for (int i = 0; i < levels.Length; i++)
                    {
                        if (starsCollected[i] == 1 && numStars >= levels[i].Item2)
                        {
                            games++;
                            numStars += 1;
                            starsCollected[i] = 2;
                            tooBad = false;
                            break;
                        }
                    }
                }

                if (tooBad)
                {
                    for (int i = 0; i < levels.Length; i++)
                    {
                        if (starsCollected[i] == 0 && numStars >= levels[i].Item1)
                        {
                            games++;
                            numStars += 1;
                            starsCollected[i] = 1;
                            tooBad = false;
                            break;
                        }
                    }
                }

                if (tooBad)
                {
                    return -1;
                }
            }

            return games;
        }
    }
}
