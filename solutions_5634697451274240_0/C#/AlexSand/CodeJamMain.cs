using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace jam
{

    class CodeJamMain
    {
        static string inputFile = @"C:\Users\a.gilotte\Documents\jam\B-small-attempt0.in";

        public static void Main()
        {
            var lines = File.ReadAllLines(inputFile);
            var results = new Pancakes().Run(lines);
            var formated = FormatResult(results).ToList();
            var outpFile = inputFile.Replace(".txt", "") + "_output.txt";
            File.WriteAllLines(outpFile, formated);
        }

        static IEnumerable<string> FormatResult(IEnumerable<string> rawResults)
        {
            int i = 1;
            foreach (var result in rawResults)
            {
                yield return "Case #" + i + ": " + result;
                i++;
            }
        }

    }

    class Pancakes 
    {
        public Pancakes() { }

        public IEnumerable<string> Run(IList<string> lines)
        {
            foreach (var line in lines.Skip(1))
            {
                yield return Solve(line);
            }
        }
        string Solve(string line)
        {
            if (line.Count() == 0)
                return "" + 0;

            if (line.Replace("+", "").Replace("-", "").Count() > 0)
            {
                Console.WriteLine(line);
            }
            var lineReversed = line.Reverse().ToList();
            int n = 0;
            if (lineReversed.First() == '-')
                n++;
            var lastChar = lineReversed.First();
            foreach (var nextChar in lineReversed.Skip(1))
            {
                if (nextChar != lastChar)
                {
                    n++;
                    lastChar = nextChar;
                }
            }

            return""+n;
        }
    
    
    }


}
