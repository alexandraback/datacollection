using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _2015qualB
{
    // For each diner, we have Pi and Ki (number of splits).
    // Let Ri = ceil(Pi / Ki) = (Pi + Ki - 1) / Ki.
    // We want to minimize max(Ri)+sum(Ki-1).
    struct Diner
    {
        public uint P;
        public uint K;
    }

    class Solver
    {
        private uint D;
        private List<Diner>[] R;

        private uint RLevel;

        public Solver(uint D, uint[] P)
        {
            this.D = D;
            this.RLevel = P.Max();
            R = new List<Diner>[this.RLevel + 1];

            for (uint i = 0; i < R.Length; i++)
            {
                R[i] = new List<Diner>();
            }

            for (uint i = 0; i < this.D; i++)
            {
                Diner di = new Diner();
                di.P = P[i];
                di.K = 1;
                R[di.P].Add(di);
            }
        }

        public uint Solve()
        {
            uint L = uint.MaxValue;

            do
            {
                L = Math.Min(L, this.Eval());
            }
            while (this.NextLevel());

            return L;
        }

        public uint Eval()
        {
            uint M = 0;
            uint S = 0;
            for (uint i = 0; i <= this.RLevel; i++)
            {
                if (R[i].Count > 0)
                {
                    M = i;
                }

                foreach (Diner di in R[i])
                {
                    S += di.K - 1;
                }
            }
            return S + M;
        }

        public bool NextLevel()
        {
            if (this.RLevel == 0)
            {
                return false;
            }

            for (int i = 0; i < this.R[this.RLevel].Count; i++)
            {
                Diner di = this.R[this.RLevel][i];
                di.K++;
                uint Ri = (di.P + di.K - 1) / di.K;
                if (Ri == this.RLevel)
                {
                    return false;
                }
                R[Ri].Add(di);
            }
            R[this.RLevel].Clear();

            this.RLevel--;

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("input.txt");
            TextWriter tw = new StreamWriter("output.txt");

            uint T = uint.Parse(tr.ReadLine());
            for (int c = 1; c <= T; c++)
            {
                Console.WriteLine("Solving case #" + c);

                uint D = uint.Parse(tr.ReadLine());
                string[] Ps = tr.ReadLine().Split(' ');
                uint[] P = new uint[Ps.Length];

                for (uint i = 0; i < P.Length; i++)
                {
                    P[i] = uint.Parse(Ps[i]);
                }

                Solver sol = new Solver(D, P);

                tw.WriteLine("Case #" + c + ": " + sol.Solve());
            }

            tr.Close();
            tw.Close();
        }
    }
}
