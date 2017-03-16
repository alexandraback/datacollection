using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2012
{
    class Problem3
    {
        public static void Solve(string inFilePath, string outFilePath)
        {
            using (var inFile = File.OpenText(inFilePath))
            using (var outFile = File.OpenWrite(outFilePath))
            using (var outWriter = new StreamWriter(outFile))
            {
                var cases = int.Parse(inFile.ReadLine());

                for (int c = 0; c < cases; ++c)
                {
                    List<KeyValuePair<int, int>> recycledPairs = new List<KeyValuePair<int, int>>();

                    var inputLine = inFile.ReadLine();
                    var parts = inputLine.Split(' ').Select(s => int.Parse(s)).ToList();
                    var A = parts[0];
                    var B = parts[1];

                    for (int a = A; a < B; ++a)
                    {
                        var aStr = a.ToString();
                        var aLength = aStr.Length;
                        for (int s = 1; s <= aLength - 1; ++s)
                        {
                            var bStr = aStr.Substring(s, aLength - s) + aStr.Substring(0, s);
                            var b = int.Parse(bStr);

                            if (a < b && A <= b && b <= B)
                            {
                                recycledPairs.Add(new KeyValuePair<int, int>(a, b));
                            }
                        }
                    }

                    var outLine = string.Format("Case #{0}: {1}", c + 1, recycledPairs.Distinct().Count());
                    Console.WriteLine(outLine);
                    outWriter.WriteLine(outLine);
                }
                outWriter.Flush();
            }
        }
    }
}
