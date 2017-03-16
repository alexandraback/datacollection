using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace B
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
                int K = int.Parse(aLine[0]);
                int L = int.Parse(aLine[1]);
                int S = int.Parse(aLine[2]);
                string sKeys = oSR.ReadLine();
                string sWord = oSR.ReadLine();

                double nS = Solve(K, L, S, sKeys, sWord);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                string s = nS.ToString();
                s = s.Replace(',', '.');
                oAnswer.Append(s);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int Instances(string sWord, char c)
        {
            int n = 0;
            foreach(char x in sWord)
            {
                if (x == c)
                    n++;
            }

            return n;
        }

        static double Solve(int K, int L, int S, string sKeys, string sWord)
        {
            if (S < L)
                return 0;

            int Pu = 1;
            foreach(char c in sWord)
            {
                int nc = Instances(sKeys, c);
                Pu *= nc;
                if (Pu == 0)
                    break;
            }

            if (Pu == 0)
            {
                return 0;
            }

            BigInteger[] EBup = GetUp(S, L, sKeys, sWord);
            BigInteger Pd = BigInteger.Pow(K, S);

            double EB = 0;
            int BMax = 0;
            for (int i = 1; i < EBup.Length; i++ )
            {
                if (EBup[i] != 0)
                    BMax = i;

                BigInteger Up = EBup[i] * i;
                EB += (((double)Up) / ((double)Pd));
            }

            return ((double)BMax) - EB;
        }

        static BigInteger[] GetUp(int S, int L, string sKeys, string sWord)
        {
            BigInteger[] nRes = new BigInteger[S+1];
            int[] aWord = new int[S];
            int nk = sKeys.Length;

            do
            {
                int n = RateWord(aWord, sWord, sKeys, S, L);
                nRes[n]++;
            }
            while (NextWord(aWord, nk, S));

            return nRes;
        }

        static int RateWord(int[] aWord, string sWord, string sKeys, int S, int L)
        {
            int nRes = 0;
            for(int i=0; i<=S - L; i++)
            {
                bool bFound = true;
                for(int j=0; j<L; j++)
                {
                    char c = sWord[j];
                    char x = sKeys[aWord[i + j]];
                    if (c != x)
                    {
                        bFound = false;
                        break;
                    }
                }
                if (bFound)
                    nRes++;
            }

            return nRes;
        }

        static bool NextWord(int[] aWord, int nk, int S)
        {
            for(int i=S-1; i>=0; i--)
            {
                aWord[i]++;
                if (aWord[i] == nk )
                {
                    aWord[i] = 0;
                }
                else return true;
            }

            return false;
        }
    }
}
