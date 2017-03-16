using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;
using System.Globalization;

namespace CodeJam0505
{
    class Program
    {
        static void Main(string[] args)
        {
            //EqualSum.equalsum(args);
            //return;

            string inputFile = "A-small-attempt3.in";
            string outputFile = "A-small-result3.out";

            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);
            dynamic inputResult = new ExpandoObject();

            inputResult.TestCases = int.Parse(reader.ReadLine());
            inputResult.Cases = new List<dynamic>();

            for (int caseCount = 0; caseCount < inputResult.TestCases; caseCount++)
            {
                string line = reader.ReadLine();
                string[] words = line.Split(' ');

                int numberContestants = int.Parse(words[0]);
                int[] judgesValue = new int[numberContestants];
                int sum = 0;

                for (int contestant = 0; contestant < numberContestants; contestant++)
                {
                    judgesValue[contestant] = int.Parse(words[contestant + 1]);
                    sum += judgesValue[contestant];
                }

                string sout = "Case #" + (caseCount + 1) + ": ";

                for (int contestant = 0; contestant < numberContestants; contestant++)
                {
                    double dbpercentage = 100;
                    for (double percentage = 0; percentage <= 1000000; percentage++)
                    {
                        double perc = percentage / 1000000;
                        double value = judgesValue[contestant] + sum * perc;
                        double need = 0;
                        bool alive = false;
                        for (int otherContestant = 0; otherContestant < numberContestants; otherContestant++)
                        {
                            if (otherContestant == contestant)
                                continue;
                            else
                            {
                                if (value > judgesValue[otherContestant])
                                {
                                    need += (value - judgesValue[otherContestant]) / sum;
                                    if (need > 1)
                                    {
                                        alive = true;
                                        break;
                                    }

                                }
                            }
                        }
                        if (need >= 1 - perc)
                        {
                            alive = true;
                            if (perc < dbpercentage)
                                dbpercentage = perc;
                            break;
                        }
                    }
                    sout += dbpercentage.ToString(CultureInfo.CreateSpecificCulture("en-GB")) + " ";
                    
                    
                }

                //output:
                writer.WriteLine(sout);
                Console.WriteLine(sout);
                writer.Flush();

            }

            Console.ReadLine();


        }
    }
}
