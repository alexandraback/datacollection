using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamPlayground
{
    class Solution
    {
        public string solve(StreamReader sr)
        {
            int A, B;
            string line = sr.ReadLine();
            string[] part = line.Split(' ');
            A = Convert.ToInt32(part[0]);
            B = Convert.ToInt32(part[1]);

            line = sr.ReadLine();
            string[] sProb = line.Split(' ');
            double[] prob = new double[sProb.Length];
            for (int i = 0; i < sProb.Length; i++)
                prob[i] = Convert.ToDouble(sProb[i]);

            // prob if continue
            double contProb = 1.0;
            double contCost = B - A + 1;
            for (int i = 0; i < sProb.Length; i++)
                contProb *= prob[i];
            double contLoseProb = 1 - contProb;
            double contLoseCost = contCost + B + 1;

            double exp_cost = contProb * contCost + contLoseProb * contLoseCost;

            // prob if press enter right away
            double cost_right_away = 1 + B + 1;

            // prob if press backspace for m time   
            double min_cost = Math.Min(exp_cost, cost_right_away);
            for (int m = 1; m <= A; m++)
            {
                double m_cost = m; // press backspace for m times

                contProb = 1.0;
                for (int i = 0; i < sProb.Length-m; i++)
                    contProb *= prob[i];
                contLoseProb = 1 - contProb;

                contCost = B - A + 1 + 2*m;
                contLoseCost = contCost + B + 1;

                m_cost = contProb * contCost + contLoseProb * contLoseCost;

                min_cost = Math.Min(min_cost, m_cost);
            }

            return min_cost.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string input_id = "A-large";
            StreamReader sr = new StreamReader(input_id + ".in");
            StreamWriter sw = new StreamWriter(input_id + ".out");

            int total_test_case = Int32.Parse(sr.ReadLine());
            Console.WriteLine("Total test case: " + total_test_case);

            Solution s = new Solution();

            for (int i = 1; i <= total_test_case; i++)
            {
                Console.WriteLine("==== Test case: " + i + " ====");
                string result = s.solve(sr);
                sw.WriteLine("Case #" + i + ": " + result);
                Console.WriteLine("Case #" + i + ": " + result);
            }

            sr.Close();
            sw.Close();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
