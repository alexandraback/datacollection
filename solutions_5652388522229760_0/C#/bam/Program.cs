using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CodeJam2016Qualification1
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputPath = @"C:\Users\Alexander\Downloads\A-small-attempt0 (1).in";
            var outputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q1A-small-Out.txt";

            var input = File.ReadAllLines(inputPath);
            var output = new List<string>();
            var nlines = int.Parse(input[0]);

            for (int i = 1; i <= nlines; i++)
            {
                string line = input[i];
                int nInput = int.Parse(line.Split(' ')[0]);

                var n = new BigInteger(nInput);

                if (nInput == 0)
                {
                    output.Add(string.Format("Case #{0}: {1}", i, "INSOMNIA"));
                    continue;
                }

                var numSet = new HashSet<char>();
                int step = 0;
                var currentNum = new BigInteger(0);
                while(numSet.Count<10)
                {
                    step++;
                    currentNum += n;
                    foreach(char c in currentNum.ToString())
                    {
                        numSet.Add(c);
                    }
                }
                output.Add(string.Format("Case #{0}: {1}", i, currentNum));
            }

            File.WriteAllLines(outputPath, output);
        }
    }
}
