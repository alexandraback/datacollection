using System;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string line;
            int testCaseCount;

            using (StreamReader file = new StreamReader("A-large.in"))
            {
                using (StreamWriter output = new StreamWriter("output.txt"))
                {
                    testCaseCount = int.Parse(file.ReadLine());
                    for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
                    {
                        line = file.ReadLine();
                        string[] splitLine = line.Split(new char[] { ' ' });
                        int maxShyness = int.Parse(splitLine[0]);
                        int peopleSoFar = 0;
                        int totalAdded = 0;
                        for (int shynessLevel = 0; shynessLevel <= maxShyness; ++shynessLevel)
                        {
                            int numberOfPeople = int.Parse(splitLine[1].Substring(shynessLevel, 1));
                            if (peopleSoFar < shynessLevel)
                            {
                                totalAdded += shynessLevel - peopleSoFar;
                                peopleSoFar += shynessLevel - peopleSoFar;
                            }
                            peopleSoFar += numberOfPeople;
                        }
                        output.WriteLine("Case #" + (testCaseIndex + 1) + ": " + totalAdded);
                    }
                }
            }
        }
    }
}
