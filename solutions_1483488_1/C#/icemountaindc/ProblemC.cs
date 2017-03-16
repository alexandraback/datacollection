using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2012.Qualification
{
    class ProblemC
    {
        public static string Solve(string[] input)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < input.Length; i++)
            {
                HashSet<string> set = new HashSet<string>();
                string[] q = input[i].Split(' ');
                int A = int.Parse(q[0]);
                int B = int.Parse(q[1]);

                for (int j = A; j <= B; j++)
                {
                    string n = j.ToString();
                    for (int k = 1; k < n.Length; k++)
                    {
                        string m = n.Substring(n.Length - k, k) + n.Substring(0, n.Length - k);
                        int z = int.Parse(m);
                        if (z > j && z <= B)
                        {
                            if (!set.Contains(n + m))
                                set.Add(n + m);
                        }
                    }
                }

                sb.Append("Case #" + i + ": " + set.Count + System.Environment.NewLine);
            }

            return sb.ToString();
        }
    }
}
