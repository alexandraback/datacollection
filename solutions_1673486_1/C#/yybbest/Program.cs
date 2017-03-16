using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace Password
{
    //struct dataStruct
    //{
    //    public int sumScores;
    //    //int[] scores;
    //    public bool isOverP;
    //    public bool isSurpring;
    //    public bool isSurpringOverP;
    //};

    class Program
    {
        static void Main(string[] args)
        {
            string infilename = "A-large.in", outfilename = "A-large.out";
            StreamReader sr = new StreamReader(infilename);
            StreamWriter sw = new StreamWriter(outfilename);
            int T = int.Parse(sr.ReadLine().ToString());
            int A; int B; double[] P=new double[100000]; //dataStruct[] tdata;
            string[] str ;
            double[] exp = new double[100001];
            double sumP=0.0;
            double result = 0;
            for (int t = 1; t <= T; ++t)
            {
                str = sr.ReadLine().ToString().Split(' ');
                A = int.Parse(str[0]);
                B= int.Parse(str[1]);
                str = sr.ReadLine().ToString().Split(' ');
                for (int i = 0; i < A; ++i)
                {
                    P[i] = double.Parse(str[i]);
                }
                exp[A+1] = B + 2;
                for (int i = 0; i <= A; ++i)
                {
                    sumP=1.0;
                    for(int j=0;j<A-i;++j)sumP*=P[j];
                    exp[i] = (B - A + 1 + 2 * i) * sumP + (2 * B + 2 - A + 2 * i) * (1 - sumP);
                }
                result = 9999999999999;
                for (int i = 0; i <= A+1; ++i)
                {
                    if (result > exp[i]) result=exp[i];
                }
                sw.WriteLine("Case #{0}: {1}", t,result.ToString("#0.000000"));//.ToString()
            }
            sw.Flush();
        }
    }
}