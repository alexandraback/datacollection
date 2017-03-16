using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program3
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"../../C-large.in");

            lines[0] = null;

            int ct = 1;
            List<string> output = new List<string>();
            foreach (string line in lines)
            {
                if (line == null)
                    continue;
                string res = "Case #" + ct + ": ";
                int result = 0;

                List<string> inputs = line.Split(new Char[] { ' ' }).ToList();

                int bot = int.Parse(inputs[0]);
                int top = int.Parse(inputs[1]);

                Dictionary<int, HashSet<int>> pairs = new Dictionary<int, HashSet<int>>();

                for (int i = bot; i <= top; i++)
                {
                    pairs.Add(i, new HashSet<int>());
                    string temp = i.ToString();
                    int count = 1;

                    for (int j = temp.Length - 1; j > 0; j--)
                    {
                        string first = temp.Substring(0, j);
                        string last = temp.Substring(j, count);
                        int m = int.Parse(last + first);
                        if (m > i && m <= top && !pairs.ContainsKey(m) && !pairs[i].Contains(m))
                        {
                            pairs[i].Add(m);
                        }
                        count++;
                    }
                }

                foreach (int key in pairs.Keys)
                {
                    result += pairs[key].Count;
                }

                res += result;
                output.Add(res);
                ct++;
            }
            System.IO.File.WriteAllLines("../../C-large.out", output);
        }
    }
}
