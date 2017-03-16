using System;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class Fractiles
    {
        public long[] Run(int k, int c, int s)
        {
            var minChecks = (k - 1)/c + 1;
            if (minChecks > s)
                return null;

            var checks = new long[minChecks];
            for (var i = 0; i < minChecks; i++)
            {
                var originalPos = i * c;
                long pos = originalPos;
                for (var j = 1; j < c; j++)
                {
                    pos = pos*k + (originalPos + j < k
                        ? originalPos + j
                        : 0);
                }
                checks[i] = pos + 1;
            }

            return checks;
        }

        public void Run(string inputFile, string outputFile)
        {
            var splitters = new[] {' '};
            var inputLines = File.ReadAllLines(inputFile);
            var outputLines = inputLines
                .Skip(1)
                .Take(int.Parse(inputLines[0]))
                .Select((l, i) =>
                {
                    var parts = l.Split(splitters, StringSplitOptions.RemoveEmptyEntries);
                    var k = int.Parse(parts[0]);
                    var c = int.Parse(parts[1]);
                    var s = int.Parse(parts[2]);

                    return $"Case #{i + 1}: {ToText(Run(k, c, s))}";
                });

            File.WriteAllLines(outputFile, outputLines);
        }

        private string ToText(long[] checks)
        {
            return checks == null 
                ? "IMPOSSIBLE" 
                : string.Join(" ", checks.Select(c => c.ToString()));
        }
    }
}