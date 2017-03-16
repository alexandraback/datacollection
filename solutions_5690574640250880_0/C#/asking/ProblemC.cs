using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualRound
{
    class ProblemC
    {
        public static void solve()
        {
            //string inFile = @"..\..\c-sample.in";
            string inFile = @"..\..\C-small-attempt3.in";
            //string inFile = @"..\..\D-large.in";
            string outFile = inFile.Substring(0, inFile.Length - 2) + "out";

            using (var sr = new StreamReader(inFile))
            using (var sw = new StreamWriter(outFile, false))
            {
                int T = int.Parse(sr.ReadLine());
                for (int casei = 1; casei <= T; casei++)
                {
                    var arr = sr.ReadLine().Split(" ".ToArray(), StringSplitOptions.RemoveEmptyEntries);
                    int R = int.Parse(arr[0]);
                    int C = int.Parse(arr[1]);
                    int M = int.Parse(arr[2]);
                    int N = R * C;

                    sw.WriteLine("Case #{0}:", casei);

                    if (N == M + 1)
                    {
                        printM(sw, R, C, 0, 0, 0);
                        continue;
                    }

                    var possible = Enumerable.Range(1, R)
                        .SelectMany(r => Enumerable.Range(1, C), (r, c) => new { r = r, c = c, resM = M - (N - r * c) })
                        .Where(p => p.resM >= 0 && p.resM < Math.Min(p.r, p.c))
                        .Where(p => Math.Min(p.r, p.c) != 1 || Math.Min(R, C) == 1)
                        .ToArray();

                    //Console.WriteLine("feas:");
                    //foreach (var t in possible)
                    //{
                    //    Console.WriteLine("{0} {1} {2}", t.r, t.c, t.resM);
                    //}

                    var anss = possible
                        .Where(p => (Math.Min(p.r, p.c) > 2 && p.resM <= (p.r - 2) * (p.c - 2))
                            || p.resM == 0)
                        .ToArray();

                    //Console.WriteLine("ans:");
                    //foreach (var t in anss)
                    //{
                    //    Console.WriteLine("{0} {1} {2}", t.r, t.c, t.resM);
                    //}

                    if (anss == null || anss.Length == 0)
                    {
                        sw.WriteLine("Impossible");

                        Console.WriteLine("Case #{0}:", casei);
                        Console.WriteLine("{0} {1} {2}", R, C, M);
                        Console.WriteLine("Impossible");
                    }
                    else
                    {
                        var ans = anss[0];
                        printM(sw, R, C, ans.r, ans.c, ans.resM);
                    }                    
                }
            }
        }

        public static void printM(StreamWriter sw, int r, int c, int rr, int cc, int res)
        {
            var mat = new char[r][];
            for(int i = 0; i < r; i++)
            {
                mat[i] = Enumerable.Repeat('*', c).ToArray();
            }
            for (int i = 0; i < rr; i++)
            {
                for (int j = 0; j < cc; j++)
                {
                    mat[i][j] = '.';
                }
            }
            // set rest mine
            for (int cnt = res, i = rr - 1, j = cc - 1; cnt > 0; )
            {
                mat[i][j] = '*';
                cnt--;
                j--;
                if (j < 2)
                {
                    i--;
                    j = cc - 1;
                }
            }
            mat[0][0] = 'c';

            for (int i = 0; i < r; i++)
            {
                sw.WriteLine(new string(mat[i]));
            }
        }
    }
}
