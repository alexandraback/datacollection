using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GcjQ2DancingWithGooglers
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("input.txt"))
            using (var writer = new StreamWriter("output.txt"))
            {
                int caseCount = int.Parse(reader.ReadLine());
                for (int @case = 1; @case <= caseCount; @case++)
                {
                    var parts = reader.ReadLine().Split(' ');
                    int N = int.Parse(parts[0]);
                    int S = int.Parse(parts[1]);
                    int p = int.Parse(parts[2]);

                    int[] ts = parts.Skip(3).Select(x => int.Parse(x)).ToArray();
                    Array.Sort(ts);
                    int y = 0; //S + ts.SkipWhile(ti => ti < p * 3 - 4).Skip(S).SkipWhile(ti => ti < p * 3 - 2).Count();
                    foreach (var ti in ts)
                        if (ti >= p + 2 * (Math.Max(p - 2, 0)))
                        {
                            if (ti >= p + 2 * (Math.Max(p - 1, 0)))
                                y++;
                            else if (S > 0)
                            {
                                y++;
                                S--;
                            }
                        }
                    writer.WriteLine("Case #{0}: {1}", @case, y);
                }
            }
        }
    }
}
