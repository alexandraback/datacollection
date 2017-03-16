using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;

namespace CodeJam.Problems
{
    public class CodeJam2013_QualificationRound_B : BaseProblem
    {
        protected override object SolveCase(StreamReader reader)
        {
            int[] inputs = reader.ReadLine().ConvertInputToIntArray();

            int N = inputs[0];
            int M = inputs[1];

            List<int[]> yard = new List<int[]>();

            for (int n = 0; n < N; n++)
                yard.Add(reader.ReadLine().ConvertInputToIntArray());

            for (int n = 0; n < N; n++)
            {
                for (int m = 0; m < M; m++)
                {
                    //horizontal check
                    bool horizontalPass = true;
                    for (int x = 0; x < M; x++)
                    {
                        if (yard[n][x] > yard[n][m])
                        {
                            horizontalPass = false;
                            break;
                        }
                    }
                    if (horizontalPass) continue;
                    
                    //vertical check
                    bool verticalPass = true;
                    for (int y = 0; y < N; y++)
                    {
                        if (yard[y][m] > yard[n][m])
                        {
                            verticalPass = false;
                            break;
                        }
                    }
                    if (verticalPass) continue;

                    return "NO";
                }
            }

            return "YES";
        }
    }
}
