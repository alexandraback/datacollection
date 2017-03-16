using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class TheRepeater
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var c in Enumerable.Range(1, numTestCases))
            {
                var numStrings = helper.ReadLineInt32();
                var strings = helper.ReadLines(numStrings);
                var answer = Solve(strings);
                helper.OutputCase(answer == -1 ? "Fegla Won" : answer.ToString());
            }
        }

        public static int Solve(string[] strings)
        {
            int numStrings = strings.Length;
            //Precompute all distances
            var distances = new int[numStrings, numStrings];
            for (int rootString = 0; rootString < numStrings; ++rootString)
            {
                for (int otherString = rootString + 1; otherString < numStrings; ++otherString)
                {
                    var distance = Distance(strings[rootString], strings[otherString]);
                    if (distance == -1) return -1;
                    distances[rootString, otherString] = distance;
                    distances[otherString, rootString] = distance;
                }
            }
            //Find the string with the minimal sum of distance to all other strings
            var best = Int32.MaxValue;            
            for (int i = 0; i < numStrings; ++i)
            {
                int sum = 0;
                for (int j = 0; j < numStrings; ++j)
                {
                    if (i != j)
                        sum += distances[i, j];
                }
                if (sum < best)
                    best = sum;
            }
            return best;
        }

        public static int Distance(string a, string b)
        {
            int i = 0;
            int j = 0;
            int distance = 0;
            while (i < a.Length || j < b.Length)
            {
                bool aDifferent = i >= a.Length || (i == 0 || a[i] != a[i - 1]);
                bool bDifferent = j >= b.Length || (j == 0 || b[j] != b[j - 1]);

                char aChar = a[Math.Min(i, a.Length - 1)];
                char bChar = b[Math.Min(j, b.Length - 1)];

                //Both are different, they must be the same
                if (aDifferent && bDifferent)
                {
                    if (aChar != bChar)
                        return -1;
                    i += 1;
                    j += 1;
                }
                //Both are continuations, that's cool, keep going.
                else if (!aDifferent && !bDifferent)
                {
                    if (i == a.Length)
                        distance += 1;
                    else
                        i += 1;

                    if (j == b.Length)
                        distance += 1;
                    else
                        j += 1;
                }
                //Just a is different, move b forward
                else if (aDifferent)
                {
                    j += 1;
                    distance += 1;
                }
                //Just b is different, move a forward
                else
                {
                    i += 1;
                    distance += 1;
                }
            }
            return distance;
        }

        //public static List<Tuple<char, int>> ParseString(string a)
        //{
        //    char lastChar = ' ';
        //    int count = 0;
        //    var rv = new List<Tuple<char, int>>();
        //    for (int i = 0; i < a.Length; ++i)
        //    {
        //        if (i != 0 && a[i] != lastChar)
        //        {

        //        }
        //        else
        //        {
        //            count += 1;
        //        }
        //    }
        //}
    }
}
