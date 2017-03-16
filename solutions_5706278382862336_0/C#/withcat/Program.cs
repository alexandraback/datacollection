using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Codejam2014.R1B
{
    class Program
    {
        class Sample
        {
            public double p;
            public double q;
        }

        public static string elf(double p)
        {
            int count = 0;
            bool tf = true;
            for (int i = 1; i <= 40; i++)
            {
                p *= 2;
                if (p >= 1)
                {
                    if (tf) count = i;
                    tf = false;
                    p -= 1;
                    if (p == 1 || p == 0) return count.ToString();
                }
            }
            return "impossible";
        }

        static void Main(string[] args)
        {
            string sampleName = "small1";
            string sampleDir = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(AppDomain.CurrentDomain.BaseDirectory))) + "\\";
            string iFilePath = sampleDir + sampleName + ".i.txt";
            string oFilePath = sampleDir + sampleName + ".o.txt";
            string cFilePath = sampleDir + sampleName + ".c.txt";

            string[] iLines = File.ReadAllLines(iFilePath);
            List<string> oLines = new List<string>();

            int lineCnt = 0;
            int sampleCnt = int.Parse(iLines[lineCnt++]);

            List<Sample> sampleList = new List<Sample>();
            for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
            {
                string[] itemList = iLines[lineCnt++].Split(new char[] {'/'});

                Sample s = new Sample();
                s.p = double.Parse(itemList[0]);
                s.q = double.Parse(itemList[1]);
                sampleList.Add(s);
            }

            for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
            {
                Sample s = sampleList[sampleIdx];

                string ret = elf(s.p/s.q);
                oLines.Add(string.Format("Case #{0}: {1}", sampleIdx + 1, ret));
            }
            File.WriteAllLines(oFilePath, oLines);

            if (File.Exists(cFilePath))
            {
                string[] cLines = File.ReadAllLines(cFilePath);
                for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
                {
                    string oLine = oLines[sampleIdx];
                    string cLine = cLines[sampleIdx];

                    if (oLine != cLine)
                    {
                        throw new Exception("not match");
                    }
                }
            }
        }
    }
}
