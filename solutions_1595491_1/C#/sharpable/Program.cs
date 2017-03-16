using System;
using System.Collections.Generic;
using System.Text;

namespace Problem_B
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= cases; c++)
            {
                string[] caseRecord = Console.ReadLine().Split(' ');

                int n = int.Parse(caseRecord[0]);
                int s = int.Parse(caseRecord[1]);
                int p = int.Parse(caseRecord[2]);
                
                int[]ti = new int[n];
                for (int nn = 0; nn < n; nn++)
                {
                    ti[nn] = int.Parse(caseRecord[3 + nn]);
                }

                int result = ProcessCase(s, p, ti);

                Console.WriteLine(String.Format("Case #{0}: {1}", c, result));
            }
        }

        ResultsMatrix Matrix = new ResultsMatrix();

        private int ProcessCase(int s, int p, int[] ti)
        {
            int googlers = 0;
            int surprising = 0;

            for (int n = 0; n < ti.Length; n++)
            {
                bool passed = false;
                bool surprise = true;

                foreach (var triplet in Matrix.Possibles(ti[n]))
                {
                    if (triplet.C >= p)
                    {
                        passed = true;

                        if (!triplet.IsSurprise)
                        {
                            surprise = false;
                        }
                    }
                }

                if (passed)
                {
                    if (surprise)
                    {
                        surprising++;
                    }
                    else
                    {
                        googlers++;
                    }
                }
            }

            googlers += (s < surprising ? s : surprising);

            return googlers;
        }

    }

    class Triplet
    {
        public int A { get; private set; }
        public int B { get; private set; }
        public int C { get; private set; }

        public bool IsSurprise { get; private set; }

        public Triplet(int a, int b, int c)
        {
            this.A = a;
            this.B = b;
            this.C = c;

            this.IsSurprise = (b - a == 2 || c - a == 2 || c - b == 2) ;
        }
    }

    class ResultsMatrix
    {
        Dictionary<int, List<Triplet>> Triplets = new Dictionary<int, List<Triplet>>();

        public ResultsMatrix()
        {
            for (int r1 = 0; r1 <= 11; r1++)
            {
                for (int r2 = r1; r2 <= 11; r2++)
                {
                    if (r2 - r1 > 2)
                    {
                        continue;
                    }

                    for (int r3 = r2; r3 <= 11; r3++)
                    {
                        if (r3 - r2 > 2 || r3 - r1 > 2)
                        {
                            continue;
                        }

                        int sum = r1 + r2 + r3;

                        if (!Triplets.ContainsKey(sum))
                        {
                            Triplets.Add(sum, new List<Triplet>());
                        }

                        Triplets[sum].Add(new Triplet(r1, r2, r3));
                    }
                }
            }
        }

        public List<Triplet> Possibles(int total)
        {
            return Triplets[total];
        }
    }
}
