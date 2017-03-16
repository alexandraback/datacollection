using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ2
{
    class Program
    {
        static void Main(string[] args)
        {

            int c = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= c; i++)
            {
                int desde, hasta;
                string linea = Console.ReadLine();
                string[] valores = linea.Split();
                desde = Convert.ToInt32(valores[0]);
                hasta = Convert.ToInt32(valores[1]);
                Console.WriteLine("Case #" + i + ": " + contar(desde, hasta));
            }
        }
        
        private static int contar(int desde, int hasta)
        {
            int c = 0;
            HashSet<int> contados = new HashSet<int>();
            HashSet<int> combinaciones = new HashSet<int>();
            int l = desde.ToString().Length;
            int offset = (int)Math.Pow(10,l-1);
            for (int i = desde; i <= hasta; i++)
            {
                //string istring = i.ToString();
                //if (istring.Contains('0')) continue;

                int v = i;
                combinaciones.Clear();
                int min = 0;
                for (int j = 0; j < l; j++)
                {
                   
                    if (v >= desde && v <= hasta && !combinaciones.Contains(v))
                    {
                        combinaciones.Add(v);
                        if (min == 0 || v < min) min = v;
                    }
                    v = v / 10 + (v % 10) * offset;
                }
                if (!contados.Contains(min))
                {
                    int cantidad = combinaciones.Count;
                    c += (cantidad * (cantidad - 1) / 2);
                    contados.Add(min);
                }
            }
            return c;
        }
    }
}
