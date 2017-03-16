using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace GoogleCodeJam2013
{
    class Round1A_A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("a.in");
            TextWriter fileOut = new StreamWriter("a.out");

            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 1; caseCount <= countNum; caseCount++)
            {
                string[] stringVals = fileIn.ReadLine().Split(' ');

                Int64 r = Int64.Parse(stringVals[0]);
                Int64 t = Int64.Parse(stringVals[1]);

                int ringCount = 0;
                while (t > 0)
                {
                    t -= ((r + 1) * (r + 1)) - (r*r);
                    if (t >= 0)
                    {
                        r += 2;
                        ringCount++;
                    }
                }

                fileOut.WriteLine("Case #" + caseCount + ": " + ringCount);
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();

        }
    }
}
