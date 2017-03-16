using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;
using System.Drawing;

namespace CodeJam.Problems
{
    public class ProblemB : BaseProblem
    {
        protected override object SolveCase(StreamReader reader)
        {
            int N = Int32.Parse(reader.ReadLine());

            List<int[]> levels = new List<int[]>();
            List<int[]> singleGameLevels = new List<int[]>();

            for (int n = 0; n < N; n++)
            {
                levels.Add(reader.ReadLine().ConvertInputToIntArray());
            }

            int stars = 0;
            int games = 0;
            bool go = true;
            
            while (true)
            {
                // Find levels where I can get 2 stars
                int i = levels.FindIndex(x => x[0] <= stars && x[1] <= stars);
                if (i >= 0)
                {
                    stars += 2;
                    levels.RemoveAt(i);
                    games++;
                    continue;
                }

                // Find single star levels
                i = singleGameLevels.FindIndex(x => x[1] <= stars);
                if (i >= 0)
                {
                    stars += 1;
                    singleGameLevels.RemoveAt(i);
                    games++;
                    continue;
                }

                // Find level where I meet the first star and the largest second star
                int spread = 0;
                i = -1;
                for (int l = 0; l < levels.Count; l++)
                {
                    if (levels[l][0] <= stars && levels[l][1] - levels[l][0] > spread)
                    {
                        spread = levels[l][1] - levels[l][0];
                        i = l;
                    }
                }
                if (i >= 0)
                {
                    stars += 1;
                    singleGameLevels.Add(levels[i]);
                    levels.RemoveAt(i);
                    games++;
                    continue;
                }

                if (levels.Count > 0 || singleGameLevels.Count > 0)
                    games = -1;

                break;
            }
                
            return (games == -1) ? ("Too Bad") : (games.ToString());
        }
    }
}
