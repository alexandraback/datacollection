using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            int numberOfBlocks = int.Parse(input.ReadLine());
            string[] parts = input.ReadLine().Split(' ');
            List<double> naomiWeights = new List<double>();
            for (int index = 0; index < numberOfBlocks; index++)
            {
                naomiWeights.Add(double.Parse(parts[index]));
            }
            naomiWeights.Sort();
            parts = input.ReadLine().Split(' ');
            List<double> kenWeights = new List<double>();
            for (int index = 0; index < numberOfBlocks; index++)
            {
                kenWeights.Add(double.Parse(parts[index]));
            }
            kenWeights.Sort();
            List<double> kenWarWeights = new List<double>(kenWeights);
            int kenIndex = 0;
            int warcount = 0;
            int decieptCount = 0;
            for (int naomiIndex = 0; naomiIndex < numberOfBlocks; naomiIndex++)
            {
                // Canculate decieptfulWar
                if (naomiWeights[naomiIndex] > kenWeights[kenIndex])
                {
                    decieptCount++;
                    kenIndex++;
                }
                // Calculate normal war list
                bool found = false;
                for (int compareIndex = 0; compareIndex < kenWarWeights.Count; compareIndex++)
                {
                    if (kenWarWeights[compareIndex] > naomiWeights[naomiIndex])
                    {
                        kenWarWeights.RemoveAt(compareIndex);
                        found=true;
                        break;
                    }
                }
                if (!found)
                {
                    warcount++;
                    kenWarWeights.RemoveAt(0);
                }
            }
            output.WriteLine(decieptCount.ToString() + " " + warcount.ToString());
        }
    }
}
