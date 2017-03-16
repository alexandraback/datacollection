using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1C_C
{
    class Program
    {
        static long result;

        static int n, m;

        static int[] A, B;
        static long[] a, b;

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"..\..\input.txt");

            StringBuilder output = new StringBuilder();

            int countOfTests = int.Parse(input[0]);
            int k = 1;
            for (int i = 0; i < countOfTests; i++)
            {
                string[] str = input[k].Split(' ');
                
                n = int.Parse(str[0]);
                m = int.Parse(str[1]);

                a = new long[n];
                b = new long[m];
                A = new int[n];
                B = new int[m];

                string[] row = input[k + 1].Split(' ');
                for (int j = 0; j < n; j++)
                {
                    a[j] = long.Parse(row[j * 2]);
                    A[j] = int.Parse(row[j * 2 + 1]);
                }

                row = input[k + 2].Split(' ');
                for (int j = 0; j < m; j++)
                {
                    b[j] = long.Parse(row[j * 2]);
                    B[j] = int.Parse(row[j * 2 + 1]);
                }
                result = long.MinValue;

                Find(0, 0, a[0], b[0], 0);

                output.AppendLine(string.Format("Case #{0}: {1}", i + 1, result));
                k += 3;
            }

            File.WriteAllText(@"..\..\output.txt", output.ToString());
        }

        private static void Find(int i, int j, long boxes, long toys, long res)
        {
            if (i == n || j == m)
            {
                if (res > result)
                    result = res;

                return;
            }
            if (A[i] == B[j])
            {
                long r = Math.Min(boxes, toys);
                if (boxes == r)
                    Find(i + 1, j, i + 1 < n ? a[i + 1] : 0, toys - r, res + r);
                else
                    Find(i, j + 1, boxes - r, j + 1 < m ? b[j + 1] : 0, res + r);
            }
            else
            {
                Find(i + 1, j, i + 1 < n ? a[i + 1] : 0, toys, res );
                Find(i, j + 1, boxes, j + 1 < m ? b[j + 1] : 0, res);
            }
        }
    }
}
