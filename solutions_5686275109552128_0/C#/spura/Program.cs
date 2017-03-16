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
                int nDiners = int.Parse(sLine);
                sLine = oSR.ReadLine();
                string[] aCakes = sLine.Split(' ');
                List<int> nCakes = new List<int>(aCakes.Length);
                for (int j = 0; j < aCakes.Length; j++)
                    nCakes.Add(int.Parse(aCakes[j]));

                nCakes.Sort(new DinerComparer());
                int nResult = Solve3(nCakes, nCakes[0], 0);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                oAnswer.Append(nResult);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve3(List<int> nCakes, int nInitMax, int nThis)
        {
            if (nThis >= nInitMax)
                return 1000000;

            // eat?
            List<int> l2 = nCakes.ToList();
            int nBest_Eat;
            if (!Eat(l2))
                nBest_Eat = 1;
            else
                nBest_Eat = 1 + Solve3(l2, nInitMax, nThis + 1);

            if (nBest_Eat <= 3)
                return nBest_Eat;

            if (nThis + 1 == nInitMax)
                return nBest_Eat;

            // distribute?
            int nBest_Distr = 1000000;
            int nMax = nCakes[0];
            if (nMax > 1)
            {
                for (int nTo = 1; nTo <= nCakes.Count; nTo++)
                {
                    int[] aHowMuch;
                    if (nMax == 9)
                        aHowMuch = new int[] { 5, 6 };
                    else
                        aHowMuch = new int[] { nMax / 2 };

                    foreach(int nHowMuch in aHowMuch)
//                    for (int nHowMuch = nMax/2; nHowMuch <= nMax; nHowMuch++)
                    {
                        l2 = nCakes.ToList();
                        int nNew;
                        if (nTo == nCakes.Count)
                            nNew = nHowMuch;
                        else
                        {
                            nNew = l2[nTo] + nHowMuch;
                            l2.RemoveAt(nTo);
                        }
                        if (nNew >= nMax)
                            continue;
                        l2.RemoveAt(0);
                        Add(l2, nMax - nHowMuch);
                        Add(l2, nNew);

                        int nRes = 1 + Solve3(l2, nInitMax, nThis + 1);
                        if (nRes < nBest_Distr)
                            nBest_Distr = nRes;
                    }
                }
            }

            if (nBest_Eat < nBest_Distr)
                return nBest_Eat;
            else
                return nBest_Distr;
        }

        static bool Eat(List<int> nCakes)
        {
            int i = 0;
            int k = nCakes.Count;
            for(int j=0; j<k; j++)
            {
                nCakes[i]--;
                if (nCakes[i] == 0)
                {
                    nCakes.RemoveAt(i);
                }
                else i++;
            }

            if (nCakes.Count == 0)
                return false;

            return true;
        }

        static void Add(List<int> nCakes, int n)
        {
            if (n == 0)
                return;

            for(int i=0; i<nCakes.Count; i++)
            {
                if(nCakes[i] <= n)
                {
                    nCakes.Insert(i, n);
                    return;
                }
            }
            nCakes.Insert(nCakes.Count, n);
        }

        class DinerComparer: IComparer<int>
        {
            public int Compare(int x, int y)
            {
                return -(x.CompareTo(y));
            }
        }
    }
}
