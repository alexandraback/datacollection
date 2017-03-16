using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Template
{
    class Program
    {
        static String runCase(StreamReader inputReader)
        {
            double[] values = inputReader.ReadLine().Split(' ').Select(n => Convert.ToDouble(n)).ToArray();
            double baseProduction = 2.0;
            double farmPrice = values[0];
            double farmProductionRate = values[1];
            double required = values[2];

            double productionRate = baseProduction;
            double timeToFinish = required / productionRate;
            double farmProductionTime = 0.0;

            while (true)
            {
                farmProductionTime += farmPrice / productionRate;
                double newProductionRate = productionRate + farmProductionRate;
                double newTimeToFinish = (required / newProductionRate) + farmProductionTime;

                if (timeToFinish < newTimeToFinish)
                {
                    return "" + timeToFinish.ToString("0.0000000");
                }
                else
                {
                    timeToFinish = newTimeToFinish;
                    productionRate = newProductionRate;
                }
            }
        }

        static String fileName = "B-large";
        static String folderName = "2014QB";

        static String pathToFiles = "../../../../io/";
        static String inputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".in";
        static String outputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".out";

        static void Main(string[] args)
        {
            File.WriteAllText(outputFileName, string.Empty);
            using (StreamWriter outputFile = new StreamWriter(outputFileName))
            {
                using (StreamReader inputReader = new StreamReader(inputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = runCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ": " + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
