using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace CodeJam2012
{
    class ProblemC
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            
            string[] lines = File.ReadAllLines("C-small-attempt0.in");

            for (int i = 1; i < lines.Length; i++)
            {
                string[] testcase = lines[i].Split(' ');
                int min = Int32.Parse(testcase[0]);
                int max = Int32.Parse(testcase[1]);

                int count = 0;

                for (int j = min; j < max; j++)
                {
                    List<string> pairs = new List<string>();
                    string number = j.ToString();
                    for (int k = 1; k < number.Length; k++)
                    {
                        string suffix = number.Substring(number.Length - k, k);
                        string prefix = number.Remove(number.Length - k, k);
                        int result = Int32.Parse(suffix + prefix);

                        if (result > j && result <= max)
                        {
                            string pair = j + " " + result;
                            if (!pairs.Contains(pair))
                            {
                                count++;
                                pairs.Add(pair);
                            }
                        }
                    }
                }

                output.AppendFormat("Case #{0}: {1}", i, count);
                output.AppendLine();
            }

            File.WriteAllText("C-small-attempt0.out", output.ToString());
        }
    }
}
