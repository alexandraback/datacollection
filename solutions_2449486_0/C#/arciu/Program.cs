using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LawnMower
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;
            T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int[] s = Console.ReadLine().Split(' ').Select(w => int.Parse(w)).ToArray();
                int N = s[0], M = s[1];
                int[][] b = new int[N][];
                for (int i = 0; i < N; i++)
                {
                    b[i] = Console.ReadLine().Split(' ').Select(w => int.Parse(w)).ToArray();
                }
                List<Tuple<int, int, int>> tup = new List<Tuple<int, int, int>>(N*M);
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        tup.Add(Tuple.Create(b[i][j], i, j));
                    }
                }
                tup = tup.OrderBy(tu => tu.Item1).ToList();
                bool result = true;
                foreach (var item in tup)
                {
                    bool ok1 = true;
                    for (int i = 0; i < N; i++)
                        if (b[i][item.Item3] > item.Item1)
                            ok1 = false;
                    bool ok2 = true;
                    for (int j = 0; j < M; j++)
                        if (b[item.Item2][j] > item.Item1)
                            ok2 = false;
                    if (ok1 || ok2)
                        b[item.Item2][item.Item3] = 1;
                    else
                    {
                        result = false;
                        break;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", t, result ? "YES" : "NO");
            }

        }
    }
}
