using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace grapeot.CodeJam.Round1
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "input.txt";
            var lines = File.ReadAllLines(inputFileName);
            File.WriteAllLines("output.txt", Enumerable.Range(1, (lines.Length - 1) / 2).Select(i => ProcessData(i, lines[i * 2 - 1], lines[i * 2])));
        }

        static string ProcessData(int index, string input1, string input2)
        {
            // parse the input
            var fields1 = input1.Split(' ');
            var A = int.Parse(fields1[0]);
            var B = int.Parse(fields1[1]);
            var p = input2.Split(' ').Select(x => double.Parse(x)).ToArray();

            var results = new List<double>();

            // option 1
            var c = 1.0;
            for (int i = 0; i < A; i++) c *= p[i];
            results.Add((B - A + 1) * c + (2 * B - A + 2) * (1 - c));

            // option 2
            var nMax = (A + 1) / 2;
            for (int n = 1; n <= nMax; n++)
			{
                var c2 = 1.0;
                for (int i = 0; i < A - n; i++) c2 *= p[i];
                results.Add(c2 * (2 * n + B - A + 1) + (1 - c2) * (2 * n + 2 * B - A + 2));
			}

            // option 3
            results.Add(2 + B);

            Console.Write(".");
            return string.Format("Case #{0}: {1}", index, results.Min());
        }
    }
}
