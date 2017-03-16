using System;
using System.IO;

namespace Safety_in_Numbers
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"A-large.in.txt";

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
            int[] S = new int[N];
            int sum = 0;
            for(int i=0; i<N;i++)
            {
                S[i] = int.Parse(s[i+1]);
                sum += S[i];
            }

            Console.Write("Case #{0}:", C);
            writer.Write("Case #{0}:", C);

            int count = N;
            int sumwithout = sum;

            m1:
            int maxi = 0;
            for (int i = 1; i < N; i++)
            {
                if (S[maxi] < S[i])
                {
                    maxi = i;
                }
            }

            if (S[maxi] > 0 && S[maxi] > 1.0*(sum+sumwithout)/count)
            {
                sumwithout -= S[maxi];
                count--;
                S[maxi] = -1;
                goto m1;
            }

            for(int i=0; i<N; i++)
            {

                double d=0;
                if (S[i] >=0 )
                {
                    d = 100.0 * (1.0*(sum + sumwithout) / count - S[i]) / sum;
                }
                if (d<0)
                    d = 0;

                Console.Write(string.Format(" {0:0.000000}", d).Replace(',', '.'));
                writer.Write(string.Format(" {0:0.000000}", d).Replace(',', '.'));
            }

            Console.WriteLine();
            writer.WriteLine();
        }
    }
}