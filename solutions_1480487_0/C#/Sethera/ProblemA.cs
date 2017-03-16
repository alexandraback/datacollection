using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

namespace GoogleCodeJam {
    public class ProblemA {
        public static String filename = "A-small-attempt3";
        public static bool printToConsole = false;

        public static void Main(string[] args) {
            TextReader tr = new StreamReader("E:\\Downloads\\" + filename + ".in");
            TextWriter tw = new StreamWriter("E:\\Downloads\\" + filename + ".out");
            if (printToConsole) {
                tw = System.Console.Out;
            }

            ProblemA prob = new ProblemA();
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
            List<String> points = new List<String>();

            int readCaseNumber = 0;

            lock (_readLock) {
                caseNumber++;
                if (caseNumber > caseCount) {
                    return false;
                }
                readCaseNumber = caseNumber;

                #region "really read the case"
                String[] parts = _tr.ReadLine().Split(' ');

                points.AddRange(parts.Skip(1));
                #endregion
            }

            String solution = ProcessCase(points);

            lock (_writeLock) {
                solutions[readCaseNumber] = solution;
            }

            return true;
        }


        private String ProcessCase(List<String> strPoints) {
            int players = strPoints.Count;

            List<int> points = strPoints.Select(s => int.Parse(s)).ToList();

            int x = points.Sum();

            String retval = "";
            for (int p = 0; p < players; p++) {
                List<int> cpoints = new List<int>(points);
                cpoints.RemoveAt(p);
                int nextlowest = cpoints.Min();
                int nextlowestcount = cpoints.Count(c => c == nextlowest);

                int pPoints = points[p];

                double voteNeeded = (((double)nextlowestcount * (double)(nextlowest - pPoints) / (double)x) + 1.0)   / (double)(nextlowestcount + 1) * 100.0;

                if (voteNeeded < 0) {
                    voteNeeded = 0;
                }
                retval += voteNeeded.ToString() + " ";
            }

            return retval.Trim();
        }
    }
}
