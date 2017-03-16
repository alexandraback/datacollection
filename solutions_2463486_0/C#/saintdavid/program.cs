using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class program
    {
        public static bool Judge(long number)
        {
            string s = number.ToString();
            bool flag = true;
            for (int i = 0; i < s.Length; i++)            
                if (s[i] != s[s.Length - i - 1])
                {
                    flag = false;
                    break;
                }
            return flag;
        }

        public static void Main()
        {
            List<long> numbers = new List<long>();
            List<string> numroot = new List<string>();

            for (int i = 1; i < 10000000; i++)
            {
                long t = i;
                long sum = t * t;
                if ((Judge(t)) && (Judge(sum)))
                {
                    numbers.Add(sum);
                    double root = Math.Sqrt((double)sum);
                    long aa = (long)root;
                    numroot.Add(aa + "*" + aa + "=" + sum);
                }

            }
            funcs.WriteLongs(@"numbers.txt", numbers);
            funcs.WriteLines(@"roots.txt", numroot);

            //List<string> lines = funcs.getInputDocs2("input.txt");
            List<string> lines = funcs.getInputDocs2("C-small-attempt0.in");
            int sample = int.Parse(lines[0]);
            int count = 1;
            List<string> outlines = new List<string>();
            for (int i = 0; i < sample; i++)
            {
                string[] words = lines[count].Split(' '); count++;
                int A = int.Parse(words[0]); int B = int.Parse(words[1]);
                int curnum = 0;
                for (int j = 0; j < numbers.Count; j++)
                    if ((numbers[j] >= A) && (numbers[j] <= B))
                        curnum++;

                string outline = "Case #" + (i + 1).ToString() + ": " + curnum;
                outlines.Add(outline);
            }
            funcs.WriteLines(@"output_small.txt", outlines);
        }
    }
}
