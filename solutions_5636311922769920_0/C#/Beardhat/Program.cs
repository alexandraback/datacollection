using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
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
                string[] kcs = Console.ReadLine().Split(' ');
                int initialCount = int.Parse(kcs[0]);
                int complexity = int.Parse(kcs[1]);
                int unpaidGradStudents = int.Parse(kcs[2]);

                long[] locations;
                if (!CanVerifyGold(initialCount, complexity, unpaidGradStudents, out locations))
                {
                    Console.WriteLine(String.Format(outputFrame, caseIdx, "IMPOSSIBLE"));
                }
                else
                {
                    Console.WriteLine(String.Format(outputFrame, caseIdx, String.Join(" ", locations)));
                }
            }
        }

        static bool CanVerifyGold(int initialCount, int complexity, int unpaidGradStudents, out long[] locations)
        {
            locations = null;
            if (initialCount == 1)
            {
                locations = new long[] { 1 };
                return true;
            }
            else if (complexity == 1 && (initialCount == unpaidGradStudents))
            {
                List<long> locList = new List<long>();
                for (int loc = 1; loc <= initialCount; loc++)
                    locList.Add(loc);

                locations = locList.ToArray();
            }

            long tileSpan = 1;
            for (int compScale = 2; compScale <= complexity; compScale++)
                tileSpan *= initialCount;

            if (initialCount == unpaidGradStudents)
            {
                List<long> locList = new List<long>();
                for (int tileBlock = 0; tileBlock < initialCount; tileBlock++)
                {
                    locList.Add((tileBlock * tileSpan) + 1);
                }

                locations = locList.ToArray();
                return true;
            }
            else 
            { 
                //TODO: Do some real calculations for the large dataset.
                return false;
            }
        }
    }
}
