using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                string[] aLine = sLine.Split(' ');
                int R = int.Parse(aLine[0]);
                int C = int.Parse(aLine[1]);
                int W = int.Parse(aLine[2]);

                int nResult = Solve(R, C, W);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                oAnswer.Append(nResult);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve(int R, int C, int W)
        {
            int n = C / W;
            int nMiss = n * (R - 1);

            int Z = C - (n - 1) * W;
            
            int x;
            if (Z == W)
                x = W;
            else
                x = W + 1;

            return nMiss + n - 1 + x;
        }
    }
}
