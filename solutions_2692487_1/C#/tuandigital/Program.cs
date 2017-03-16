using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace OneB_FirstProblem
{
    class Program
    {

        static Tuple<long, long> countOperation(long start, long destination) {
            long count = 0;
            while (start <= destination) {
                if (start == 1) {
                    count = 100;
                    break;
                }
                start += start - 1;
                count++;
            }
            return Tuple.Create<long, long>(count, start);
        }

        static void Main(string[] args)
        {
            int test = int.Parse(Console.ReadLine());
            for (int tt = 1; tt <= test; tt++) {
                string[] firstLine = Console.ReadLine().Split();
                long A = long.Parse(firstLine[0]);
                int N = int.Parse(firstLine[1]);
                long[] motes = new long[N+1];
                string[] secondLine = Console.ReadLine().Split();
                for (int i = 1; i <= N; i++)
                    motes[i] = long.Parse(secondLine[i - 1]);
                Array.Sort(motes,1, N);
                motes[0] = A;
                long[,] L = new long[N+1,2];
                long[,] sum = new long[N + 1, 2];
                sum[0, 0] = A;
                sum[0, 1] = A;
                for (int i = 1; i <= N; i++) {
                    if (L[i - 1, 0] < L[i - 1, 1] || (L[i - 1, 0] == L[i - 1, 1] && sum[i-1, 0] > sum[i-1, 1]))
                    {
                        sum[i, 0] = sum[i - 1, 0];
                        L[i, 0] = L[i - 1, 0] + 1;
                    }
                    else {
                        sum[i, 0] = sum[i - 1, 1];
                        L[i, 0] = L[i - 1, 1] + 1;
                    }
                    Tuple<long, long> operationNum0 = countOperation(sum[i - 1, 0], motes[i]);
                    Tuple<long, long> operationNum1 = countOperation(sum[i - 1, 1], motes[i]);
                    if (L[i - 1, 0] + operationNum0.Item1 < L[i - 1, 1] + operationNum1.Item1 || (L[i - 1, 0] + operationNum0.Item1 == L[i - 1, 1] + operationNum1.Item1 && operationNum0.Item2 > operationNum1.Item2))
                    {
                        L[i, 1] = L[i - 1, 0] + operationNum0.Item1;
                        sum[i, 1] = operationNum0.Item2 + motes[i];
                    }
                    else {
                        L[i, 1] = L[i - 1, 1] + operationNum1.Item1;
                        sum[i, 1] = operationNum1.Item2 + motes[i];
                    }
                }
                long res = Math.Min(L[N, 0], L[N, 1]);
                    Console.WriteLine("Case #{0}: {1}", tt, res);
            }
        }
    }
}
