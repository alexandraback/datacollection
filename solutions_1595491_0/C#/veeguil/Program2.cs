using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program2
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"../../B-small.in");

            lines[0] = null;

            int ct = 1;
            List<string> output = new List<string>();
            foreach (string line in lines)
            {
                if (line == null)
                    continue;
                string res = "Case #" + ct + ": ";
                int result = 0;

                List<string> strinputs = line.Split(new Char[] { ' ' }).ToList();

                List<int> inputs = new List<int>();
                foreach (string str in strinputs)
                {
                    inputs.Add(int.Parse(str));
                }
                int n = inputs[0];
                int s = inputs[1];
                int p = inputs[2];

                inputs.RemoveRange(0, 3);
                inputs.Sort();
                inputs.Reverse();

                foreach (int input in inputs)
                {
                    bool isSurprising = false;
                    int i = 10;
                    for (i = 10; i >= p; i--)
                    {
                        int total = input - i;
                        //int n1 = (int)Math.Ceiling(total / 2.0);
                        int n2 = (int)Math.Floor(total / 2.0);
                        if (n2 < 0)
                            continue;
                        if (Math.Abs(i - n2) < 2)
                        {
                            result++;
                            break;
                        }
                        else if (Math.Abs(p - n2) == 2 && s > 0)
                        {
                            isSurprising = true;
                        }

                    }
                    if (isSurprising && i == p-1)
                    {
                        s--;
                        result++;
                    }
                }
                res += result;
                output.Add(res);
                ct++;
            }
            System.IO.File.WriteAllLines("../../B-small.out", output);
        }
    }
}
