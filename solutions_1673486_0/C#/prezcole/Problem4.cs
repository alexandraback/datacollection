using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Problem4
    {
        private const string INPUT = "A-small-attempt0.in";
        private const string OUTPUT = "A-small-attempt0.out";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            for (int i = 1, count = 1; i < input.Length; i += 2, count++)
            {
                output.Add("Case #" + count + ": " + GetResult(input[i], input[i + 1]));
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);
        }

        private static string GetResult(string p, string p_2)
        {
            var results = new List<decimal>();

            var firstLine = p.Split().Select(n => Convert.ToInt32(n)).ToList();
            int charsAlreadyTyped = firstLine[0];
            int totalChars = firstLine[1];

            var allProbs = p_2.Split().Select(n => Convert.ToDecimal(n)).ToList();




            for (int i = allProbs.Count; i > 0 ; i--)
            {
                int numCharsWeBackspace = charsAlreadyTyped - i;
                //i is num chars we use
                decimal probRightSoFar = GetProbabilities(allProbs.Take(i));
                int charsFirstAttempt = (totalChars - charsAlreadyTyped + 2*numCharsWeBackspace + 1);
                decimal expectedIfRight = probRightSoFar * charsFirstAttempt;
                int charsSecondAttempt = totalChars + 1;
                decimal expectedIfWrong = (1 - probRightSoFar) * (charsFirstAttempt + charsSecondAttempt);
                results.Add(expectedIfRight + expectedIfWrong);
            }
            
            //give up case ENTER password ENTER
            results.Add(1 + 1 + totalChars);

            return results.OrderBy(n => n).First().ToString("0.0000000");
        }

        private static decimal GetProbabilities(IEnumerable<decimal> probabilities)
        {
            decimal result = 1;
            foreach (var prob in probabilities)
            {
                result *= prob;
            }
            return result;
        }
    }
}
