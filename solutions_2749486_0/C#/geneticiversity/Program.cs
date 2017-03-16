using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ_1C2013B_Pogo
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "B-small-attempt0";
            FileStream fs = new FileStream(@"C:\Users\Patrick\Desktop\" + filename + ".in", System.IO.FileMode.Open);

            StreamReader sr = new StreamReader(fs);

            int cases = int.Parse(sr.ReadLine());

            FileStream fw = new FileStream(@"C:\Users\Patrick\Desktop\out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fw);

            for (int n = 0; n < cases; n++)
            {
                string line = sr.ReadLine();

                string[] parts = line.Split(' ');
                int X = int.Parse(parts[0]);
                int Y = int.Parse(parts[1]);

                string Directions = "";

                int steps = 1;
                int currX = 0;
                int currY = 0;

                if (X > 0)
                {
                    steps *= -1;
                }
                while (X != currX)
                {
                    currX += steps;
                    Directions += steps > 0 ? "E" : "W";
                    if (steps < 0)
                        steps--;
                    else
                        steps++;
                    steps *= -1;
                }


                if (Y > 0)
                {
                    steps = steps * Math.Sign(steps) * -1;
                }
                else
                {
                    steps = steps * Math.Sign(steps);
                }

                while (Y != currY)
                {
                    currY += steps;
                    Directions += steps > 0 ? "N" : "S";
                    if (steps < 0)
                        steps--;
                    else
                        steps++;
                    steps *= -1;
                }


                string output = Directions;



                sw.WriteLine(string.Format("Case #{0}: {1}", n + 1, output));
                Console.WriteLine(string.Format("Case #{0}: {1}", n + 1, output));
            }


            sw.Flush();
            sw.Close();
            fw.Close();
            fs.Close();
            Console.ReadKey();
        }
    }
}
