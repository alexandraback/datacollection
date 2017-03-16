using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_MagicTrick
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
            }
            output.Flush();
        }

        private static string HandleCase(TextReader input)
        {
            string[] lineSplit = input.ReadLine().Split(' ');
            double farmCost = double.Parse(lineSplit[0]);
            double farmCookiesPerSecond = double.Parse(lineSplit[1]);
            double victoryAmount = double.Parse(lineSplit[2]);

            double cps = 2;
            double time = 0;

            while ((farmCost / cps + victoryAmount / (cps + farmCookiesPerSecond)) < (victoryAmount / cps))
            {
                time += farmCost / cps;
                cps += farmCookiesPerSecond;
            }
            time += victoryAmount / cps;

            return time.ToString();
        }
    }
}
