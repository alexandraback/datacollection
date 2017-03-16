using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace Dancing
{
    struct dataStruct
    {
        public int sumScores;
        //int[] scores;
        public bool isOverP;
        public bool isSurpring;
        public bool isSurpringOverP;
    };

    class Program
    {
        static void Main(string[] args)
        {
            string infilename = "B-large.in", outfilename = "B-large.out";
            StreamReader sr = new StreamReader(infilename);
            StreamWriter sw = new StreamWriter(outfilename);
            int T = int.Parse(sr.ReadLine().ToString());
            int N; int S; int P; dataStruct[] tdata;
            string[] str ;
            
            for (int i = 1; i <= T; ++i)
            {
                str = sr.ReadLine().ToString().Split(' ');
                N = int.Parse(str[0]);
                S= int.Parse(str[1]);
                P= int.Parse(str[2]);
                tdata=new dataStruct[N];
                int[] datatmp = new int[3];
                int result=0;
                int dtmp = 0;
                for (int j = 0; j < N; ++j)
                {
                    tdata[j].sumScores= int.Parse(str[3+j]);
                    datatmp[1] = tdata[j].sumScores/3;
                    datatmp[0] = (tdata[j].sumScores - datatmp[1] )/ 2;
                    datatmp[2] = tdata[j].sumScores - datatmp[1] - datatmp[0];
                    if (datatmp[0] > datatmp[1])
                    {
                        dtmp=datatmp[0];
                        datatmp[0] = datatmp[1];
                        datatmp[1] = dtmp;
                    }
                    if (datatmp[0] > 0) tdata[j].isSurpring = true;
                    else if (datatmp[1] ==1&& datatmp[2]==1) tdata[j].isSurpring = true;
                    else tdata[j].isSurpring = false;
                    if (datatmp[2] >= P) tdata[j].isOverP = true; else tdata[j].isOverP = false;
                    if (tdata[j].isSurpring == true) { if (datatmp[1] == datatmp[2]) datatmp[2]++; }
                    if (datatmp[2] >= P) tdata[j].isSurpringOverP = true; else tdata[j].isSurpringOverP = false;
                }
                int sumOverP = 0, sumMaySurpringOverP = 0;
                for (int j = 0; j < N; ++j)
                {
                    if (tdata[j].isOverP) sumOverP++;
                    else if (tdata[j].isSurpring && tdata[j].isSurpringOverP) sumMaySurpringOverP++;
                }
                if (sumMaySurpringOverP >= S) result = sumOverP + S; else result = sumOverP + sumMaySurpringOverP;
                sw.WriteLine("Case #{0}: {1}", i,result);
            }
            sw.Flush();
        }
    }
}
