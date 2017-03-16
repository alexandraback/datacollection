using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using log4net;

namespace Miner {
     class Program {
        static void Main(string[] args) {
            log4net.Config.XmlConfigurator.Configure();
            int testCount = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            for(int i = 1; i <= testCount; i++) {
                Test test = new Test();
                test.Load();
                Console.WriteLine("Case #{0}:", i);
                Console.WriteLine(test.Solve());
            }
        }
    }

    public class Test {
        private static readonly ILog log = LogManager.GetLogger(typeof(Test));
        int rows, cols, mines, empties;
        string[] lines; 
        public void Load() {
            var pars = Console.ReadLine().Split().Select(it => Int32.Parse(it));
            rows = pars.First();
            cols = pars.Skip(1).First();
            mines = pars.Last();
            empties = rows * cols - mines;
        }
        bool calc() {
            if(empties == 2 && cols != 1 && rows != 1) {
                return false;
            }
            if(empties == 3 && cols != 1 && rows != 1) {
                return false;
            }
            if(empties == 5 && cols != 1 && rows != 1) {
                return false;
            }
            if(empties == 7 && cols != 1 && rows != 1) {
                return false;
            }
            lines = new string[rows];
            int firstrows = Math.Min(cols, empties / 2);
            int inlastrow = empties % cols;
            int qrow = empties / cols;
            if(firstrows != cols) {
                inlastrow = empties % 2;
                if(firstrows != 0) {
                    qrow = 2;
                }
            }
            if(rows == 1){
                firstrows =empties;
                inlastrow=0;
            }

            if(rows == 2 && inlastrow > 0 && cols != 1&&empties!=1) {
                return false;
            }
            //if(rows > 1) {
                lines[0] = new String('.', firstrows) + new String('*', cols - firstrows);
            //}
            if(rows > 1) {
                lines[1] = new String('.', firstrows) + new String('*', cols - firstrows);
            }
            for(int i = 2; i < rows; i++) {
                if(qrow >i) {
                    lines[i] = new String('.', cols);
                } else if(qrow==i){
                    lines[i] = new String('.', inlastrow) + new String('*', cols - inlastrow);
                    if(inlastrow == 1) {
                        if(cols == 1) {//все ok
                        }else if(cols==2){
                            return false;
                        } else {
                            int laspos = lines[i - 1].ToList().LastIndexOf('.');
                            lines[i - 1] = lines[i - 1].Remove(laspos, 1) + "*";
                            if(i == 2) {
                                lines[i - 2] = lines[i - 2].Remove(laspos, 1) + "*";
                                lines[i] = new String('.', 3) + new String('*', cols - 3);
                            } else {
                                lines[i] = new String('.', 2) + new String('*', cols - 2);
                            }
                        }
                    }
                }else{
                    lines[i] = new String('*', cols);
                }
            }

            //special cases: 1 пустая, 1 строка, 1 ряд
            lines[0] = "c" + lines[0].Substring(1);
            return true;
        }
        public string Solve() {
            if(!calc()) {
                log.InfoFormat("Impossible {0} {1} {2} {3}", rows, cols, mines, empties);
                if(lines != null) {
                    log.InfoFormat("{0}", string.Join("\n", lines));
                }
                return "Impossible";
            }
            /*if(empties == 1) {
                return "Impossible";
            }*/
            if(lines.Sum(it => it.Sum(iz => (iz == '.' || iz == 'c') ? 1 : 0)) != empties) {
                log.InfoFormat("Horrible empties {0} {1} {2} {3}", rows, cols, mines, empties);
                log.InfoFormat("{0}", string.Join("\n", lines));
            }
            if(lines.Sum(it => it.Sum(iz => (iz == '*') ? 1 : 0)) != mines) {
                log.InfoFormat("Horrible mines {0} {1} {2} {3}", rows, cols, mines, empties);
                log.InfoFormat("{0}", string.Join("\n", lines));
            }
            return string.Join("\n", lines);
        }
    }
}
