using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolveT9
{
    class Program
    {

        static Dictionary<char, KeyValuePair<char, int>> sources = new Dictionary<char, KeyValuePair<char, int>>();

        static void Main(string[] args)
        {
            int counter = 1;
            string line;
            String[] files = Directory.GetFiles(@"C:\googleJam", "*.in");
            System.IO.StreamReader file = new System.IO.StreamReader(files[0]);
            StreamWriter resultFile = new StreamWriter(files[0].Replace(".in", ".out"));
            file.ReadLine();
            while ((line = file.ReadLine()) != null)
            {
                int nbCoups = 0;
                System.Console.WriteLine(line);
                String[] c = line.Split(' ');
                int R = Convert.ToInt32(c[0]);
                int taille = Convert.ToInt32(c[1]);
                int bateau = Convert.ToInt32(c[2]);

                nbCoups += (int) Math.Floor((double) taille / bateau);
                nbCoups = nbCoups * (R - 1);

                if ((taille % bateau) != 0) nbCoups++;
                nbCoups += (int)Math.Floor((double)taille / bateau);
                nbCoups += bateau - 1;

                resultFile.WriteLine("Case #" + counter + ": " + nbCoups);
                counter++;
            }
            file.Close();
            resultFile.Flush();
            resultFile.Close();
            System.Console.WriteLine("There were {0} lines.", counter);
            System.Console.ReadLine();
        }


    }
}
