using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Q_Lawnmower
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            foreach (var t in Enumerable.Range(0, T))
            {
                Console.WriteLine("Case #{0}: {1}", t + 1, ProcessCase());
            }
        }

        static string ProcessCase()
        {
            var sNM = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int n = sNM[0], m=sNM[1];

            return new Lawn(Enumerable.Range(0, n).Select(iN => Console.ReadLine()).ToArray(), n, m).Status;
        }
    }

    class Lawn
    {
        private readonly int n;
        private readonly int m;

        int[][] board;
        int[][] validation;

        private readonly int[] maxN;
        private readonly int[] maxM;



        public Lawn(string[] input, int n, int m)
        {
            this.n = n;
            this.m = m;

            board = new int[n][];
            validation = new int[n][];
            for (int iN = 0; iN < n; iN++)
            {
                board[iN] = input[iN].Split(' ').Select(s => int.Parse(s)).ToArray();
                validation[iN] = Enumerable.Repeat<int>(3, m).ToArray();
            }
            

            maxN = board.Select(x => x.Max()).ToArray();
            maxM = Enumerable.Range(0, m).Select(iM => board.Select(row => row[iM]).Max()).ToArray();

            for(int iN=0;iN<n;iN++)
                for (int iM = 0; iM < m; iM++)
                {
                    validation[iN][iM] =
                        (board[iN][iM] == maxN[iN] ? 1 : 0) |
                        (board[iN][iM] == maxM[iM] ? 2 : 0);

                }
        }

        public string Status
        {
            get
            {
                return validation.All(row => row.All(c => c > 0)) ? "YES" : "NO";
            }
        }

        
    }
}
