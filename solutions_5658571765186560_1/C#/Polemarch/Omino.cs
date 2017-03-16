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
                var canAlwaysWin = CanAlwaysWinLarge(parts[0], parts[1], parts[2]);

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

        public static bool CanAlwaysWinLarge(int X, int R, int C)
        {
            if(X == 1) return true;
            if(X == 2)
            {
                return R * C % 2 == 0;
            }
            if(X == 3)
            {
                if(R == 1 || C == 1) return false;
                if((R * C) % 3 != 0)
                    return false;                
                return true;
            }
            if(X == 4)
            {
                if((R * C) % 4 != 0)
                    return false;
                //Must be able to support 1x4
                if(R < 4 && C < 4)
                    return false;
                //2x? won't work because a T will split it into two odd parts
                if(R <= 2 || C <= 2)
                    return false;
                //Anything else will
                return true;
            }
            if(X == 5)
            {
                if((R * C) % 5 != 0)
                    return false;
                //Must be able to support 1x5
                if(R < 5 && C < 5)
                    return false;
                //2x? won't work because a of the L piece
                if(R <= 2 || C <= 2)
                    return false;
                //3x5 won't work, but 3x10 or 3x15 will!
                if(R == 3 || C == 3)
                    return R >= 10 || C >= 10;
                //5x4 and up will work!
                return true;
            }
            if(X == 6)
            {
                if((R * C) % 6 != 0)
                    return false;
                //Must be able to support 1x6
                if(R < 6 && C < 6)
                    return false;
                //3x? won't work because the 4 piece creates an unreachable square
                /* X X
                 * XXX
                 *   X       */
                if(R <= 3 || C <= 3)
                    return false;
                //6x4 and up will work!
                return true;
            }
            else
            {
                return false;  //For 7+ ominoes, Richard can pick a piece that will have some squares inaccessible by anything else
            }
        }
    }
}
