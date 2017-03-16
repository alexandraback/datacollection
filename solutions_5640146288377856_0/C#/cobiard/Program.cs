using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace A
{
    public class Reader
    {
        public static int ReadInt()
        {
            int x;
            int vstup = 0;
            bool minus = false;
            x = Console.Read();
            while (!(x >= '0' && x <= '9'))
            {
                if (x == '-') minus = true;
                else minus = false;
                x = Console.Read();
            }
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
        static int Maybe(int r, int c, int w)
        {
            if ((w > 1) && ((c % w) != 0)) return 1;
            else return 0;
        }

        static void Main(string[] args)
        {
            //Zakladne premenne
            int T = int.Parse(Console.ReadLine());
            int[] vystup = new int[T];
            int r, c, w;

            //Hlavny cyklus - T testcases
            for (int i = 0; i < T; i++)
            {
                r = Reader.ReadInt();
                c = Reader.ReadInt();
                w = Reader.ReadInt();
                vystup[i] = (c/w) * r + w - 1 + Maybe(r,c,w);
            }



            //Vystup
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, vystup[i]);
            }

            //Zakomentovat
            /*
            Console.ReadLine();
            Console.ReadLine();
            //*/
        }
    }
}
