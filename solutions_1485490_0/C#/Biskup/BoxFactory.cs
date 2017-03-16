using System;
using System.Collections;
using System.IO;

namespace Round1C
{
    public class BoxFactory
    {
        [STAThread]
        public static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            long _case = Convert.ToInt64(srd.GetNext());

            for (long tc = 0; tc < _case; tc++)
            {
                long N = Convert.ToInt64(srd.GetNext());
                long[,] A = new long[N, 2];
                long M = Convert.ToInt64(srd.GetNext());
                long[,] B = new long[M, 2];
                for (long i = 0; i < N; i++)
                {
                    A[i, 0] = Convert.ToInt64(srd.GetNext());
                    A[i, 1] = Convert.ToInt64(srd.GetNext());
                }
                for (long i = 0; i < M; i++)
                {
                    B[i, 0] = Convert.ToInt64(srd.GetNext());
                    B[i, 1] = Convert.ToInt64(srd.GetNext());
                }

                long [,,] ar = new long[110,110,3];
                for (long j = 1; j <= M; j++)
                {
                    if (A[0, 1] == B[j - 1, 1])
                    {
                        ar[0, j, 0] = ar[0, j - 1, 0] + Math.Min(B[j - 1, 0], A[0, 0] - ar[0, j - 1, 0]);
                        ar[0, j, 2] = Math.Max(0, B[j - 1, 0] - A[0, 0] + ar[0, j - 1, 0]);
                    }
                    else
                        ar[0, j, 0] = ar[0, j - 1, 0];

                    ar[0, j, 1] = ar[0, j, 0];
                }

                for (long i = 1; i < N; i++)
                {
                    for (long j = 0; j <= M; j++)
                    {
                        long ost = ar[i - 1, j, 2];
                        ar[i, j, 2] = ar[i - 1, j, 2];
                        if (j != 0 && B[j - 1, 1] == A[i, 1])
                        {
                            ar[i, j, 0] = Math.Min(ar[i - 1, j, 2], A[i, 0]);
                            ost = Math.Max(0, ar[i - 1, j, 2] - A[i, 0]);
                        }else ar[i, j, 0] = 0;

                        long nn = ar[i - 1, j, 1];
                        if (nn > ar[i, j, 1] ||
                            (nn == ar[i, j, 1] && ost > ar[i, j, 2]))
                        {
                            ar[i, j, 1] = nn;
                            ar[i, j, 2] = ost;
                        }



                        for (long k = j + 1; k <= M; k++)
                        {
                            ost = 0;
                            if (A[i, 1] == B[k - 1, 1])
                            {
                                ar[i, k, 0] = ar[i, k - 1, 0] + Math.Min(B[k - 1, 0], A[i, 0] - ar[i, k - 1, 0]);
                                ost = Math.Max(0, B[k - 1, 0] - A[i, 0] + ar[i, k - 1, 0]);
                            }
                            else
                                ar[i, k, 0] = ar[i, k - 1, 0];

                            nn = ar[i - 1, j, 1] + ar[i, k, 0];
                            if (nn > ar[i, k, 1] ||
                                (nn == ar[i, k, 1] && ost > ar[i, k, 2]))
                            {
                                ar[i, k, 1] = nn;
                                ar[i, k, 2] = ost;
                            }
                        }
                    }
                }

                long max = 0;
                for (long j = 0; j <= M; j++)
                    if (ar[N - 1, j, 1] > max) max = ar[N - 1, j, 1];

                sw.Write(String.Format("Case #{0:G}: {1:G}\n", tc + 1, max));
            }

            sr.Close();
            sw.Close();
        }
    }

    public class StreamDataRead
    {
        private readonly Queue _queue;
        private readonly Queue _queueLine;

        public StreamDataRead(StreamReader sr)
        {
            _queue = new Queue();
            _queueLine = new Queue();

            while (sr.Peek() >= 0)
            {
                string readLine = sr.ReadLine();
                _queueLine.Enqueue(readLine);
                if (readLine != null)
                {
                    string[] strTmp = readLine.Trim().Split(new[] { ' ' });
                    foreach (string str in strTmp)
                        if (str.Length > 0)
                            _queue.Enqueue(str);
                }
            }
        }

        public object GetNext()
        {
            return _queue.Dequeue();
        }

        public object GetNextLine()
        {
            return _queueLine.Dequeue();
        }
    }
}