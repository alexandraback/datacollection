using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Schema;

namespace GCJ_2014_Qualification
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
                // read case
                string sCase = oSR.ReadLine();
                sCase = sCase.Replace('.', ',');
                string[] aCase = sCase.Split(' ');
                double C = double.Parse(aCase[0]);
                double F = double.Parse(aCase[1]);
                double X = double.Parse(aCase[2]);

                double t = Solve(X, C, F);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                string s = System.Math.Round(t, 7).ToString();
                s = s.Replace(',', '.');
                oAnswer.Append(s);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static double Solve(double X, double C, double F)
        {
            double t = 0;
            double y_current = 2;

            do
            {
                double t_to_next_f = C / y_current;
                double next_y = y_current + F;
                double t_to_finish = X / y_current;
                double t_to_finish_with_next_f = t_to_next_f + X/(next_y);

                if (t_to_finish <= t_to_finish_with_next_f)
                {
                    return t_to_finish + t;
                }

                t += t_to_next_f;
                y_current = next_y;

            } while (true);
        }
    }
}
