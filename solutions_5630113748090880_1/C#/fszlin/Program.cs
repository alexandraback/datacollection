using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016R1
{
    public class Program
    {
        static int N;
        public static void Main(string[] args)
        {
            var input = File.ReadAllLines("../../in.txt");
            var T = int.Parse(input[0]);

            using (var writer = File.CreateText("../../out.txt"))
            {
                var idx = 1;
                for (var i = 1; i <= T; ++i)
                {
                    writer.Write($"Case #{i}: ");

                    N = int.Parse(input[idx]);
                    var lines = input.Skip(idx + 1).Take(N * 2 - 1).ToArray();
                    idx += N * 2;
                    new Program().Solve(lines, writer);
                }
            }
        }

        private void Solve(string[] input, StreamWriter o)
        {
            var heights = input
                .SelectMany(l => l.Split(' ').Select(i => int.Parse(i)))
                .OrderBy(h => h)
                .ToArray();

            var cnt = new int[2501];
            foreach (var h in heights)
            {
                cnt[h]++;
            }

            o.WriteLine(string.Join(" ", cnt
                .Select((c, i) => new { c = (c % 2) > 0, i })
                .Where(h => h.c)
                .Select(h => h.i)));
            //o.WriteLine(string.Join(" ", heights));
            //lines = input
            //    .Select(l => l.Split(' ').Select(i => int.Parse(i)).ToArray())
            //    .OrderBy(line => line[0] * 10000 + line[1])
            //    .ToArray();

            //memo = new bool[N, 2];
            //grid = new int[N, N];
            //firstRow = lines[0];

            //o.WriteLine(str);
        }
    }
}
