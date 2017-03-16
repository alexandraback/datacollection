using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016Library
{
    public class Problem1A_B
    {
        public static string Run(string input)
        {
            StringBuilder output = new StringBuilder();
            string[] lines = input.Split('\n');

            int cases = int.Parse(lines[0]);

            for (int i=0; i< cases; i++)
            {
                int n = int.Parse(lines[i + 1]);
                List<List<string>> lists = new List<List<string>>();
                for (int j = 0; j < 2* n - 1; j++)
                {
                    string row = lines[i + 1 + j + 1 ];
                    lists.Add(row.Split(' ').ToList<string>());

                }
                string caseoutput = RunCase(n , lists);
                output.AppendLine("Case #" + (i + 1) + ": " + caseoutput);
            }

            return output.ToString();
        }

        private static string RunCase(int n, List<List<string>> lists)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            foreach (List<string> list in lists)
                foreach (string s in list)
                {
                    int i = int.Parse(s);
                    if (dict.ContainsKey(i))
                    {
                        dict[i] += 1;
                    }
                    else
                    {
                        dict[i] = 1;
                    }
                }

            List<int> result = new List<int>();
            foreach (int key in dict.Keys)
            {
                if (dict[key] % 2 != 0)
                    result.Add(key);
            }
            result.Sort();

            string line = "";
            foreach (int v in result)
            {
                if (line == "")
                    line = v.ToString();
                else
                    line += " " + v.ToString();
            }
            return line;
        }

        bool[] digits = { false, false, false, false, false, false, false, false, false, false };
        int number;

        public Problem1A_B(int v)
        {

        }

        public bool Say(int v)
        {
            string text = v.ToString();
            foreach (char c in text)
            {
                digits[int.Parse(c.ToString())] = true;
            }

            bool result = true;
            foreach (bool d in digits)
            {
                if (!d)
                {
                    result = false;
                    break;

                }
            }
            return result;
        }
        

    }

}
