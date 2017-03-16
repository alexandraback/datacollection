using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    class Program
    {
        static void Main(string[] args)
        {
            string outputFrame = "Case #{0}: {1}";

            int caseCount = int.Parse(Console.ReadLine());
            for (int caseIdx = 1; caseIdx <= caseCount; caseIdx++)
            {
                int countSeed = int.Parse(Console.ReadLine());

                if (countSeed == 0)
                {
                    Console.WriteLine(String.Format(outputFrame, caseIdx, "INSOMNIA"));
                    continue;
                }

                int snorePoint = AttemptSleep(countSeed);
                Console.WriteLine(String.Format(outputFrame, caseIdx, snorePoint));
            }
        }

        public static int AttemptSleep(int countSeed)
        {
            int tracker = 0;
            int countTarget = countSeed;
            while (true)
            {
                CheckDigits(countTarget, ref tracker);
                if (tracker == 0x03FF)
                    return countTarget;

                countTarget += countSeed;
            }
        }

        public static void CheckDigits(int checkee, ref int tracker)
        {
            tracker |= (1 << (checkee % 10));

            if (tracker == 0x03FF)
                return;

            int divider = 10;
            while (divider <= checkee)
            {
                tracker |= (1 << ((checkee / divider) % 10));

                if (tracker == 0x03FF)
                    return;

                divider *= 10;
            }
        }
    }
}
