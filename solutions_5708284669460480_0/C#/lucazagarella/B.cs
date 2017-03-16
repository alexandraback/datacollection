using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace GoogleCodeJam.Rounds.R1C.B
{
    public class B : Problem
    {
        protected override string SolveCase()
        {
            String[] valoriInput = GetLine().Split(' ');

            int K = int.Parse(valoriInput[0]);
            int L = int.Parse(valoriInput[1]);
            int S = int.Parse(valoriInput[2]);
            var keys = GetLine().ToArray().GroupBy(x => x).ToDictionary(x => x.Key.ToString(CultureInfo.InvariantCulture), y => y.Count());
            var search = GetLine();
            var input = new Dictionary<string, int>();
            var output = new Dictionary<string, int>();
            input.Add("", 1);
            int s = 0;
            if (S > 7) return "??";

            while (s < S)
            {
                foreach (var element in input)
                {
                    foreach (var key in keys)
                    {
                        output.Add(element.Key + key.Key, element.Value * key.Value);
                    }
                }
                s++;
                input = output;
                output = new Dictionary<string, int>();
            }

            int sum = 0;
            int max = 0;
            foreach (var element in input)
            {
                var count = Count(element.Key, search);
                if (max < count) max = count;
                sum += element.Value * count;
            }

            var avg = ((double)sum) / Math.Pow(K, S);


            double res = max - avg;

            return res.ToString().Replace(",",".");
        }


        private static int Count(string parent, string child)
        {
            int count = 0;
            while (parent.IndexOf(child) >= 0)
            {
                count++;
                parent = parent.Substring(parent.IndexOf(child) + 1);
            }
            return count;
        }
    }
}


