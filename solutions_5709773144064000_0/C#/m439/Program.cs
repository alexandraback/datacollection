using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            // string fileName = "input";
            string fileName = "B-small-attempt1";

            string line;

            System.IO.StreamReader inFile =
               new System.IO.StreamReader(fileName + ".in");
            System.IO.StreamWriter outFile = 
                new System.IO.StreamWriter(fileName + ".out");

            line = inFile.ReadLine();

            int testcases;
            bool success = int.TryParse(line, out testcases);

            for (int i = 0; i < testcases; i++)
            {
                solveSingleTestcase(inFile, outFile, i + 1);
            }

            inFile.Close();
            outFile.Close();

            Console.ReadLine();
        }

        private static void solveSingleTestcase(System.IO.StreamReader inFile, System.IO.StreamWriter outFile, int testcaseNumber)
        {
            string line = inFile.ReadLine();
            string[] tokens = line.Split(' ');

            double c; // factory cost
            double f; // factory production
            double x; // goal
            double.TryParse(tokens[0], NumberStyles.Any, CultureInfo.InvariantCulture, out c);
            double.TryParse(tokens[1], NumberStyles.Any, CultureInfo.InvariantCulture, out f);
            double.TryParse(tokens[2], NumberStyles.Any, CultureInfo.InvariantCulture, out x);

//            Console.WriteLine(c);
//            Console.WriteLine(f);
//            Console.WriteLine(x);

            double currentRate = 2.0d;
            double secondsPassed = 0.0d;

            while (true)
            {
                // wait until factory can be bought
                double timeToFactory = c / currentRate;
                secondsPassed += timeToFactory;

                // check options
                double timeToFinishNoFactory = (x - c) / currentRate;
                double timeToFinishFactory = x / (currentRate + f);

                if (timeToFinishNoFactory <= timeToFinishFactory)
                {
                    secondsPassed += timeToFinishNoFactory;
                    break;
                }
                else
                {
                    currentRate += f;
                }
            }

            string secondsPassedString = secondsPassed.ToString("0.0000000", CultureInfo.InvariantCulture);
            Console.Write("Case #" + testcaseNumber + ": ");
            Console.WriteLine("{0:F7}", secondsPassedString); 
            outFile.Write("Case #" + testcaseNumber + ": ");
            outFile.WriteLine("{0:F7}", secondsPassedString);
        }
    }
}
