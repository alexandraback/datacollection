using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Q2
{
    class Q2
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader(@"c:\cjData\q2sample.txt");
            StreamWriter output = new StreamWriter(@"c:\cjData\q2output.txt");

            int totalCount = int.Parse(input.ReadLine());

            for (int i = 0; i < totalCount; i++)
            {
                string line = input.ReadLine();
                string[] splits = line.Split(new char[]{' '});

                int N = int.Parse(splits[0]);
                int S = int.Parse(splits[1]);
                int P = int.Parse(splits[2]);

                int[] T = new int[N];
                for (int j = 0; j < N; j++)
                {
                    T[j] = int.Parse(splits[j + 3]);
                }

                int solution = Solve(N, S, P, T);
                output.WriteLine("Case #" + (i+1) + ": " + solution);
                Debug.WriteLine("Case #" + (i + 1) + ": " + solution);
            }

            output.Close();
            input.Close();
        }

        static int Solve(int N, int S, int P, int[] T)
        {
            int count = 0;
            for (int i = 0; i < N; i++)
            {
                if (T[i] / 3 + ((T[i] % 3 == 0) ? 0 : 1) >= P)
                    count++;
                else if (S > 0 && T[i] >=2 )
                {
                    if ((T[i] - 2) / 3 + 2 >= P)
                    {
                        count++;
                        S--;
                    }
                }
            }

            return count;
        }

    }
}
