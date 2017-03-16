using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _B__Cookie_Clicker_Alpha
{
    class Program
    {
        static void Main(string[] args)
        {
            // Fix globalization
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.CreateSpecificCulture("en-US");
            // Number of games
            int T = Int32.Parse(Console.ReadLine());
            // Set up output file
            TextWriter writer = new StreamWriter("out.txt", false);
            for (int t = 1; t <= T; t++)
            {
                // Read the data
                String[] line = Console.ReadLine().Split(' ');
                double C = Double.Parse(line[0]);
                double F = Double.Parse(line[1]);
                double X = Double.Parse(line[2]);
                // Set variables
                double time = 0;
                double production = 2;
                double timeToFarm, timeWithFarm, timeToGoal;
                // Calculate the time
                do
                {
                    timeToFarm = C / production;
                    timeWithFarm = timeToFarm + X / (production + F);
                    timeToGoal = X / production;
                    if (timeToGoal > timeWithFarm) {
                        time += timeToFarm;
                        production += F;
                    }
                } while (timeToGoal > timeWithFarm);
                time += timeToGoal;
                // Output the result
                writer.Write("Case #" + t + ": ");
                writer.WriteLine(time.ToString("F7"));
            }
            // EOF
            writer.Close();
        }
    }
}
