using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lottery
{
    class Program
    {
        static void Main(string[] args)
        {
            string entree = "B-small-attempt0.in";
            string sortie = "out.txt";

            StringBuilder sb = new StringBuilder();
            string[] parametres = File.ReadAllLines(entree);


            int nbTest = int.Parse(parametres[0]);

            for (int i = 1; i <= nbTest; i++)
            {
                string chaine = parametres[i];
                var p = chaine.Split(' ').Select(x => int.Parse(x)).ToArray();

                int resultat = Runs(p[0], p[1], p[2]);
                sb.AppendLine("Case #" + i + ": " + resultat);
            }


            File.WriteAllText(sortie, sb.ToString());
        }

        static int Runs(int A, int B, int K)
        {
            int cpt = 0;

            for (int k = 0; k < K; k++)
            {
                for (int a = 0; a < A; a++)
                {
                    for (int b = 0; b < B; b++)
                    {
                        if ((a & b) == k)
                            cpt++;
                    }
                }
            }

            return cpt;
        }

    }
}
