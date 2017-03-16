using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Standing_Ovation
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"./input/input.txt";
            Boolean first = false;
            int textCase = 1;
            using (StreamWriter sw = new StreamWriter("out.out"))
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    while (sr.Peek() > 0)
                    {
                        if (!first)
                        {
                            string data = sr.ReadLine();
                            first = true;
                            continue;
                        }
                        else
                        {
                            string data = sr.ReadLine();
                            string[] splitted = data.Split(' ');
                            Console.WriteLine(data);
                            int result = getNumber(splitted[0], splitted[1]);
                            sw.WriteLine("Case #" + textCase++ + ": " + result);
                        }
                    }
                }
                sw.Close();
            }
            Console.Read();
        }

        static int getNumber(string SMax, string friends)
        {
            int total = 0;
            int max = int.Parse(SMax);
            List<int> numberMax = new List<int>();
            for (int i = 0; i < friends.Length; i++)
            {
                numberMax.Add(int.Parse(friends[i].ToString()));
            }
            int somme = 0;
            int retard = 0;
            if (max == 0)
            {
                return 0;
            }
            int cpt = numberMax[0];
            for (int i = 1; i < numberMax.Count; i++)
            {
                int diff = 0;
                if (i > cpt)
                {
                    diff = Math.Abs(i - cpt);
                    total += diff;
                }
                cpt += numberMax[i] + diff;
            }
            return total;
        }
    }
}
