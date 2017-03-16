using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

namespace GoogleCodeJam {
    public class ProblemA {
        public static String filename = "A-small-attempt0";
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
            List<String> classes = new List<String>();

            int readCaseNumber = 0;

            lock (_readLock) {
                caseNumber++;
                if (caseNumber > caseCount) {
                    return false;
                }
                readCaseNumber = caseNumber;

                #region "really read the case"
                String[] counts = _tr.ReadLine().Split(' ');

                int classCount = int.Parse(counts[0]);

                for (int i = 0; i < classCount; i++) {
                    classes.Add(_tr.ReadLine());
                }
                #endregion
            }

            String solution = ProcessCase(classes);

            lock (_writeLock) {
                solutions[readCaseNumber] = solution;
            }

            return true;
        }


        private String ProcessCase(List<String> strClasses) {
            int classCount = strClasses.Count;

            ClassNode[] classes = new ClassNode[classCount];

            for (int i = 0; i < classCount; i++) {
                classes[i] = new ClassNode();
                classes[i].number = i + 1;
            }

            for (int i = 0; i < classCount; i++) {
                String strClass = strClasses[i];

                classes[i].inherits = strClass.Split(' ').Skip(1).Select(s => classes[int.Parse(s) - 1]).ToList();
            }

            bool diamondExists = false;

            for (int i = 0; i < classCount; i++) {
                if (classes[i].IsRootOfDiamond()) {
                    diamondExists = true;
                    break;
                }
            }

            if (diamondExists) {
                return "Yes";
            } else {
                return "No";
            }
        }


        private class ClassNode {
            public int number = -1;
            public List<ClassNode> inherits = new List<ClassNode>();

            public bool IsRootOfDiamond() {
                List<ClassNode> seen = new List<ClassNode>();
                List<ClassNode> toprocess = new List<ClassNode>();

                bool foundDiamond = false;
                seen.AddRange(inherits);
                toprocess.AddRange(inherits);

                while (toprocess.Count > 0) {
                    ClassNode next = toprocess[0];
                    toprocess.RemoveAt(0);

                    foreach (ClassNode i in next.inherits) {
                        if (seen.Contains(i)) {
                            foundDiamond = true;
                            break;
                        }
                    }

                    seen.AddRange(next.inherits);
                    toprocess.AddRange(next.inherits);                    
                }

                return foundDiamond;
            }
        }
    }
}
