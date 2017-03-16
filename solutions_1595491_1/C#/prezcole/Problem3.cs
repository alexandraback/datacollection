using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Program
    {
        private const string INPUT = "B-large.in";
        private const string OUTPUT = "B-large.out";

        static void Main(string[] args)
        {


            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            for (int i = 1; i < input.Length; i++)
            {
                output.Add("Case #" + i + ": " + GetResult(input[i]));
                Console.WriteLine(i + " of " + input.Length);
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);

        }

        private static int GetResult(string inputLine)
        {
            string[] inputLineSplit = inputLine.Split();
            int surprising = -1;
            int bestScoreMin = -1;
            var scores = new List<int>();
            for (int i = 0; i < inputLineSplit.Length; i++)
            {
                if (i == 0) continue;
                if (i == 1) surprising = Convert.ToInt32(inputLineSplit[i]);
                else if (i == 2) bestScoreMin = Convert.ToInt32(inputLineSplit[i]);
                else scores.Add(Convert.ToInt32(inputLineSplit[i]));
            }

            int counter = 0;
            foreach (var score in scores.OrderBy(n => n))
            {
                if (score == 0)
                {
                    if (bestScoreMin == 0) counter++;
                    continue;
                }

                switch (score % 3)
                {
                    case 0:
                    {
                        if ((score / 3) >= bestScoreMin) counter++;
                        else if (surprising > 0 && (score / 3 + 1) >= bestScoreMin)
                        {
                            surprising--;
                            counter++;
                        }
                        break;
                    }
                    case 1:
                    {
                        if ((score / 3 + 1) >= bestScoreMin) counter++;
                        break;
                    }
                    case 2:
                    {
                        if ((score / 3 + 1) >= bestScoreMin) counter++;
                        else if (surprising > 0 && (score / 3 + 2) >= bestScoreMin)
                        {
                            surprising--;
                            counter++;
                        }
                        break;
                    }
                    default:
                    {
                        throw new Exception();
                    }
                }
            }
            return counter;
        }
    }
}
