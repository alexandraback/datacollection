using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ1
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] tabla = new char[26];

            cargarTabla(tabla, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            cargarTabla(tabla, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            cargarTabla(tabla, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            cargarTabla(tabla, "qz", "zq");

            int c = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= c; i++)
            {
                Console.Write("Case #" + i + ": ");
                traducir(tabla, Console.ReadLine());
            }
        }

        private static void cargarTabla(char[] tabla, string cad1, string cad2)
        {
            for (int i = 0; i < cad1.Length; i++)
            {
                if (cad1[i] != ' ')
                {
                    int pos = cad1[i] - 'a';
                    tabla[pos] = cad2[i];
                }
            }
        }

        private static void traducir(char[] tabla, string cad)
        {
            for (int i = 0; i < cad.Length; i++)
            {
                if (cad[i] != ' ')
                {
                    int pos = cad[i] - 'a';
                    Console.Write(tabla[pos]);
                }
                else
                {
                    Console.Write(' ');
                }
            }
            Console.WriteLine();
        }

    }
}
