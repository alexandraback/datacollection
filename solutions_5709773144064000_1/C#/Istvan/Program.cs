using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Reading input file...");
            StreamReader streamReader = new StreamReader(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem B\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem B\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }

            Console.WriteLine("Number of tests: " + nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                line = streamReader.ReadLine();
                string[] items = line.Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
                if(items.Length != 3)
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": number of input parameters is not 3");
                }
                decimal costOfFarm = 0;
                decimal productionPerFarm = 0;
                decimal winningCap = 0;
                if(!decimal.TryParse(items[0], out costOfFarm))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": cost of farm is not numeric");
                }
                if(!decimal.TryParse(items[1], out productionPerFarm))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": production per farm is not numeric");
                }
                if (!decimal.TryParse(items[2], out winningCap))
                {
                    Console.WriteLine("Case #" + caseNR.ToString() + ": winning cap is not numeric");
                }

                //process it
                Console.WriteLine("Case #"+caseNR.ToString()+": processing input");
                decimal productionPerSecond = 2;
                decimal totalTimeToCap = decimal.MaxValue;
                decimal totalTimeToFarm = 0;
                while (true)
                {
                    decimal timeToCap = 0, timeToFarm = 0;
                    timeToCap = winningCap / productionPerSecond;
                    timeToFarm = costOfFarm / productionPerSecond;

                    productionPerSecond += productionPerFarm;
                    decimal newTotalTimeToCap = totalTimeToFarm + timeToCap;
                    if (newTotalTimeToCap > totalTimeToCap)
                    { 
                        //found the minimum point, break the cycle
                        break;
                    }
                    totalTimeToCap = newTotalTimeToCap;
                    totalTimeToFarm = totalTimeToFarm + timeToFarm;
                }

                //write results
                string message = totalTimeToCap.ToString("F7");
                Console.WriteLine("Case #" + caseNR.ToString() + ": result is "+ message);
                Console.WriteLine("Case #" + caseNR.ToString() + ": writing output");
                streamWriter.WriteLine("Case #" + caseNR + ": " + message); 
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }
    }
}
