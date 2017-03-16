using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1B
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static string[] ReadStringArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ');
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                string result = String.Empty;
                
                int[] data = ReadIntArray(reader);
                int X = data[0];
                int Y = data[1];

                int currentX = 0, currentY = 0;
                while (X != currentX || Y != currentY)
                {
                    if (X - currentX > 0)
                    {
                        result = result + "WE";
                        currentX++;
                    }
                    else if (X - currentX < 0)
                    {
                        result = result + "EW";
                        currentX--;
                    }
                    else if (Y - currentY > 0)
                    {
                        result = result + "SN";
                        currentY++;
                    }
                    else if (Y - currentY < 0)
                    {
                        result = result + "NS";
                        currentY--;
                    }
                }
                writer.WriteLine("Case #" + i + ": " + result.ToString());
            }

            reader.Dispose();
            writer.Dispose();
        }
    }

}
