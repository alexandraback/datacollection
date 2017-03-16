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
                    decimal r = decimal.Parse(strs[0]);
                    decimal t = decimal.Parse(strs[1]);
                    

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(r, t);
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

    public class prob {
        static int BIG = 99999999;

        public static string Solve(decimal r, decimal t) {
            decimal rh = Math.Ceiling(r / 2m);
            decimal ret = 0m;

            try {
                if (rh == r / 2m) {
                    //even
                    decimal def = 2m * (rh - 1m) * (rh - 1m) + 3m * rh - 3m;

                    if (2m * rh * rh + 3m * rh - def <= t) {
                        rh += 10000m;
                    }

                    while (2m * rh * rh + 3m * rh - def <= t) {
                        ret += 10000m;
                        rh += 10000m;
                    }
                    if (rh > 0)
                        rh -= 10000m;
                    while (2m * rh * rh + 3m * rh - def <= t) {
                        ret += 1m;
                        rh += 1m;
                    }
                } else {
                    //odd
                    decimal def = 2m * (rh - 1m) * (rh - 1m) + rh - 1m;

                    if (2m * rh * rh + rh - def <= t) {
                        rh += 10000m;
                    }

                    while (2m * rh * rh + rh - def <= t) {
                        ret += 10000m;
                        rh += 10000m;
                    }
                    if (rh > 0)
                        rh -= 10000m;
                    while (2m * rh * rh + rh - def <= t) {
                        ret += 1m;
                        rh += 1m;
                    }
                }
            } catch (Exception) {
                ret = 0m;
                decimal sum = 2m * r + 1m;
                while (sum <= t) {
                    ret += 1m;
                    r += 2m;
                    sum += 2m * r + 1m;
                }
            }

            return ret.ToString("##############################");
        }
    }
}
