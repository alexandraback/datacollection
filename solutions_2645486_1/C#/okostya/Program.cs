using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Manage_your_Energy
{
    class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"B-small-attempt0.in.txt";
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
        static int[] nn;
        static int E;
        static int R;
        static long max(int index, int mindex, int count)
        {
            if (index == mindex)
                return 0;

            int maxc = Math.Min(E, count + R);
            if (index == mindex - 1)
            {
                return nn[index] * maxc;
            }
            
            int maxv = index;
            for (int i = index + 1; i < mindex; i++)
            {
                if (nn[maxv] < nn[i])
                    maxv = i;
            }

            long rcount = Math.Min(E, count + (long)R * (maxv - index+1));

            long maxx = max(index,maxv,count, rcount-R) +   nn[maxv] * rcount + max(maxv+1, mindex, 0);
            return maxx;
        }

        static long max(int index, int mindex, int count, long vcount)
        {
            if (mindex <= index)
                return 0;
            if (vcount < 0)
                vcount = 0;

            int maxc = Math.Min(E, count + R);
            if (index == mindex - 1)
            {
                if (maxc > vcount)
                    return nn[index] * (maxc - vcount);
                return 0;
            }

            int maxv = index;
            for (int i = index + 1; i < mindex; i++)
            {
                if (nn[maxv] < nn[i])
                    maxv = i;
            }
            long rcount = Math.Min(E, count + (long)R * (maxv - index+1));
            long ncount = vcount - (mindex - maxv-1) * (long)R;
            if (ncount >= 0)
            {
                if (ncount >= rcount)
                    return max(index, maxv, count, ncount - rcount);
                else
                {
                    rcount -= ncount;
                    return max(index, maxv, count, E - R) + nn[maxv] * rcount;
                }
            }
            else
            {
                return max(index, maxv, count, rcount - R) + nn[maxv] * rcount + max(maxv + 1, mindex, 0, vcount);
            }
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
             E = int.Parse(s[0]);
             R = int.Parse(s[1]);
            int N = int.Parse(s[2]);

             nn = new int[N];
            s = reader.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                nn[i] = int.Parse(s[i]);
            }

            long count = max(0, N, E);


            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);

        }
    }
}
