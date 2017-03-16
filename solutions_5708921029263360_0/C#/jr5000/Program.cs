using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var reader = new StreamReader("C:\\CodeJam\\1c\\c\\C-small-attempt1 (1).in"))
            {
                using (var writer = new StreamWriter("C:\\CodeJam\\1c\\c\\out.txt"))
                {
                    var numCases = int.Parse(reader.ReadLine());
                    for(int i = 1; i <= numCases; i++)
                    {
                        Console.Write("Case #{0}: ", i);
                        writer.Write("Case #{0}: ", i);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var j = line[0];
            var p = line[1];
            var s = line[2];
            var useJ = j < p || j < s;
            var useP = p < j || p < s;
            var useS = s < j || s < p;
            var times = Math.Min(!useJ ? j : (!useP ? p : s), line[3]);

            var lines = new List<string>();
            var usedAC = new Dictionary<string, int>();
            var usedAB = new Dictionary<string, int>();
            var usedBC = new Dictionary<string, int>();

            for (int i = 1; i <= (useJ ? j : s); i++)
            {
                for(int k = 1; k <= (useP ? p : s); k++)
                {
                    var AB = i.ToString() + " " + k.ToString();

                    for (int l = 1; l <= (!useJ ? j : (!useP ? p : s)); l++)
                    {
                        if (!usedAB.ContainsKey(AB))
                            usedAB.Add(AB, 0);
                        if (usedAB[AB] == line[3])
                            continue;

                        var AC = i.ToString() + " " + l.ToString();
                        if (!usedAC.ContainsKey(AC))
                            usedAC.Add(AC, 0);
                        if (usedAC[AC] == line[3])
                            continue;

                        var BC = k.ToString() + " " + l.ToString();
                        if (!usedBC.ContainsKey(BC))
                            usedBC.Add(BC, 0);
                        if (usedBC[BC] == line[3])
                            continue;

                        usedAB[AB]++;
                        usedAC[AC]++;
                        usedBC[BC]++;
                        lines.Add(string.Format("{0} {1} {2}", useJ ? i : l, useP ? k : l, !useJ ? i : (!useP ? k : l)));
                    }
                }
            }
            Console.WriteLine(lines.Count);
            writer.WriteLine(lines.Count);
            foreach(var x in lines)
            {
                Console.WriteLine(x);
                writer.WriteLine(x);
            }
        }
    }
}
