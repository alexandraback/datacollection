using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1B_1
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\r1_1_2.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\r1_1_2Out.txt");
            var total = long.Parse(file.ReadLine());

            for (long i = 1; i <= total; i++)
            {
                bool feglaWon = false;
                var nlines = int.Parse(file.ReadLine());

                string baseString = null;
                var lineLengths = new List<List<long>>();
                for (int j = 0; j < nlines; j++)
                {
                    var currentLineLen = new List<long>();
                    lineLengths.Add(currentLineLen);
                    var line = file.ReadLine();
                    var localString = string.Empty;
                    foreach (char c in line)
                    {
                        if (localString == string.Empty)
                        {
                            localString = localString + c;
                            currentLineLen.Add(1);
                            continue;
                        }

                        if (localString.Last() != c)
                        {
                            localString = localString + c;
                            currentLineLen.Add(1);
                        }
                        else
                        {
                            currentLineLen[currentLineLen.Count - 1] = currentLineLen[currentLineLen.Count - 1] + 1;
                        }
                    }
                    if (baseString == null)
                    {
                        baseString = localString;
                    }

                    if (baseString != localString)
                        feglaWon = true;

                }

                if (feglaWon)
                    outFile.WriteLine(string.Format("Case #{0}: Fegla Won", i));
                else
                {
                    long minMoves = 0;
                    for (var charNum = 0; charNum < lineLengths.First().Count; charNum++)
                    {
                        long localMinMoves = long.MaxValue;

                        var minLen = lineLengths.Min(x=>x[charNum]);
                        var maxLen = lineLengths.Max(x => x[charNum]);
                        for (var l = minLen; l <= maxLen; l++)
                        {
                            var sum = lineLengths.Sum(x => Math.Abs(l - x[charNum]));
                            if (sum < localMinMoves)
                                localMinMoves = sum;
                        }
                        minMoves += localMinMoves;
                    }
                    
                    outFile.WriteLine(string.Format("Case #{0}: {1}", i, minMoves));
                }

            }

            file.Close();
            outFile.Close();
        }
    }
}
