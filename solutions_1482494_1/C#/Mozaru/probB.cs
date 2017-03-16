using System;
using System.Collections.Generic;
using System.Text;

namespace ProbB
{
    class probB
    {
        static int stars = 0;
        class tupla
        {
            public tupla(int a1, int a2) { l1 = a1; l2 = a2; fez = false; }
            public int l1, l2;
            public bool fez;
            public int vlbase
            {
                get { return fez ? l2 : l1; }
            }
            static int comp(tupla a, tupla b)
            {
                int pos = 0;
                if (a.l2 <= stars)
                    pos--;
                if (b.l2 <= stars)
                    pos++;
                if (pos == 0)
                    pos = a.vlbase - b.vlbase;
                if (pos == 0)
                    pos = -a.l2 + b.l2;
                return pos;
            }

            static void Main(string[] args)
            {
                int N = int.Parse(Console.ReadLine());
                List<tupla> lista = new List<tupla>();
                for (int i = 0; i < N; i++)
                {
                    lista.Clear();
                    int Lv = int.Parse(Console.ReadLine());
                    for (int x = 0; x < Lv; x++)
                    {
                        string[] Linha = Console.ReadLine().Split(' ');
                        lista.Add(new tupla(int.Parse(Linha[0]), int.Parse(Linha[1])));
                    }
                    stars = 0;
                    lista.Sort(new Comparison<tupla>(comp));
                    int it;
                    it = 0;
                    while (lista.Count > 0 && lista[0].vlbase <= stars)
                    {
                        it++;
                        if (lista[0].fez)
                        {
                            stars += 1;
                            lista.RemoveAt(0);
                        }
                        else
                        {

                            if (lista[0].l2 <= stars)
                            {
                                stars += 2;
                                lista.RemoveAt(0);
                            } 
                            else if (lista[0].l1 <= stars)
                            {                                stars += 1;
                                                            lista[0].fez = true;
                            }
     
                        }
                        lista.Sort(new Comparison<tupla>(comp));
                    }
                    Console.WriteLine("Case #{0}: {1}", i + 1, ((lista.Count == 0) ? ""+it : "Too Bad"));
                    Console.WriteLine();
                }
            }
        }
    }
}
    