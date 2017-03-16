using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class _2012QC
    {
        static void Main()
        {
            var CaseCounter = 0;
            var FirstTime = true;
            var sb = new StringBuilder();
            using (var sr = new StreamReader("2012Qc.in"))
            {
                String line;
                while ((line = sr.ReadLine()) != null)
                {
                    if (FirstTime)
                    {
                        FirstTime = false;
                        continue;
                    }
                    CaseCounter++;

                    var bounds = line.Split(Convert.ToChar(" "));
                    var LowerBound = Convert.ToInt32(bounds[0]);
                    var UpperBound = Convert.ToInt32(bounds[1]);
                    var Hits = 0;

                    for (int LowNum = LowerBound; LowNum < UpperBound; LowNum++)
                    {
                        var LowerNumberOptions = new List<int>();
                        var PossibleMatches = new List<int>();
                        var sLowNum = LowNum.ToString();
                        for (int j = 1; j < sLowNum.Length; j++)
                        {
                            var firstHalf = sLowNum.Substring(j, sLowNum.Length - j);
                            var secondHalf = sLowNum.Substring(0, j);
                            var tempInt = Convert.ToInt32(firstHalf + secondHalf);
                            if (tempInt >= LowerBound && tempInt <= UpperBound && !LowerNumberOptions.Contains(tempInt))
                                LowerNumberOptions.Add(tempInt);
                        }
                        for (int j = LowNum + 1; j <= UpperBound; j++)
                            PossibleMatches.Add(j);
                        Hits += PossibleMatches.Count(LowerNumberOptions.Contains);
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
