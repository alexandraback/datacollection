using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Consonants
{
    class Consonants
    {
        static void Main(string[] args)
        {
            //string entree = "Test.txt";
            string entree = "A-small-attempt0.in";
            string sortie = "out.txt";

            StringBuilder sb = new StringBuilder();
            string[] parametres = File.ReadAllLines(entree);


            int nbTest = int.Parse(parametres[0]);

            for (int i = 1; i <= nbTest; i++)
            {
                string chaine = parametres[i];

                string s = chaine.Split(' ')[0];
                int n = int.Parse(chaine.Split(' ')[1]);
                int resultat = CalculerConsonnes(s, n);
                sb.AppendLine("Case #" + i + ": " + resultat);
            }


            File.WriteAllText(sortie, sb.ToString());
        }

        private static int CalculerConsonnes(string s, int n)
        {

            int res = 0;

            List<int> list = new List<int>();
            for (int i = 0; i <= s.Length - n; i++)
            {
                bool suite = true;
                for (int j = 0; j < n && suite; j++)
                {
                    if (IsConsonne(s[i + j]) == false)
                        suite = false;
                }

                if (suite)
                {
                    int longueurAvant = i;
                    if (list.Count() > 0)
                        longueurAvant = i - (list.Last() + 1);
                    int longueurApres = s.Length - i - n;
                    res += longueurAvant + longueurApres + longueurAvant * longueurApres + 1;
                    list.Add(i);
                }
            }

            return res;
        }

        static bool IsConsonne(char c)
        {
            return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
        }
    }
}
