using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ.GCJ2012.Round1A
{
    class B
    {
        private static int INF = 1000000;
        private static int GetNextPossibleLevel(int currentStars, List<List<int>> starsNeeded)
        {
            bool gameOver = true;
            for (int i = 0; i < starsNeeded.Count; ++i)
            {
                if (starsNeeded[i][1] != INF)
                    gameOver = false;
            }
            if (gameOver)
                return -2;

            for (int i = 0; i < starsNeeded.Count; ++i)
            {
                if (starsNeeded[i][1] <= currentStars)
                    return i;
            }
            for (int i = 0; i < starsNeeded.Count; ++i)
            {
                if (starsNeeded[i][0] <= currentStars)
                    return i;
            }

            return -1;
        }

        public static void Main()
        {
            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\B-small-attempt0.in");
            var outputStream = new StreamWriter(@"C:\Users\asaraswat\Downloads\B-small-attempt0.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = GetInt();
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                int n = GetInt();

                List<List<int>> starsNeeded = new List<List<int>>();

                for (int i = 0; i < n; ++i)
                {
                    starsNeeded.Add(GetListOfInt());
                }

                int currentStars = 0;

                int levelsPlayed = 0;

                while (true)
                {
                    int nextPossibleLevel = GetNextPossibleLevel(currentStars, starsNeeded);
                    if (nextPossibleLevel == -2)
                        break;
                    if (nextPossibleLevel == -1)
                    {
                        levelsPlayed = 0;
                        break;
                    }
                    if (starsNeeded[nextPossibleLevel][1] <= currentStars)
                    {
                        if (starsNeeded[nextPossibleLevel][0] == INF)
                            currentStars++;
                        else
                            currentStars += 2;
                        levelsPlayed++;
                        starsNeeded[nextPossibleLevel][1] = INF;
                    }
                    else
                    {
                        currentStars++;
                        levelsPlayed++;
                        starsNeeded[nextPossibleLevel][0] = INF;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", cs, levelsPlayed > 0 ? levelsPlayed.ToString() : "Too Bad");
            }

            inputStream.Close();
            outputStream.Close();
        }

        private static int GetInt()
        {
            string p = Console.ReadLine();
            return Convert.ToInt32(p);
        }

        private static List<int> GetListOfInt(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => int.Parse(t)).ToList();
        }
    }
}
