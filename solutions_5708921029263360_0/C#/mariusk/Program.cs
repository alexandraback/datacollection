using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            using (var reader = new StreamReader(@"..\..\input.txt"))
            using (var writer = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(reader.ReadLine());

                for (int currentCase = 0; currentCase < caseCount; currentCase++)
                {
                    writer.Write("Case #" + (currentCase + 1) + ": ");
                    Solve(reader, writer);
                }
            }
        }

        private static void Solve(StreamReader reader, StreamWriter writer)
        {
            var data = reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

            var J = data[0];
            var P = data[1];
            var S = data[2];
            var K = data[3];

            var arr = new int[10000];
            var results = new List<int>();

            for (var i = 1; i <= J; i++)
            {
                for (var m = 1; m <= P; m++)
                {
                    for (var r = 1; r <= S; r++)
                    {
                        var p1 = i * 100 + m * 10;
                        var p2 = i * 100 + r;
                        var p3 = m * 10 + r;

                        if (arr[p1] >= K || arr[p2] >= K || arr[p3] >= K)
                            continue;

                        arr[p1]++;
                        arr[p2]++;
                        arr[p3]++;
                        results.Add(i * 100 + m * 10 + r);
                    }
                }
            }

            writer.WriteLine(results.Count);
            for (var i = 0; i < results.Count; i++)
            {
                var j = results[i] / 100;
                var p = (results[i] / 10) % 10;
                var s = results[i] % 10;

                writer.WriteLine("{0} {1} {2}", j, p, s);
            }
        }

        private static void Repeat(int count, Action<int> action)
        {
            for (int i = 0; i < count; i++)
            {
                action(i);
            }
        }
    }
}
