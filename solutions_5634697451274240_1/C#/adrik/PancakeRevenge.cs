using System.IO;
using System.Linq;

namespace Qualification
{
    public class PancakeRevenge
    {
        public int Run(string pancakes)
        {
            var switches = 0;
            var current = '+';

            foreach (var pancake in pancakes.Reverse())
            {
                if (pancake == current) continue;

                current = pancake;
                switches++;
            }

            return switches;
        }

        public void Run(string inputFile, string outputFile)
        {
            var inputLines = File.ReadAllLines(inputFile);
            var outputLines = inputLines
                .Skip(1)
                .Take(int.Parse(inputLines[0]))
                .Select((l, i) => $"Case #{i + 1}: {Run(l)}");

            File.WriteAllLines(outputFile, outputLines);
        }
    }
}