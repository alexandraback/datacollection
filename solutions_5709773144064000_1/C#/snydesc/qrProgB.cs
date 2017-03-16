using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2014ProgB
{
    class qrProgB
    {
        public const string cInputFile = "C:\\Dev\\2014\\qrB\\B-large.in";
        public const string cOutputFile = "C:\\Dev\\2014\\qrB\\out.txt";
        public const string cExampleAnswerFile = "C:\\Dev\\2014\\qrB\\ea.txt";

        static void Main(string[] args)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(cOutputFile))
                {
                    using (StreamReader reader = new StreamReader(cInputFile))
                    {
                        int numberOfTestCases = int.Parse(reader.ReadLine());

                        for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                        {
                            string[] parms = reader.ReadLine().Split(' ');

                            double farmCost = double.Parse(parms[0]);
                            double farmProducion = double.Parse(parms[1]);
                            double cookiesToWin = double.Parse(parms[2]);

                            double currentCookieCount = 0.0;
                            double currentCookieProductionRatePerSecond = 2.0;
                            double currentTime = 0.0;
                            int    numberOfFarms = 0;

                            double maxTimeInSeconds = cookiesToWin / 2.0;

                            double timeToWin = -1.0;
                            double timeToProduceNextFarm = farmCost / currentCookieProductionRatePerSecond;
                            double timeToWinWithNextFarm = (currentTime + timeToProduceNextFarm) + (cookiesToWin / currentCookieProductionRatePerSecond + farmProducion);
                            double previousTimeToWin = -1.0;
                            while (true)
                            {
                                timeToProduceNextFarm = farmCost / currentCookieProductionRatePerSecond;
                               
                                timeToWin = currentTime + (cookiesToWin / currentCookieProductionRatePerSecond);
                                timeToWinWithNextFarm = (currentTime + timeToProduceNextFarm) + (cookiesToWin / currentCookieProductionRatePerSecond + farmProducion);
                                
                                if (timeToWin > 0.0 && previousTimeToWin > 0.0 && previousTimeToWin <= timeToWin)
                                {
                                    break;
                                }
    
                                if ((timeToProduceNextFarm + currentTime) < timeToWin)
                                {
                                    numberOfFarms++;
                                    currentTime = currentTime + timeToProduceNextFarm;
                                    currentCookieProductionRatePerSecond = currentCookieProductionRatePerSecond + farmProducion;
                                    currentCookieCount = 0;
                                }
                               previousTimeToWin = timeToWin;

                            }



                            //Output testcase 
                            string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + previousTimeToWin.ToString("0.0000000");

                            Console.WriteLine(outputLine);
                            writer.WriteLine(outputLine);
                        }
                    }
                }
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc);
            }
            ///CompareResultWithExample();
        }
    }
}
