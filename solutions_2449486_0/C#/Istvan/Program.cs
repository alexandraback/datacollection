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
            StreamReader streamReader = new StreamReader(@"D:\Programming Challange\CodeJam 2013\Qualifying\Problem C\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Programming Challange\CodeJam 2013\Qualifying\Problem C\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }
            Console.WriteLine("Get all numbers for medium-size test");
            List<Int64> allPalindromes = new List<Int64>();
            for (Int64 j = 1; j < Convert.ToInt64(Math.Sqrt(1000000000000000)) + 1; j++)
            {
                if (IsPalindrome(j) && IsPalindrome(Convert.ToInt64(Math.Pow(j, 2))))
                {
                    allPalindromes.Add(Convert.ToInt64(Math.Pow(j, 2)));
                }
            }

            Console.WriteLine("Number of tests: " + nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                line = streamReader.ReadLine();
                string[] items = line.Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
                if(items.Length != 2)
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": number of input parameters is not 2");
                }
                Int64 limitBottom = 0;
                Int64 limitTop = 0;
                if(!Int64.TryParse(items[0], out limitBottom))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": bottom limit is not numeric");
                }
                if(!Int64.TryParse(items[1], out limitTop))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": top limit is not numeric");
                }

                //process it
                Console.WriteLine("Case #"+caseNR.ToString()+": processing input");
                int nrOfResultItems = 0;
                for (int j = 0; j < allPalindromes.Count; j++)
                {
                    if(allPalindromes[j] >= limitBottom && allPalindromes[j] <= limitTop)
                    {
                        Console.WriteLine("Case #" + caseNR.ToString() + ": item found " + allPalindromes[j].ToString());
                        nrOfResultItems++;
                    }
                }

                //write results
                string message = nrOfResultItems.ToString();
                Console.WriteLine("Case #" + caseNR.ToString() + ": result is "+ message);
                Console.WriteLine("Case #" + caseNR.ToString() + ": writing output");
                streamWriter.WriteLine("Case #" + caseNR + ": " + message); 
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }

        private static bool IsPalindrome(Int64 number)
        {
            string s = number.ToString();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            }
            return true;
        }
    }
}
