using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class _2012QB
    {
        static void Main()
        {
            //0 - 0       0 / 3 = 0       0%3 = 0
            //1 - 1       1 / 3 = .3333   1%3 = 1
            //2 - 1 / 2   2 / 3 = .6666   2%3 = 2
            //3 - 1 / 2   3 / 3 = 1       3%3 = 0

            //4 - 2       4 / 3 = 1.333   4%3 = 1  1+1
            //5 - 2 / 3   5 / 3 = 1.666   5%3 = 2  2+0
            //6 - 2 / 3   6 / 3 = 2       6%3 = 0  2+1

            //7 - 3       7 / 3 = 2.333   7%3 = 1  2+1
            //8 - 3 / 4   8 / 3 = 2.666   8%3 = 2  3+0
            //9 - 3 / 4   9 / 3 = 3       9%3 = 0

            //10- 4       10/ 3 = 3.333  10%3 = 1
            //11- 4 / 5   11/ 3 = 3.666  11%3 = 2

            var CaseCounter = 0;
            var FirstTime = true;
            var sb = new StringBuilder();
            using (var sr = new StreamReader("2012Qb_large.in"))
            {
                String line;
                // Read and display lines from the file until the end of
                // the file is reached.
                while ((line = sr.ReadLine()) != null)
                {
                    if (FirstTime)
                    {
                        FirstTime = false;
                        continue;
                    }
                    CaseCounter++;

                    var Hits = 0;
                    var IntList = line.Split(Convert.ToChar(" ")).ToList();
                    var NumOfSurprisesLeft = Convert.ToInt32(IntList[1]);
                    var Target = Convert.ToInt32(IntList[2]);

                    IntList.RemoveRange(0,3);

                    foreach (var value in IntList)
                    {
                        var TotalScore = Convert.ToInt32(value);

                        if (TotalScore == 0)
                        {
                            if (Target == 0)
                                Hits++;
                            continue;
                        }

                        var mod = TotalScore%3;
                        var ceilingVal = Math.Ceiling((decimal)TotalScore / 3);
                        if (ceilingVal >= Target)
                            Hits++;
                        else if (ceilingVal + 1 >= Target && mod != 1 && NumOfSurprisesLeft > 0)
                        {
                            NumOfSurprisesLeft--;
                            Hits++;
                        }
                    }
                    sb.AppendLine("Case #" + CaseCounter + ": " + Hits);
                }
                using (var outfile = new StreamWriter(@"output.txt"))
                {
                    outfile.Write(sb.ToString());
                }
            }
        }
    }
}
