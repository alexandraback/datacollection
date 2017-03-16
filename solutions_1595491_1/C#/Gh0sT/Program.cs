using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace CodeJam2012
{
    class ProblemB
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            
            string[] lines = File.ReadAllLines("B-large.in");

            for (int i = 1; i < lines.Length; i++)
            {
                string[] testcase = lines[i].Split(' ');
                int S = Int32.Parse(testcase[1]);
                int P = Int32.Parse(testcase[2]);

                int s = 0;
                int ns = 0;

                for (int j = 3; j < testcase.Length; j++)
                {
                    int score = Int32.Parse(testcase[j]);
                    int r = score - P;
                    if (r >= 0)
                    {
                        if (r / 2m >= P - 1)
                            ns++;
                        if (r / 2m >= P - 2)
                            s++;
                    }
                }

                int count = ns + S > s ? s : ns + S;
                output.AppendFormat("Case #{0}: {1}", i, count);
                output.AppendLine();
            }

            File.WriteAllText("B-large.out", output.ToString());
        }
    }
}
