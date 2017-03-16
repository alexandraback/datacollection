using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamManager
{
    class A12012 : SolutionBase
    {
        public override void ProcessOne(int processNumber, System.IO.StreamReader input, System.IO.StreamWriter output)
        {
            int[] data = base.ReadLineAsIntTable(input);
            int A = data[0];
            int B = data[1];
            double[] prob = base.ReadLineAsDoubleTable(input);
            double[] aver2case = new double[A];

            // 1 case - continue typing
            double probgood = 1;
            foreach (double d in prob)
            {
                probgood *= d;
            }
            double aver1 = probgood * (B - A + 1) + (1 - probgood) * (B - A + 1 + B + 1);

            // 2 case - delete some
            probgood = 1;
            double aver2 = Double.MaxValue;
            for (int i = 0; i < A; i++)
            {
                double aver = probgood * (A-i + B - i + 1) + (1 - probgood) * (A-i + B - i + 1 + B + 1);
                aver2 = Math.Min(aver, aver2);
                probgood *= prob[i];
            }

            double result = Math.Min(aver1, aver2);

            // 3 case giveup
            double aver3 = 1 + B + 1;

            result = Math.Min(result, aver3);
            base.StoreResults(output, processNumber, result,6);
        }
    }
}
