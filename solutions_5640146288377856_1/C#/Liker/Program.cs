using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam2015_Qualification
{
    class Program
    {
        static void Main(string[] args)
        {
            ProblemA.Small();
        }

    }

    static class ProblemA
    {
        public static void Small()
        {
            StreamReader strR = new StreamReader("A-large.in");
            StreamWriter strW = new StreamWriter("Output.txt");

            int n = Convert.ToInt32(strR.ReadLine());

            for (int i = 1; i <= n; i++)
            {
                var line = strR.ReadLine().Split(' ').ToList<string>();

                int R = Convert.ToInt32(line[0]);
                int C = Convert.ToInt32(line[1]);
                int W = Convert.ToInt32(line[2]);

                strW.WriteLine("Case #{0}: {1}", i, ProblemA.CalculateBig(R, C, W));

            }

            strR.Close();
            strW.Close();
        }

        public static int CalculateSmall(int C, int W)
        {
            int result = C / W;
            if(result * W == C)
            {
                result--;
            }

            result += W;

            return result;
        }

        public static int CalculateBig(int R, int C, int W)
        {
            int result = C / W;
            result *= R;

            if (C % W == 0)
            {
                result--;
            }
            
            result += W;

            return result;
        }
    }
}
