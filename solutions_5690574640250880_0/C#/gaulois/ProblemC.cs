
#define TRACE

using System;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Linq;

namespace test
{
    enum Block
    {
        Empty = 100,
        Mine = 101,
        Start = 102
    }

    class Pos
    {
        public int x;
        public int y;

        public override int GetHashCode()
        {
            return this.x + this.y << 10;
        }

        public override bool Equals(object obj)
        {
            Pos o = (Pos)obj;

            if (o.x == this.x && o.y == this.y)
            {
                return true;
            }

            return false;
        }

        public override string ToString()
        {
            return string.Format("({0}, {1})", this.x, this.y);
        }
    }

    class Problem
    {
        static Dictionary<Block, string> T = new Dictionary<Block, string> { { Block.Empty, "." }, { Block.Mine, "*" }, { Block.Start, "c" } };

        public int[,] blocks;
        public int nBombs;
        public int y;
        public int x;

        public void ResetBlocks()
        {
            for (int i = 0; i < this.y; ++i)
            {
                for (int j = 0; j < this.x; ++j)
                {
                    this.blocks[i, j] = (int)Block.Empty;
                }
            }
        }

        public void ResetCountedBlocks()
        {
            for (int i = 0; i < this.y; ++i)
            {
                for (int j = 0; j < this.x; ++j)
                {
                    if (this.blocks[i, j] < (int)Block.Empty)
                    {
                        this.blocks[i, j] = (int)Block.Empty;
                    }
                }
            }
        }

        public bool IsAnyLeftEmpty()
        {
            for (int i = 0; i < this.y; ++i)
            {
                for (int j = 0; j < this.x; ++j)
                {
                    if (this.blocks[i, j] == (int)Block.Empty)
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        public int At(int y, int x)
        {
            return this.blocks[y, x];
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < this.y; ++i)
            {
                for (int j = 0; j < this.x; ++j)
                {
                    if (Problem.T.ContainsKey((Block)this.blocks[i, j]))
                    {
                        sb.Append(Problem.T[(Block)this.blocks[i, j]]);
                    }
                    else
                    {
                        sb.Append(this.blocks[i, j]);
                    }
                }

                if (i != this.y - 1)
                {
                    sb.Append("\n");
                }
            }

            return sb.ToString();
        }
    }

    class MainClass
    {
        static int Min(int a, int b)
        {
            if (a < b)
            {
                return a;
            }

            return b;
        }

        static int Max(int a, int b)
        {
            if (a > b)
            {
                return a;
            }

            return b;
        }

        static Problem SolveUniLine(Problem m)
        {
            int nB = m.nBombs;
            int L = Max(m.x, m.y);
            for (int i = 0; i < L; ++i)
            {
                if (nB > 0)
                {
                    if (L == m.x)
                    {
                        m.blocks[0, i] = (int)Block.Mine;
                    }
                    else
                    {
                        m.blocks[i, 0] = (int)Block.Mine;
                    }
                    nB -= 1;
                }

                if (i == L - 1)
                {
                    if (L == m.x)
                    {
                        m.blocks[0, i] = (int)Block.Start;
                    }
                    else
                    {
                        m.blocks[i, 0] = (int)Block.Start;
                    }
                }
            }

            return m;
        }

        static bool Next(BitArray ba)
        {
            for (int i = 0; i < ba.Length; ++i)
            {
                if (ba[i] == false)
                {
                    ba[i] = true;
                    return false;
                }
                else
                {
                    ba[i] = false;
                }
            }

            return true;
        }

        static int Sum(BitArray ba)
        {
            int s = 0;
            for (int i = 0; i < ba.Length; ++i)
            {
                if (ba[i] == true)
                {
                    s += 1;
                }
            }

            return s;
        }

        static string Print(BitArray ba)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < ba.Length; ++i)
            {
                if (ba[i] == true)
                {
                    sb.Append("1");
                }
                else
                {
                    sb.Append("0");
                }
            }

            return sb.ToString();
        }

        static List<Pos> GetNeighbors(Problem m, int y, int x)
        {
            List<Pos> P = new List<Pos>();

            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if ((i != 0 || j != 0))
                    {
                        if (x + i >= 0 && x + i < m.x)
                        {
                            if (y + j >= 0 && y + j < m.y)
                            {
                                Pos p = new Pos();
                                p.x = x + i;
                                p.y = y + j;
                                P.Add(p);
                            }
                        }
                    }
                }
            }

