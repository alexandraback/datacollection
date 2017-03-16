using System;
using System.IO;

namespace Password_Problem
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
            int A = int.Parse(s[0]);
            int B = int.Parse(s[1]);

            s = reader.ReadLine().Split(' ');
            double[] p = new double[A]; 

            for(int i=0; i<A; i++)
            {
                p[i] = double.Parse(s[i].Replace('.',','));
            }

            double[] probabylity = new double[A+1];

            double dd = p[0];
            probabylity[A] = 1 - p[0];
            int index = 0;
            for(int i=A-1; i>=0; i--)
            {
                if (i == 0)
                {
                    probabylity[i] = dd;
                }
                else
                {
                    index++;
                    probabylity[i] = dd*(1 - p[index]);
                    dd = dd*p[index];
                }
            }

            double[] sumprobabylity = new double[A + 1];
            sumprobabylity[A] = probabylity[A];
            for (int i = A - 1; i >= 0; i--)
            {
                sumprobabylity[i] = probabylity[i] + sumprobabylity[i + 1];
            }

            double swap = B+2;

            for (int bs = 0; bs <= Math.Min(A, B / 2); bs++ )
            {
                int countgood = 2*bs+ B - A + 1;
                int countbad = 2 * bs + B - A + 1 + (B + 1);

                double cc = 0;
                for(int i=0; i<=bs;i++)
                {
                    cc += probabylity[i]*countgood;
                }

                if (bs < A)
                {
                    cc += sumprobabylity[bs + 1]*countbad;
                }

                if (cc < swap)
                    swap = cc;
            }


            Console.WriteLine(string.Format("Case #{0}: {1:0.000000}", C, swap).Replace(',', '.'));
            writer.WriteLine(string.Format("Case #{0}: {1:0.000000}", C, swap).Replace(',', '.'));
        }
    }
}