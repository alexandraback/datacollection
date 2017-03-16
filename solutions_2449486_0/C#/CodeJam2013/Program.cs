namespace Lawnmower
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(args[0] + ".in"))
            using (var writer = new StreamWriter(args[0] + ".out"))
            {
                int T = Int32.Parse(reader.ReadLine());
                for (int x = 1; x <= T; ++x)
                {
                    int[] dim = reader.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
                    int N = dim[0];
                    int M = dim[1];

                    var pattern = new int[N][];
                    for (int i = 0; i < N; ++i)
                        pattern[i] = reader.ReadLine().Split(' ').Select(Int32.Parse).ToArray();

                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < M; ++j)
                        {
                            if (!HorizontallyPossible(pattern, i, j) &&
                                !VerticallyPossible(pattern, i, j))
                            {
                                Console.WriteLine("Case #{0}: NO", x);
                                writer.WriteLine("Case #{0}: NO", x);
                                goto label1;
                            }
                        }
                    }

                    Console.WriteLine("Case #{0}: YES", x);
                    writer.WriteLine("Case #{0}: YES", x);

                    label1:;
                }

                writer.Close();
            }
        }

        static bool HorizontallyPossible(int[][] pattern, int x, int y)
        {
            for (int j = 0; j < pattern[x].Length; ++j)
            {
                if (pattern[x][j] > pattern[x][y])
                    return false;
            }

            return true;
        }

        static bool VerticallyPossible(int[][] pattern, int x, int y)
        {
            for (int i = 0; i < pattern.Length; ++i)
            {
                if (pattern[i][y] > pattern[x][y])
                    return false;
            }

            return true;
        }
    }
}
