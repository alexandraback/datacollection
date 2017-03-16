using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"C:\Users\lincha\Documents\CodeJam1A\a-small.in");
            List<string> output = new List<string>();
            int N = int.Parse(input[0]);
            for (int testcase = 1; testcase <= N; testcase++)
            {
                string test = input[testcase];
                output.Add(String.Format("Case #{0}: {1}", testcase, ProcessString(test)));
            }
            File.WriteAllLines(@"C:\Users\lincha\Documents\CodeJam1A\a-small.txt", output.ToArray());
        }

        static string ProcessString(string s)
        {
            var curstring = String.Empty;
            foreach (char c in s)
            {
                var pre_append = curstring + c.ToString();
                var post_append = c.ToString() + curstring;
                if (string.Compare(pre_append, post_append, StringComparison.Ordinal) >= 0 )
                {
                    curstring = pre_append;
                }
                else
                {
                    curstring = post_append;
                }
            }
            return curstring;
        }
    }
}