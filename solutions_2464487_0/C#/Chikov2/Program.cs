using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TopCoderJamProb1
{
    class Program
    {
        public static StreamWriter writer = new StreamWriter("c:\\test\\output.txt", false);
        public static StreamReader reader = new StreamReader("c:\\test\\input.txt");

        static void Main(string[] args)
        {
            writer.AutoFlush = true;
            int num = Int32.Parse(reader.ReadLine());

            for (int i = 1; i <= num; i++)
            {
                string line = reader.ReadLine();
                string[] inputData = line.Split(' ');

                long radius = long.Parse(inputData[0]);
                long paint = long.Parse(inputData[1]);

                //paint = paint;
                int result = 0;
                bool cont = true;
                do 
                {
                    cont = false;
                    long paintRequired = (radius + 1) * (radius + 1) - (radius) * (radius);
                    //if (radius == 1) paintRequired = Math.PI * radius * radius;
                    if (paintRequired <= paint)
                    {
                        result++;
                        paint -= paintRequired;
                        radius += 2;
                        cont = true;
                    }
                } while(cont && radius > 0);

                writer.WriteLine("Case #" + i + ": " + result);
            }
        }
    }
}
