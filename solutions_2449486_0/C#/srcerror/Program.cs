using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\1\B-small-attempt1.in";
            string output = @"d:\Work\Current\CodeJam\1\B-small-attempt1.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task2(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        private static string Task2(StreamReader sin)
        {
            string result = "";
            var s = sin.ReadLine();
            var mn = s.Split(' ');
            int N = int.Parse(mn[0]);
            int M = int.Parse(mn[1]);
            int [,] inp = new int[N,M];

            for (int i = 0; i < N; i++)
            {
                var l = sin.ReadLine().Split(' ');
                for (int j = 0; j < M; j++)
                {
                    inp[i, j] = int.Parse(l[j]);
                }
            }

            // check every cell
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    // check [i,j]
                    bool safe = T2CheckVertical(inp, i, j);
                    if (safe) continue;
                    safe = T2CheckHorizontal(inp, i, j);
                    if (!safe) return "NO";
                }
            }

            result = "YES";
            return result;
        }

        private static bool T2CheckVertical(int[,] inp, int i, int j)
        {
            var val = inp[i, j];
            int N = inp.GetUpperBound(0);
            for (int k = 0; k <= N; k++)
            {
                if (val < inp[k, j]) return false;
            }
            return true;
        }

        private static bool T2CheckHorizontal(int[,] inp, int i, int j)
        {
            var val = inp[i, j];
            int M = inp.GetUpperBound(1);
            for (int k = 0; k <= M; k++)
            {
                if (val < inp[i, k]) return false;
            }
            return true;
        }




        private static string Task1(StreamReader sin)
        {
            var r1 = "X won";
            var r2 = "O won";
            var r3 = "Draw";
            var r4 = "Game has not completed";

            string inp;
            var sb = new StringBuilder();
            for (int i = 0; i < 4; i++)
            {
                sb.Append(sin.ReadLine().Substring(0, 4));
            }
            inp = sb.ToString();
            //Console.WriteLine(inp);
            sin.ReadLine();

            // process
            // find winner
            bool hasEmpty = false;
            var combos = new[]
                {
                    new[] { 0, 1, 2, 3 },
                    new[] { 4, 5, 6, 7 },
                    new[] { 8, 9, 10, 11 },
                    new[] { 12, 13, 14, 15 },
                    new[] { 0, 4, 8, 12 },
                    new[] { 1, 5, 9, 13 },
                    new[] { 2, 6, 10, 14 },
                    new[] { 3, 7, 11, 15 },
                    new[] { 0, 5, 10, 15 },
                    new[] { 3, 6, 9, 12 },
                };
            foreach (var combo in combos)
            {
                char? r = CheckCombo(inp, combo);
                if (r.HasValue)
                {
                    if (r == 'O')
                        return r2;
                    if (r == 'X')
                        return r1;
                }
            }
            // no winner
            if (inp.IndexOf('.') >= 0)
                return r4;
            else return r3;
        }
        private static char? CheckCombo(string inp, int[] p)
        {
            int i = 0;
            char x = inp[p[i++]];
            if (x == 'T')
            {
                x = inp[p[i++]];
            }

            while (true)
            {
                if (i > 3) return x;
                char cc = inp[p[i]];
                if (cc == '.') return null;
                if (cc != x && cc != 'T') return null;
                i++;
            }
        }
    }
}
