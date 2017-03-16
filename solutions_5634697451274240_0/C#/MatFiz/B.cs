using System;

namespace CodeJam2016
{
    static class Program
    {
        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var i = 0; i < t; i++)
            {
                var pile = Console.ReadLine();
                Console.WriteLine("Case #{0}: {1}", i + 1, B(pile));
            }
        }

        static string B(string pile)
        {
            var rotateCount = 0;
            var previousPancake = pile[0];

            foreach (var pancake in pile)
            {
                if (pancake == previousPancake)
                    continue;

                previousPancake = pancake;
                rotateCount ++;
            }

            if (previousPancake != '+')
                rotateCount++;

            return rotateCount.ToString();
        }
    }
}