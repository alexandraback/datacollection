using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _1bb
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = "B-small-attempt0";
            string inputFile = file + ".in";
            string outputFile = file + ".out";

            using (StreamWriter writer = new StreamWriter(outputFile))
            {


                using (StreamReader reader = new StreamReader(inputFile))
                {
                    int t = int.Parse(reader.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        var r = ReadLine(reader.ReadLine());
                        int a = r[0];
                        int b = r[1];
                        int k = r[2];
                        int res = 0;
                        for (int m = 0; m < a; m++)
                        {
                            for (int n = 0; n < b; n++)
                            {
                                if ((m & n) < k)
                                {
                                    res++;
                                }
                            }
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, res);
                    }
                }
            }
        }

        static int[] ReadLine(string line)
        {
            int[] res = line.Split(' ').Select(o => int.Parse(o)).ToArray();
            return res;
        }


    }
}
