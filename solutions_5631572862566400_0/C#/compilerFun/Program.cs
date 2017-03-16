using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1.A.CS
{
    class Program
    {
        static void Main(string[] args)
        {
            var reader = new StreamReader("input.txt");
            var writer = new StreamWriter("output.txt");
            var testCaseCount = int.Parse(reader.ReadLine());

            for (int i = 0; i < testCaseCount; i++)
            {
                var N = int.Parse(reader.ReadLine());
                var bffs = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                var longestOut = new short[N];
                var longestIn = new short[N];

                for (int j = 0; j < N; j++)
                {
                    var visited = new bool[N];
                    visited[j] = true;
                    var friend = bffs[j] - 1;
                    while (!visited[friend])
                    {
                        visited[friend] = true;
                        friend = bffs[friend] - 1;
                    }
                    var count = visited.Count(f => f);
                    if (friend != j && bffs[bffs[friend] - 1] - 1 != friend)
                        count--;
                    longestOut[j] = (short)count;
                }

                var max = longestOut.Max();

                writer.Write("Case #{0}: ", i+1);
                writer.WriteLine(max);
            }

            reader.Close();
            writer.Flush();
            writer.Close();
        }
    }
}