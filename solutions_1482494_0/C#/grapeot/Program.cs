using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace grapeot.CodeJam.Round1.P2
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "input.txt";
            var lines = File.ReadAllLines(inputFileName);
            var t = int.Parse(lines[0]);
            var lineNum = 1;
            var results = new List<string>();
            for (int i = 0; i < t; i++)
            {
                var n = int.Parse(lines[lineNum]);
                var l1 = new List<int>();
                var l2 = new List<int>();
                for (int j = 0; j < n; j++)
                {
                    var fields = lines[lineNum + j + 1].Split(' ').Select(x => int.Parse(x)).ToArray();
                    l1.Add(fields[0]);
                    l2.Add(fields[1]);
                }
                results.Add(ProcessData(i, l1.ToArray(), l2.ToArray()));
                lineNum += n + 1;
            }
            File.WriteAllLines("output.txt", results);
        }

        static string ProcessData(int index, int[] l1, int[] l2)
        {
            var s = 0;
            var steps = 0;
            var unFinished1 = Enumerable.Range(0, l1.Length).ToList();
            var unFinished2 = Enumerable.Range(0, l1.Length).ToList();
            var oldUnfinished1 = -1;
            var oldUnfinished2 = -1;
            while (unFinished2.Count > 0 && (unFinished1.Count != oldUnfinished1 || unFinished2.Count != oldUnfinished2))
            {
                oldUnfinished1 = unFinished1.Count;
                oldUnfinished2 = unFinished2.Count;

                // scan L2 to check whether it's possible to directly pass some level with 2 stars
                var toRemove = -1;
                foreach (var i in unFinished2)
                {
                    if (s >= l2[i])
                    {
                        toRemove = i;
                        ++steps;
                        s += unFinished1.Contains(i) ? 2 : 1;
                        Console.Write("{0} ", i);
                        break;
                    }
                }
                if (toRemove != -1)
                {
                    unFinished2.Remove(toRemove);
                    if (unFinished1.Contains(toRemove)) unFinished1.Remove(toRemove);
                    continue;
                }

                // scan L1 to check whether it's possible to pass some level with 1 star
                // try to avoid stages with only 1-star difference in requirements first
                toRemove = -1;
                var toRemove2 = -1;
                foreach (var i in unFinished1)
                {
                    if (s >= l1[i])
                    {
                        toRemove2 = i;
                        if (l1[i] + 1 < l2[i])
                        {
                            toRemove = i;
                            ++steps;
                            s += 1;
                            Console.Write("{0} ", i);
                            break;
                        }
                    }
                }
                if (toRemove != -1)
                {
                    unFinished1.Remove(toRemove);
                    continue;
                }
                if (toRemove2 != -1)
                {
                    unFinished1.Remove(toRemove2);
                    ++steps;
                    s += 1;
                    Console.Write("{0} ", toRemove2);
                    continue;
                }
            }

            if (unFinished1.Count != 0 || unFinished2.Count != 0)
                return string.Format("Case #{0}: Too Bad", index + 1);
            return string.Format("Case #{0}: {1}", index + 1, steps);
        }
    }
}
