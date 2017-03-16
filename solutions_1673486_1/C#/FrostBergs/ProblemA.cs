using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;

namespace CodeJam.Problems
{
    public class ProblemA : BaseProblem
    {
        protected override object SolveCase(StreamReader reader)
        {
            int[] inputs = reader.ReadLine().ConvertInputToIntArray();
            
            int A = inputs[0];
            int B = inputs[1];
            int left = B - A;
            List<decimal> factors = new List<decimal>();

            decimal[] inputs2 = reader.ReadLine().ConvertInputToDecimalArray();
            int len = inputs2.Length;
            decimal factor = 1m;
            foreach (decimal d in inputs2)
            {
                factor *= d;
                factors.Add(factor);                
            }

            List<decimal> results = new List<decimal>();
            results.Add(factor * Convert.ToDecimal(left + 1) + (1m - factor) * Convert.ToDecimal(left + 1 + B + 1));
            results.Add(Convert.ToDecimal(1 + B + 1));

            for (int b = 1; b < A; b++)
                results.Add(factors[len - 1 - b] * (b + left + b + 1) + (1m - factors[len - 1 - b]) * (b + left + b + 1 + B + 1));

            return results.Min().ToString("0.000000");
        }
    }
}
