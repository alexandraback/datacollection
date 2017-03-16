using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace GCJ_QA_Round1A2012
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream(@"C:\Users\Patrick\Desktop\A-small-attempt0.in", System.IO.FileMode.Open);

            StreamReader sr = new StreamReader(fs);

            int cases = int.Parse(sr.ReadLine());

            FileStream fw = new FileStream(@"C:\Users\Patrick\Desktop\out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fw);

            for (int i = 0; i < cases; i++)
            {
                string line = sr.ReadLine();

                string[] parts = line.Split(' ');
                int A = int.Parse(parts[0]);
                int B = int.Parse(parts[1]);

                line = sr.ReadLine();

                double output = double.MaxValue;

                string[] keyprobs = line.Split(' ');

                double[] keyprobabilities = new double[keyprobs.Length];
                for (int j = 0; j < keyprobs.Length; j++)
                {
                    keyprobabilities[j] = double.Parse(keyprobs[j]);
                }

                List<string> combos = new List<string>();


                string x = "";
                AddOption(x, A, combos, "!");
                AddOption(x, A, combos, ".");


                double[] instanceprobability = new double[combos.Count];

                for (int j = 0; j < combos.Count; j++)
                {
                    double probability = 1;
                    for (int k = 0; k < combos[j].Length; k++)
                    {
                        if (combos[j][k] == '!')
                        {
                            probability *= 1 - keyprobabilities[k];
                        }
                        else
                        {
                            probability *= keyprobabilities[k];
                        }
                    }
                    instanceprobability[j] = probability;
                }


                //number of times pressing backspace


                for (int j = 0; j <= A; j++)
                {
                    //if no bakscpaes
                    int strokestoend = B - A + 1;

                    //int strokeswithbackspaces = B - A + 1 + j;

                    double expected = 0;
                    for (int k = 0; k < combos.Count; k++)
                    {
                        int strokeswithbackspaces = B - A + 1 + 2 * j;
                        if (combos[k].Substring(0, combos[k].Length - j).Contains('!'))
                        {
                            strokeswithbackspaces += B + 1;
                        }
                        expected += instanceprobability[k] * strokeswithbackspaces;

                    }
                    if (expected < output)
                        output = expected;
                }

                //quit case
                double expectedq = 0;
                for (int k = 0; k < combos.Count; k++)
                {
                    int strokeswithbackspaces = B  + 1 + 1;
                    //if (combos[k].Substring(0, combos[k].Length - j).Contains('!'))
                    //{
                    //    strokeswithbackspaces += B + 1;
                    //}
                    expectedq += instanceprobability[k] * strokeswithbackspaces;

                }
                if (expectedq < output)
                    output = expectedq;



                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, output));

            }


            sw.Flush();
            sw.Close();
            fw.Close();
            fs.Close();

        }


        public static void AddOption(string input, int maxLength, List<string> combos, string option)
        {
            input += option;
            //combos.Add(input);
            if (input.Length < maxLength)
            {
                AddOption(input, maxLength, combos, "!");
                AddOption(input, maxLength, combos, ".");
            }
            else
            {
                combos.Add(input);
            }

        }

        public List<string> permutate;
    }
}
