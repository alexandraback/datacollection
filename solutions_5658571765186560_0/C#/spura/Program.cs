using System;
using System.Collections;
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
                int X = int.Parse(aLine[0]);
                int R = int.Parse(aLine[1]);
                int C = int.Parse(aLine[2]);

                bool bResult = Solve(X, R, C);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                string sResult = bResult ? "GABRIEL" : "RICHARD";
                oAnswer.Append(sResult);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static bool Solve(int X, int R, int C)
        {
            if (X == 1)
                return true;
            if (((R * C) % X) != 0)
                return false;
            if (X > R && X > C)
                return false;
            if (X == 2)
                return true;
            if(X == 3)
            {
                if (R < 2 || C < 2)
                    return false;
                else
                    return true;
            }
            if (X == 4)
            {
                if(R < 3 || C < 3)
                    return false;
                else
                    return true;
            }

            throw new ApplicationException("?");
        }
    }
}
