using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamManager
{


    class B12012 : SolutionBase, IComparer<KeyValuePair<int,int>>
    {
        List<KeyValuePair<int, int>> sorted;
        public override void ProcessOne(int processNumber, System.IO.StreamReader input, System.IO.StreamWriter output)
        {
            int L = int.Parse(input.ReadLine());
            int[][] data = new int[L][];
           sorted = new List<KeyValuePair<int, int>>(L);
            for (int i = 0; i < L; i++)
            {
                data[i] = base.ReadLineAsIntTable(input);
                sorted.Add(new KeyValuePair<int, int>(i, data[i][1]));
            }
            sorted.Sort(this);

            
            int stars = 0;
            int[] result = new int[L];
            bool done = false;
            int minGames = 0;
            do
            {
              // finish all avaliable levels at 2 stars
                bool progres = false;
                for (int i = 0; i < L; i++)
                {
                    if (result[i] < 2 && data[i][1] <= stars)
                    {
                        stars += 2 - result[i];
                        result[i] = 2;
                        minGames++;
                        progres = true;
                    }
                }
                if (AllLevels(result))
                {
                    done = true; 
                    break;
                }
                if (progres) continue;
              // finish some levels at 1 start
              // find min stars need to finish lvl at 2
                int minStars = int.MaxValue;
                for (int i = 0; i < L; i++)
                {
                    if (result[i] < 2)
                    {
                        minStars = Math.Min(minStars, data[i][1]);
                    }
                }
                minStars -= stars;
                if (GainStarsFromRank1(result, data, stars, minStars))
                {
                    stars += minStars;
                    minGames += minStars;
                }
                else
                {
                    done = true; // TOO BAD
                    minGames = 0;
                }
                //gain stars from 1rank lvl

            } while (!done);

            if (minGames > 0)
            {
                base.StoreResults(output, processNumber, minGames);
            }
            else
            {
                base.StoreResults(output, processNumber, "Too Bad");
            }
        }

        bool AllLevels(int[] result)
        {
            foreach (int i in result)
            {
                if (i != 2) return false;
            }
            return true;
        }

        bool GainStarsFromRank1(int[] result, int[][] data,int currentStars, int toGain)
        {

            bool progres;

            do
            {
                 progres = false;
                foreach (KeyValuePair<int, int> k in sorted)
                {
                    if (result[k.Key] == 0 && data[k.Key][0] <= currentStars)
                    {
                        result[k.Key] = 1;
                        currentStars++;
                        toGain--;
                        progres = true;
                        break;
                    }
                }

            } while (progres && toGain > 0);

            return (toGain == 0);
        }

        public int Compare(KeyValuePair<int, int> x, KeyValuePair<int, int> y)
        {
            return y.Value - x.Value;
        }
    }
}
