using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Helper;

namespace ProblemC
{
    public class Solver
    {
        public String Solve(String input)
        {
            var sb = new StringBuilder();
            var reader = new InputReader(input);
            var T = reader.NextInt();
            for (int i = 0; i < T; i++)
            {
                var N = reader.NextInt();
                var M = reader.NextInt();
                var K = reader.NextInt();
                var minCount = 0;
                if (N == 1 || M == 1)
                {
                    minCount = K;
                }
                else
                {
                    if (K <= 4)
                    {
                        minCount = K;
                    }
                    else
                    {
                        minCount = K;
                        for (int j = 1; j <= M; j++)
                        {
                            for (int n = 1; n <= N; n++)
                            {
                                int stones = 2*j + 2*n;
                                int enclosed = stones + (j*n);

                                if (enclosed >= K)
                                {
                                    minCount = Math.Min(minCount, stones);
                                }
                            }
                        }
                    }
                    
                }
                sb.Append("Case #");
                sb.Append("" + (i + 1));
                sb.Append(": ");
                sb.Append(minCount);
                sb.AppendLine();
            }

            return sb.ToString();
        }
    }


    public class Program
    {
        private static void Main(string[] args)
        {
            const string filename = "C-small-attempt1.in";
            string outFile = filename.Replace(".in", ".out");
            var result = new Solver().Solve(File.ReadAllText(filename));
            File.WriteAllText(outFile, result);
        }
    }
}
