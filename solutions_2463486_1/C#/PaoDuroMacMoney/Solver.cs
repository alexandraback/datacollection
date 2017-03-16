using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SquareAndFair
{
    class Solver : ISolver
    {
        private static List<long> v_FareAndSquares = new List<long>();

        public string Solve(System.IO.StreamReader v_Reader)
        {
            String[] v_Line = v_Reader.ReadLine().Split(' ');
            long v_LowerLimit = long.Parse(v_Line[0]);
            long v_UpperLimit = long.Parse(v_Line[1]);

            if (v_FareAndSquares.Count == 0)
            {
                for (long i = 1; i <= Math.Pow(10, 7); i++)
                {
                    if (isFare(i) && isFare(i * i))
                    {
                        v_FareAndSquares.Add(i * i);
                    }
                }
            }

            return v_FareAndSquares.Count(v_Item => v_Item >= v_LowerLimit && v_Item <= v_UpperLimit) + "";
        }

        private bool isFare(long i)
        {
            String v_NumberString = i + "";
            return v_NumberString == new string(v_NumberString.ToCharArray().Reverse().ToArray());
        }
    }
}
