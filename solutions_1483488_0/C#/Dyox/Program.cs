using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2012
{
    public class Program
    {
        static long Factoriel(long n)
        {
            return n > 1 ? n * Factoriel(n - 1) : 1;
        }  

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("C:\\CodeJam2012\\C\\C-small-attempt0.in");
            string output = "";
            long result;
            int testCases = int.Parse(input[0]);
            for (int i = 1; i <= testCases; i++)
            {
                result = 0;
                string[] line = input[i].Split(' ');
                int A = int.Parse(line[0]);
                int B = int.Parse(line[1]);
                int numOfDigits = A.ToString().Length;
                int[] resultTemp = new int[numOfDigits];
                List<int> nAllStates = new List<int>();
                //int[] nAllStates = new int[numOfDigits];
                for (int n = A; n <= B; n++)
                {
                    // nAllStates
                    for (int j = 0; j < numOfDigits; j++)
                    {
                        string left = n.ToString().Substring(0, j);
                        string right = n.ToString().Substring(j, numOfDigits - j);
                        int state = int.Parse(right + left);
                        if (!nAllStates.Contains(state) && (state >= A) && (state <= B))
                            nAllStates.Add(state);
                    }
                    resultTemp[nAllStates.Count - 1]++;
                    nAllStates.Clear();
                }
                for (int j = 1; j < numOfDigits; j++)
                {
                    result = result + (resultTemp[j] / (j + 1)) * (Factoriel(j + 1) / (Factoriel(2) * Factoriel(j + 1 - 2)));
                }
                output += "Case #" + i + ": " + result + Environment.NewLine;
            }
            File.WriteAllText("C:\\CodeJam2012\\C\\C-small.out", output);
        }

    }
}
