using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            var line1 = Console.ReadLine();


            var numTests = Int32.Parse(line1);

            for (int testCase = 0; testCase < numTests; testCase++)
            {

                var line = Console.ReadLine();
                var split = line.Split(' ');

                var lowNum = Int32.Parse(split[0]);
                var highNum = Int32.Parse(split[1]);

                var totalPairs = 0;
                var timer = Stopwatch.StartNew();

                var matches = new List<long>(highNum.ToString().Length);

                for (int i = lowNum; i <= highNum; i++)
                {
                    matches.Clear();

                    var stringRep = i.ToString();

                    int[] intArray = new int[stringRep.Length];

                    for (int c = 0; c < stringRep.Length; c++)
                    {
                        intArray[c] = Int32.Parse(stringRep[c].ToString());
                    }

                    for (int c = 1; c < intArray.Length; c++)
                    {
                        var newNum = CreateNum(intArray, c);

                        //Console.WriteLine("Curr: {0}", newNum);
                        //Console.ReadLine();

                        if (newNum != i && newNum >= lowNum && newNum <= highNum)
                        {
                            //Console.WriteLine("Num : {0} {1}",i, newNum);

                            if (!matches.Contains(newNum))
                            {
                                matches.Add(newNum);
                                totalPairs++;
                            }
                        }
                    }
                }

                timer.Stop();

                Console.WriteLine("Case #{0}: {1}", testCase + 1, totalPairs / 2);
            }

        }

        private static long CreateNum(int[] intArray, int startPos)
        {
            //int factor = 1;
            long returnNum = 0;
            for (int i = 0; i < intArray.Length; i++)
            {
                returnNum = returnNum * 10 + intArray[(i + startPos) % intArray.Length];

                //factor = factor * 10;
            }

            return returnNum;
        }
    }
}
