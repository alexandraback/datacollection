using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2016_Round1C
{
    public class B
    {
        private const string Possible = "POSSIBLE";
        private const string Impossible = "IMPOSSIBLE";

        private Dictionary<Tuple<int, int>, string> InitializeDict()
        {
            var dict = new Dictionary<Tuple<int, int>, string>();

            for (int k = 0; k < (1 << 15); k++)
            {
                for (int b = 2; b <= 6; b++)
                {
                    var edge = new bool[b, b];
                    int counter = 0;
                    for (int y = 0; y < b - 1; y++)
                    {
                        for (int x = y + 1; x < b; x++)
                        {
                            edge[y, x] = ((k & (1 << counter)) != 0);
                            counter++;
                        }
                    }

                    var dp = new long[b];
                    dp[0] = 1;
                    for (int i = 0; i < b; i++)
                    {
                        for (int j = 0; j < b; j++)
                        {
                            if (edge[i, j])
                            {
                                dp[j] += dp[i];
                            }
                        }
                    }

                    var m = dp[b - 1];
                    if (0 < m && m <= 20 && !dict.ContainsKey(Tuple.Create(b, (int)m)))
                    {
                        var builder = new StringBuilder();
                        for (int y = 0; y < edge.GetLength(0); y++)
                        {
                            for (int x = 0; x < edge.GetLength(1); x++)
                            {
                                builder.Append(edge[y, x] ? "1" : "0");
                            }
                            builder.AppendLine();
                        }
                        dict[Tuple.Create(b, (int)m)] = builder.ToString();
                    }
                }
            }

            return dict;
        }

        private void Run()
        {
            var dict = InitializeDict();
            //foreach (var p in dict.OrderBy(x => x.Key.Item1).ThenBy(x => x.Key.Item2))
            //{
            //    Console.WriteLine(p.Key.Item1 + " " + p.Key.Item2);
            //    Console.WriteLine(p.Value);
            //}

            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                var B = int.Parse(input[0]);
                var M = int.Parse(input[1]);

                Console.Write("Case #{0}: ", testcase);
                string result;
                if (dict.TryGetValue(Tuple.Create(B, M), out result))
                {
                    Console.WriteLine(Possible);
                    Console.Write(result);
                }
                else
                {
                    Console.WriteLine(Impossible);
                }
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
