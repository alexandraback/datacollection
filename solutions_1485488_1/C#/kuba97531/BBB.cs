using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;

namespace GCJDevKit.Solvers
{
    class Field
    {
        public int i;
        public int j;
        public int top;
        public int bottom;
        public int minAccessTime;

        public override string ToString()
        {
            return "[" + i + "," + j + "] at "+minAccessTime;
        }
    }

    class BBB : AbstractSolver
    {
        Field[,] fields; 

        int swim = 10;
        int walk = 100;
        int n, m;
        protected override object Solve(System.IO.StreamReader input)
        {
            int h = NextInt();
            n = NextInt();
            m = NextInt();

            fields = new Field[n, m];
            

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    fields[i, j] = new Field();
                    fields[i, j].top = NextInt();
                    fields[i, j].i = i;
                    fields[i, j].j = j;
                    fields[i, j].minAccessTime = 1000000000;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    fields[i, j].bottom = NextInt();
                }
            }

            fields[0, 0].minAccessTime = 0;
            Heap<Field> stack = new Heap<Field>(n*m+1);
            
            for (int i = 0; i < n; i++)                for (int j = 0; j < m; j++) stack.Add(fields[i, j].minAccessTime, fields[i, j]);
                    
            

            while (!stack.Empty)
            {
                var kvp = stack.Pop();
                Field f = kvp.Value;

                if (f.minAccessTime == 1000000000) break;

                var nbs = neighbours(f.i, f.j);

                for (int i = 0; i < nbs.Length; i++ )
                {
                    var neig = nbs[i];
                    int t = timeToMove(f, neig, h - f.minAccessTime);
                    if (t != -1 && f.minAccessTime + t < neig.minAccessTime)
                    {
                        neig.minAccessTime = f.minAccessTime + t;
                        stack.ChangePriorityToSmaller(neig, neig.minAccessTime);
                    }
                }
            }

            int score = fields[n - 1, m - 1].minAccessTime;
            return score / 10 + "." + score % 10;

        }

        Field[] neighbours(int i, int j)
        {
            List<Field> ns = new List<Field>();
            if (fieldAt(i,j-1)) ns.Add (fields[i,j-1]);
            if (fieldAt(i,j+1)) ns.Add(fields[i,j+1]);
            if (fieldAt(i-1,j)) ns.Add(fields[i-1,j]);
            if (fieldAt(i+1,j)) ns.Add(fields[i+1,j]);
            return ns.ToArray();
        }

        bool fieldAt(int i, int j)
        {
            return  !(i < 0 || i >= n || j < 0 || j >= m);
        }

        int timeToMove(Field oldField, Field  newField, int waterLevel)
        {
            int minTop = Math.Min(oldField.top, newField.top);
            int maxbottom = Math.Max(oldField.bottom, newField.bottom);

            if (minTop - 50 < maxbottom) return -1;

            

            int originalTimeToWait = 0;

            if (waterLevel + 50 > minTop)
            {
                originalTimeToWait =  waterLevel -minTop + 50;
                waterLevel = minTop - 50;
                //waterLevel -= waterLevel -minTop + 50;
            }

            if (originalTimeToWait == 0 && oldField.minAccessTime == 0)
            {
                return 0;
            }

            if (oldField.bottom + 20 <= waterLevel) return originalTimeToWait + swim; else return originalTimeToWait + walk;
        }

    }
}
