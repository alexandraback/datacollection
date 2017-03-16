using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {

        static int[,] m;
        static int N;

        static void getfrom (int v, ref int[] list)
        {
            for (int i = 0; i < N; i++)
            {
                if (m[v, i] > 0)
                {
                    list[i] = 1;
                    getfrom(i, ref list);
                }
            }
        }

        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int test = 1; test <= tests; test++) {
                Console.Write("Case #" + test.ToString() + ": ");

                N = int.Parse(Console.ReadLine());

                m = new int[N,N];

                for (int i = 0; i < N; i++)
                {
                    string[] data = Console.ReadLine().Split(' ');
                    for (int j = 1; j < data.Length; j++)
                        m[i, int.Parse(data[j]) - 1] = 1;
                }

                bool ans = false;

                for (int i = 0; i < N; i++)
                {
                    int[] from = new int[N], from1 = new int[N];

                    for (int j = 0; j < N; j++)
                    {
                        if (m[i, j] > 0)
                        {
                            for (int k = 0; k < N; k++)
                                from1[k] = 0;

                            getfrom(j, ref from1);
                            from1[j] = 1;

                            for (int k = 0; k < N; k++)
                                if (from1[k] > 0)
                                {
                                    if (from[k] > 0)
                                    {
                                        ans = true;
                                        k = N;
                                        j = N;
                                        i = N;
                                    }
                                    else
                                        from[k] = 1;
                                }
                        }
                    }
                }

                Console.WriteLine(ans ? "Yes" : "No");
            }
        }
    }
}
