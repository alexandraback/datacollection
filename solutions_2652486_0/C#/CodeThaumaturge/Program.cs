using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Bullseye
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] output;
            using (StreamReader reader = new StreamReader(args[0]))
            {
                int records = Int32.Parse(reader.ReadLine());

                output = new string[records];

                for (int i = 0; i < records; i++)
                {
                    string[] tokens = reader.ReadLine().Split(' ');

                    long r = Int64.Parse(tokens[0]);
                    long ink = Int64.Parse(tokens[1]);

                    int rings = 0;

                    while (ink > 0)
                    {
                        long requiredInk = (long)(BigInteger.Pow(r + 1, 2) - BigInteger.Pow(r, 2));

                        if (requiredInk <= ink)
                        {
                            rings++;

                            r += 2;
                            ink -= requiredInk;
                        }
                        else
                            ink = 0;
                    }

                    if (rings < 1)
                        rings = 1;

                    output[i] = String.Format("Case #{0}: {1}", i + 1, rings);
                }
            }

            using (StreamWriter writer = new StreamWriter(args[0].Replace(".in", ".out")))
                writer.Write(String.Join(Environment.NewLine, output));
        }
    }
}
