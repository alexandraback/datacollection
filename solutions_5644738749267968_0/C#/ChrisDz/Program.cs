using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    class Program
    {
        private static int PlayHonest(IEnumerable<double> naomiBlocks, IEnumerable<double> kenBlocks)
        {
            var naomiBlocksSorted = new List<double>(naomiBlocks);
            var kenBlocksSorted = new List<double>(kenBlocks);

            naomiBlocksSorted.Sort();
            kenBlocksSorted.Sort();

            int points = 0;

            while (naomiBlocksSorted.Count > 0)
            {
                var naomiBlock = naomiBlocksSorted[0];
                naomiBlocksSorted.Remove(naomiBlock);

                var kenBlock = kenBlocksSorted.FirstOrDefault(b => b > naomiBlock);
                if (kenBlock == 0.0) kenBlock = kenBlocksSorted[0];
                kenBlocksSorted.Remove(kenBlock);

                if (naomiBlock > kenBlock)
                    points++;
            }

            return points;
        }

        private static int PlayDeceitful(IEnumerable<double> naomiBlocks, IEnumerable<double> kenBlocks)
        {
            var naomiBlocksSorted = new List<double>(naomiBlocks);
            var kenBlocksSorted = new List<double>(kenBlocks);

            naomiBlocksSorted.Sort();
            kenBlocksSorted.Sort();

            int points = 0;

            while (naomiBlocksSorted.Count > 0)
            {
                var kenBlock = kenBlocksSorted[0];
                kenBlocksSorted.Remove(kenBlock);

                var naomiBlock = naomiBlocksSorted.FirstOrDefault(b => b > kenBlock);
                if (naomiBlock == 0.0) naomiBlock = naomiBlocksSorted[0];
                naomiBlocksSorted.Remove(naomiBlock);

                if (naomiBlock > kenBlock)
                    points++;
            }

            return points;
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            int n = int.Parse(reader.ReadLine());
            var naomiBlocks = reader.ReadLine().Split(' ').Select(double.Parse);
            var kenBlocks = reader.ReadLine().Split(' ').Select(double.Parse);

            var pointsDeceitful = PlayDeceitful(naomiBlocks, kenBlocks);
            var pointsHonest = PlayHonest(naomiBlocks, kenBlocks);
            writer.WriteLine("Case #{0}: {1} {2}", id, pointsDeceitful, pointsHonest);
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
