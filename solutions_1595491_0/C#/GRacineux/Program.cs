using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DancingWithTheGoogler
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
                int n = int.Parse(splitted[0]);
                int s = int.Parse(splitted[1]);
                int p = int.Parse(splitted[2]);
                for (int j = 0; j < n; j++)
                {
                    int t = int.Parse(splitted[j + 3]);
                    if (p == 1)
                    {
                        if (t > 0)
                        {
                            res++;
                        }
                    }
                    else if (p == 0)
                    {
                        res++;
                    }
                    else
                    {
                        if (t >= 3 * p - 2)
                        {
                            res++;
                        }
                        else if (s > 0 && t >= 3 * p - 4)
                        {
                            s--;
                            res++;
                        }
                    }

                }
                Console.WriteLine("Case #{0}: {1}", i + 1, res);

            }
        }

    }
}
