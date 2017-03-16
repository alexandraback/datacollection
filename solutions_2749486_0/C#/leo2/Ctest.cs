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
                prob pp = new prob();
                pp.CalcSteps();

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
                    int X = int.Parse(strs[0]);
                    int Y = int.Parse(strs[1]);

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = pp.Solve(X, Y);
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

    public class CellStep {
        public int Step = -1;
        public string Dirs = string.Empty;
    }

    public class prob {
        const int Field = 101;

        C2DArray<CellStep> Arr;

        public prob() {
            Arr = new C2DArray<CellStep>(Field, Field);
        }

        public string Solve(int X, int Y) {
            string dirs = Arr.Array[Math.Abs(X)][Math.Abs(Y)].Val.Dirs;

            if (X < 0)
                dirs = ReverseEW(dirs);

            if (Y < 0)
                dirs = ReverseNS(dirs);

            return dirs;
        }

        public string ReverseNS(string sdir) {
            sdir = sdir.Replace("N", "T");
            sdir = sdir.Replace("S", "N");
            sdir = sdir.Replace("T", "S");

            return sdir;
        }

        public string ReverseEW(string sdir) {
            sdir = sdir.Replace("E", "T");
            sdir = sdir.Replace("W", "E");
            sdir = sdir.Replace("T", "W");

            return sdir;
        }

        public void CalcSteps() {
            int scnt = 0;
            List<C2DCell<CellStep>> lstp = new List<C2DCell<CellStep>>();
            List<C2DCell<CellStep>> lrch = new List<C2DCell<CellStep>>();
            for (int i = 0; i < Field; i++) {
                for (int j = 0; j < Field; j++) {
                    Arr.Array[i][j].Val = new CellStep();
                    if (i == 0 && j == 0) {
                        Arr.Array[i][j].Val.Step = 0;
                        lrch.Add(Arr.Array[i][j]);
                    } else {
                        lstp.Add(Arr.Array[i][j]);
                    }
                }
            }

            while (lstp.Count > 0) {
                scnt++;
                List<C2DCell<CellStep>> lnext = new List<C2DCell<CellStep>>();
                foreach (C2DCell<CellStep> rc in lrch) {
                    {
                        //north
                        int nr = rc.Row;
                        int nc = rc.Col + scnt;
                        if (nc >= Field && rc.Col > 0) {
                            C2DCell<CellStep> cell = Arr.Array[nr][rc.Col - 1];
                            if (cell.Val.Step < 0 || scnt + 1 < cell.Val.Step) {
                                cell.Val.Step = scnt + 1;
                                cell.Val.Dirs = rc.Val.Dirs + "NS";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, rc.Col - 1, new CellStep());
                            ncell.Val.Step = scnt + 1;
                            ncell.Val.Dirs = rc.Val.Dirs + "NS";
                            lnext.Add(ncell);
                        } else {
                            C2DCell<CellStep> cell = Arr.Array[nr][nc];
                            if (cell.Val.Step < 0 || scnt < cell.Val.Step) {
                                cell.Val.Step = scnt;
                                cell.Val.Dirs = rc.Val.Dirs + "N";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, nc, new CellStep());
                            ncell.Val.Step = scnt;
                            ncell.Val.Dirs = rc.Val.Dirs + "N";
                            lnext.Add(ncell);
                        }
                    }

                    {
                        //south
                        int nr = rc.Row;
                        int nc = rc.Col - scnt;
                        if (nc < 0 && rc.Col < Field - 1) {
                            C2DCell<CellStep> cell = Arr.Array[nr][rc.Col + 1];
                            if (cell.Val.Step < 0 || scnt + 1 < cell.Val.Step) {
                                cell.Val.Step = scnt + 1;
                                cell.Val.Dirs = rc.Val.Dirs + "SN";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, rc.Col + 1, new CellStep());
                            ncell.Val.Step = scnt + 1;
                            ncell.Val.Dirs = rc.Val.Dirs + "SN";
                            lnext.Add(ncell);
                        } else {
                            C2DCell<CellStep> cell = Arr.Array[nr][nc];
                            if (cell.Val.Step < 0 || scnt < cell.Val.Step) {
                                cell.Val.Step = scnt;
                                cell.Val.Dirs = rc.Val.Dirs + "S";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, nc, new CellStep());
                            ncell.Val.Step = scnt;
                            ncell.Val.Dirs = rc.Val.Dirs + "S";
                            lnext.Add(ncell);
                        }
                    }

                    {
                        //east
                        int nr = rc.Row + scnt;
                        int nc = rc.Col;
                        if (nr >= Field && rc.Row > 0) {
                            C2DCell<CellStep> cell = Arr.Array[rc.Row - 1][nc];
                            if (cell.Val.Step < 0 || scnt + 1 < cell.Val.Step) {
                                cell.Val.Step = scnt + 1;
                                cell.Val.Dirs = rc.Val.Dirs + "EW";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(rc.Row - 1, nc, new CellStep());
                            ncell.Val.Step = scnt + 1;
                            ncell.Val.Dirs = rc.Val.Dirs + "EW";
                            lnext.Add(ncell);
                        } else {
                            C2DCell<CellStep> cell = Arr.Array[nr][nc];
                            if (cell.Val.Step < 0 || scnt < cell.Val.Step) {
                                cell.Val.Step = scnt;
                                cell.Val.Dirs = rc.Val.Dirs + "E";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, nc, new CellStep());
                            ncell.Val.Step = scnt;
                            ncell.Val.Dirs = rc.Val.Dirs + "E";
                            lnext.Add(ncell);
                        }
                    }

                    {
                        //west
                        int nr = rc.Row - scnt;
                        int nc = rc.Col;
                        if (nr < 0 && rc.Row < Field - 1) {
                            C2DCell<CellStep> cell = Arr.Array[rc.Row + 1][nc];
                            if (cell.Val.Step < 0 || scnt + 1 < cell.Val.Step) {
                                cell.Val.Step = scnt + 1;
                                cell.Val.Dirs = rc.Val.Dirs + "WE";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(rc.Row + 1, nc, new CellStep());
                            ncell.Val.Step = scnt + 1;
                            ncell.Val.Dirs = rc.Val.Dirs + "WE";
                            lnext.Add(ncell);
                        } else {
                            C2DCell<CellStep> cell = Arr.Array[nr][nc];
                            if (cell.Val.Step < 0 || scnt < cell.Val.Step) {
                                cell.Val.Step = scnt;
                                cell.Val.Dirs = rc.Val.Dirs + "W";
                            }
                            C2DCell<CellStep> ncell = new C2DCell<CellStep>(nr, nc, new CellStep());
                            ncell.Val.Step = scnt;
                            ncell.Val.Dirs = rc.Val.Dirs + "W";
                            lnext.Add(ncell);
                        }
                    }
                }

                List<C2DCell<CellStep>> lrmv = new List<C2DCell<CellStep>>();
                foreach (C2DCell<CellStep> sc in lstp) {
                    if (sc.Val.Step >= 0 && sc.Val.Step <= scnt) {
                        lrmv.Add(sc);
                    }
                }

                foreach (C2DCell<CellStep> sc in lrmv) {
                    lstp.Remove(sc);
                }

                lrch.Clear();
                lnext.Sort((c1, c2) => {
                    if (c1.Val.Step < c2.Val.Step)
                        return -1;
                    if (c1.Val.Step > c2.Val.Step)
                        return 1;
                    if (c1.Row < c2.Row)
                        return -1;
                    if (c1.Row > c2.Row)
                        return 1;
                    if (c1.Col < c2.Col)
                        return -1;
                    if (c1.Col > c2.Col)
                        return 1;
                    return 0;
                });

                for (int ic = 0; ic < lnext.Count;ic++ ) {
                    C2DCell<CellStep> sc = lnext[ic];
                    if (sc.Val.Step > scnt)
                        break;

                    if (ic > 0 && lnext[ic - 1].Row == sc.Row && lnext[ic - 1].Col == sc.Col)
                        continue;

                    lrch.Add(sc);
                }

                lnext.RemoveAll(c => c.Val.Step <= scnt);
            }
        }
    }
}
