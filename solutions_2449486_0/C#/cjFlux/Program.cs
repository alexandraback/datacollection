using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace QualificationB
{
    class Program
    {
        static int TakeStep(byte[,] field, int n, int m)
        {
            byte min = byte.MaxValue;
            for (int y = 0; y < n; y++)
                for (int x = 0; x < m; x++)
                    min = Math.Min(min, field[x, y]);
            if (min == byte.MaxValue) return 0;

            int cnt = 0;
            #region horizontal
            for (int y = 0; y < n; y++)
            {
                bool flag = true;
                for (int x = 0; x < m; x++)
                {
                    if (field[x, y] == byte.MaxValue) continue;
                    if (field[x, y] != min) { flag = false; break; }
                }
                if (flag)
                {
                    for (int x = 0; x < m; x++)
                    {
                        if (field[x, y] == byte.MaxValue) continue;
                        field[x, y] = byte.MaxValue;
                        cnt++;     
                    }
                }
            }
            #endregion
            #region vertical
            for (int x = 0; x < m; x++)
            {
                bool flag = true;
                for (int y = 0; y < n; y++)
                {
                    if (field[x, y] == byte.MaxValue) continue;
                    if (field[x, y] != min) { flag = false; break; }
                }
                if (flag)
                {
                    for (int y = 0; y < n; y++)
                    {
                        if (field[x, y] == byte.MaxValue) continue;
                        field[x, y] = byte.MaxValue;
                        cnt++;
                    }
                }
            }
            #endregion
            return cnt;
        }

        static bool Solve(byte[,] field, int n, int m)
        {
            int cnt = 0;
            while (true)
            {
                int p = TakeStep(field, n, m);
                if (p > 0) cnt += p; else break;
            }
            return cnt == n * m;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"..\..\input.txt");
            StreamWriter sw = new StreamWriter(@"..\..\output.txt");

            int cnt = int.Parse(sr.ReadLine());
            for (int t = 1; t <=cnt ; t++)
            {
                var dim = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries), int.Parse);
                int n = dim[0], m = dim[1];
                byte[,] field = new byte[m, n];
                for (int y = 0; y < n; y++)
                {
                    var line = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries), byte.Parse);
                    for (int x = 0; x < m; x++) field[x, y] = line[x];
                }
                sw.WriteLine("Case #{0}: {1}", t, Solve(field, n, m) ? "YES" : "NO");
            }

            sr.Close();
            sw.Close();
        }
    }
}
