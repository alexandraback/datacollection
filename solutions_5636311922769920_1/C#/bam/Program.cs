using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CodeJam2016Qualification4
{
    class Program
    {
        struct NumberProp
        {
            public bool IsPrime;
            public long Divisor;
        }
        static void Main(string[] args)
        {
            checked
            {
                var inputPath = @"C:\Users\Alexander\Downloads\D-large.in";
                var outputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q4LargeOut.txt";

                var input = File.ReadAllLines(inputPath);
                var output = new List<string>();
                var nlines = int.Parse(input[0]);

                for (int i = 1; i <= nlines; i++)
                {
                    var values = input[i].Split(new[] { ' ' });

                    int K = byte.Parse(values[0]);
                    int C = int.Parse(values[1]);
                    int S = int.Parse(values[2]);

                    //output.Add(string.Format("Case #{0}: {1}", i, string.Join(" ", Enumerable.Range(1, K))));
                    var resPositions = new List<string>();
                    int studentsAvailable = S;
                    int discoveredTiles = 0;
                    while (discoveredTiles < K)
                    {
                        studentsAvailable--;
                        if (studentsAvailable < 0)
                        {
                            break;
                        }

                        BigInteger position = discoveredTiles + 1;
                        discoveredTiles++;
                        for (int curLevel = 2; curLevel <= C; curLevel++)
                        {
                            position = (position - 1) * K + discoveredTiles;
                            if (discoveredTiles < K)
                            {
                                discoveredTiles++;
                                position++;
                            }
                        }
                        resPositions.Add(position.ToString());
                    }

                    if (studentsAvailable < 0)
                    {
                        output.Add(string.Format("Case #{0}: {1}", i, "IMPOSSIBLE"));
                    }
                    else
                    {
                        output.Add(string.Format("Case #{0}: {1}", i, string.Join(" ", resPositions)));
                    }


                }

                File.WriteAllLines(outputPath, output);
            }
        }

    }
}
