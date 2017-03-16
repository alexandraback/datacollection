using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pogo
{
    class Pogo
    {
        static void Main(string[] args)
        {
            //string entree = "Test.txt";
            string entree = "B-small-attempt0.in";
            string sortie = "out.txt";

            StringBuilder sb = new StringBuilder();
            string[] parametres = File.ReadAllLines(entree);


            int nbTest = int.Parse(parametres[0]);

            for (int i = 1; i <= nbTest; i++)
            {
                string chaine = parametres[i];
                long X = long.Parse(chaine.Split(' ')[0]);
                long Y = long.Parse(chaine.Split(' ')[1]);
                string resultat = CalculerDirection(0, 0, X, Y, 1);
                sb.AppendLine("Case #" + i + ": " + resultat);
            }


            File.WriteAllText(sortie, sb.ToString());
        }

        private static string CalculerDirection(long posX, long posY, long X, long Y, int noJump)
        {
            if (posX == X && posY == Y)
                return string.Empty;

            if (posX != X)
            {
                if (X >= posX + noJump)
                    return "E" + CalculerDirection(posX + noJump, posY, X, Y, noJump + 1);
                else
                    return "W" + CalculerDirection(posX - noJump, posY, X, Y, noJump + 1);
            }
            else
            {

                if (Y >= posY + noJump)
                    return "N" + CalculerDirection(posX, posY + noJump, X, Y, noJump + 1);
                else
                    return "S" + CalculerDirection(posX, posY - noJump, X, Y, noJump + 1);
            }
        }
    }
}

