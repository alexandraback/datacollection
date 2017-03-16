using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class B
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("c:\\codejam\\2013\\qual\\B-small-attempt1.in");
        StreamWriter sw = new StreamWriter("c:\\codejam\\2013\\qual\\B-small-attempt1.out");


        int T = Int32.Parse(sr.ReadLine());
        foreach (int caseN in Enumerable.Range(1, T))
        {
            var tmp = sr.ReadLine().Split(' ');
            int N = int.Parse(tmp[0]);
            int M = int.Parse(tmp[1]);
            
            int[,] board = new int[N,M];
            for (int n = 0; n < N; n++)
            {
                var tmp2 = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (int m = 0; m < M; m++)
                {
                    board[n,m] = tmp2[m];
                }
            }

            bool possible = true;
            //for every point
            for (int n = 0; n < N; n++)
            {
                for (int m = 0; m < M; m++)
                {
                    bool rh = false;
                    for (int p = m + 1; p < M; p++)
                    {
                        if (board[n, p] > board[n, m])
                            rh = true;
                    }
                    bool lh = false;
                    for (int p = 0; p < m; p++)
                    {
                        if (board[n, p] > board[n, m])
                            lh = true;
                    }
                    bool uh = false;
                    for (int p = n + 1; p < N; p++)
                    {
                        if (board[p, m] > board[n, m])
                            uh = true;
                    }
                    bool dh = false;
                    for (int p = 0; p < n; p++)
                    {
                        if (board[p, m] > board[n, m])
                            dh = true;
                    }

                    if ((rh || lh) && (uh || dh))
                    {
                        possible = false;
                        goto done;
                    }
                }
            }

        done:
            
            sw.WriteLine("Case #{0}: {1}", caseN, possible ? "YES" : "NO");

            sw.Flush();
        }

    }
}
