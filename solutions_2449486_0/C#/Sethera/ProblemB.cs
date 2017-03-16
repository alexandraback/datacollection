using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam2013
{
    class ProblemB
    {
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader(new FileStream(@"test.txt", FileMode.Open)));

            int problemCount = int.Parse(Console.In.ReadLine());

            for (int i = 0; i < problemCount; i++)
            {
                solveB(i + 1);
            }

            Console.Out.Flush();
        }

        public static void solveB(int caseNumber)
        {
            String[] dims = Console.In.ReadLine().Split(' ');
            int N = int.Parse(dims[0]);
            int M = int.Parse(dims[1]);

            int[,] lawn = new int[N, M];

            SortedSet<int> lawnHeights = new SortedSet<int>();

            for (int n = 0; n < N; n++)
            {
                String[] lineParts = Console.In.ReadLine().Split(' ');
                for (int m = 0; m < M; m++)
                {
                    lawn[n, m] = int.Parse(lineParts[m]);
                    lawnHeights.Add(lawn[n, m]);
                }
            }

            bool possible = true;

            int[] lawnHeightsArray = lawnHeights.ToArray();

            for (int i = 0; i < lawnHeightsArray.Length - 1; i++)
            {
                if (!canGrowBackLawn(ref lawn, lawnHeightsArray[i], lawnHeightsArray[i + 1]))
                {
                    possible = false;
                    break;
                }
            }


            if (possible)
            {
                Console.Out.WriteLine("Case #" + caseNumber.ToString() + ": YES");
            }
            else
            {
                Console.Out.WriteLine("Case #" + caseNumber.ToString() + ": NO");
            }
        }


        public static bool canGrowBackLawn(ref int[,] lawn, int targetBladeHeight, int newBladeHeight)
        {
            int maxX = lawn.GetLength(0);
            int maxY = lawn.GetLength(1);

            bool[,] acceptable = new bool[maxX, maxY];

            for (int x = 0; x < maxX; x++)
            {
                for (int y = 0; y < maxY; y++)
                {
                    if (lawn[x, y] != targetBladeHeight)
                    {
                        acceptable[x, y] = true;
                    }
                }
            }



            for (int x = 0; x < maxX; x++)
            {
                bool rowPassed = true;

                for (int y = 0; y < maxY; y++)
                {
                    if (lawn[x, y] != targetBladeHeight)
                    {
                        rowPassed = false;
                        break;
                    }
                }

                if (rowPassed)
                {
                    for (int y = 0; y < maxY; y++)
                    {
                        acceptable[x, y] = true;
                    }
                }
            }



            for (int y = 0; y < maxY; y++)
            {
                bool colPassed = true;

                for (int x = 0; x < maxX; x++)
                {
                    if (lawn[x, y] != targetBladeHeight)
                    {
                        colPassed = false;
                        break;
                    }
                }

                if (colPassed)
                {
                    for (int x = 0; x < maxX; x++)
                    {
                        acceptable[x, y] = true;
                    }
                }
            }




            for (int x = 0; x < maxX; x++)
            {
                for (int y = 0; y < maxY; y++)
                {
                    if (!acceptable[x, y])
                    {
                        return false;
                    }
                }
            }

            for (int x = 0; x < maxX; x++)
            {
                for (int y = 0; y < maxY; y++)
                {
                    if (lawn[x, y] == targetBladeHeight)
                    {
                        lawn[x, y] = newBladeHeight;
                    }
                }
            }


            return true;
        }

    }
}
