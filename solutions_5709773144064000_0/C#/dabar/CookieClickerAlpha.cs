using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CookieClickerAlpha
{
    class TestCase
    {
        int number;
        double cFarmCost;
        double fFarmRate;
        double xGoal;

        double? result;


        public string GetResult()
        {
            if (result == null)
                Calc();

            //return string.Format("Case #{0}: {1}", number, Math.Round(result.Value,7).ToString());
            return string.Format("Case #{0}: {1:0.0000000}", number,result.Value);            
        }

        public TestCase(int _number, double c, double f,double x)
        {
            number = _number;
            cFarmCost = c;
            fFarmRate = f;
            xGoal = x;

        }

        private void Calc()
        {
           int farms = 0;
           double cookiesPerSec = 2;
           double currentSecs = SecondsToGoal(cookiesPerSec,xGoal);
           do
           {
               double secsSoFar = 0;
               farms++;
               cookiesPerSec = 2;
               for (int i = 0; i < farms; i++)
               {
                   secsSoFar += SecondsToGoal(cookiesPerSec, cFarmCost);
                   cookiesPerSec += fFarmRate;
               }
               secsSoFar += SecondsToGoal(cookiesPerSec, xGoal);
               if (secsSoFar > currentSecs)
               {
                   result=currentSecs;
                   return;
               }
               currentSecs = secsSoFar;
               
           } while (true);//hopefully not inf loop!           

        }

        private double SecondsToGoal(double rate, double goal)
        {
            return goal/rate;
        }

    }
    class CookieClickerAlpha
    {
        static void Main(string[] args)
        {
            try
            {
                using (StreamReader sr = new StreamReader(string.Format("c:\\codejam\\{0}", args[0])))
                {
                    System.IO.StreamWriter file = new System.IO.StreamWriter(string.Format("c:\\codejam\\out_{0}", args[0]));
                    int numberOfTest = Int32.Parse(sr.ReadLine());                    
                    TestCase test;
                    Console.WriteLine(string.Format("{0} Test cases", numberOfTest));
                    for (int i = 0; i < numberOfTest; i++)
                    {
                        var line = sr.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
                        

                        //could check prices.Count() == noItems;
                        test = new TestCase(i + 1, line[0], line[1], line[2]);
                        file.WriteLine(test.GetResult());
                        if (i % 10 == 0)
                            Console.WriteLine(string.Format("wrote test {0}", i + 1));
                    }
                    file.Close();
                    Console.WriteLine(string.Format("Done {0} Tests", numberOfTest));

                }
                //Console.WriteLine(new TestCase(1,30.0,1.0,2.0).GetResult());
                //Console.WriteLine(new TestCase(2, 30.0,2.0,100.0).GetResult());
                //Console.WriteLine(new TestCase(3,30.50000,3.14159,1999.19990).GetResult());
                //Console.WriteLine(new TestCase(4, 500.0,4.0,2000.0).GetResult());
            }
            catch (Exception e)
            {
                Console.WriteLine("Something bad:");
                Console.WriteLine(e.Message);
                return;
            }
        }

    
    }
}
