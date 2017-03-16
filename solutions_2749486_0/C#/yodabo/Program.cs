using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem2
{
    class Program
    {
        static void GoToXY(int X, int Y, int N)
        {
            if (X > 0)
            {
                for (int i = 0; i < X; ++i)
                {
                    Console.Write("WE");
                }
            }
            else if (X < 0)
            {
                for (int i = 0; i < -X; ++i)
                {
                    Console.Write("EW");
                }
            }
            if (Y > 0)
            {
                for (int i = 0; i < Y; ++i)
                {
                    Console.Write("SN");
                }
            }
            if (Y < 0)
            {
                for (int i = 0; i < -Y; ++i)
                {
                    Console.Write("NS");
                }
            }
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] line = Console.ReadLine().Trim(' ').Split(' ');
                int X = int.Parse(line[0]);
                int Y = int.Parse(line[1]);
                Console.Write("Case #{0}: ", 1 + i);
                GoToXY(X, Y, 1);
                Console.WriteLine();
            }
        }
    }
}
