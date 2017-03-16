using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2013R1P1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("..\\..\\input.txt").Split('\n');
            String output = "";

            int l = 0;
            int T = int.Parse(input[l]);
            l++;
            for (int c = 0; c < T; c++)
            {
                int curentMoteSize = int.Parse(input[l].Split(' ')[0]);
                int MotTotal = int.Parse(input[l].Split(' ')[1]);
                List<int> Mots = new List<int>();
                l++;
                for (int n = 0; n < MotTotal; n++)
                {
                    Mots.Add(int.Parse(input[l].Split(' ')[n]));
                }
                l++;
                Mots.Sort();
                int ret = GetNumberOfGeneratored(Mots, 0, 0, curentMoteSize);

                output += "Case #" + (c + 1).ToString() + ": " + ret.ToString() + "\n";
                Console.WriteLine("Case #" + (c + 1).ToString() + ": " + ret.ToString());
            }

            File.WriteAllText("..\\..\\output.txt", output.Trim());
            Console.ReadLine();
        }

        private static int GetNumberOfGeneratored(List<int> Mots, int position, int added, int curentMoteSize)
        {
            int CostToTrim = (Mots.Count - position);

            int CostToAdvance = 0;

            if (Mots.Count == position)
            {
                return (added);
            }

            if (Mots[position] < curentMoteSize)
            {
                CostToAdvance = added + GetNumberOfGeneratored(Mots, position + 1, 0, curentMoteSize + Mots[position]);
            }
            else
            {
                if (1 == curentMoteSize)
                {
                    CostToAdvance = (Mots.Count);
                }
                else
                {
                    Mots.Insert(position, curentMoteSize - 1);
                    CostToAdvance = (GetNumberOfGeneratored(Mots, position, added + 1, curentMoteSize));
                }
            }

            return (CostToTrim > CostToAdvance ? CostToAdvance : CostToTrim);
        }



        //static int GetNumberOfGeneratored(
    }
}
