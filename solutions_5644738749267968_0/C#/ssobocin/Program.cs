using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Code
{
    class Code
    {

        static void Main(string[] args)
        {
            using (System.IO.StreamWriter file = new System.IO.StreamWriter("C:\\out.out"))
            {
                FileStream filestream = new FileStream("c:\\in.in", FileMode.Open);
                StreamReader streamreader = new StreamReader(filestream);
                file.AutoFlush = true;

                string firstLine = streamreader.ReadLine();

                int caseID = 0;
                while (!streamreader.EndOfStream)
                {
                    caseID++;
                    string line1 = streamreader.ReadLine();
                    string line2 = streamreader.ReadLine();
                    string line3 = streamreader.ReadLine();
                    string[] lineN = line2.Split(' ');
                    string[] lineK = line3.Split(' ');

                    int L;

                    int.TryParse(line1, out L);
               
                       double[] blockN = new double[L];
                       double[] blockK = new double[L];
                       double[] blockND = new double[L];
                       double[] blockKD = new double[L];
                    int Npoints = 0;
                    int NDpoints = 0;

                       for (int i = 0; i < L; i++ )
                       {
                           blockN[i] = Convert.ToDouble(lineN[i]);
                           blockK[i] = Convert.ToDouble(lineK[i]);
                           blockND[i] = Convert.ToDouble(lineN[i]);
                           blockKD[i] = Convert.ToDouble(lineK[i]);
                       }
                       Array.Sort(blockK);
                       Array.Sort(blockN);
                       Array.Sort(blockKD);
                       Array.Sort(blockND);
                       foreach (var a in blockN)
                       {                
                           double  k = Array.Find(blockK, x => x >= a);
                            int numIndex = Array.IndexOf(blockK, k);
                            blockK = blockK.Where((val, idx) => idx != numIndex).ToArray();
                            if (a > k)
                            {
                                Npoints++;
                            }
                       }
                       for(int i =0; i<L; i++)
                       {
                           double k = blockKD[0];
                           double nwybiera = Array.Find(blockND, x => x >= k);
                           int ik= Array.IndexOf(blockKD, k);
                           blockKD = blockKD.Where((val, idx) => idx != ik).ToArray();
                           int ina = Array.IndexOf(blockND, nwybiera);
                           blockND = blockND.Where((val, idx) => idx != ina).ToArray();
                           if (nwybiera > k)
                           {
                               NDpoints++;
                           }
                       }
                       file.WriteLine("Case #{0}: {1} {2}", caseID, NDpoints, Npoints);
                }
            }
        }
    }
}
