using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace QualificationRound
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string inputFilename = "B-large.in"; //args[0];
            string outputFilename = Path.ChangeExtension(inputFilename, "out");

            using (var input = new StreamReader(File.OpenRead(inputFilename)))
            using (var output = new StreamWriter(File.OpenWrite(outputFilename)))
            {
                int T = int.Parse(input.ReadLine());

                for (int tc = 1; tc <= T; ++tc)
                {
                    var a = input.ReadLine().Split(' ').Select(double.Parse).ToArray();
                    var c = a[0];
                    var f = a[1];
                    var x = a[2];

                    double rate = 2;
                    double time = 0; 
                    var bestTime = x / rate;

                    while (true)
                    {
                        time += c/rate;
                        rate += f;
                        var candidate = time + x/rate;
                        if (candidate > bestTime) break; // done!
                        bestTime = candidate;
                    }

                    output.WriteLine("Case #{0}: {1:F7}", tc, bestTime);
                }
            }
        }
    }
}