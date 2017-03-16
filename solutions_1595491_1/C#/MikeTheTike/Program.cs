using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problemb
{
    class Program
    {
        static void Main(string[] args)
        {

            var line1 = Console.ReadLine();

            var testCases = Int32.Parse(line1);

            for (int i = 0; i < testCases; i++)
            {
                var line = Console.ReadLine();
                var split = line.Split(' ');

                int numResults = Int32.Parse(split[0]);
                int numSuprises = Int32.Parse(split[1]);
                int p = Int32.Parse(split[2]);


                //int totalResultsAboveP = 0;

                //if (p == 0)
                //{
                //    Console.WriteLine("Case #{0}: {1}", i + 1, numResults);
                //    continue;
                //}
                int totalClean = 0;
                int totalSurpises = 0;

                for (int j = 0; j < numResults; j++)
                {
                    var result = Int32.Parse(split[j + 3]);

                
                    // Must be greater than the min value
                    if (result >= (p + 2 * Math.Max(0, p - 1)))
                    {
                        totalClean ++;
                        continue;
                    }

                    if (result >= (p + 2 * Math.Max(0, p - 2)))
                    {
                        totalSurpises ++;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", i + 1,totalClean + Math.Min(totalSurpises, numSuprises));
            }
        }
    }
}
