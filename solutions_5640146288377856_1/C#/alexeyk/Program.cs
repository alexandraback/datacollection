using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large-out.txt"))
                {
                    SolveIt(sr, sw);
                }
            }
        }

        private static void SolveIt(StreamReader sr, StreamWriter sw)
        {
            int T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int R = splitted[0];
                int C = splitted[1];
                int W = splitted[2];

                long res = R * (C / W) + W - 1;
                if (C % W != 0)
                {
                    res++;
                }

                sw.WriteLine("Case #{0}: {1}", (t+1), res);
            }
        }
    }
}
