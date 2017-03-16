using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Round1CProblemB : Problem
    {
        protected override string SolveCase()
        {
            int[] parameters = ReadNextLineAsInt32Array();
            int numberOfKeys = parameters[0];
            int lengthOfTarget = parameters[1];
            int lengthOfString = parameters[2];
            char[] keyboardKeys = ReadNextLineAsString().ToCharArray();
            string target = ReadNextLineAsString();

            if (target.ToCharArray().Except(keyboardKeys).Any()) 
            {
                return "0.0";
            }

            int possibleStartPositions = lengthOfString - lengthOfTarget + 1;
            double probability = 1.0;
            for (int i = 0; i < lengthOfTarget; i++)
            {
                probability *= 1.0 * keyboardKeys.Where(c => c == target[i]).Count() / numberOfKeys;
            }

            int maxOccurences = (lengthOfString - lengthOfTarget) / (lengthOfTarget - MaxOverlap(target)) + 1;
            return Math.Round((maxOccurences * (1 - probability)), 6).ToString();
        }

        private int MaxOverlap(string input)
        {
            for (int i = input.Length - 1; i > 0; i--)
            {
                if (input.LastIndexOf(input.Substring(0, i)) > 0)
                {
                    return i;
                }
            }
            return 0;
        }
    }
}
