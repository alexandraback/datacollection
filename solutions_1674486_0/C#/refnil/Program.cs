using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace round1ca
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] fin = File.ReadAllLines("./A-small-attempt0.in");
            
            //string[] fin = File.ReadAllLines("aa.txt");
            
            //string[] fin = new string[] { "1", "1 9", "10 40", "100 500", "1111 2222" , "10000 99999", "100000 999999", "1000000 1999999"};

            int incpt = 0;

            int nb = Convert.ToInt32(fin[incpt++]);

            string[] fout = new String[nb];

            for (int i = 0; i < nb; i++)
            {
                int nbclass = Convert.ToInt32(fin[incpt++]);

                bool[,] herite = new bool[nbclass,nbclass];
                bool found = false;

                for (int j = 0; j < nbclass; j++)
                {
                    string[] split = fin[incpt++].Split(' ');

                    int nbheritage = Convert.ToInt32(split[0]);

                    for (int k = 0; k < nbheritage; k++)
                    {
                        int heriteur = Convert.ToInt32(split[k+1]);

                        herite[j, heriteur - 1] = true;
                    }

                }

                for (int j = 0; j < nbclass; j++)
                {

                    if (checklink(j, ref herite))
                    {
                        found = true;
                        break;
                    }
                }

                fout[i] = "Case #" + (i+1) + ": " + (found ? "Yes" : "No");

                Console.WriteLine(fout[i]);
                //Console.ReadLine();
                
            }

            File.WriteAllLines("output.txt", fout);
            Console.Read();
        }

        public static bool checklink(int heriteur,ref bool[,] heritage)
        {
            HashSet<Int32> allAbove = new HashSet<Int32>();

            bool result = checknode(heriteur,ref heritage, ref allAbove);
                
            return result;
        }

        public static bool checknode(int heriteur, ref bool[,] heritage,ref HashSet<Int32> set)
        {
            int length = heritage.GetLength(0);
            bool result = false;

            for (int i = 0; i < length; i++)
            {
                if (heritage[heriteur, i])
                {
                    if (set.Add(i))
                    {
                        if (checknode(i, ref heritage, ref set))
                        {
                            result = true;
                            break;
                        }
                    }
                    else
                    {
                        result = true;
                        break;
                    }
                }
            }

            return result;
        }

    }
}
