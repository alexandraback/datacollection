using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace GoogleCodeJam.Practice._2012.Round1C
{
    public class DiamondInheritance
    {
        private const string inputsmall = @"E:\Development\CodeJam\2012\Round1C\A-small-attempt2.in";
        private const string inputlarge = @"E:\Development\CodeJam\2012\Round1C\A-large-practice.in";
        private const string inputtest = @"E:\Development\CodeJam\2012\Round1C\A-test.in";
        private const string outputsmall = @"E:\Development\CodeJam\2012\Round1C\A-small.out";
        private const string outputlarge = @"E:\Development\CodeJam\2012\Round1C\A-large.out";
        private const string outputtest = @"E:\Development\CodeJam\2012\Round1C\A-test.out";

        public void Run()
        {
            //Calculate(inputtest, outputtest);
            Calculate(inputsmall, outputsmall);
            //Calculate(inputlarge, outputlarge);
        }

        private void Calculate(string input, string output)
        {
            string[] source = File.ReadAllLines(input);
            int cases = int.Parse(source[0]);
            string[] results = new string[cases];

            int lineCount = 0;
            for (int i = 0; i < cases; i++)
            {
                string result = string.Empty;

                int N = int.Parse(source[1 + lineCount]);
                Dictionary<int, int[]> dic = new Dictionary<int, int[]>();
                //ArrayList al = new ArrayList();
                bool found = false;
                for (int j = 1; j <= N; j++)
                {
                    int counts = int.Parse(source[lineCount+1+j].Split(' ').First());
                    int[] targets = source[lineCount + 1 + j].Split(' ').Reverse().Take(counts).Select(x => int.Parse(x)).ToArray();
                    dic.Add(j, targets);                    
                }

                for (int j = 1; j <= N; j++)
                {
                    int[] endpoint = dic[j];
                    ArrayList al = new ArrayList();
                    foreach (int t in endpoint)
                    {
                        int[] a = dic[t];
                        if (Check(dic, al, a))
                        {
                            found = true;
                            break;
                        }
                        if (al.Contains(t))
                        {
                            found = true;
                            break;
                        }
                        al.Add(t);
                    }
                    if (found)
                    {
                        break;
                    }
                }


                if (found)
                    result = "Yes";
                else
                    result = "No";

                lineCount += N + 1;
                results[i] = string.Format("Case #{0}: {1}", i + 1, result);
            }
            File.WriteAllLines(output, results);
        }

        private static bool Check(Dictionary<int, int[]> dic, ArrayList al, int[] newTargets)
        {
            foreach (int t in newTargets)
            {
                int[] a = dic[t];
                if (Check(dic, al, a))
                    return true;

                if (al.Contains(t))
                    return true;
                al.Add(t);
            }
            return false;
        }
    }
}
