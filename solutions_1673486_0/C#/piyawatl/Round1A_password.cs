using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1A_password
    {
        public Round1A_password()
        {
            StreamReader reader = File.OpenText("A-small-attempt0.in");
            StreamWriter writer = File.CreateText("A-small-attempt0.out");
            string s = reader.ReadLine();
            string[] tokens;
            char[] sep = { ' ' };
            double[] probs = new double[120000];
            double expected, x;
            double correct;
            int T = Int32.Parse(s);
            int A, B, y;
            for (int t = 0; t < T; t++)
            {
                s = reader.ReadLine();
                tokens = s.Split(sep);
                A = Int32.Parse(tokens[0]);
                B = Int32.Parse(tokens[1]);
                s = reader.ReadLine();
                tokens = s.Split(sep);
                for (int i = 0; i < A; i++)
                {
                    probs[i] = Double.Parse(tokens[i]);
                }
                expected = B + 2;
                correct = 1;
                for (int i = 1; i <= A; i++)
                {
                    correct *= probs[i-1];
                    // correct: 2*(A-i) + (B-A) + 1 = B+A-2i+1
                    // incorrect: B+A-2i+1
                    y = B+A-(2*i)+1;
                    x = (correct * y) + ((1 - correct) * (y + B + 1));
                    if (x < expected) expected = x;
                }
                writer.WriteLine("Case #" + (t + 1) + ": " + expected.ToString("F6"));
            }
            reader.Close();
            writer.Close();
        }
    }
}
