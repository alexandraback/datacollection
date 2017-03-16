using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2012.Qualification
{
    class ProblemB
    {       
        enum Surprising
        {
            NotSurprising,
            Either,
            Surprising
        }

        public static string Solve(string[] input)
        {
            StringBuilder output = new StringBuilder();
            for (int i = 1; i < input.Length; i++)
            {
                string[] z = input[i].Split(' ');
                int N = int.Parse(z[0]);
                int S = int.Parse(z[1]);
                int p = int.Parse(z[2]);
                int[] g = new int[z.Length - 3];
                for (int j = 3; j < z.Length; j++)
                    g[j - 3] = int.Parse(z[j]);

                bool[][] possibleStates = new bool[g.Length][];
                for (int j = 0; j < g.Length; j++)
                {
                    possibleStates[j] = new bool[4];
                    int[] sub = { 0, 1, 2, 2, 3, 4 };

                    for (int k = 0; k < sub.Length; k++)
                    {
                        if (g[j] - sub[k] >= 0 && (g[j] - sub[k]) % 3 == 0)
                        {
                            switch (k)
                            {
                                case 0:
                                    possibleStates[j][g[j] / 3 >= p ? 2 : 0] = true;
                                    break;
                                case 1:
                                    possibleStates[j][(g[j] - 1) / 3 + 1 >= p ? 2 : 0] = true;
                                    break;
                                case 2:
                                    possibleStates[j][(g[j] - 2) / 3 + 2 >= p ? 3 : 1] = true;
                                    break;
                                case 3:
                                    possibleStates[j][(g[j] - 2) / 3 + 1 >= p ? 2 : 0] = true;
                                    break;
                                case 4:
                                    possibleStates[j][(g[j] - 3) / 3 + 2 >= p ? 3 : 1] = true;
                                    break;
                                case 5:
                                    possibleStates[j][(g[j] - 4) / 3 + 2 >= p ? 3 : 1] = true;
                                    break;
                            }
                        }
                    }
                }

                int high = 0;
                int surprises = 0;
                int[] states = new int[g.Length];

                for (int j = 0; j < g.Length; j++)
                {
                    if (possibleStates[j][2])
                    {
                        states[j] = 2;
                        high++;
                    }
                    else if (possibleStates[j][3])
                    {
                        states[j] = 3;
                        high++;
                        surprises++;
                    }
                    else if (possibleStates[j][0])
                    {
                        states[j] = 0;
                    }
                    else if (possibleStates[j][1])
                    {
                        states[j] = 1;
                        surprises++;
                    }
                }

                if (surprises < S)
                {
                    for (int j = 0; j < g.Length; j++)
                    {
                        if (surprises < S && states[j] == 2 && possibleStates[j][3])
                        {
                            states[j] = 3;
                            surprises++;
                        }
                        else if (surprises < S && states[j] == 0 && possibleStates[j][1])
                        {
                            states[j] = 1;
                            surprises++;
                        }
                    }
                }

                if (surprises < S)
                {
                    for (int j = 0; j < g.Length; j++)
                    {
                        if (surprises < S && states[j] == 2 && possibleStates[j][1])
                        {
                            states[j] = 1;
                            surprises++;
                            high--;
                        }
                    }
                }

                if (surprises > S)
                {
                    for (int j = 0; j < g.Length; j++)
                    {
                        if (surprises > S && states[j] == 3 && possibleStates[j][0])
                        {
                            states[j] = 0;
                            high--;
                            surprises--;
                        }
                    }
                }

                output.Append("Case #" + i + ": " + high + System.Environment.NewLine);
            }
            return output.ToString();
        }
    }
}
