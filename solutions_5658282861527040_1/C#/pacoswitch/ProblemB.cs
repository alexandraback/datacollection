using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace CodeJam
{
    class ProblemB
    {
        private cIO console;
        private const int max = 100;
        public ProblemB(cIO c) 
        {
            console = c;
        }
        public void solve()
        {
            /*
            int[,] pre = new int[max, max];
            
            for (int j = 0; j < max; j++)
            {
                for (int l = j; l < max; l++)
                {
                    pre[j, l] = pre[l, j] = (l & j);
                    console.WriteLine("[" + j.ToString() + "," + l.ToString() + "]=" + (l & j));
                }
            }*/
            int veces;
            veces = console.ReadInt();
            for (int i = 0; i < veces; i++)
            {
                Int64 a, b, k;
                a = console.ReadInt64();
                b = console.ReadInt64();
                k = console.ReadInt64();
                Int64 posibles = a * b;
                Int64 maximo = Math.Max(a, b);
                Int64 minimo = Math.Min(a, b);
                for (int j = (int)k; j < maximo; j++)
                {
                    for (int l = (int)k; l < minimo; l++)
                    {
                        if ((j & l) >= k) posibles--;
                    }
                }
                console.WriteLineCodeJamFormat(i + 1, posibles.ToString());
            }
        }
    }
}
