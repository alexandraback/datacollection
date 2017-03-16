using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam3
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemD\\D-large.in"))
            {
                using (var writer = new StreamWriter("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemD\\D-large.out"))
                {
                    int testCases = int.Parse(reader.ReadLine());
                    for (int tc = 0; tc < testCases; tc++)
                    {
                        Solve(tc + 1, reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static long Pow(long x, long y)
        {
            long total = 1;
            for(long i = 0; i < y; i++)
            {
                total *= x;
            }
            return total;
        }

        static void Solve(int caseNumber, StreamReader reader, StreamWriter file)
        {
            var line = reader.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var K = line[0];
            var C = line[1];
            var S = line[2];
            var size = Pow(K, C);
            file.Write("Case #{0}:", caseNumber);
            Console.Write("Case #{0}:", caseNumber);

            long numPositions = (K + C - 1) / C;
            if (numPositions > S)
            {
                file.Write(" IMPOSSIBLE");
                Console.Write(" IMPOSSIBLE");
            }
            else
            {
                for (long i = 0; i < numPositions; i++)
                {
                    long start = 0;
                    long len = size;
                    for (long j = 0; j < Math.Min(C, K - i * C); j++)
                    {
                        len /= K;
                        start += (i * C + j) * len;
                    }
                    file.Write(" " + (start + 1));
                    Console.Write(" " + (start + 1));
                }
            }
            file.WriteLine();
            Console.WriteLine();
        }
    }
}
