using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2014
{
    class DeceitfulWar
    {
        public void solution(string filename)
        {
            StreamWriter sw = new StreamWriter("DeceitfulWar.txt");

            StreamReader sr = new StreamReader(filename);
            string strSize = sr.ReadLine();
            int iSize = Int32.Parse(strSize);

            for (int caseIndex = 0; caseIndex < iSize; caseIndex++)
            {
                string BlockCount = sr.ReadLine();

                string line = sr.ReadLine();
                List<double> Naomi = new List<double>();
                string[] sWeight = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (string w in sWeight)
                    Naomi.Add(Convert.ToDouble(w));
                Naomi.Sort();

                List<double> Ken = new List<double>();
                line = sr.ReadLine();
                sWeight = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (string w in sWeight)
                    Ken.Add(Convert.ToDouble(w));
                Ken.Sort();



                int NaomiStart = 0;
                int KenStart = 0;

                int WarPoints = 0, DecWarPoints = 0;

                for (NaomiStart = 0; NaomiStart < Naomi.Count; NaomiStart++)
                {

                    while (KenStart < Ken.Count && Ken[KenStart] < Naomi[NaomiStart])
                        KenStart++;
                    KenStart++;
                    if (KenStart > Ken.Count)
                    {
                        WarPoints = Naomi.Count - NaomiStart;
                        break;
                    }
                   


                }

                KenStart = 0;

                for (NaomiStart = 0; NaomiStart < Naomi.Count; NaomiStart++)
                {
                    if (Ken[KenStart] < Naomi[NaomiStart])
                    {
                        KenStart++;
                        DecWarPoints++;
                    }
                    
                }
                Console.WriteLine("Case #{0}: {1} {2}", caseIndex + 1, DecWarPoints, WarPoints);

                sw.WriteLine("Case #{0}: {1} {2}", caseIndex + 1, DecWarPoints, WarPoints);

            }
            sw.Close();

        }
    }
}
