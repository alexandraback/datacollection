using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class DancingWithGooglers
    {
        public static void Main()
        {
            string InputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\DancingWithGooglers\\in.txt";
            string OutputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\DancingWithGooglers\\out.txt";

            string FileOutput = "";
            string FileInput = System.IO.File.ReadAllText(InputPath);

            string[] InputLines = FileInput.Split(new string[] { "\r", "\n", "\r\n" }, StringSplitOptions.RemoveEmptyEntries);

            int Cases = Int32.Parse(InputLines[0]);
            for (int x = 1; x <= Cases; x++)
            {
                if (x != 1)
                    FileOutput += "\n";

                string[] Params = InputLines[x].Split(' ');
                int n = Int32.Parse(Params[0]);
                int s = Int32.Parse(Params[1]);
                int p = Int32.Parse(Params[2]);

                List<int> totals = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    totals.Add(Int32.Parse(Params[3 + i]));
                }
                   
                FileOutput += "Case #" + x + ": " + GetResult(s, p, totals);
            }


            System.IO.File.WriteAllText(OutputPath, FileOutput);

        }

        public static int GetResult(int suprising, int p, List<int> totals)
        {
            bool[] Possible = new bool[totals.Count];
            bool[] PossibleIfSuprising = new bool[totals.Count];

            int performer = 0;
            foreach (int total in totals)
            {
                for (int first = p; first <= 10; first++)
                {
                    for (int dSecond = -2; dSecond <= 2; dSecond++)
                    {
                        for (int dThird = -2; dThird <= 2; dThird++)
                        {
                            if ((first + (first + dSecond) + (first + dThird)) == total && (first>=0) && ((first+dSecond)>=0) && ((first+dThird)>=0))
                            {
                                if (Math.Abs(dSecond) == 2 || Math.Abs(dThird) == 2)
                                    PossibleIfSuprising[performer] = true;
                                else
                                {
                                    Possible[performer] = true;
                                    goto FoundSolution;
                                }
                            }

                        }
                    }

                }
                FoundSolution:
                performer++;
            }

            int solutions = 0;
            for (int x = 0; x < totals.Count; x++)
            {
                if (Possible[x])
                    solutions++;
                else if (PossibleIfSuprising[x] && suprising > 0)
                {
                    suprising--;
                    solutions++;
                }
            }

            return solutions;

        }
    }
}
