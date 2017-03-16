using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minesweeper
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                Console.WriteLine("Case #{0}:", t);
                var line = Console.ReadLine().Split(' ').Select(token => Convert.ToInt32(token)).ToList();
                int R = line[0], C = line[1], M = line[2], S = R * C - M;
                if (S == 1 || R == 1 || C == 1 || C == 2 && M % 2 == 0 && S >= 4)
                {
                    for (int r = 0; r < R; ++r)
                    {
                        for (int c = 0; c < C; ++c)
                            Console.Write(r == 0 && c == 0 ? 'c' : r * C + c < S ? '.' : '*');
                        Console.WriteLine();
                    }
                }
                else if (R == 2 && M % 2 == 0 && S >= 4)
                {
                    for (int r = 0; r < R; ++r)
                    {
                        for (int c = 0; c < C; ++c)
                            Console.Write(r == 0 && c == 0 ? 'c' : 2 * c < S ? '.' : '*');
                        Console.WriteLine();
                    }
                }
                else if (R == 2 || C == 2 || S == 2 || S == 3 || S == 5 || S == 7)
                    Console.WriteLine("Impossible");
                else if (S == 4 || S == 6)
                {
                    for (int r = 0; r < R; ++r)
                    {
                        for (int c = 0; c < C; ++c)
                            Console.Write(r == 0 && c == 0 ? 'c' : 2 * c < S && r < 2 ? '.' : '*');
                        Console.WriteLine();
                    }
                }
                else
                {
                    S -= 8;
                    int Re = Math.Min(S / 2, R - 3);
                    S -= 2 * Re;
                    int Ce = Math.Min(S / 2, C - 3);
                    S -= 2 * Ce;
                    Re += 3;
                    Ce += 3;
                    for (int r = 0; r < R; ++r)
                    {
                        for (int c = 0; c < C; ++c)
                            Console.Write(r == 0 && c == 0 ? 'c' : r < Re && c < 2 || c < Ce && r < 2 || c >= 2 && r >= 2 && (r - 2) * (C - 2) + (c - 2) < S ? '.' : '*');
                        Console.WriteLine();
                    }
                }
            }
        }
    }
}
