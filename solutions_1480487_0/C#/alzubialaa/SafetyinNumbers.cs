using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamTest
{
   public class SafetyinNumbers
    {
        public static string[] SaftyInNumbers(string[] inputLines)
        {
            int testCases = int.Parse(inputLines[0]);
            string[] output = new string[testCases];
            for (int index = 1; index <= testCases; index++)
            {
                output[index - 1] = ("Case #" + (index).ToString() + ": " + GetMinimumPercentage(inputLines[index]) + "\n");
            }

            return output;

        }

        private static string GetMinimumPercentage(string row)
        {
            string minimun = string.Empty;
            string[] numbers = row.Split(' ');
            int contestants = int.Parse(numbers[0]);
            int sum = 0;
            for (int i = 1; i <= contestants; i++)
            {
                sum += int.Parse(numbers[i]);
            }

            for (int i = 1; i <= contestants; i++)
            {
                minimun += ((float)(sum - float.Parse(numbers[i])* (contestants -1)) / (float)sum).ToString() + " ";
            }
            return minimun;
        }
    }
}
