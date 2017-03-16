using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace GoogleJam2016.Practice._2016._1B
{
    class B_CloseMatch : IGoogleCodeJam
    {
        public override void Compute(StreamReader reader, StreamWriter writer)
        {
            int t = Convert.ToInt32(reader.ReadLine());

            for (int i = 1; i <= t; i++)
            {
                string[] x = reader.ReadLine().Split(' ');
                string c = x[0];
                string j = x[1];

                writer.WriteLine($"Case #{i}: {Solve(CreateRegex(c), CreateRegex(j), c.Length, j.Length)}");
            }
        }

        private Regex CreateRegex(string x)
        {
            bool leading = true;
            string r = "^";

            foreach (var c in x)
            {
                if (c == '?' && leading)
                {
                    r += "[0-9]?";
                }
                else if (c == '?' && !leading)
                {
                    r += "[0-9]";
                }
                else if (c != '?')
                {
                    leading = false;
                    r += c;
                }
            }

            return new Regex(r + "$", RegexOptions.Compiled);
        }


        private string Solve(Regex regexC, Regex regexJ, int c, int j)
        {
            int bestC = Int32.MaxValue / 2;
            int bestJ = Int32.MinValue / 2;
            for (int currentC = 0; currentC < Math.Pow(10, c); currentC++)
            {
                if(!regexC.IsMatch(currentC.ToString("D" + c))) continue;
                for (int currentJ = 0; currentJ < Math.Pow(10, j); currentJ++)
                {
                    if(!regexJ.IsMatch(currentJ.ToString("D" + j))) continue;
                    if (Math.Abs(currentC - currentJ) < Math.Abs(bestC - bestJ))
                    {
                        bestC = currentC;
                        bestJ = currentJ;
                    } else if (Math.Abs(currentC - currentJ) == Math.Abs(bestC - bestJ))
                    {
                        if (currentC < bestC)
                        {
                            bestC = currentC;
                            bestJ = currentJ;
                        }
                        else if (currentC == bestC && currentJ < bestJ)
                        {
                            bestC = currentC;
                            bestJ = currentJ;
                        }
                    }
                }
            }

            return $"{bestC.ToString("D" + c)} {bestJ.ToString("D" + j)}";
        }

    }
}
