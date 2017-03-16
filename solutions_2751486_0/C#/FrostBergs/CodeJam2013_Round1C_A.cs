using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;
using System.Drawing;

namespace CodeJam.Problems
{
    public class CodeJam2013_Round1C_A : BaseProblem
    {
        protected override object SolveCase()
        {
            string[] inputs = GetNextInputLine().Split(' ');

            string name = inputs[0];
            int n = Int32.Parse(inputs[1]);

            long nValue = 0;
            int lastStart = -1;

            for (int i = 0; i <= name.Length - n; i++)
            {
                if (Valid(name.Substring(i, n)))
                {
                    nValue += (i - lastStart) * (name.Length - i - n + 1);
                    lastStart = i;
                }
            }

            return nValue;

        }

        private bool Valid(string subString)
        {
            return
                !(subString.Contains('a') ||
                subString.Contains('e') ||
                subString.Contains('i') ||
                subString.Contains('o') ||
                subString.Contains('u'));
        }

       
    }
}
