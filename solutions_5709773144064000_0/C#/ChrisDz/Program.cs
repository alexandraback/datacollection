using System;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    class Program
    {
        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(double.Parse).ToArray();
            double c = line[0], f = line[1], x = line[2];

            double time = 0.0;
            double rate = 2.0;
            while (true)
            {
                double timeToGoal = x / rate;
                double timeToFarm = c / rate;
                double timeToGoalWithFarm = timeToFarm + x / (rate + f);

                if (timeToGoal < timeToFarm || timeToGoal < timeToGoalWithFarm)
                {
                    time += timeToGoal;
                    break;
                }

                time += timeToFarm;
                rate += f;
            }

            writer.WriteLine("Case #{0}: {1}", id, time);
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
