﻿using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {
        int v;
        Dictionary<char, int> keysMap;
        char[] keys;
        char[] target;
        int commonChars;

        decimal getOdds(int pos, decimal odds, string cumul)
        {
            decimal resodds = 0;
         
            if (pos == v)
            {
                int count = 0;
                for (int i = 0; i <= cumul.Length - target.Length; i++)
                {
                    bool ok = true;
                    for (int j = 0; j < target.Length; j++)
                    {
                        if (target[j] != cumul[i + j])
                        {
                            ok = false;
                            continue;
                        }
                    }
                    if (ok)
                        count++;
                }
                return count * odds;
            }
            else
            {
                pos += 1;
                odds /= keys.Length;

                for (int i = 0; i < keys.Length; i++)
                {
                    var newCumul = cumul + keys[i];
                    resodds += getOdds(pos, odds, newCumul);
                }
            }
            return resodds;
        }

        string solveCase(string[][] input)
        {
            v = Convert.ToInt32(input[0][2]);
            keys = input[1][0].ToArray();
            string targetStr = input[2][0];
            target = input[2][0].ToArray();
            keysMap = new Dictionary<char, int>();
            for (int i = 0; i < keys.Length; i++)
            {
                char key = keys[i];
                if (keysMap.ContainsKey(key))
                    keysMap[key] = keysMap[key] + 1;
                else
                    keysMap[key] = 1;
            }

            int maxFits = 1;
            if (v < target.Length)
                return "0.0";
            if (v > target.Length)
            {
                int initialLength = target.Length;
                commonChars = 0;
                while (commonChars < (initialLength - 1) && targetStr.Substring(targetStr.Length - 1 - commonChars) == targetStr.Substring(0, commonChars + 1))
                {
                    commonChars++;
                }
                int aditionaTargetLength = initialLength - commonChars;
                maxFits = 1 + (v - target.Length) / aditionaTargetLength;
            }

            if (v < target.Length)
                return "0.0";
            for (int i = 0; i < target.Length; i++)
            {
                char targetKey = target[i];
                if (!keysMap.ContainsKey(targetKey))
                    return "0.0";
            }

            decimal odds = getOdds(0, 1, "");

           // return maxFits.ToString() + "-" + odds.ToString();
            return Math.Round(maxFits -  odds, 7, MidpointRounding.AwayFromZero).ToString();
        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            StringBuilder sb = new StringBuilder();
            int nbCases = Convert.ToInt32(lines[0]);
            int iLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                //Console.WriteLine("Case: " + i);

                string[] lineParts = lines[iLine].Split(' ');

                int caseLines = 2;
                string[][] caseInput = new string[caseLines + 1][];
                caseInput[0] = lineParts;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    caseInput[caseLine + 1] = lineParts;
                }
                string result = solveCase(caseInput);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
                iLine++;
            }
            return sb.ToString();
        }
    }

}

