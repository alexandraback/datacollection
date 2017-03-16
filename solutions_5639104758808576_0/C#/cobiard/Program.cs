using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication16
{
    public class Ctecka
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
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            int[] vystup = new int[T];
            int k;
            int s;
            int pridat;
            int postaveni;
            for (int i = 0; i < T; i++)
            {
                postaveni = 0;
                pridat = 0;
                k = Console.Read() - '0';
                Console.Read();
                for (int j = 0; j <= k; j++)
                {
                    if (j > postaveni)
                    {
                        pridat += j - postaveni;
                        postaveni = j;
                    }
                    s = Console.Read() - '0';
                    postaveni += s;
                }
                Console.ReadLine();
                vystup[i] = pridat;
            }
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, vystup[i]);    
            }
        }
    }
}
