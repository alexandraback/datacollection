using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Net.Configuration;
using System.Runtime.CompilerServices;
using System.Runtime.Hosting;
using System.Runtime.Remoting.Lifetime;
using System.Text;
using System.Text.RegularExpressions;
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
                int N = int.Parse(oSR.ReadLine());
                double[] Naomi = new double[N];
                double[] Ken = new double[N];
                string sN = oSR.ReadLine();
                string sK = oSR.ReadLine();
                sN = sN.Replace('.', ',');
                sK = sK.Replace('.', ',');
                string[] aN = sN.Split(' ');
                string[] aK = sK.Split(' ');
                for(int j=0; j<N; j++)
                {
                    Naomi[j] = double.Parse(aN[j]);
                    Ken[j] = double.Parse(aK[j]);
                }

                int nDWar, nWar;
                Solve(Naomi, Ken, N, out nDWar, out nWar);

                // write answer
                oAnswer.AppendFormat("Case #{0}: {1} {2} ", i + 1, nDWar, nWar);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static void Solve(double[] Naomi, double[] Ken, int N, out int nDWar, out int nWar)
        {
            List<double> wNaomi = Naomi.ToList();
            List<double> wKen = Ken.ToList();

            wNaomi.Sort();
            wKen.Sort();

            List<double> dwKen = wKen.ToList();

            // WAR
            nWar = 0;
            foreach (double b in Naomi)
            {
                int nIndex = BestKensResponse(wKen, b);
                double b2 = wKen[nIndex];
                wKen.RemoveAt(nIndex);
                if (b > b2)
                    nWar++;
            }

            // DECEITFUL WAR
            nDWar = 0;

            while (N > 0)
            {
                double dBestN = wNaomi.Last();
                double dWorstN = wNaomi.First();
                double dBestK = dwKen.Last();
                double dWorstK = dwKen.First();

                if (dBestN < dWorstK)
                {
                    return; // strategy irrelevant; Ken wins all remaining rounds
                }
                if (dBestK < dWorstN)
                {
                    nDWar += N; // strategy irrelevant; Naomi wins all remaining rounds
                    return;
                }

                // attack Ken's worst block, Naomi gets a point
                int n = BestKensResponse(wNaomi, dWorstK);
                wNaomi.RemoveAt(n);
                nDWar++;
                dwKen.RemoveAt(0);
                
                /*
                // attack Ken's best block, play Naomi's worst
                dwKen.RemoveAt(dwKen.Count - 1);
                wNaomi.RemoveAt(0);
                */

                N--;
            }
        }

        static int BestKensResponse(List<double> wKen, double b)
        {
            int? nBestIndex = null;
            double? dBestDist = null;

            // win?
            int i = -1;
            foreach (double d in wKen)
            {
                i++;
                if (d - b > 0)
                {
                    if (!nBestIndex.HasValue || d - b < dBestDist.Value)
                    {
                        nBestIndex = i;
                        dBestDist = d - b;
                    }
                }
            }

            if (!nBestIndex.HasValue)
            {
                return 0; // lowest block; Ken looses anyway
            }
            else return nBestIndex.Value;
        }
    }
}
