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
                    if (strs.Length < 2)
                        continue;

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");
                    Console.WriteLine(rcnum.CountRecycle(int.Parse(strs[0]), int.Parse(strs[1])));
                    sw.WriteLine(rcnum.CountRecycle(int.Parse(strs[0]), int.Parse(strs[1])));
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

    public class rcnum {

        public static int CountRecycle(int A, int B) {
            int icnt = 0;

            for (int n = A; n < B; n++) {
                Dictionary<int, int> dic = new Dictionary<int, int>();
                string nstr = n.ToString();
                for (int i = 1; i < nstr.Length; i++) {
                    int m = int.Parse(nstr.Substring(i) + nstr.Substring(0, i));
                    if (m > n && m <= B && !dic.ContainsKey(m)) {
                        dic.Add(m, 1);
                        icnt++;
                    }
                }
            }

            return icnt;
        }
    }
}
