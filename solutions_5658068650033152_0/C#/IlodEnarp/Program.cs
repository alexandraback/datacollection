using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Globalization;

namespace ConsoleApplication1
{
    class Program
    {

        static int res(int N, int M, int K)
        {
            if (N == 1 || M == 1) return K;
            if (K <= 4) return K;
            if (K > N*M-4)
            {
                if (K == N * M - 3) return N + N + M + M - 7;
                if (K == N * M - 2) return N + N + M + M - 6;
                if (K == N * M - 1) return N + N + M + M - 5;
                if (K == N * M) return N + N + M + M - 4;
            }
            int min = int.MaxValue;
            for (int i = 2; i <= N; ++i)
            {
                for (int j = 2; j <= M; ++j)
                {
                    if ((i * j - 4) >= K)
                    {
                        int perim = i + i + j + j - 8;
                        if (perim < min) min = perim;
                        break;
                    }
                    else if ((i * j - 4 >= K - 1))
                    {
                        int perim = i + i + j + j - 7;
                        if (perim < min) min = perim;
                        break;
                    }
                }
            }
            return min;
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader c = new System.IO.StreamReader("C:\\Users\\Ilod\\Downloads\\C-small-attempt0.in");
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Scanner s = new Scanner(c.ReadLine());
            int NTEST = s.nextInt();
            for (int iTest = 0; iTest < NTEST; ++iTest)
            {
                s = new Scanner(c.ReadLine());
                int N = s.nextInt();
                int M = s.nextInt();
                int K = s.nextInt();
                Debug.Print(string.Format("Case #{0}: {1}", iTest+1, res(N, M, K)));
            }
        }
    }
}
