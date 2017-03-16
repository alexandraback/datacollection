using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"C:\Users\Viktor\Downloads\GCJ\B-small-attempt1.in");

            StringBuilder result = GetValue(lines);

            var length = result.Length - 1;
            File.WriteAllText(@"E:\res.res", result.Remove(length, 1).ToString());
        }

        private static StringBuilder GetValue(string[] lines)
        {
            var result = new StringBuilder();
            int cases = int.Parse(lines[0]);


            for (int i = 1; i <= cases; i++)
            {
                var res = new StringBuilder();
                var line = lines[i].Split(' ');
                int x = int.Parse(line[0]);
                int y = int.Parse(line[1]);

                int currentX = 0, currentY = 0;
                int step = 1;

                bool direction = x == 2;

                while (x != currentX)
                {
                    if (!direction)
                    {
                        currentX += step;
                        step++;
                        res.Append('E');
                        direction = !direction;
                    }
                    else
                    {
                        currentX -= step;
                        step++;
                        res.Append('W');
                        direction = !direction;
                    }
                }

                direction = y > 0;
                while (y != currentY)
                {
                    if (!direction)
                    {
                        currentY += step;
                        step++;
                        res.Append('N');
                        direction = !direction;
                    }
                    else
                    {
                        currentY -= step;
                        step++;
                        res.Append('S');
                        direction = !direction;
                    }
                }

                result.AppendFormat("Case #{0}: {1}\n", i, res);
            }

            return result;
        }
    }
}
