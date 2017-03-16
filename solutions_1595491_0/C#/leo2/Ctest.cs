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

                    string[] strs = str.Split(new char[] {' '});
                    if (strs.Length < 3)
                        continue;

                    int N = int.Parse(strs[0]);
                    int S = int.Parse(strs[1]);
                    int P = int.Parse(strs[2]);
                    List<int> scores = new List<int>();
                    for (int i = 0; i < N; i++) {
                        scores.Add(int.Parse(strs[3 + i]));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");
                    Console.WriteLine(triplet.Count(S, P, scores));
                    sw.WriteLine(triplet.Count(S, P, scores));
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

    public class triplet {

        public static int Count(int S, int P, List<int> scores) {
            int icnt = 0;

            int ibt = 0;
            int ibts = 0;
            if (P == 1) {
                ibt = 1;
                ibts = 1;
            } else if (P > 1) {
                ibt = P + (P - 1) * 2;
                ibts = P + (P - 2) * 2;
            }

            int iscnt = 0;

            foreach (int scr in scores) {
                if (scr >= ibt) {
                    icnt++;
                } else if (scr >= ibts && iscnt < S) {
                    icnt++;
                    iscnt++;
                }
            }

            return icnt;
        }
    }
}
