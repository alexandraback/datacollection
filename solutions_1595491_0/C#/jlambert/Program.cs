using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamGooglerDancing
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args == null || args.Length < 1)
            {
                Console.WriteLine("Please specify a file.");
                Console.ReadKey();
                return;
            }
            string path = args[0];
            List<string> fileLines = new List<string>();
            try
            {
                fileLines = File.ReadLines(path).ToList<string>();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Could not find file or read from it. " + ex.Message);
                Console.ReadKey();
                return;
            }
            int numberOfLines = Convert.ToInt32(fileLines[0]);
            StringBuilder outputSB = new StringBuilder();
            for (int i = 1; i <= numberOfLines; i++)
            {
                
                List<int> numbers = fileLines[i].Split(' ').ToList().Select(x => int.Parse(x)).ToList();
                int totalNumber = numbers[0];
                int surprisingNumber = numbers[1];
                int bestScore = numbers[2];
                int runningTotal = 0;
                int totalNumberOfSurprises = 0;
                for (int j = 3; j < numbers.Count; j++)
                {
                    int currentTotal = numbers[j];
                    if (currentTotal == 0 || currentTotal == 1)
                    {
                        if (currentTotal >= bestScore)
                            runningTotal++;
                        continue;
                    }

                    int leftOver = currentTotal - bestScore;
                    int halfNumber = Convert.ToInt32(Math.Floor(Convert.ToDecimal(leftOver / 2)));
                    int scoreToTest = bestScore - 2;
                    if (scoreToTest < 0)
                        scoreToTest = 0;
                    if (halfNumber >= scoreToTest)
                    {
                        if (halfNumber == bestScore - 2)
                        {
                            if (totalNumberOfSurprises < surprisingNumber)
                                totalNumberOfSurprises++;
                            else
                                continue;
                        }
                        runningTotal++;
                    }
                }
                outputSB.AppendLine("Case #" + i + ": " + runningTotal);
            }
            Console.Write(outputSB.ToString());
            string currentAppPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            File.WriteAllText(currentAppPath + "\\output.txt", outputSB.ToString());
            Console.ReadKey();

        }
    }
}
