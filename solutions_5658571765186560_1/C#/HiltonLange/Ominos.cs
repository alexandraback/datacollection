using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Ominos : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split();
                int X = int.Parse(s[0]);
                int R = int.Parse(s[1]);
                int C = int.Parse(s[2]);
                string ret = OminoPossible(X, R, C);

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

        private const string CANBLOCK = "RICHARD";
        private const string CANBUILD = "GABRIEL";

        private string OminoPossible(int X, int R, int C)
        {
            if (R > C)
            {
                int temp = R;
                R = C;
                C = temp;
            }

            if (R * C % X > 0) return CANBLOCK;

            if (X >= 7) return CANBLOCK;

            if (X == 6)
            {
                if (R <= 3) return CANBLOCK;
                return CANBUILD;
            }

            if (X == 5)
            {
                if (R <= 3)
                {
                    if (C <= 5) return CANBLOCK;
                    if (C >= 10) return CANBUILD;
                    throw new Exception(string.Format("5: 3 and {0}",C));
                }
                return CANBUILD;
            }

            if (X == 4)
            {
                if (R <= 2) return CANBLOCK;
                return CANBUILD;
            }

            if (X == 3)
            {
                if (R == 1) return CANBLOCK;
                return CANBUILD;
            }

            if (X == 2) return CANBUILD;

            if (X == 1) return CANBUILD;

            throw new Exception(string.Format("No X matched: {0}", X));
        }
    }
}
