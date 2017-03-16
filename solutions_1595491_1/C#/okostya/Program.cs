using System;
using System.IO;

namespace Dancing_With_the_Googlers
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"B-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int S = int.Parse(s[1]);
            int p = int.Parse(s[2]);

            int[] t = new int[N];

            for(int i=0; i<N; i++)
            {
                t[i] = int.Parse(s[3+i]);
            }

            int[] maxM = new int[] {0,1,4,7,10,13,16,19,22,25,28 };
            int[] minM = new int[] {0,1,2,5,8,11,14,17,20,23,26 };

            int max = maxM[p];
            int min = minM[p];

            int swap1 = 0;
            int swap = 0;

            for (int i = 0; i < N; i++ )
            {
                if (t[i] >= max)
                    swap++;
                else if (t[i] >= min)
                    swap1++;
            }

            swap += Math.Min(swap1, S);

                Console.WriteLine("Case #{0}: {1}", C, swap);
            writer.WriteLine("Case #{0}: {1}", C, swap);
        }
    }
}