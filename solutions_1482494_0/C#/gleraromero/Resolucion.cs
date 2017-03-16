using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2012._1B
{
    class Resolucion
    {
        public static void Resolver(string path)
        {
            StreamWriter escritor = new StreamWriter(string.Concat(path, "/", "current.out"));
            StreamReader lector = new StreamReader(string.Concat(path, "/", "current.in"));
            int casos = int.Parse(lector.ReadLine());
            int counter = 1;
            while (counter <= casos)
            {
                int levels = int.Parse(lector.ReadLine());
                int[][] starsPerLevel = new int[levels][];
                for (int i = 0; i < levels; ++i)
                {
                    starsPerLevel[i] = new int[2];
                    string[] starsReq = lector.ReadLine().Split(' ');
                    starsPerLevel[i][0] = int.Parse(starsReq[0]);
                    starsPerLevel[i][1] = int.Parse(starsReq[1]);
                }

                //Stuff
                int min = 0;
                int levelsCompleted = 0;
                int[] starsEarned = new int[levels];
                int totalStars = 0;
                for (int i = 0; i < levels; i++)
                    starsEarned[i] = 0;

                List<KeyValuePair<int, int>> lvlLeft = new List<KeyValuePair<int, int>>();
                for (int j = 0; j < levels; j++)
                {
                    if (starsPerLevel[j][1] <= totalStars)
                    {
                        if (starsEarned[j] == 0)
                        {
                            ++min;
                            starsEarned[j] = 2;
                            ++levelsCompleted;
                            totalStars += 2;
                        }
                    }
                    else
                    {
                        lvlLeft.Add(new KeyValuePair<int, int>(starsPerLevel[j][1],j));
                    }
                }
                lvlLeft.Sort(delegate(KeyValuePair<int, int> x, KeyValuePair<int, int> y) { return x.Key.CompareTo(y.Key); });;
                int prevCount = -1;
                while (lvlLeft.Count != 0 && prevCount != totalStars)
                {
                    prevCount = totalStars;
                    //remove 2-star
                    int range = 0;
                    for (int i = 0; i < lvlLeft.Count; i++)
                    {
                        if (lvlLeft[i].Key <= totalStars)
                        {
                            ++min;
                            if (starsEarned[lvlLeft[i].Value] == 0)
                                totalStars += 2;
                            else
                                totalStars++;

                            starsEarned[lvlLeft[i].Value] = 2;
                            ++levelsCompleted;
                            
                            ++range;
                        }
                        else
                            break;
                    }
                    if (range > 0)
                    {
                        lvlLeft.RemoveRange(0, range);
                    }

                    //remove 1-star
                    for (int i = lvlLeft.Count - 1; i >= 0; i--)
                    {
                        if (starsPerLevel[lvlLeft[i].Value][0] <= totalStars)
                        {
                            ++min;
                            starsEarned[lvlLeft[lvlLeft.Count - 1].Value] = 1;
                            totalStars += 1;
                            //lvlLeft.RemoveAt(lvlLeft.Count - 1);
                            break;
                        }
                    }
                }

                escritor.WriteLine(string.Format("Case #{0}: {1}", counter, lvlLeft.Count != 0 ? "Too Bad" : min.ToString()));
                ++counter;
            }
            lector.Close();
            escritor.Close();
        }

    }
}
