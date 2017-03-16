using System;
using System.Collections.Generic;
using System.Text;

namespace ProbC
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, A,B;
            List<int> Vet = new List<int>();
            List<string> List = new List<string>();
            T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int Qtd = 0;
                string[] str = Console.ReadLine().Split(' ');
                A = int.Parse(str[0]);
                B = int.Parse(str[1]);
                for (int n = A; n < B; n++)
                {
                    List.Clear();
                    int maxpot = 10;
                    while (n/maxpot>0)
                        maxpot *= 10;
                    maxpot = maxpot / 10;
                    for (int pot = 10; maxpot > 1; pot = pot * 10, maxpot = maxpot / 10)
                    {
                        int m = n % pot * maxpot + n / pot;
                        string s = string.Format("{0}-{1}", n, m);
                        if (m > n && m <= B && !List.Contains(s))
                        {
                            List.Add(s);
                            Qtd++;
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, Qtd);
            }
        }
    }
}
