using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            RunSmall(C, 0);
        }

        private static void Solve(TextReader reader, TextWriter writer)
        {
            var cases = Convert.ToInt32(reader.ReadLine());

            for (var i = 1; i <= cases; i++)
            {
                var input = reader.ReadLine().Split(' ').Select(s => Convert.ToInt32(s)).ToList();

                var res = FashionPolice(input[0], input[1], input[2], input[3]);

                writer.WriteLine($"Case #{i}: {res.Count}");
                foreach (var re in res)
                {
                    writer.WriteLine(String.Join(" ", re.Select(r => r.ToString())));
                }
            }
        }

        public static List<int[]> FashionPolice(int J, int P, int S, int K)
        {
            var all = new List<int[]>();

            for (var j = 1; j <= J; j++)
            {
                for (var p = 1; p <= P; p++)
                {
                    for (var k = 0; k < K; k++)
                    {
                        all.Add(new[] { j, p, 0 });
                    }
                }
            }

            for (var i = 0; i < all.Count; i++)
            {
                var curr = all[i];

                for (var x = 1; x <= S; x++)
                {
                    var comp = all.Take(i).ToArray();
                    var similar1Count = comp.Count(c => c[0] == curr[0] && c[2] == x);
                    var similar2Count = comp.Count(c => c[1] == curr[1] && c[2] == x);
                    var exactCount = comp.Count(c => c[0] == curr[0] && c[1] == curr[1] && c[2] == x);
                    if (similar1Count >= K || similar2Count >= K || exactCount >= 1) continue;

                    curr[2] = x;
                    break;
                }
            }

            return all.Where(c => c[2] != 0).ToList();
        } 

        public static void RunSample()
        {
            var sample = @"5
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
3 3 3 2
";

            var reader = new StringReader(sample);
            var writer = Console.Out;

            Solve(reader, writer);
            Console.ReadKey();
        }

        public static void RunSmall(string problemLetter, int attemptNo)
        {
            SolveFile(problemLetter, "-small", "-attempt" + attemptNo);
        }

        public static void RunLarge(string problemLetter)
        {
            SolveFile(problemLetter, "-large", "");
        }

        public static void SolveFile(string problemLetter, string size, string suffix)
        {
            var dir = @"C:\Users\paulijon\Downloads";

            var fileName = problemLetter + size + suffix;

            var reader = new StreamReader(Path.Combine(dir, fileName + ".in"));
            var writer = new StreamWriter(Path.Combine(dir, fileName + ".out"));

            Solve(reader, writer);

            writer.Dispose();
        }

        public const string A = "A";
        public const string B = "B";
        public const string C = "C";
    }
}