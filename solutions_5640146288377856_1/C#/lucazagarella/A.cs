using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace GoogleCodeJam.Rounds.R1C.A
{
    public class A : Problem
    {
        protected override string SolveCase()
        {

            String[] valoriInput = GetLine().Split(' ');

            int R = int.Parse(valoriInput[0]);
            int C = int.Parse(valoriInput[1]);
            int W = int.Parse(valoriInput[2]);

            int r = (R - 1) * (C / W) + W + (C - 1) / W;

            string res = r.ToString();

            res = res.Replace(',', '.');

            return res;
        }






    }
}


