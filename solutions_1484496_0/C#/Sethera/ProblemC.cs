using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

namespace GoogleCodeJam {
    public class ProblemC {
        public static String filename = "C-small-attempt0";
        public static bool printToConsole = false;

        public static void Main(string[] args) {
            TextReader tr = new StreamReader("E:\\Downloads\\" + filename + ".in");
            TextWriter tw = new StreamWriter("E:\\Downloads\\" + filename + ".out");
            if (printToConsole) {
                tw = System.Console.Out;
            }

            ProblemC prob = new ProblemC();
            long start = DateTime.Now.Ticks;
            prob.Solve(tr, tw, 2);
            TimeSpan ts = new TimeSpan(DateTime.Now.Ticks - start);
            System.Console.Out.WriteLine(ts.ToString());

            tr.Close();

            tw.Flush();
            tw.Close();

            System.Console.Out.WriteLine("finished!");
            System.Console.In.ReadLine();
        }

        #region "class variables"
        private TextReader _tr;
        private TextWriter _tw;
        private Object _readLock;
        private int caseNumber;
        private int caseCount;
        private Dictionary<int, String> solutions;
        private Object _writeLock;
        #endregion

        public void Solve(TextReader tr, TextWriter tw, int threadCount) {
            _tr = tr;
            _tw = tw;
            _readLock = new Object();
            _writeLock = new Object();

            caseCount = int.Parse(_tr.ReadLine());
            solutions = new Dictionary<int, String>();

            if (threadCount > 1) {
                Thread[] threads = new Thread[threadCount];
                for (int i = 0; i < threadCount; i++) {
                    threads[i] = new Thread(() => { while (SolveCase()) { } });
                    threads[i].Start();
                }
                for (int i = 0; i < threadCount; i++) {
                    threads[i].Join();
                }

            } else {
                while (SolveCase()) { }
            }

            for (int i = 1; i <= caseCount; i++) {
                _tw.WriteLine("Case #" + i + ": " + solutions[i]);
            }
        }




        private bool SolveCase() {
            List<String> strS = new List<String>();

            int readCaseNumber = 0;

            lock (_readLock) {
                caseNumber++;
                if (caseNumber > caseCount) {
                    return false;
                }
                readCaseNumber = caseNumber;

                #region "really read the case"
                String[] parts = _tr.ReadLine().Split(' ');

                strS.AddRange(parts.Skip(1));
                #endregion
            }

            String solution = ProcessCase(strS);

            lock (_writeLock) {
                solutions[readCaseNumber] = solution;
            }

            return true;
        }


        private String ProcessCase(List<String> strS) {
            List<long> S = strS.Select(s => long.Parse(s)).ToList();

            Dictionary<int, long> subsetSums = new Dictionary<int, long>();
            Dictionary<int, List<long>> subsets = new Dictionary<int, List<long>>();

            int combos = 1048576;

            String retval = "Impossible";

            for (int i = 1; i < combos; i++) {
                List<long> subset = GetSubsetX(S, i);
                subsets[i] = subset;
                long sum = subset.Sum();
                if (subsetSums.ContainsValue(sum)) {
                    KeyValuePair<int, long> otherPair = subsetSums.First(p => p.Value == sum);
                    List<long> othersubset = subsets[otherPair.Key];
                    String seta = "";
                    String setb = "";
                    for (int j = 0; j < subset.Count; j++) {
                        seta += subset[j] + " ";
                    }
                    for (int j = 0; j < othersubset.Count; j++) {
                        setb += othersubset[j] + " ";
                    }
                    retval = "\n" + seta.Trim() + "\n" + setb.Trim() + "\n";
                    break;
                } else {
                    subsetSums[i] = sum;
                }
            }

            return retval;
        }


        private List<long> GetSubsetX(List<long> S, long x) {
            long mask = 1;
            List<long> subset = new List<long>();

            for (int i = 0; i < 21; i++) {
                if ((x & mask) != 0) {
                    subset.Add(S[i]);
                }
                mask = mask << 1;
            }

            return subset;

        }
    }
}
