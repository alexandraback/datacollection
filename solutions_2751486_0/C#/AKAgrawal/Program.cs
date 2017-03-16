using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] x = File.ReadAllLines("input.in");
            File.Delete("output.txt");
            long count = 1;
            for (int i = 0; i < Convert.ToInt16(x[0]); i++)
            {
                string[] names = x[count].Split(' ');

                double z = Solve(names[0], Convert.ToInt64(names[1]));
                count = count + 1;
                string outputString = String.Format("Case #{0}: {1}" + Environment.NewLine, i + 1, z);
                File.AppendAllText("output.txt", outputString);
            }
        }

        private static long Solve(string name, long num)
        {
            long count = 0;
            long counter =0;
            char[] val = name.ToCharArray();
            for (long x = 0; x < name.Length; x++ )
            {
                for (long y = (num-1)+x; y < name.Length; y++)
                {
                    counter = 0;
                    for (long z = x; z <= y; z++)
                    {
                        if (val[z] != 'a' && val[z] != 'e' && val[z] != 'i' && val[z] != 'o' && val[z] != 'u')
                        {
                            counter++;
                            if (counter >= num)
                            {
                                count++;
                                counter = 0;
                                break;
                            }
                        }
                        else
                            counter = 0;
                    }
                }
            }

            return count;
        }
    }
}
