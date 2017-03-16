using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{


    class Program
    {
        static void Main(string[] args)
        {
            cookieCliker cc = new cookieCliker();
            cc.solve();
        }
    }




    class cookieCliker
    {
        public void solve()
        {
            string result = string.Empty;
            string inputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\input.txt";


            string[] lines = File.ReadAllLines(inputFile);
            int totalRowCounter = 0;

            int testCases = Int32.Parse(lines[totalRowCounter++]);

            for (int i = 0; i < testCases; i++)
            {
                double totalSeconds = 0;

                string[] gameInfo = lines[totalRowCounter++].Split(' ').ToArray();
                double C = Double.Parse(gameInfo[0]);
                double F = Double.Parse(gameInfo[1]);
                double X = Double.Parse(gameInfo[2]);

                double cookiesPerSec = 2;

                double waitingCost = 0;
                double buyFarmCost = 0;

                while (true)
                {
                    waitingCost = (X / cookiesPerSec);
                    buyFarmCost = (X / (cookiesPerSec + F)) + (C / cookiesPerSec);

                    if (waitingCost > buyFarmCost)
                    {
                        totalSeconds += (C / cookiesPerSec);
                        cookiesPerSec += F;
                    }
                    else
                    {
                        totalSeconds += waitingCost;
                        break;
                    }
                }

                result += String.Format("Case #{0}: {1}\n", i + 1, Math.Round(totalSeconds, 7));
            }


            string outputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\output.txt";
            File.WriteAllText(outputFile, result);

            Console.WriteLine("Success!");
            Console.Read();
        }

    }
}
