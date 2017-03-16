using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016Library
{
    public class Problem1A_A
    {
        public static string Run(string input)
        {
            StringBuilder output = new StringBuilder();
            string[] lines = input.Split('\n');

            int cases = int.Parse(lines[0]);

            for (int i=0; i< cases; i++)
            {
                string caseinput = lines[i + 1];
                string caseoutput = RunCase(caseinput);
                output.AppendLine("Case #" + (i + 1) + ": " + caseoutput);
            }

            return output.ToString();
        }

        private static string RunCase(string s)
        {
            char first = s[0];
            char last = s[0];
            string result = s[0].ToString();
            for (int i = 1; i < s.Length; i++)
            {
                char current = s[i];
                if (current >= first)
                {
                    first = current;
                    result = current + result;
                }
                else
                {
                    result = result + current;
                }
            }
            return result;
        }

       

        public Problem1A_A(int v)
        {

        }
        

    }

}
