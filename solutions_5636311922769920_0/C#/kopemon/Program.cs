using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "../../D-small-attempt0.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int c = 1; c <= T; c++)
                {
                    string ans = "IMPOSSIBLE";

                    var data = tr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

                    int K = data[0], C = data[1], S = data[2];

                    // For small only
                    if (K == S)
                    {
                        ans = string.Join(" ", Enumerable.Range(1, K));
                    }

                    Console.WriteLine($"Case #{c}: {ans}");
                    tw.WriteLine($"Case #{c}: {ans}");
                }
            }
        }
    }
}
