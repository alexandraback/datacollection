using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace CookieMonster
{
    class Program
    {
     
        static void Main(string[] args)
        {
            CookieMonster(@"C:\Users\Yulin\Downloads\B-small-attempt0.in", @"C:\Users\Yulin\Downloads\B-small-attempt0.out");
        }

        private static void CookieMonster(string inputName, string outputName)
        {
            using (StreamReader sr = File.OpenText(inputName))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(outputName)))
                {
                    int T = int.Parse(sr.ReadLine());

                    for (int i = 0; i < T; i++)
                    {
                        string line = sr.ReadLine();
                        string[] numbers = line.Split(new char[] {' '});
                        decimal[] testcase = new decimal[3];
                        int counter = 0;
                        foreach (string number in numbers)
                        {
                            testcase[counter] = decimal.Parse(number);
                            counter++;
                        }
                        decimal C = testcase[0];
                        decimal F = testcase[1];
                        decimal X = testcase[2];

                        SolveCookieMonster(C , F , X , sw , i+1);

                    }

                }
            }
        }

        private static void SolveCookieMonster(decimal C, decimal F, decimal X, StreamWriter sw , int caseNum)
        {
            decimal besttime = 100001m;
            decimal curtime = 0m; //Time has used
            decimal pr = 2m;   //Current Production Rate
            decimal cp = 0m;   //Cumulative Production
            while (true)
            {
                decimal time = (X - cp) / pr + curtime;
                if (time < besttime)
                    besttime = time;
                if (time > besttime) break;
                if (F < 0m) break;
                curtime += C / pr;
                pr += F;
            }
            sw.WriteLine(String.Format("Case #{0}: {1:0.0000000}" , caseNum , besttime));

        }
    }
}
