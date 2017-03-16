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

            long range = 10000000;
            for (long i = 1; i < range; i++)
            {
                long t = i;
                if (Judge(t))
                {
                    long sum = t * t;
                    if (Judge(sum))
                    {
                        numbers.Add(sum);
                        double root = Math.Sqrt((double)sum);
                        long aa = (long)root;
                        numroot.Add(aa + "*" + aa + "=" + sum);
                    }
                }
            }
            funcs.WriteLongs(@"numbers.txt", numbers);
            funcs.WriteLines(@"roots.txt", numroot);

            //List<string> lines = funcs.getInputDocs2("input.txt");
            List<string> lines = funcs.getInputDocs2("C-large-1.in");
            int sample = int.Parse(lines[0]);
            int count = 1;
            List<string> outlines = new List<string>();
            for (int i = 0; i < sample; i++)
            {
                string[] words = lines[count].Split(' '); count++;
                long A = long.Parse(words[0]); long B = long.Parse(words[1]);
                int curnum = 0;
                for (int j = 0; j < numbers.Count; j++)
                    if ((numbers[j] >= A) && (numbers[j] <= B))
                        curnum++;

                string outline = "Case #" + (i + 1).ToString() + ": " + curnum;
                outlines.Add(outline);
            }
            funcs.WriteLines(@"output_mid.txt", outlines);
        }
    }
}
