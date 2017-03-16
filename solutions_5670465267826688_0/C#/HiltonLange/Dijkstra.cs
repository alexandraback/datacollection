using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Dijkstra : GCJBase
    {
        public override void Solve()
        {
            initTransforms();
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split();
                int let = int.Parse(s[0]);
                long rep = long.Parse(s[1]);
                string str = Console.ReadLine();
                string ret = dijkPoss(str, rep);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string dijkPoss(string str, long rep)
        {
            int iter = 0;
            int state = 3;
            int statesign = 1;
            int offset=0;
            // Look for i
            do
            {
                Next(ref str, ref iter, ref offset, ref state, ref statesign);
                if (iter >= rep) return "NO";
                if (state == 0 && statesign == 1) break;
            } while (true);
            
            // Look for k
            do
            {
                Next(ref str, ref iter, ref offset, ref state, ref statesign);
                if (iter >= rep) return "NO";
                if (state == 2 && statesign == 1) break;
            } while (true);

            // Finish on -1
            do
            {
                Next(ref str, ref iter, ref offset, ref state, ref statesign);
                if (iter >= rep)
                {
                    if (state == 3 && statesign == -1) return "YES";
                    return "NO";
                }
            } while (true);
        }

        private void Next(ref string str, ref int iter, ref int offset, ref int state, ref int statesign)
        {
            char c;
            c = str[offset++];
            if (offset >= str.Length)
            {
                offset = 0;
                iter++;
            }

            int c2;
            switch (c)
            {
                case 'i':
                    c2 = 0;
                    break;
                case 'j':
                    c2 = 1;
                    break;
                case 'k':
                    c2 = 2;
                    break;
                default:
                    throw new NotImplementedException();
            }
            int state2, statesign2;
            mult(state, c2, statesign, 1, out state2, out statesign2);
            state = state2;
            statesign = statesign2;
        }

        int[,] transforms = new int[4, 4];
        int[,] signs = new int[4, 4];

        private void initTransforms()
        {
            // 0: i
            // 1: j
            // 2: k
            // 3: 1

            // 1: +
            // -1: -

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    transforms[i, j] = 99;
                    signs[i, j] = 99;
                }
            }

            // Identity
            transforms[0, 0] = 3;
            signs[0, 0] = -1;
            transforms[1, 1] = 3;
            signs[1, 1] = -1;
            transforms[2, 2] = 3;
            signs[2, 2] = -1;
            transforms[3, 3] = 3;
            signs[3, 3] = 1;

            // With 1
            transforms[0, 3] = 0;
            signs[0, 3] = 1;
            transforms[1, 3] = 1;
            signs[1, 3] = 1;
            transforms[2, 3] = 2;
            signs[2, 3] = 1;

            // 1 with
            transforms[3, 0] = 0;
            signs[3, 0] = 1;
            transforms[3, 1] = 1;
            signs[3, 1] = 1;
            transforms[3, 2] = 2;
            signs[3, 2] = 1;

            // ij
            transforms[0, 1] = 2;
            signs[0, 1] = 1;
            transforms[1, 2] = 0;
            signs[1, 2] = 1;
            transforms[2, 0] = 1;
            signs[2, 0] = 1;

            // ji
            transforms[1, 0] = 2;
            signs[1, 0] = -1;
            transforms[2, 1] = 0;
            signs[2, 1] = -1;
            transforms[0, 2] = 1;
            signs[0, 2] = -1;
        }

        private void mult(int c1, int c2, int sign1, int sign2, out int res, out int ressign)
        {
            res = transforms[c1, c2];
            ressign = signs[c1, c2];
            ressign *= sign1 * sign2;
        }
    }

}
