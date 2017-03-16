using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Brattleship
    {
        static int Test(int r, int c, int w)
        {
            if (w == 1) return r * c;
            else if (c % w == 0) return c / w * r + w - 1;
            else return c / w * r + w;
        }

        static void Main(string[] args)
        {
            FileStream file = File.Open("test_in.txt", FileMode.Open);
            StreamReader reader = new StreamReader(file);

            FileStream fileOut = File.Open("test_out.txt", FileMode.Create);
            StreamWriter writer = new StreamWriter(fileOut);

            int t = int.Parse(reader.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int[] vars = reader.ReadLine().Split(' ').Select(str => int.Parse(str)).ToArray();
                writer.WriteLine("Case #{0}: {1}", i + 1, Test(vars[0], vars[1], vars[2]));
            }

            writer.Close();

            file.Close();
            fileOut.Close();
        }
    }
}
