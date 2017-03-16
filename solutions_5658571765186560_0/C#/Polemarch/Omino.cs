using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Omino
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var n in Enumerable.Range(1, numTestCases))
            {
                var parts = helper.ReadInt32Array();
                var canAlwaysWin = CanAlwaysWinSmall(parts[0], parts[1], parts[2]);

                helper.OutputCase(canAlwaysWin ? "GABRIEL" : "RICHARD");
            }
        }

        public static bool CanAlwaysWinSmall(int X, int R, int C)
        {
            if(X == 1)
            {
                return true;
            }
            if(X == 2)
            {
                return R % 2 == 0 || C % 2 == 0;
            }
            if(X == 3)
            {
                if(R != 3 && C != 3) return false;
                var other = R * C / 3;
                return other >= 2;
            }
            if(X == 4)
            {
                if(R != 4 && C != 4) return false;
                var other = R * C / 4;
                return other >= 3;
            }
            throw new NotImplementedException();
        }
    }
}
