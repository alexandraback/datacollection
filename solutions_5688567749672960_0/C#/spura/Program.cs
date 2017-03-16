using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJam
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

            // number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                int N = int.Parse(sLine);

                int nS = Solve(N);

                // write answer
                oAnswer.AppendFormat("Case #{0}: {1}", i + 1, nS);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Solve(int N)
        {
            int k = 1, l = 1;

            while (l != N)
            {
                string sN = l.ToString();
                char[] aArr = sN.ToCharArray();
                List<char> aList = aArr.ToList();
                aList.Sort(new Revcomparer());
                StringBuilder oSB = new StringBuilder();
                foreach (char c in aList)
                    oSB.Append(c);
                sN = oSB.ToString();
                int NN = int.Parse(sN);

                if (NN > l && NN <= N)
                {
                    l = NN;
                }
                else l++;

                k++;
            }

            return k;
        }

        public class Revcomparer: IComparer<char>
        {

            public int Compare(char x, char y)
            {
                return -x.CompareTo(y);
            }
        }
    }
}
