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
            string input = "../../D-large.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int c = 1; c <= T; c++)
                {
                    string ans = "IMPOSSIBLE";


                    var data = tr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

                    int K = data[0], C = data[1], S = data[2];

                    if (S * C >= K) {

                        List<long> select = new List<long>();
                        for (int i = 0 ; i < K; i += C)
                        {
                            var hoge = Enumerable.Range(i, C).Select(x => (long) (x % K));
                            var aho = hoge.Select((x, index) => x * (long)Math.Pow(K, hoge.Count() - index - 1));
                            select.Add(aho.Sum() + 1L);
                        }
                        ans = string.Join(" ", select);
                    }

                    Console.WriteLine($"Case #{c}: {ans}");
                    tw.WriteLine($"Case #{c}: {ans}");
                }
            }
        }
    }
}
