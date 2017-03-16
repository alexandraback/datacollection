using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1b
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "A";
                string ptype = "small-attempt1";
                //string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in",root,problem,ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string N = lines[idx++];
                    int moves = 0;
                    int offset = 0;
                    if (N[N.Length - 1] == '0')
                    {
                        offset = 1;
                        N = (long.Parse(N) - 1).ToString();
                    }
                    if (N.Length == 1)
                    {
                        moves = int.Parse(N);
                    }
                    else
                    {
                        int l10 = N.Length;
                        moves = calc(l10);
                        moves += calc2(N);
                    }
                    tw.WriteLine("Case #{0}: {1}", a + 1, moves + offset);
                }

                tw.Close();
            }
        }

        private static int calc2(string N)
        {
            string first = N[0] + "";
            bool swap = first != "1";
            for (int a = 1; a < N.Length / 2; a++)
            {
                first = N[a] + first;
                if (N[a] != '0')
                {
                    swap = true;
                }
            }
            string second = "";
            for (int a = N.Length / 2; a < N.Length; a++)
            {
                second += N[a];
            }
            int sec = second == "" ? 0: int.Parse(second);
            int fir = first == "" ? 0 : int.Parse(first);
            return swap ? fir + sec : sec;
        }

        private static int calc(int l10)
        {
            if (l10 == 1)
            {
                return 0;
            }
            int moves = 0;
            string first = "";
            for (int a = 0; a < l10 / 2; a++)
            {
                first += "9";
            }
            string second = "";
            for (int a = 0; a < l10 - (l10 / 2) -1; a++)
            {
                second += "9";
            }
            int sec = second == "" ? 0 : int.Parse(second);
            moves += int.Parse(first) + sec + 1;
            
            return moves + calc(l10 - 1);
        }
    }
}
