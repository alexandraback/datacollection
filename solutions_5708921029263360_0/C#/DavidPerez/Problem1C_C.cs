using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam2016Library
{
    public class Problem1C_C
    {
        public static string Run(string input)
        {
            StringBuilder output = new StringBuilder();
            string[] lines = input.Split('\n');

            int i = 0;
            int cases = int.Parse(lines[i++]);

            for (int c = 0; c < cases; c++)
            {
                string[] caseinput = lines[i++].Split(' ');
                string caseoutput = RunCase(int.Parse(caseinput[0]), int.Parse(caseinput[1]), int.Parse(caseinput[2]), int.Parse(caseinput[3]));
                output.Append("Case #" + (c + 1) + ": " + caseoutput);
            }

            return output.ToString();
        }

        private static string RunCase(int J, int P, int S, int K)
        {
            StringBuilder output = new StringBuilder();

            List<string> outfits = new List<string>();
            Dictionary<string, int> combinationJP = new Dictionary<string, int>();
            Dictionary<string, int> combinationJS = new Dictionary<string, int>();
            Dictionary<string, int> combinationSP = new Dictionary<string, int>();
            for (int p = 1; p <= P; p++)
            {
                for (int s = 1; s <= S; s++)
                {
                    for (int j=1; j<= J; j++)
                    {
                        if (!combinationJP.ContainsKey(j + "-" + p)) combinationJP.Add(j + "-" + p, 0);
                        if (!combinationJS.ContainsKey(j + "-" + s)) combinationJS.Add(j + "-" + s, 0);
                        if (!combinationSP.ContainsKey(s + "-" + p)) combinationSP.Add(s + "-" + p, 0);

                        if (combinationJP[j + "-" + p] < K &&
                            combinationJS[j + "-" + s] < K &&
                            combinationSP[s + "-" + p] < K )
                        {
                            outfits.Add(j + " " + p + " " + s);
                            combinationJP[j + "-" + p] += 1;
                            combinationJS[j + "-" + s] += 1;
                            combinationSP[s + "-" + p] += 1;
                        }
                    }
                }
            }

            output.AppendLine(outfits.Count.ToString());
            outfits.Sort();
            foreach (string of in outfits)
                output.AppendLine(of);

            return output.ToString();
        }
        
        

    }

}
