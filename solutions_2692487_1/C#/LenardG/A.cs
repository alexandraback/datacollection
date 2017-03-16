using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013Q1B_A
{
    class A
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A2.in"))
            using (StreamWriter sw = new StreamWriter("A2.out"))
            {
                string line = null;
                string[] parts = null;

                line = sr.ReadLine();
                long T = long.Parse(line);

                for (int t = 0; t < T; t++)
                {
                    line = sr.ReadLine();
                    parts = line.Split(' ');
                    long A = long.Parse(parts[0]);
                    int N = int.Parse(parts[1]);

                    long[] motes = new long[N];
                    line = sr.ReadLine();
                    parts = line.Split(' ');
                    for (int n = 0; n < N; n++)
                    {
                        motes[n] = long.Parse(parts[n]);
                    }
                    Array.Sort(motes);

                    long op = eat(A, N, motes, 0, 0);

                    Console.WriteLine("Case #{0}: {1}", t + 1, op);
                    sw.WriteLine("Case #{0}: {1}", t + 1, op);
                }
            }
        }

        public static long eat ( long A, long N, long[] motes, int nextmote, long op )
        {
            if (nextmote == N) return op; // terminate

            while (nextmote < N)
            {
                if (motes[nextmote] < A) // eat while we can
                {
                    A += motes[nextmote];
                    nextmote++;
                }
                else if (motes[nextmote] < A + A - 1)
                {
                    op++; // insert mote A-1
                    A += A - 1 + motes[nextmote];
                    nextmote++;
                }
                else
                {
                    break;
                }
            }
            if (nextmote == N) return op;

            long op2 = op + N - nextmote;
            if (op > N) return op2;

            long op1 = eat(A + A - 1, N, motes, nextmote, op + 1);

            return Math.Min(op1, op2);
        }
    }
}
