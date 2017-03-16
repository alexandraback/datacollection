using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012R1_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "A.in";

            if (args.Count() > 0)
                inputFileName = args[0];

            var sb = new StringBuilder();
            var input = new List<string>();

            using (var stream = new FileStream(inputFileName, FileMode.Open))
            {
                using (var reader = new StreamReader(stream))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        input.Add(line);
                    }
                }
            }

            var caseCount = Convert.ToInt32(input[0]);
            var sw = new Stopwatch();
            sw.Start();

            NumberFormatInfo provider = new NumberFormatInfo( );
            provider.NumberDecimalSeparator = ".";

            for (int i = 0; i < caseCount; i++)
            {
                var numbers = input[i * 2 + 1].Split(' ');
                var probs = input[i * 2 + 2].Split(' ').Select(v => Convert.ToDouble(v, provider)).ToList();

                var typedCnt = Convert.ToInt32(numbers[0]);
                var totalCnt = Convert.ToInt32(numbers[1]);

                var probTyped = 1.0;

                foreach (var prob in probs)
                {
                    probTyped *= prob; 
                }

                var best = 0.0;

                var forward = (totalCnt + 1 + totalCnt - typedCnt + 1) * (1 - probTyped) + (totalCnt - typedCnt + 1) * probTyped;
                var enterNow = (totalCnt + 1 + 1);

                best = Math.Min(forward, enterNow);

                var totalBack  = (totalCnt + 1 + typedCnt);
                best = Math.Min(totalBack, best);

                var cnt = 1;
                var probCnt = probTyped;
                probs.Reverse();
                probs.RemoveAt(probs.Count - 1);
                foreach (var prob in probs)
                {
                    probCnt = probCnt / prob * (1 - prob);
                    var back = (totalCnt - typedCnt + 1 + cnt + cnt) * (probCnt + probTyped) +
                        (totalCnt + 1 + totalCnt - typedCnt + 1 + cnt + cnt) * (1 - probTyped - probCnt);
                    best = Math.Min(back, best);
                    ++cnt;
                }

                sb.AppendFormat("Case #{0}: {1:0.000000}", i + 1, best);
                sb.AppendLine();
                Console.WriteLine("Case #{0}: time spent {1:0.00}, total predicted {2:0.0}",
                    i + 1, sw.Elapsed.TotalSeconds, sw.Elapsed.TotalSeconds / (i + 1) * caseCount);
            }

            using (var stream = new FileStream(inputFileName + ".out", FileMode.Create))
            {
                using (var writer = new StreamWriter(stream))
                {
                    writer.Write(sb.ToString());
                }
            }

            Console.WriteLine("press a key to exit");
            Console.ReadKey();
        }
    }
}
