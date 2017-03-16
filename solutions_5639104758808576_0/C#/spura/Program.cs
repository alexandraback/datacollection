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
                int nMax = int.Parse(aLine[0]);
                string sDigits = aLine[1];

                int nResult = Solve(sDigits);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                oAnswer.Append(nResult);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve(string sDigits)
        {
            int nMaxShy = sDigits.Length - 1;
            int nPeopleStanding = 0;
            int nPeopleInvited = 0;

            for(int s = 0; s<=nMaxShy; s++)
            {
                char c = sDigits[s];
                int k = c - '0';
                if(k > 0 && s > nPeopleStanding)
                {
                    int nToInvite = s - nPeopleStanding;
                    nPeopleStanding += nToInvite;
                    nPeopleInvited += nToInvite;
                }
                nPeopleStanding += k;
            }

            return nPeopleInvited;
        }
    }
}
