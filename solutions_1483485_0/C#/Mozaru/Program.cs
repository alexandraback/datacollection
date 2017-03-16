using System;
using System.Collections.Generic;
using System.Text;

namespace ProbA
{
    class Program
    {
        
        static void Main(string[] args)
        {
            string Entrada = 
                "ejp mysljylc kd kxveddknmc re jsicpdrysi"+
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+
                "de kr kd eoya kw aej tysr re ujdr lkgc jvqz";
            string Saida =
                "our language is impossible to understand" +
                "there are twenty six factorial possibilities" +
                "so it is okay if you want to just give upzq";

            Dictionary<char, char> Map = new Dictionary<char, char>();
            for (int i = 0; i < Entrada.Length; i++)
                if (!Map.ContainsKey(Entrada[i]))
                    Map.Add(Entrada[i], Saida[i]);

            int N = int.Parse(Console.ReadLine());
            for (int i = 0; i < N; i++)
            {
                Console.Write("Case #{0}: ",i+1);
                string Linha = Console.ReadLine();
                foreach (char c in Linha)
                    Console.Write(Map[c]);
                Console.WriteLine();
            }
        }
    }
}
