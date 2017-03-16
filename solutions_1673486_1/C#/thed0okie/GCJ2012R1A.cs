using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

/* Yoel Grodentzik
 * thed0okie
 * C#
 * Password Problem  (A)
 */

namespace goroGCjam
{
    class GCJ2012R1A
    {
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader(@"C:\A-large (1).in");
            StreamWriter sw = new StreamWriter(@"C:\A-large (1).out");

            int numCases = 0;
            numCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                string theLine = sr.ReadLine();
                long A = Convert.ToInt32(theLine.Split(' ')[0]);
                long B = Convert.ToInt32(theLine.Split(' ')[1]);

                double[] p = new double[A];
                theLine = sr.ReadLine();

                string[] tmp = new string[A];
                tmp = theLine.Split(' ');
                for(int j = 0; j < A; j++)
                    p[j] = Convert.ToDouble(tmp[j]);

                //case enter
                double minExp = B + 2;

                double prob = 1;
                for (int j = 0; j < A; j++)
                {
                    prob *= p[j];
                    double newExp = prob * (A - (j + 1) + B - (j + 1) + 1) + (1 - prob) * (A - (j + 1) + B - (j + 1) + 1 + B + 1);
                    if (newExp < minExp)
                        minExp = newExp;
                }

                //delete whole word
                if (A + B + 1 < minExp)
                    minExp = A + B + 1;
                sw.WriteLine("Case #" + (i + 1) + ": " + minExp);

                p = null;
            }

            sr.Close();
            sw.Close();
        }

    }


}
