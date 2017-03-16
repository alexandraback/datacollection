using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace C
{
    class Program
    {
        const int I = 2;
        const int J = 3;
        const int K = 4;

        static int[][] multiplication =
        {
            new int[] {1,  I,  J,  K},
            new int[] {I, -1,  K, -J},
            new int[] {J, -K, -1,  I},
            new int[] {K,  J, -I, -1},
        };

        static int Mul(int a, int b)
        {
            int sgn = 1;
            if(a < 0)
            {
                a = -a;
                sgn *= -1;
            }

            if (b < 0)
            {
                b = -b;
                sgn *= -1;
            }

            return multiplication[a - 1][b - 1] * sgn;
        }

        static bool Solve(long X, string s)
        {
            int block = 1;
            foreach(var c in s)
            {
                int v = (int)(c - 'i' + 2);
                block = Mul(block, v);
            }

            int copies = 1;
            int tmp = block;
            while(tmp != 1)
            {
                tmp = Mul(tmp, block);
                copies++;
            }

            long x = 30 * copies + (X % copies);
            x = Math.Min(x, X);

            StringBuilder sb = new StringBuilder();
            for (long y = 0; y < x; y++)
                sb.Append(s);

            s = sb.ToString();


            int n = s.Length;
            int[] left = new int[n + 1];
            left[0] = 1;

            for (int i = 1; i <= n; i++)
            {
                int curr = (int)(s[i - 1] - 'i' + 2);
                left[i] = Mul(left[i - 1], curr);
            }

            if (left[n] != -1)
                return false;

            int p = Array.IndexOf(left, I);
            if (p < 0)
                return false;

            int q = Array.IndexOf(left, K, p);
            if (q < 0)
                return false;

            return true;
        }

        static void Main(string[] args)
        {
            //Console.SetIn(File.OpenText("input.txt"));

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                long L = long.Parse(line[0]);
                long X = long.Parse(line[1]);
                string s = Console.ReadLine();

                Console.WriteLine("Case #{0}: {1}", t, Solve(X, s) ? "YES" : "NO");
            }
        }
    }
}
