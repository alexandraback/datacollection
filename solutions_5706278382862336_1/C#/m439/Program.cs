using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ {
    class Program {
        static void Main(string[] args) {
            // string fileName = "input";
            // string fileName = "A-small-attempt0";
            string fileName = "A-large";

            string line;

            using (StreamReader inFile = new System.IO.StreamReader(fileName + ".in"))
            using (StreamWriter outFile = new System.IO.StreamWriter(fileName + ".out")) {
                ConsoleFileWriter cfw = new ConsoleFileWriter(outFile);
 
                line = inFile.ReadLine();

                int testcases = int.Parse(line);
                for (int i = 0; i < testcases; i++) {
                    solveSingleTestcase(inFile, cfw, i + 1);
                }

            }

            Console.ReadLine();
        }

        private static void solveSingleTestcase(StreamReader inFile, ConsoleFileWriter cfw, int testcaseNumber) {
            cfw.Write("Case #" + testcaseNumber + ": ");
            
            string line = inFile.ReadLine();
            string[] tokens = line.Split(new char[] { '/' });

            BigInteger P, Q;
            P = BigInteger.Parse(tokens[0]);
            Q = BigInteger.Parse(tokens[1]);
    
            BigInteger two = new BigInteger(2);
            int generation = -1;
            for (int i = 1; i <= 40; i++) {
                P = BigInteger.Multiply(P, two);

                if (BigInteger.Compare(P, Q) != -1) {
                    if (generation == -1) {
                        generation = i;
                    }

                    P = BigInteger.Subtract(P, Q);

                    if (P.IsZero) {
                        break;
                    }
                } 
            }

            if (generation >= 0 && P.IsZero) {
                cfw.WriteLine("" + generation);
            } else {
                cfw.WriteLine("impossible");
            }
        }
    }
}
