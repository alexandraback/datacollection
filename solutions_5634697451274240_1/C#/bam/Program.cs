using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016Qualification2
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputPath = @"C:\Users\Alexander\Downloads\B-large (1).in";
            var outputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q2LargeOut.txt";

            var input = File.ReadAllLines(inputPath);
            var output = new List<string>();
            var nlines = int.Parse(input[0]);

            for (int i = 1; i <= nlines; i++)
            {
                int step = 0;
                string line = input[i];
                var cakes = line.ToCharArray().ToList();
                int minusIndex = line.IndexOf('-');
                while(minusIndex!=-1)
                {
                    step++;
                    if(minusIndex == 0)
                    {
                        int j = 0;
                        while (cakes.Count > j && cakes[j] == '-')
                        {
                            cakes[j] = '+';
                            j++;
                        }

                        minusIndex = cakes.IndexOf('-');
                    }
                    else
                    {
                        int j = 0;
                        while (cakes.Count > j && cakes[j] == '+')
                        {
                            cakes[j] = '-';
                            j++;
                        }
                        minusIndex = 0;
                    }
                }
                
                output.Add(string.Format("Case #{0}: {1}", i, step));
            }

            File.WriteAllLines(outputPath, output);
        }
    }
}
