using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication19
{
    public class Reader
    {
        public static int ReadInt()
        {
            int x;
            int vstup = 0;
            bool minus = false;
            //preskoci necislice
            x = Console.Read();
            while (!(x >= '0' && x <= '9'))
            {
                if (x == '-') minus = true;
                else minus = false;
                x = Console.Read();
            }
            //nacita cislice
            while (x >= '0' && x <= '9')
            {
                vstup = vstup * 10 + (x - '0');
                x = Console.Read();
            }
            if (minus) vstup = -vstup;
            return vstup;
        }
    }

    class Program
    {

        static void Main(string[] args)
        {
            int T, x, r, c;
            bool dasa;

            T = Reader.ReadInt();
            bool[] vysl = new bool[T];

            for (int i = 0; i < T; i++)
            {
                dasa = true;
                x = Reader.ReadInt();
                r = Reader.ReadInt();
                c = Reader.ReadInt();
                if (r < x && c < x)
                {
                    vysl[i] = false;
                    continue;
                }
                if ((r * c) % x != 0)
                {
                    dasa = false;
                    vysl[i] = dasa;
                    continue;
                }
                if ((r == 1) || (c == 1))
	            {
	                if (x > 2) dasa = false;
                    vysl[i] = dasa;
   	                continue;
              	}
                if (r <= 4 && c <= 4)
                {
                    switch (r * c)
                    {
                        case 4:
                            if (x >= 4) dasa = false;
                            break;
                        case 6:
                            if (x >= 6) dasa = false;
                            break;
                        case 8:
                            if (x >= 4) dasa = false;
                            break;
                        case 9:
                            if (x >= 9) dasa = false;
                            break;
                        case 12:
                            if (x >= 6) dasa = false;
                            break;
                        case 16:
                            if (x >= 8) dasa = false;
                            break;
                        default:
                            break;
                    }
                    vysl[i] = dasa;
                    continue;
                }
                if(r <= 3 || c <= 3)
                {
                    if (x >= 2 * Math.Min(r, c))
                    {
                        vysl[i] = false;
                        continue;
                    }
                }
                if (x >= 7) dasa = false;

                vysl[i] = dasa;
            }
            for (int i = 0; i < T; i++)
            {
                if (vysl[i]) Console.WriteLine("Case #{0}: GABRIEL", i + 1);
                else Console.WriteLine("Case #{0}: RICHARD", i + 1);
            }
        }
    }
}
