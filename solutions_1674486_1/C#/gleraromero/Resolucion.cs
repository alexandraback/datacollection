using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2012._3B
{
    class Resolucion
    {
        public static void Resolver(string path)
        {
            StreamWriter escritor = new StreamWriter(string.Concat(path, "/", "current.out"));
            StreamReader lector = new StreamReader(string.Concat(path, "/", "current.in"));
            int T = int.Parse(lector.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                int N = int.Parse(lector.ReadLine());
                Nodo[] nodos = new Nodo[N+1];

                List<int> areParents = new List<int>();

                for (int n = 0; n < N; n++)
                {
                    string[] data = lector.ReadLine().Split(' ');
                    int Mi = int.Parse(data[0]);
                    int[] inherited = new int[Mi];
                    for (int m = 1; m < Mi + 1; m++)
                    {
                        inherited[m - 1] = int.Parse(data[m]);
                        if (!areParents.Contains(inherited[m - 1]))
                            areParents.Add(inherited[m - 1]);
                    }

                    nodos[n + 1] = new Nodo(n + 1, inherited);
                }

                List<int> toCheck = new List<int>();
                for (int n = 1; n < N+1; n++)
                    if (!areParents.Contains(n))
                        toCheck.Add(n);

                List<int> alche = new List<int>();
                bool isDiamond = false;
                while (toCheck.Count > 0 && !isDiamond)
                {
                    int current = toCheck[0];
                    foreach (int n in nodos[current].inherited)
                    {
                        if (!nodos[n].children.Contains(current))
                            nodos[n].children.Add(current);

                        foreach (int child in nodos[current].children)
                            if (!nodos[n].children.Contains(child))
                                nodos[n].children.Add(child);
                        
                        if (!toCheck.Contains(n) && !alche.Contains(n))
                            toCheck.Add(n);
                    }
                    alche.Add(toCheck[0]);
                    toCheck.RemoveAt(0);
                }

                for (int n = 1; n < N+1 && !isDiamond; n++)
                {
                    foreach (int inh in nodos[n].inherited)
                    {
                        if (nodos[inh].childrenDuplicated.Intersect(nodos[n].children).Count() > 0 || nodos[inh].childrenDuplicated.Contains(n))
                        {
                            isDiamond = true;
                            break;
                        }
                        nodos[inh].childrenDuplicated.AddRange(nodos[n].children);
                        nodos[inh].childrenDuplicated.Add(n);
                    }
                }
                escritor.WriteLine(string.Format("Case #{0}: {1}", i+1, isDiamond ? "Yes" : "No"));
            }
            lector.Close();
            escritor.Close();
        }

        class Nodo
        {
            public int N;
            public int[] inherited;
            public List<int> children = new List<int>();
            public List<int> childrenDuplicated = new List<int>();

            public Nodo(int n, int[] inherited)
            {
                N = n;
                this.inherited = inherited;
            }
        }
    }
}