            return P;
        }

        static bool IsSolved(Problem m)
        {
            // Assume the 'c' is in the lower-right
            var visited = new HashSet<Pos>();

            var toVisit = new Stack<Pos>();
            var toVisitN = new Stack<Pos>();

            Pos p = new Pos();
            p.x = m.x - 1;
            p.y = m.y - 1;
            toVisit.Push(p);

            //if(m.At(cP.y, cP.x) == (int)Block.Start || m.At(cP.y, cP.x) == 0 )
            while (toVisit.Count != 0)
            {
                Pos cP = toVisit.Pop();

                List<Pos> N = GetNeighbors(m, cP.y, cP.x);

                int nN = 0;
                foreach (var n in N)
                {
                    if (m.At(n.y, n.x) == (int)Block.Mine)
                    {
                        nN += 1;
                    }
                }

                if (m.At(cP.y, cP.x) == (int)Block.Empty)
                {
                    m.blocks[cP.y, cP.x] = nN;
                }

                if (nN == 0)
                {
                    foreach (var n in N)
                    {
                        if (m.At(n.y, n.x) == (int)Block.Empty)
                        {
                            if (!visited.Contains(n))
                            {
                                visited.Add(n);
                                toVisit.Push(n);
                            }
                        }
                    }
                }
            }

            //System.Console.WriteLine(m);

            bool v = false;
            if (!m.IsAnyLeftEmpty())
            {
                v = true;
            }

            m.ResetCountedBlocks();

            return v;
        }

        static Problem BruteForce(Problem m, int bombsLeft)
        {
            List<Pos> possibleBombs = new List<Pos>();

            for (int i = 0; i < m.y; ++i)
            {
                for (int j = 0; j < m.x; ++j)
                {
                    if (m.blocks[i, j] == (int)Block.Empty)
                    {
                        var pos = new Pos();
                        pos.y = i;
                        pos.x = j;
                        possibleBombs.Add(pos);
                    }
                }
            }

            //System.Console.WriteLine(possibleBombs.Count);
            BitArray pSpace = new BitArray(possibleBombs.Count);

            //System.Console.WriteLine("-----------------------");
            //System.Console.WriteLine(m);
            //System.Console.WriteLine("-----------------------");

            while (Next(pSpace) == false)
            {
                if (Sum(pSpace) != bombsLeft)
                {
                    continue;
                }

                for (int i = 0; i < pSpace.Length; ++i)
                {
                    if (pSpace[i] == true)
                    {
                        m.blocks[possibleBombs[i].y, possibleBombs[i].x] = (int)Block.Mine;
                    }
                }

                if (IsSolved(m))
                {
                    return m;
                }
                else
                {
                    ////System.Console.WriteLine(m);
                    //return null;
                }

                //System.Console.WriteLine(IsSolved(m));
                //System.Console.WriteLine(m);

                // Reset
                for (int i = 0; i < pSpace.Length; ++i)
                {
                    if (pSpace[i] == true)
                    {
                        m.blocks[possibleBombs[i].y, possibleBombs[i].x] = (int)Block.Empty;
                    }
                }
            }

            return null;
        }

        static Problem Solve(Problem m)
        {
            if (m.x == 1 || m.y == 1)
            {
                return SolveUniLine(m);
            }

            int nBombsLeft = m.nBombs;
            for (int i = 0; i < m.y - 3; ++i)
            {
                if (nBombsLeft > m.x)
                {
                    for (int j = 0; j < m.x; ++j)
                    {
                        nBombsLeft -= 1;
                        m.blocks[i, j] = (int)Block.Mine;
                    }
                }
            }

            m.blocks[m.y - 1, m.x - 1] = (int)Block.Start;

            if (nBombsLeft == 0)
            {
                return m;
            }

            return BruteForce(m, nBombsLeft);
        }

        static List<Problem> ReadProblems(string file)
        {
            List<Problem> problems = new List<Problem>();

            string[] lines = System.IO.File.ReadAllLines(file);

            int nProbs = int.Parse(lines[0]);
            for (int i = 1; i < lines.Length; ++i)
            {
                Problem problem = new Problem();

                string[] lS = lines[i].Split(' ');
                problem.y = int.Parse(lS[0]);
                problem.x = int.Parse(lS[1]);

                problem.blocks = new int[problem.y, problem.x];

                problem.ResetBlocks();

                problem.nBombs = int.Parse(lS[2]);

                problems.Add(problem);
            }

            // Trace.Assert (nProbs == problems.Count);

            return problems;
        }

        public static void Main(string[] args)
        {
            Trace.Listeners.Add(new ConsoleTraceListener());
            
            //string filename = "../../tiny.in";
            string filename = "../../C-small-attempt2.in";
            
            List<Problem> problems = ReadProblems(filename);

            int i = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var problem in problems)
            {
                Problem p = Solve(problem);

                string s = string.Format("Case #{0}:\n{1}", i + 1, p == null ? "Impossible" : p.ToString());

                Console.WriteLine(s);
                sb.Append(s);
                sb.Append("\n");

                ++i;
            }

            System.IO.File.WriteAllText(filename.Replace(".in", ".out"), sb.ToString());
        }
    }
}
