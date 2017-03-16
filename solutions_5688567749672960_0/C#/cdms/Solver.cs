using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CodeJam
{

    class Solver
    {
        int currentMin;
        static List<int> getTurnNumbers(int start)
        {
            var res = new List<int>();
            if (start % 10 == 0)
                start = start - 1;
            string startStr = start.ToString();
            int digits = start.ToString().Length;
            if (digits == 1)
                return res;

            for (int i = digits - 1; i >= 0; i--)
            {
                int a = startStr[i] - 48;
                if (a == 1 && i == digits - 1)
                {
                    res.Add(start);
                    continue;
                }
                if (a == 0)
                    continue;

                int pow = (int)Math.Pow(10, digits - i);
                res.Add(((int)(start / pow)) * (int)pow + 1);
            }

            if (digits > 2)
                getTurnNumbers((int)Math.Pow(10, digits - 1) - 1).ForEach(i => res.Add(i));

            return res;
        }
        void calculateMinForValue(int toReach, int cumul)
        {

            List<int> turnNumbers = getTurnNumbers(toReach);

            int total = cumul + toReach;
            if (currentMin > total)
                currentMin = total;

            for (int i = 0; i < turnNumbers.Count; i++)
            {
                int turnAt = turnNumbers[i];
                int nextToReach = int.Parse(new String(turnAt.ToString().Reverse().ToArray()));
                if (nextToReach >= turnAt)
                    continue;
                calculateMinForValue(nextToReach, toReach - turnAt + 1 + cumul);
            }

        }
        string solveCase(int[] input)
        {
            
            currentMin = int.MaxValue;
            int toReach = input[0];
            calculateMinForValue(toReach, 0);
            return currentMin.ToString();
        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            int nbCases = Convert.ToInt32(lines[0]);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < nbCases; i++)
            {
                //MessageBox.Show(i + "");
                int caseLine = i + 1;
                string[] lineParts = lines[caseLine].Split(' ');
                int[] inputData = lineParts.Select(n => Convert.ToInt32(n)).ToArray();
                string result = solveCase(inputData);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
            }
            return sb.ToString();
        }
    }

}

