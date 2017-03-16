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

                    int H = int.Parse(strs[0]);
                    int N = int.Parse(strs[1]);
                    int M = int.Parse(strs[2]);

                    int[][] Cl = new int[N][];
                    int[][] Fl = new int[N][];
                    for (int il = 0; il < N; il++) {
                        str = sr.ReadLine();
                        strs = str.Split(new char[] { ' ' });
                        if (strs.Length < M)
                            continue;

                        Cl[il] = new int[M];
                        for (int im = 0; im < M; im++) {
                            Cl[il][im] = int.Parse(strs[im]);
                        }
                    }
                    for (int il = 0; il < N; il++) {
                        str = sr.ReadLine();
                        strs = str.Split(new char[] { ' ' });
                        if (strs.Length < M)
                            continue;

                        Fl[il] = new int[M];
                        for (int im = 0; im < M; im++) {
                            Fl[il][im] = int.Parse(strs[im]);
                        }
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = tidal.Count(H, N, M, Cl, Fl);
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

    public class tidal {
        static int BIG = 99999999;

        public static string Count(int H, int N, int M, int[][] Cl, int[][] Fl) {
            int[][] rt = new int[N][];
            int[][] CH = new int[N][];
            for (int i = 0; i < N; i++) {
                rt[i] = new int[M];
                CH[i] = new int[M];
                for (int im = 0; im < M; im++) {
                    rt[i][im] = BIG;
                    CH[i][im] = BIG;
                }
            }

            rt[0][0] = 0;
            CH[0][0] = H;

            while (rt[N - 1][M - 1] > BIG - 1) {
                int mint = BIG, mini = 0, minj = 0, minh = 0;
                for (int ii = 0; ii < N; ii++) {
                    for (int ij = 0; ij < M; ij++) {
                        if (rt[ii][ij] > BIG - 1)
                            continue;

                        if (ij > 0) {
                            if (rt[ii][ij - 1] > BIG - 1) {
                                int mt = GetMoveTime(H, CH[ii][ij], ii, ij, ii, ij - 1, Cl, Fl);
                                if (rt[ii][ij] + mt < mint) {
                                    mini = ii;
                                    minj = ij - 1;
                                    mint = rt[ii][ij] + mt;
                                    minh = CH[ii][ij] - mt;
                                }
                            }
                        }
                        if (ij < M - 1) {
                            if (rt[ii][ij + 1] > BIG - 1) {
                                int mt = GetMoveTime(H, CH[ii][ij], ii, ij, ii, ij + 1, Cl, Fl);
                                if (rt[ii][ij] + mt < mint) {
                                    mini = ii;
                                    minj = ij + 1;
                                    mint = rt[ii][ij] + mt;
                                    minh = CH[ii][ij] - mt;
                                }
                            }
                        }
                        if (ii > 0) {
                            if (rt[ii - 1][ij] > BIG - 1) {
                                int mt = GetMoveTime(H, CH[ii][ij], ii, ij, ii - 1, ij, Cl, Fl);
                                if (rt[ii][ij] + mt < mint) {
                                    mini = ii - 1;
                                    minj = ij;
                                    mint = rt[ii][ij] + mt;
                                    minh = CH[ii][ij] - mt;
                                }
                            }
                        }
                        if (ii < N - 1) {
                            if (rt[ii + 1][ij] > BIG - 1) {
                                int mt = GetMoveTime(H, CH[ii][ij], ii, ij, ii + 1, ij, Cl, Fl);
                                if (rt[ii][ij] + mt < mint) {
                                    mini = ii + 1;
                                    minj = ij;
                                    mint = rt[ii][ij] + mt;
                                    minh = CH[ii][ij] - mt;
                                }
                            }
                        }
                    }
                }

                if (mint > BIG - 1)
                    break;

                rt[mini][minj] = mint;
                CH[mini][minj] = minh;
            }

            return ((double)rt[N-1][M-1] / 10.0).ToString("######0.0");
        }

        static int GetMoveTime(int H, int CH, int ifrom, int jfrom, int ito, int jto, int[][] Cl, int[][] Fl) {

            if (Cl[ifrom][jfrom] - Fl[ito][jto] < 50)
                return BIG;

            if (Cl[ito][jto] - Fl[ifrom][jfrom] < 50)
                return BIG;

            if (Cl[ito][jto] - Fl[ito][jto] < 50)
                return BIG;


            int nh = 0;
            if (Cl[ito][jto] - CH < 50) {
                nh = CH + 50 - Cl[ito][jto];
            }

            if (H == CH && nh == 0)
                return 0;

            if (CH - nh - Fl[ifrom][jfrom] < 20) {
                return 100 + nh;
            } else {
                return 10 + nh;
                //if (CH == H && nh == 0) {
                //    return 0;
                //} else {
                //    return 10 + nh;
                //}
            }
        }
    }
}
