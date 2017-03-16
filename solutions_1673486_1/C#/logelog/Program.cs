using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace test1
{
    class Program
    {
        static int A, B;
        static double[] prob;

        static void Main(string[] args)
        {
            if (args.Length == 1) {
                String strIn = fileToString(args[0]);
                Console.Write(ProcessInput(strIn));
            }
            else {
                Console.Write("wrong usage ;)");
            }
        }

        public static String fileToString(String filePath)
        {
            StreamReader re = File.OpenText(filePath);
            String ret = re.ReadToEnd();
            re.Close();
            re.Dispose();
            return ret;
        }

        public static String ProcessInput(String input)
        {
            string output = "";
            int lineNumber = 0;

            input = input.Replace("\r", "");
            string []lines = input.Split(new char[] { '\n' });

            int NUM_TESTS = int.Parse(lines[lineNumber++]);
            for (int t = 1; t <= NUM_TESTS; t++)
            {
                string tline;
                
                tline = lines[lineNumber++];
                string[] AB = tline.Split(new char[] { ' ' });
                A = int.Parse(AB[0]); B = int.Parse(AB[1]);

                tline = lines[lineNumber++];
                string[] nums = tline.Split(new char[] { ' ' });

                prob = new double[A];
                for (int i = 0; i < A; i++)
                {
                    prob[i] = double.Parse(nums[i]);
                }

                output += ("Case #" + t + ": " + Solve() + "\n");
            }

            return output;
        }

        public static string Solve()
        {
            String outTxt = "";

            // A, B, prob
            double minf = 2 * B;

            for (int i = 0; i < A; i++)
            {
                double f, p = 1;
                for (int j = 0; j < A - i; j++)
                {
                    p *= prob[j];
                }
                f = p * (2 * i + B - A + 1) + (1 - p) * (2 * B + 2 * i + 2 - A);
                
                if (f < minf) minf = f;
            }

            if (minf > B + 2)
                minf = B + 2;

            return "" + minf;
        }

    }    

}

