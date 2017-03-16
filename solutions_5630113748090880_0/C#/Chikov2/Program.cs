using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2
{
    class Program
    {
        private static bool finished(List<bool> l)
        {
            for (int i = 0; i < l.Count; i++)
            {
                if (!l[i]) return false;
            }

            return true;
        }

        static void Main(string[] args)
        {
            string inputPath = @"C:\Users\pchikov\Desktop\GoogleCodeJam2\input.txt";
            string outputPath = @"C:\Users\pchikov\Desktop\GoogleCodeJam2\output.txt";

            using (StreamWriter sw = File.CreateText(outputPath))
            {
                using (StreamReader sr = File.OpenText(inputPath))
                {
                    List<int> possibleHeights = new List<int>();
                    string numCases = sr.ReadLine().Trim();

                    for (int i = 1; i < Int32.Parse(numCases) + 1; i++)
                    {
                        int N = Int32.Parse(sr.ReadLine().Trim());
                        possibleHeights.Clear();

                        for (int m = 0; m < 2510; m++)
                            possibleHeights.Add(0);

                        for (int j = 0; j < 2 * N - 1; j++)
                        {
                            string line = sr.ReadLine().Trim();
                            char[] delimiterChars = { ' ' };

                            string[] num = line.Split(delimiterChars);

                            for (int k = 0; k < num.Length; k++)
                            {
                                int temp = Int32.Parse(num[k]);
                                possibleHeights[temp] = possibleHeights[temp] + 1;
                            }
                        }

                        List<int> vectorResult = new List<int>();
                        for (int m = 0; m < possibleHeights.Count; m++)
                        {
                            if (possibleHeights[m] % 2 != 0)
                                vectorResult.Add(m);
                        }

                        vectorResult.Sort();
                        string result = "";

                        if (vectorResult.Count == N)
                        {
                            for (int o = 0; o < vectorResult.Count; o++)
                                result += vectorResult[o] + " ";
                            result = result.Trim();
                        }
                        else
                            result = "SHIT!";

                        sw.WriteLine("Case #" + i + ": " + result);
                    }
                }
            }
        }
    }
}
