using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Project1
{
    class program
    {
        public static void Main()
        {
            string[] lines = funcs.getInputDocs(@"A-small-attempt0.in");
            int size = int.Parse(lines[0]);
            List<string> newlines = new List<string>();

            for (int i = 0; i < size; i++)
            {
                string line1 = lines[2 * i + 1];
                string line2 = lines[2 * i + 2];

                string[] word1 = line1.Split();
                string[] word2 = line2.Split();

                double A = double.Parse(word1[0]);
                double B = double.Parse(word1[1]);

                List<double> p_num = new List<double>();
                double p_right = 1;
                for (int j = 0; j < word2.Length; j++)
                {
                    double num = double.Parse(word2[j]);
                    p_num.Add(num);
                    p_right = p_right * num;
                }

                double min = B + 2;

                for (int j = 0; j <= A; j++)
                {
                    //From p[0] tp p[k].
                    double value = (B - A + 1 + 2 * j) * p_right + (2 * B - A + 2 * j + 2) * (1 - p_right);
                    if (value < min)
                        min = value;

                    if (j != A)
                        p_right = p_right / p_num[(int)A - j - 1];
                }

                string s = "Case #" + (i + 1).ToString() + ": " + min.ToString("#0.000000");
                newlines.Add(s);
            }
            funcs.WriteLines(@"A-small-attempt0.out", newlines);            
        }
    }
}
