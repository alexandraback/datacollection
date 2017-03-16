using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJamQ1
{
    class Problem2
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("p2.in");
            StreamWriter fout = new StreamWriter("p2.out");

            int t = int.Parse(fin.ReadLine());

            for (int tn = 0; tn < t; tn++)
            {
                string inp = fin.ReadLine();
                string[] inps = inp.Split(new char[] {' '});

                int n = int.Parse(inps[0]);
                int s = int.Parse(inps[1]);
                int p = int.Parse(inps[2]);

                int v = 3 * p - 2;
                int canSolveRegular = 0;
                int canSolveSurp = 0;

                for (int k = 0; k < n; k++)
                {
                    int tot = int.Parse(inps[3 + k]);

                    if (tot < p) continue;
                    if (tot >= v) canSolveRegular++;
                    else if (tot >= v - 2) canSolveSurp++;
                }

                int max = canSolveRegular + Math.Min(canSolveSurp, s);
                fout.WriteLine("Case #{0}: {1}", tn + 1, max);
            }

            fin.Close();
            fout.Close();
        }
    }
}
