using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cjf
{
    partial class Algoritmo
    {
        public void Main()
        {
            int A, B; double minimumKeyStrokes, S1, pressEnterRigthAway, backSpace;
            double[] Pi;
            int T = readIntLine();
            for (int t = 1; t <= T; ++t)
            {
                A = readIntSpace();
                B = readIntLine();
                Pi = new double[A + 1];
                S1 = 1;
                for (int a = 1; a <= A; ++a)
                {
                    Pi[a] = readDoubleSpace();
                    S1 *= Pi[a];
                }
                //keep trying
                minimumKeyStrokes = S1 * (B - A + 1) + (1 - S1) * (B - A + 2 + B);

                //just press enter right away
                pressEnterRigthAway = (B + 2);
                if (minimumKeyStrokes > pressEnterRigthAway)
                    minimumKeyStrokes = pressEnterRigthAway;

                //backspace
                for (int nb = 1; nb <= A; ++nb)
                {
                    S1 = 1;
                    for (int a = 1; a <=(A - nb); ++a)
                    {
                        S1 *= Pi[a];
                    }
                    backSpace = (S1) * (nb * 2 + B - A + 1) + (1 - S1) * ((nb + B) * 2 - A + 2);
                    if (minimumKeyStrokes > backSpace)
                        minimumKeyStrokes = backSpace;
                }
                
                Case(t, minimumKeyStrokes);
                //Reset Variables TextCase
            }
        }
    }
}
