using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2014
{
    class CookieClickerAlpha
    {
        public void solution(string filename)
        {
            StreamWriter sw = new StreamWriter("CookieClickerAlpha.txt");

            StreamReader sr = new StreamReader(filename);
            string strSize = sr.ReadLine();
            int iSize = Int32.Parse(strSize);

            for (int caseIndex = 0; caseIndex < iSize; caseIndex++)
            {
                string line = sr.ReadLine();
                string[] meta = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                double FarmCost = Convert.ToDouble(meta[0]);
                double FarmProduce = Convert.ToDouble(meta[1]);
                double Target = Convert.ToDouble(meta[2]);

                //判断需要几个farm (Target-FarmCost）/PerSec< Target/（PerSec+F）
                double FarmMax = Math.Ceiling((Target * FarmProduce - FarmCost * FarmProduce - 2 * FarmCost) / (FarmCost * FarmProduce));

                double time = 0;
                int farmCount = 0;
                //先算生产farmmax个farm的时间
                while (farmCount < FarmMax)
                {
                    time += FarmCost / (farmCount * FarmProduce + 2);
                    farmCount++;
                }
                time += Target / (farmCount * FarmProduce + 2);
                Console.WriteLine(time);
                sw.WriteLine("Case #{0}: {1}", caseIndex + 1, time.ToString("f7"));

            }
            sw.Close();

        }
    }
}
