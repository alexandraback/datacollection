using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("a.in");
            StreamWriter outFile = new StreamWriter("a.out");

            string line = inFile.ReadLine();
            int csCnt = Convert.ToInt32(line);
            for (int csId = 1; csId <= csCnt; csId++)
            {
                line = inFile.ReadLine();
                string[] spt = line.Split();
                int A = Convert.ToInt32(spt[0]);
                int B = Convert.ToInt32(spt[1]);
                line = inFile.ReadLine();
                spt = line.Split();
                List<double> cP = new List<double>();
                for (int i = 0; i < A; i++) cP.Add(Convert.ToDouble(spt[i]));
                outFile.WriteLine("Case #{0}: {1}", csId, getAnswer(A, B, cP));
            }

            inFile.Close();
            outFile.Close();
        }

        static double getAnswer(int A, int B, List<double> cP)
        {
            double best = 2 + B;
            double p = 1;
            for (int i = -1; i < A; i++)
            {
                if (i >= 0) p *= cP[i];
                double tmp = (A + B - 2 * i - 1) + (1.0 - p) * (B + 1);
                if (tmp < best) best = tmp;
            }
            return best;
        }

    }
}
