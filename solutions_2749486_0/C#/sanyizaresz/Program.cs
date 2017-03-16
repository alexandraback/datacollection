using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using gcj;

namespace Task1
{
    class Program
    {
        static StreamWriter log;

        public static void Log(string msg)
        {
        //    log.WriteLine("     "+msg);
        }


        static long fact(long i)
        {
            long r = 1;
            for (long j = 1; j <= i; j++)
            {
                r = r * j;
            }
            return r;
        }
        static long nalatt(long n, long k)
        {
            if (k > n) throw new InvalidDataException();
            return fact(n) / (fact(k) * fact(n - k));

        }

        static long brickIndex(long x, long y)
        { 
            for (long lvl = 0; ;lvl = lvl+2)
            {
                long idx = 0;
                for (long xx = lvl, yy=0; xx >= 0; xx--, yy++)
                {
                    idx++;
                    if (xx == x && yy == y) { return idx; }
                }
                idx = 0;
                for (long xx = -lvl, yy = 0; xx <= 0; xx++, yy++)
                {
                    idx++;
                    if (xx == x && yy == y) { return idx; }
                }
            }
        }


        static void Main(string[] args)
        {
            char[] sep = new char[]{' '};

            using (StreamReader tr = new StreamReader("input.txt"))
            {
                using (StreamWriter sol = new StreamWriter("solution.txt"))
                {
                    long count = long.Parse(tr.ReadLine());
                    for (long task = 0; task < count; task++)
                    {
                        string[] f = tr.ReadLine().Split(sep);
                        Solve(task + 1, sol, long.Parse(f[0]),long.Parse(f[1]));
                    }
                }
            }
            Console.WriteLine("done");
            Console.ReadLine();
        }


        
        private static void Solve(long task, StreamWriter sw, long x, long y)
        {
          //  sw.WriteLine("Case #{0}", task);
            log = sw;
            StringBuilder res = new StringBuilder();
            long cx = 0;
            long cy = 0;
            {
                for (int i = 0; i<x; i++)
                {
                    res.Append("WE");
                    cx++;
                }
            }
            {
                for (int i = 0; i > x; i--)
                {
                    res.Append("EW");
                    cx--;
                }
            }
            {
                for (int i = 0; i > y; i--)
                {
                    res.Append("NS");
                    cy--;
                }
            }
            {
                for (int i = 0; i < y; i++)
                {
                    res.Append("SN");
                    cy++;
                }
            }
            if (cy != y || cx != x) throw new Exception("");
            sw.WriteLine("Case #{0}: {1}", task, res.ToString().Replace(",", "."));
           Console.WriteLine("Case #{0}: {1}", task, res.ToString());
        }
    }
}
