using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace _2012Q
{
    class _1B_A
    {

        static void Main(string[] args)
        {

            int T;

            string str;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int N;
                str = Console.ReadLine();
                string[] strs = str.Split(' ');
                N = int.Parse(strs[0]);
                int[] S = new int[N];
                for (int i = 0; i < N; i++)
                {
                    S[i] = int.Parse(strs[i + 1]);
                }

                int Stotal = S.Sum();
                int[] Sorder = S.OrderBy(x => x).ToArray();
                double border = 0;

                int Srest = Stotal;
                for (int i = 0; i < N-1; i++)
                {
                    int sa = (Sorder[i + 1] - Sorder[i]) * (i + 1);
                    if (sa <= Srest)
                    {
                        Srest -= sa;
                    }
                    else
                    {
                        border = Sorder[i] + (double)Srest / (i + 1);
                        break;
                    }
                }
                if (border == 0)
                {
                    border = Sorder[N-1] + (double)Srest / (N);
                }



                Console.Write("Case #" + caseNumber + ": ");

                for (int i = 0; i < N; i++)
                {
                    double answer = (border - S[i]) * 100 / Stotal;
                    if (answer < 0) { answer = 0; }
                    Console.Write(answer);

                    Console.Write(" ");
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }


    }
}
