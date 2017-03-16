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
            String boxes = "";
            String toys = "";
            int boxCount, toyCount;

            int readCaseNumber = 0;

            lock (_readLock) {
                caseNumber++;
                if (caseNumber > caseCount) {
                    return false;
                }
                readCaseNumber = caseNumber;

                #region "really read the case"
                String[] counts = _tr.ReadLine().Split(' ');

                boxCount = int.Parse(counts[0]);
                toyCount = int.Parse(counts[1]);

                boxes = _tr.ReadLine();
                toys = _tr.ReadLine();
                #endregion
            }

            String solution = ProcessCase(boxCount, toyCount, boxes, toys);

            lock (_writeLock) {
                solutions[readCaseNumber] = solution;
            }

            return true;
        }


        private String ProcessCase(int boxCount, int toyCount, String strboxes, String strtoys) {

            List<long> boxCounts = new List<long>();
            List<int> boxTypes = new List<int>();
            List<long> toyCounts = new List<long>();
            List<int> toyTypes = new List<int>();

            {
                String[] boxParts = strboxes.Split(' ');
                for (int i = 0; i < boxCount; i++) {
                    boxCounts.Add(long.Parse(boxParts[i * 2]));
                    boxTypes.Add( int.Parse(boxParts[i * 2 + 1]));
                }

                String[] toyParts = strtoys.Split(' ');
                for (int i = 0; i < toyCount; i++) {
                    toyCounts.Add(long.Parse(toyParts[i * 2]));
                    toyTypes.Add( int.Parse(toyParts[i * 2 + 1]));
                }
            }

            long toysMade = MakeStuff(boxCounts.ToArray(), boxTypes.ToArray(), toyCounts.ToArray(), toyTypes.ToArray());


            return toysMade.ToString();
        }


        private long MakeStuff(long[] boxCounts, int[] boxTypes, long[] toyCounts, int[] toyTypes) {
            if (boxCounts.Length == 0 || toyCounts.Length == 0) {
                return 0;
            }

            long toysMade = 0;
            while (boxTypes.Length > 0 && toyTypes.Length > 0 && boxTypes[0] == toyTypes[0]) {
                long newMade = Math.Min(boxCounts[0], toyCounts[0]);
                toysMade += newMade;

                boxCounts[0] -= newMade;
                toyCounts[0] -= newMade;

                if (boxCounts[0] <= 0) {
                    boxCounts = boxCounts.Skip(1).ToArray();
                    boxTypes = boxTypes.Skip(1).ToArray();
                }
                if (toyCounts[0] <= 0) {
                    toyCounts = toyCounts.Skip(1).ToArray();
                    toyTypes = toyTypes.Skip(1).ToArray();
                }
            }

            if (boxCounts.Length > 0 && toyCounts.Length > 0) {
                long oneWay = MakeStuff(boxCounts.Skip(1).ToArray(), boxTypes.Skip(1).ToArray(), toyCounts.ToList().ToArray(), toyTypes.ToList().ToArray());
                long otherWay = MakeStuff(boxCounts.ToList().ToArray(), boxTypes.ToList().ToArray(), toyCounts.Skip(1).ToArray(), toyTypes.Skip(1).ToArray());

                return Math.Max(oneWay, otherWay) + toysMade;
            } else {
                return toysMade;
            }
        }
    }
}
