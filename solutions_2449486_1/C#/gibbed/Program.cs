using System;
using System.IO;

namespace Gibbed.GoogleCodeJam2013.Qualification.ProblemB
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var data = Console.In;
            //var data = new StreamReader("B-sample.in");

            string input;
            string[] parts;

            input = data.ReadLine();
            if (input == null)
            {
                throw new EndOfStreamException();
            }

            var count = int.Parse(input);
            for (int i = 1; i <= count; i++)
            {
                input = data.ReadLine();
                if (input == null)
                {
                    throw new EndOfStreamException();
                }

                parts = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var width = int.Parse(parts[1]);
                var height = int.Parse(parts[0]);

                var desiredYard = new byte[width,height];
                for (byte y = 0; y < height; y++)
                {
                    input = data.ReadLine();
                    if (input == null)
                    {
                        throw new EndOfStreamException();
                    }

                    parts = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    if (parts.Length != width)
                    {
                        throw new FormatException();
                    }

                    for (byte x = 0; x < width; x++)
                    {
                        desiredYard[x, y] = byte.Parse(parts[x]);
                    }
                }

                bool success = true;

                for (byte x = 0; x < width && success == true; x++)
                {
                    for (byte y = 0; y < height && success == true; y++)
                    {
                        if (Check(x, y, desiredYard, width, height) == false)
                        {
                            success = false;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", i, success == true ? "YES" : "NO");
            }
        }

        private static bool Check(byte x, byte y, byte[,] yard, int width, int height)
        {
            var yh = yard[x, y];
            for (int yy = 0; yy < height; yy++)
            {
                yh = Math.Max(yh, yard[x, yy]);
            }

            var xh = yard[x, y];
            for (int xx = 0; xx < width; xx++)
            {
                xh = Math.Max(xh, yard[xx, y]);
            }

            return yard[x, y] >= xh ||
                   yard[x, y] >= yh;
        }
    }
}
