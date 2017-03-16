using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../C-small-attempt0.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                var digits = inputs[x * 2 + 1].Split(' ').Select(int.Parse).ToArray();
                int C = digits[0];
                int D = digits[1];
                int V = digits[2];
                var den = inputs[x * 2 + 2].Split(' ').Select(int.Parse).ToArray();
                var possibles = new bool[V];
                for (int i = 1; i < (1 << D); i++)
                {
                    int value = 0;
                    for (int j = 0; j < D; j++)
                    {
                        if ((i & (1 << j)) > 0)
                        {
                            value += den[j];
                        }
                    }
                    if (value <= V)
                    {
                        possibles[value - 1] = true;
                    }
                }
                int ans = 0;
                for (int i = 0; i < V; i++)
                {
                    if (!possibles[i])
                    {
                        ans++;
                        int value = i + 1;
                        for (int j = 0; j < V; j++)
                        {
                            if (possibles[j])
                            {
                                if (j + 1 + value <= V)
                                {
                                    possibles[j + value] = true;
                                }
                            }
                        }
                    }
                }
                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, ans));
            }

            File.WriteAllText(@"../../small.out", outputs.ToString());
        }
    }
}
