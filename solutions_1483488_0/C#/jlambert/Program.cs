using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamRecyledNumbers
{
    static class Extensions
    {
        public static string Right(this string theString, int length)
        {
            return theString.Substring(theString.Length - length);
        }
    }
    
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
                int num1 = numbers[0];
                int num2 = numbers[1];
                int runningTotal = 0;
                List<string> uniqueList = new List<string>();
                for (int j = num1; j <= num2; j++)
                {
                    string numString = j.ToString();
                    int numStringLength = numString.Length;
                    if (numStringLength == 1)
                        continue;
                    int rotations = numStringLength - 1;
                    string newString;
                    int newNum;
                    for (int k = 0; k < rotations; k++)
                    {
                        int amountToRotate = k+1;
                        newString = numString.Right(amountToRotate) + numString.Substring(0, numStringLength - amountToRotate);
                        newNum = Convert.ToInt32(newString);
                        if (newNum > j && newNum <= num2)
                        {
                            string uniqueKey = numString + newString;
                            if (!uniqueList.Contains(uniqueKey))
                            {
                                uniqueList.Add(uniqueKey);
                                runningTotal++;
                            }
                        }
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
