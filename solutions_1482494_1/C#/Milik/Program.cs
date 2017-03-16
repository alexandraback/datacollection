using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1AP2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("input.txt").Split('\n');
            String output = "";

            int line = 1;

            for (int i = 0; i < Int32.Parse(input[0]); i++)
            {
                int limit = Int32.Parse(input[line++]);
                int[,] state = new int[limit, 4];

                for (int c = 0; c < limit; c++)
                {
                    state[c, 0] = int.Parse(input[line].Split(' ')[0]);
                    state[c, 1] = int.Parse(input[line].Split(' ')[1]);
                    state[c, 2] = 0; state[c, 3] = 0;
                    line++;
                }

                int curentStar = 0;
                int counter = 0;
                Console.WriteLine("+++++++++++++++++++++++++++++++++");

                while (true)
                {                    
                    int bestAdvance = -1;
                    int isTwoStar = 0;
                    int isBigTwoStar = 2;
                    int NextStar = -1;

                    for (int c = 0; c < limit; c++)
                    {
                        if (isTwoStar == 0)
                        {
                            if ((state[c, 0] <= curentStar) && (state[c, 2] == 0))
                            {
                                if (NextStar < state[c, 1])
                                {
                                    bestAdvance = c;
                                    NextStar = state[c, 1];
                                }
                            }
                        }

                        if ((state[c, 1] <= curentStar) && (state[c, 3] == 0))
                        {
                            if (isBigTwoStar > state[c, 2])
                            {
                                bestAdvance = c;
                                isTwoStar = 1;
                                isBigTwoStar = state[c, 2];
                            }
                        }
                    }
                    if (bestAdvance >= 0)
                    {
                        counter++;
                        if (isTwoStar == 1)
                        {
                            curentStar += 2 - state[bestAdvance, 2];
                            state[bestAdvance, 2] = 1; state[bestAdvance, 3] = 1;

                            Console.WriteLine("TS" + bestAdvance.ToString());
                        }
                        else
                        {
                            curentStar += 1;
                            state[bestAdvance, 2] =1;

                            Console.WriteLine("OS" + bestAdvance.ToString());
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                bool isComplete = true;
                for (int c = 0; c < limit; c++)
                {
                    if (state[c, 3] == 0)
                    {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete)
                {
                    output += "Case #" + (i+1).ToString() + ": " + counter + "\n";
                }
                else
                {
                    output += "Case #" + (i + 1).ToString() + ": Too Bad\n";
                }

            }


            File.WriteAllText("output.txt", output.Trim());
            Console.WriteLine(output);
            Console.WriteLine(DateTime.Now);
            Console.ReadLine();

        }
    }
}
