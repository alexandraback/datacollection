using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Prob1C2Big
    {
        TextWriter sw;
        int caseNo;
        internal void Run()
        {
            using (sw = File.CreateText("C2.big.out"))
            {
                caseNo = 1;

                var lines = File.ReadAllLines("B-large.in");

                var t = int.Parse(lines[0]);

                foreach (var line in lines.Skip(1))
                {
                    var parts = line.Split(' ');
                    var b = int.Parse(parts[0]);
                    var m = BigInteger.Parse(parts[1]);
                    Solve(b, m);
                    caseNo++;
                }
            }
        }

        private void Solve(int B, BigInteger M)
        {
            var maxValue = BigInteger.Pow(2, B - 2);
            if (M > maxValue)
            {
                sw.WriteLine("Case #{0}: IMPOSSIBLE", caseNo);
                return;
            }

            var matrix = new bool[B, B];

            BigInteger count = 1;

            matrix[0, 1] = true;
            int i = 2;
            while (2 * count <= M)
            {
                for (int h = 0; h < i; h++)
                    matrix[h, i] = true;
                i++;
                count *= 2;
            }
            var diff = M;
            var last = i - 1;

            if (B - i == 1)
            {
                while (diff > 0)
                {
                    if (count <= diff)
                    {
                        diff -= count;
                        matrix[last, i] = true;
                    }

                    count /= 2;
                    last--;
                }
            }
            if (B - i > 1)
                matrix[i, B - 1] = true;

            //WalkMatrix(matrix, B);
            //Console.WriteLine(walkCount);
            sw.WriteLine("Case #{0}: POSSIBLE", caseNo);
            sw.WriteMatrix(matrix, B);
        }

        
        BigInteger walkCount;
        bool[] visited;

        void WalkMatrix(bool[,] matrix, int B)
        {
            walkCount = 0;
            visited = new bool[B];
            WalkMatrix(matrix, 0, B);
        }

        private void WalkMatrix(bool[,] matrix, int current, int B)
        {
            if (current == B - 1) { walkCount++; return; }
            visited[current] = true;
            for (int m = current + 1; m < B; m++)
            {
                if (matrix[current, m])
                    WalkMatrix(matrix, m, B);
            }

            visited[current] = false;
        }        
    }

    public static class extension
    {
        public static void WriteMatrix(this TextWriter tw, bool[,] matrix, int B)
        {
            for (int m = 0; m < B; m++)
            {
                for (int n = 0; n < B; n++)
                    tw.Write(matrix[m, n] ? 1 : 0);
                tw.WriteLine();
            }
        }
    }
}
