using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Mono.Math;
using System.Linq;

namespace Round1BProblemC
{
    class MainClass
    {
        public static void Solve(StringBuilder sb, string[] lines, ref int index) {
            int n = int.Parse(lines[index]);

            index++;

            List<Tuple<string, string>> list = new List<Tuple<string, string>>();

            for (int i = 0; i < n; i++)
            {
                var split = lines[index].Split();
                list.Add(new Tuple<string, string>(split[0], split[1]));

                index++;
            }

            Dictionary<string, int> firstCounts = new Dictionary<string, int>();

            Dictionary<string, int> secondCounts = new Dictionary<string, int>();

            for (int i = 0; i < list.Count; i++)
            {
                int f = 0;
                firstCounts.TryGetValue(list[i].Item1, out f);
                f++;
                firstCounts[list[i].Item1] = f;

                int s = 0;
                secondCounts.TryGetValue(list[i].Item2, out s);
                s++;
                secondCounts[list[i].Item2] = s;
            }

            int sum = 0;
            foreach (var item in firstCounts)
            {
                sum += Math.Max(item.Value - 1, 0);
            }

            int sum2 = 0;

            foreach (var item in secondCounts)
            {
                sum2 += Math.Max(item.Value - 1, 0);
            }

            sb.AppendLine(Math.Min(sum, sum2).ToString());
        }

        public static void Main(string[] args)
        {
            var ifname = args[0];
            var ofname = args[1];

            var lines = File.ReadAllLines(ifname);

            var lineCount = long.Parse(lines[0]);

            var sb = new StringBuilder();
            int index = 1;
            for (long i = 1; i <= lineCount; i++)
            {
                sb.Append("Case #" + i + ": ");



                Solve(sb, lines, ref index);
            }

            File.WriteAllText(ofname, sb.ToString());
        }
    }
}
