using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace taskB
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:/temp/input_b.txt");
            StreamWriter sw = new StreamWriter("c:/temp/output_b.txt");

            int T = int.Parse(sr.ReadLine());
            int n, s, p, res, maybe;
            int[] t;
            for (int test = 0; test < T; test++)
            {
                int[] data = Array.ConvertAll<string, int>(sr.ReadLine().Split(), int.Parse);
                n = data[0];
                s = data[1];
                p = data[2];
                t = new int[n];
                for (int i = 3; i < data.Length; i++)
                {
                    t[i - 3] = data[i];
                }
                res = 0;
                maybe = 0;
                for (int i = 0; i < n; i++)
                {
                    if (3 * p - 2 <= t[i]) res++;
                    else
                    {
                        if (3 * p - 4 <= t[i] && p>=2)
                            maybe++;
                    }
                }
                res += Math.Min(maybe, s);
                sw.WriteLine("Case #{0}: {1}", test + 1, res);
            }

            sr.Close();
            sw.Close();
        }
    }
}
