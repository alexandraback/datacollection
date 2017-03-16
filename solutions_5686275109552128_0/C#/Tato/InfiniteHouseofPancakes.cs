using System;
using System.Collections.Generic;
using System.Linq;

namespace InfiniteHouseofPancakes
{
    using System.IO;

    class InfiniteHouseofPancakes
    {
        static void Main(string[] args)
        {
            var inputFile = new System.IO.StreamReader(args[0]);
            var outputFile = new System.IO.StreamWriter("B-small-attempt1.out");

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var k = 0; k < T; k++)
            {
                var D = Convert.ToInt32(inputFile.ReadLine());
                var line = inputFile.ReadLine();
                if (line == null) throw new InvalidDataException();

                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                var special = 0;
                var min = 100000;

                var P = new SortedList<int, int>();

                foreach (var amount in data.Select(t => Convert.ToInt32(t)))
                {
                    if (P.ContainsKey(amount))
                    {
                        P[amount]++;
                    }
                    else
                    {
                        P[amount] = 1;
                    }
                }

                var stop = false;

                while (!stop)
                {
                    var max = P.Last().Key;
                    var count = P.Last().Value;

                    if (special + max < min)
                    {
                        min = special + max;
                    }

                    var half1 = max - max / 2;
                    var half2 = max - half1;

                    if (special + half2 + count < special + max)
                    {
                        P.Remove(max);
                        var x = P.ContainsKey(half1) ? P[half1] : 0;
                        P[half1] = x + count;

                        var y = P.ContainsKey(half2) ? P[half2] : 0;
                        P[half2] = y + count;

                        special += count;
                    }
                    else
                    {
                        special = special + max;
                        stop = true;
                    }
                }

                outputFile.Write("Case #" + (k + 1) + ": " + min + " (" + line + ")" + "\n");
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
