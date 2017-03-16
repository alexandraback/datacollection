using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {

        static string readLine()
        { return Console.ReadLine().TrimStart().TrimEnd(); }
        static long readLong()
        { return long.Parse(readLine()); }
        static string[] readStrings()
        { return readLine().Split(' '); }
        static long[] readLongs()
        { string[] inp = readLine().Split(' '); 
          long[] ret = new long[inp.Length];
          for (int i = 0; i < inp.Length; i++) ret[i] = long.Parse(inp[i]);
          return ret;
        }

        static int solve(int A, int i, int[] M)
        {
            if(i>=M.Length)
                return 0;

            int X = M[i];
            if (A > X) 
                return solve(A+X,i+1,M);
            if (A + A - 1 > X) 
                return 1+solve(A+A-1+X,i+1,M); // add one

            int left = M.Length-i;
            int needed = 0;
            int A1 = A;
            while (A1 <= X && needed < left) { A1 += A1 - 1; needed++; }
            if (A1 > X) return Math.Min(1 + solve(A, i + 1, M), needed + solve(A1+X, i + 1, M)); //skip or add more
            else return 1 + solve(A, i + 1, M); //skip
        }

        static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader(@"c:\jam\a\A-small-attempt1.in")); //@"c:\jam\a\A-small-attempt0.in"  //@"c:\jam\a\A-large.in"
            Console.SetOut(new System.IO.StreamWriter(@"c:\jam\a\out.txt"));
            int T = int.Parse(Console.ReadLine());
            for (int caseNo = 1; caseNo <= T; caseNo++)
            {
                string[] inp = readStrings();
                int A = int.Parse(inp[0]);
                int N = int.Parse(inp[1]);

                inp = readStrings();
                int[] M = new int[N];
                for (int i = 0; i < N; i++)
                    M[i] = int.Parse(inp[i]);
                Array.Sort(M);
                    
                //int moves = 0;
                //for (int i = 0; i < N; i++)
                //{
                //    int left = N-i;
                //    int X = M[i];
                //    if (A > X) A += X;
                //    else if (A + A - 1 > X) // add A-1
                //    {
                //        A += A - 1 + X;
                //        moves++;
                //    }
                //    else // skip
                //    {
                //        int needed = 0;
                //        int A1 = A;
                //        while (A1 < X && needed<left) { A1 += A1 - 1; needed++; }

                //        moves++;
                //    }
                //}
                int moves = solve(A, 0, M);

                Console.WriteLine("Case #{0}: {1}", caseNo, moves);
            }
            Console.Out.Flush();
            //Console.ReadKey();
        }
    }
}
