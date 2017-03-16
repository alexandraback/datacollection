using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    public class Prob1C2
    {
        TextWriter sw;
        internal void Run()
        {
            using (sw = File.CreateText("C2.debug.out"))
            {
                for (int i=2; i<= 6; i++)
                    Solve(i);

                var lines = File.ReadAllLines("B-small-attempt0.in");

                var t = int.Parse(lines[0]);

                int c = 1;
                using (var sw2 = File.CreateText("C2.out"))
                foreach (var line in lines.Skip(1))
                {
                    var parts = line.Split(' ');
                    var b = int.Parse(parts[0]);
                    var m = int.Parse(parts[1]);

                    if (solutionDict.ContainsKey(b) && solutionDict[b].ContainsKey(m))
                    {
                        sw2.WriteLine("Case #{0}: POSSIBLE", c);
                        for (int e = 0; e < b; e++)
                        {
                            for (int f = 0; f < b; f++)
                                sw2.Write(solutionDict[b][m][e, f] ? 1 : 0);
                            sw2.WriteLine();
                        }
                    }
                    else
                    {
                        sw2.WriteLine("Case #{0}: IMPOSSIBLE", c);
                    }

                    c++;
                }
            }
        }

        Dictionary<int, Dictionary<int, bool[,]>> solutionDict = new Dictionary<int, Dictionary<int, bool[,]>>();

        private void Solve(int b)
        {
            sw.WriteLine("B = " + b);
            B = b;
            var bits = (B * (B - 1) / 2);
            var limit = (int)Math.Pow(2, bits + 1) - 1;
            walkDict = new Dictionary<int, bool[,]>(); 
            
            for (int i = 1; i <= limit; i++)
            {
                ConstructMatrix(i, bits);
            }

            foreach (var pair in walkDict)
            {
                sw.WriteLine(pair.Key);
                for (int m = 0; m < B; m++)
                {
                    for (int n = 0; n < B; n++)
                        sw.Write(pair.Value[m, n]);
                    sw.WriteLine();
                }
            }

            solutionDict[B] = walkDict;
        }

        int B;
        private void ConstructMatrix(int i, int bits)
        {
            var originalI = i;
            var matrix = new bool[B, B];

            int o = 0, count = 1, count2 = 2;

            while (o < bits)
            {
                matrix[count / B, count % B] = i % 2 == 1;
                i /= 2;
                o++;

                count++;

                if (count % B == 0)
                {
                    count += count2;
                    count2++;
                }
            }


            walkCount = 0;
            visited = new bool[B];
            WalkMatrix(matrix, 0);
            if (walkCount > 0)
            {
                if (!walkDict.ContainsKey(walkCount))
                    walkDict.Add(walkCount, matrix);
            }
        }

        Dictionary<int, bool[,]> walkDict = new Dictionary<int, bool[,]>();
        int walkCount;
        bool[] visited = new bool[6];
        private void WalkMatrix(bool[,] matrix, int current)
        {
            if (current == B - 1) { walkCount++; return; }
            visited[current] = true;
            for (int m = current+1; m < B; m++)
            {
                if (matrix[current, m])
                    WalkMatrix(matrix, m);
            }

            visited[current] = false;
        }
    }
}
