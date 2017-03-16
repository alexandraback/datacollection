using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {

            StreamReader reader = new StreamReader(args[0]);
            int nbCase = int.Parse(reader.ReadLine());
            for (int i = 0; i < nbCase; i++)
            {
                string line = reader.ReadLine();
                int res = 0;
                var splitted = line.Split(' ');
                int a = int.Parse(splitted[0]);
                int b = int.Parse(splitted[1]);

                for (int j = a; j < b; j++)
                {
                    var v1 = j.ToString();
                    int count = v1.Count();
                    HashSet<int> memoire = new HashSet<int>();
                    for (int m = 1; m < count; m++)
                    {
                        string left = v1.Substring(count - m, m);
                        string right = v1.Substring(0, count - m);

                        int v2 = int.Parse(left + right);
                        if (j < v2 && v2 <= b)
                        {
                            memoire.Add(v2);
                        }
                    }
                    res += memoire.Count;
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, res);

            }
            //Console.ReadLine();
        }
    }
}
