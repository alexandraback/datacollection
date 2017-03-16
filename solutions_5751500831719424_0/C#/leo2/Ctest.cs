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
                    string[] strs;
                    str = sr.ReadLine();
                    int N = int.Parse(str);

                    List<strset> ssets = new List<strset>();
                    for (int i = 0; i < N; i++) {
                        str = sr.ReadLine();
                        //strs = str.Split(new char[] { ' ' });
                        ssets.Add(new strset(str));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(ssets);
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

    public class strset {
        public string str;
        public List<char> cset;
        public List<int> iset;

        public strset(string s) {
            str = s;
            cset = new List<char>();
            iset = new List<int>();
            char c = ' ';
            char[] sc = s.ToCharArray();
            for (int i = 0; i < sc.Length; i++) {
                if (sc[i] != c) {
                    c = sc[i];
                    cset.Add(c);
                    iset.Add(1);
                } else {
                    iset[iset.Count - 1]++;
                }
            }
        }

        public bool cmpcset(strset sset) {
            if (cset.Count != sset.cset.Count)
                return false;

            for (int i = 0; i < cset.Count; i++) {
                if (cset[i] != sset.cset[i])
                    return false;
            }

            return true;
        }
    }

    public class prob {
        public static string Solve(List<strset> ssets) {
            //string ret = "";
            int icnt = 0;
            for (int i = 1; i < ssets.Count; i++) {
                if (!ssets[0].cmpcset(ssets[i]))
                    return "Fegla Won";
            }

            for (int ic = 0; ic < ssets[0].cset.Count; ic++) {
                int imin = int.MaxValue;
                int imax = int.MinValue;
                for (int i = 0; i < ssets.Count; i++) {
                    if (ssets[i].iset[ic] < imin)
                        imin = ssets[i].iset[ic];
                    if (ssets[i].iset[ic] > imax)
                        imax = ssets[i].iset[ic];
                }
                if (imin == imax)
                    continue;
                List<int> lmv = new List<int>();
                for (int i = 0; i < ssets.Count; i++) {
                    for (int im = 0; im <= imax - imin; im++) {
                        if (lmv.Count <= im) {
                            lmv.Add(Math.Abs(ssets[i].iset[ic] - (imin + im)));
                        } else {
                            lmv[im] += Math.Abs(ssets[i].iset[ic] - (imin + im));
                        }
                    }
                }
                icnt += lmv.Min();
            }

            return icnt.ToString();
        }

    }
}
