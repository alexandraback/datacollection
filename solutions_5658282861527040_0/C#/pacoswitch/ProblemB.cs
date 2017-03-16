using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class ProblemB
    {
        private cIO console;
        public ProblemB(cIO c) 
        {
            console = c;
        }
        public void solve()
        {
            int[,] pre = new int[1000, 1000];
            for (int j = 0; j < 1000; j++)
            {
                for (int l = j; l < 1000; l++)
                {
                    pre[j, l] = pre[l, j] = (l & j);
                }
            }
            int veces;
            veces = console.ReadInt();
            for (int i = 0; i < veces; i++)
            {
                int a, b, k;
                a = console.ReadInt();
                b = console.ReadInt();
                k = console.ReadInt();
                int contador = 0;
                for (int j = 0; j < a; j++)
                {
                    for (int l = 0; l < b; l++)
                    {
                        if (pre[j,l] < k)
                            contador++;
                    }
                }
                console.WriteLineCodeJamFormat(i + 1, contador.ToString());
            }
        }
    }
}
