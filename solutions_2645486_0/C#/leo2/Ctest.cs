using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace test {
    public class Ctest {
        public void main(String FileName) {
            FileStream fs, fs2;
            StreamReader sr = null;
            StreamWriter sw = null;

            try {
                fs = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                sr = new StreamReader(fs, Encoding.Default);
                fs2 = new FileStream("output.txt", FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
                sw = new StreamWriter(fs2, Encoding.Default);

                //header
                string str = sr.ReadLine();

                int iSize = int.Parse(str);

                for (int ip = 0; ip < iSize; ip++) {
                    str = sr.ReadLine();
                    string[] strs = str.Split(new char[] { ' ' });
                    long E = long.Parse(strs[0]);
                    long R = long.Parse(strs[1]);
                    long N = long.Parse(strs[2]);

                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    List<act> lact = new List<act>();
                    for (int iv = 0; iv < N; iv++) {
                        long val = long.Parse(strs[iv]);
                        lact.Add(new act(iv, val, E));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(lact, E, R);
                    Console.WriteLine(sres);
                    sw.WriteLine(sres);
                }
            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            } finally {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }

            return;
        }
    }

    public class act {
        public int suf;
        public long val;
        public long maxE;

        public act(int s, long v, long e) {
            suf = s;
            val = v;
            maxE = e;
        }
    }

    public class prob {
        static int BIG = 99999999;

        public static string Solve(List<act> lact, long E, long R) {
            long ensum = 0;

            //copy
            List<act> lactst = new List<act>(lact.ToArray());

            //sort
            lactst.Sort((a1, a2) => a1.val > a2.val ? -1 : a1.val < a2.val ? 1 : 0);

            foreach (act a in lactst) {
                ensum += a.maxE * a.val;

                for (int i = a.suf; i < lact.Count; i++) {
                    long engain = R * (long)(i - a.suf);
                    if (lact[i].maxE <= engain) {
                        break;
                    } else {
                        lact[i].maxE = engain;
                    }
                }

                for (int i = a.suf - 1; i >= 0; i--) {
                    long engain = R * (long)(a.suf - i);
                    if (lact[i].maxE <= engain) {
                        break;
                    } else {
                        lact[i].maxE = engain;
                    }
                }
            }

            return ensum.ToString();
        }
    }
}
