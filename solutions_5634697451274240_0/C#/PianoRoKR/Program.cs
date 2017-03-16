using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            int lCases = int.Parse(Console.ReadLine());
            for (int i = 0; i < lCases; i++)
            {
                string lPancakes = Console.ReadLine();
                Console.Write("Case #{0}: ", i + 1);
                char lLastC = lPancakes[0];
                long lFlip = 0;
                foreach (char c in lPancakes)
                {
                    if (lLastC != c)
                        lFlip++;
                    lLastC = c;
                }
                if (lPancakes[lPancakes.Length - 1] == '-')
                    lFlip++;
                Console.WriteLine(lFlip);
            }
        }
    }
}
