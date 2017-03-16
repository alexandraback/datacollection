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
    public class CodeJam2013_Round1C_B : BaseProblem
    {
        protected override object SolveCase()
        {
            int[] inputs = GetNextInputLine().ConvertInputToIntArray();

            int X = inputs[0];
            int Y = inputs[1];

            string xAxis;

            if (X < 0)
            {
                X = -X;
                xAxis = "EW";
            }
            else
            {
                xAxis = "WE";
            }

            string yAxis;

            if (Y < 0)
            {
                Y = -Y;
                yAxis = "NS";
            }
            else
            {
                yAxis = "SN";
            }

            string result = String.Empty;

            for (int x = 0; x < X; x++)
                result += xAxis;

            for (int y = 0; y < Y; y++)
                result += yAxis;

            return (result.Length > 500) ? ("FAIL") : (result);
        }
    }
}


