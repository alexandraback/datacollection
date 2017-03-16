using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Solver : ISolver
    {
        BigInteger v_R;
        BigInteger v_Mililiters;

        public string Solve(System.IO.StreamReader v_Reader)
        {
            String[] v_Line = v_Reader.ReadLine().Split(' ');
            v_R = BigInteger.Parse(v_Line[0]);
            v_Mililiters = BigInteger.Parse(v_Line[1]);

            BigInteger v_Try = 1;

            while (getTotalRequiredInk(v_Try) < v_Mililiters)
            {
                v_Try *= 2;
            }
            v_Try /= 2;

            BigInteger v_MinRange = v_Try;
            BigInteger v_MaxRange = v_Try * 2;
            BigInteger v_MediumRange;
            BigInteger v_MediumNeeded;

            while (v_MaxRange - v_MinRange >= 100)
            {
                v_MediumRange = (v_MaxRange + v_MinRange) / 2;
                v_MediumNeeded = getTotalRequiredInk(v_MediumRange);
                if (v_Mililiters < v_MediumNeeded)
                {
                    v_MaxRange = v_MediumRange;
                }
                else
                {
                    v_MinRange = v_MediumRange;
                }
            }

            v_Try = v_MinRange;

            for (BigInteger i = v_Try; i <= 2 * v_Try; i++)
            {
                if (getTotalRequiredInk(i) <= v_Mililiters)
                {
                    v_Try += 1;
                }
                else
                {
                    v_Try -= 1;
                    break;
                }
            }

            return v_Try + "";
        }

        private BigInteger getTotalRequiredInk(BigInteger v_Circles)
        {
            return 2 * v_Circles * v_R + getSomatorio(v_Circles);
        }

        private BigInteger getSomatorio(BigInteger p_Number)
        {
            return 2*p_Number*p_Number-p_Number;
        }
    }
}
