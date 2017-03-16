using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FacebookHackerCup2012
{
    class DancingGoogle
    {
        int numberOfGooglers, surprises, p;
        int[] totalscores;
        int[][] scores;
        int cases;
        string line;
        public DancingGoogle()
        {
            StreamWriter output = new StreamWriter("dancingoutput.txt");
            StreamReader file = new StreamReader("dancinginput.txt");
            cases = Convert.ToInt32(file.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                string[] parts = line.Split(' ');
                numberOfGooglers = Convert.ToInt32(parts[0]);
                surprises = Convert.ToInt32(parts[1]);
                p = Convert.ToInt32(parts[2]);
                totalscores = new int[numberOfGooglers];
                scores = new int[numberOfGooglers][];
                for (int j = 0; j < numberOfGooglers; j++)
                {
                    totalscores[j] = Convert.ToInt32(parts[j + 3]);
                    scores[j] = new int[3];
                    scores[j][0] = (int)Math.Ceiling((double)totalscores[j] / 3);
                    scores[j][1] = (int)Math.Round((double)totalscores[j] / 3);
                    scores[j][2] = (int)Math.Floor((double)totalscores[j] / 3);
                }
                int maximum = 0;
                for (int j = 0; j < numberOfGooglers; j++)
                {
                    if (scores[j][0] >= p)
                    {
                        maximum++;
                    }
                    else if (surprises > 0 && ((scores[j][0] + 1) == p) && scores[j][0] == scores[j][1] && scores[j][0] != 0)
                    {
                        maximum++;
                        surprises--;
                    }

                }

                output.WriteLine("Case #" + (i + 1) + ": " + maximum);
                Console.WriteLine("Case #" + (i + 1) + " done.");
            }
            file.Close();
            output.Close();
        }
    }
}
