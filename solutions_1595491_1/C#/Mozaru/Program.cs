using System;
using System.Collections.Generic;
using System.Text;

namespace ProbB
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, N, S, P;
            List<int> Vet = new List<int>();
            T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int Qtd = 0;
                string[] str = Console.ReadLine().Split(' ');
                N = int.Parse(str[0]);
                S = int.Parse(str[1]);
                P = int.Parse(str[2]);
                Vet.Clear();
                for (int x = 0; x < N; x++)
                {
                    int Soma = int.Parse(str[3 + x]);
                    if (Math.Ceiling(Soma / 3f) >= P)
                        Qtd++;
                    else
                        Vet.Add(Soma);
                }

                Vet.Sort();
                for (int x = 0; x < Vet.Count && S>0; x++)
                {
                    int Soma = Vet[x];
                    int M1, M2;
                    M2 = (int)Math.Ceiling(Soma / 3f);
                    M1 = (int)Math.Floor(Soma / 3f);
                    if ((M2 - M1 == 0 && M2 + 1 >= P && M1>0) || (M2 - M1 == 1 && M2 + 1 >= P && M1 + M2 + 1 + M1 <= Soma))
                    {
                        Qtd++;
                        S--;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", i + 1, Qtd);
            }
        }
    }
}
