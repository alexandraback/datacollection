using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dijkstra
{
    class Program
    {
        static void Main(string[] args)
        {
            List<ProblemInstance> problems;

            using (var f = File.Open(args[0], FileMode.Open))
            using (var tr = new StreamReader(f)) {
                problems = ParseProblem(tr);
            }

            var solutions = problems.Select(x => x.ComputeSolution());
            
            PrintSolutions(solutions);
        }

        private static List<ProblemInstance> ParseProblem(StreamReader tr) {
            int problemCount = int.Parse(tr.ReadLine());

            var problems = new List<ProblemInstance>(problemCount);

            for (long i = 0; i < problemCount; i++) {
                string xl = tr.ReadLine();
                string snip = tr.ReadLine();

                problems.Add(ProblemInstance.Parse(xl, snip));
            }

            return problems;
        }

        private static void PrintSolutions(IEnumerable<bool> solutions) {
            long i = 1;

            foreach (var b in solutions) {
                Console.WriteLine("Case #{0}: {1}", i++, b ? "YES" : "NO");
            }
        }
    }

    public enum Quaternion {
        One = 1,
        MinusOne = -1,
        I = 2,
        MinusI = -2,
        J = 3,
        MinusJ = -3,
        K = 4,
        MinusK = -4
    }

    public static class QOp {
        public static Quaternion Negate(Quaternion q) {
            return (Quaternion)(-(long)q);
        }

        public static Quaternion Multiply(Quaternion left, Quaternion right) {
            if ((long) left < 0) {
                return Negate(Multiply(Negate(left), right));
            }

            if ((long) right < 0) {
                return Negate(Multiply(left, Negate(right)));
            }

            if ((long) left > (long) right) {
                return Negate(Multiply(right, left));
            }

            if (left == Quaternion.One) {
                return right;
            }

            if (left == right) {
                return Quaternion.MinusOne;
            }

            if (left == Quaternion.I) {
                if (right == Quaternion.J) {
                    return Quaternion.K;
                }

                if (right == Quaternion.K) {
                    return Quaternion.MinusJ;
                }
            }

            if (left == Quaternion.J) {
                // must have right == Quaternion.K
                return Quaternion.I;
            }

            throw new InvalidOperationException("Unexpected values");
        }

        public static Quaternion FromChar(char c) {
            switch (c) {
                case 'i':
                    return Quaternion.I;
                case 'j':
                    return Quaternion.J;
                case 'k':
                    return Quaternion.K;
            }

            throw new ArgumentException("c");
        }
    }


    internal class ProblemInstance {
        private readonly string snip;
        private readonly long replicationCount;

        public ProblemInstance(string snip, long replicationCount) {
            this.snip = snip;
            this.replicationCount = replicationCount;
        }

        public static ProblemInstance Parse(string xl, string snip) {
            return new ProblemInstance(snip, long.Parse(xl.Split(' ')[1]));
        }


        List<Quaternion> ComputeRollingProduct(string s) {
            Quaternion current = Quaternion.One;

            var result = new List<Quaternion>(s.Length);

            foreach (var c in s) {
                current = QOp.Multiply(current, QOp.FromChar(c));

                result.Add(current);
            }

            return result;
        } 

        public bool ComputeSolution() {
            int remainder = (int)(replicationCount%4);

            string whole = snip + snip + snip + snip;

            if (remainder == 0) {
                // impossible with zero remainder, product is 1 != -1 = ijk
                return false;
            }

            string rest;

            var rollProd = ComputeRollingProduct(whole);

            if (rollProd[snip.Length * remainder - 1] != Quaternion.MinusOne) {
                // impossible by product invariant.
                return false;
            }

            var firstI = rollProd.IndexOf(Quaternion.I);

            if (firstI == -1) {
                return false;
            }

            var firstJ = rollProd.IndexOf(Quaternion.K, firstI); // i*j = k

            if (firstJ == -1) {
                firstJ = rollProd.IndexOf(Quaternion.K);

                if (firstJ == -1) {
                    return false; // there's really no J
                }

                firstJ += snip.Length*4;
            }


            var result= firstJ < replicationCount*snip.Length;

            return result;
        }
    }
}
