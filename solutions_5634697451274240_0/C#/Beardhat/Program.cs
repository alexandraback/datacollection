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

            int lastCount = -1;
            bool[] pancakeStack = null;

            int caseCount = int.Parse(Console.ReadLine());
            for (int caseIdx = 1; caseIdx <= caseCount; caseIdx++)
            {
                string originalStackLine = Console.ReadLine();
                
                int currentCount = originalStackLine.Length;
                if (currentCount != lastCount)
                {
                    pancakeStack = new bool[currentCount];
                    lastCount = currentCount;
                }

                int frownyLimit = -1;
                for (int cakeIndex = 0; cakeIndex < currentCount; cakeIndex++)
                {
                    char pancake = originalStackLine[cakeIndex];
                    if (pancake == '+')
                        pancakeStack[cakeIndex] = true;
                    else
                    {
                        frownyLimit = cakeIndex;
                        pancakeStack[cakeIndex] = false;
                    }
                }
                
                int flipCount = MakeHappyStack(pancakeStack, frownyLimit + 1);
                Console.WriteLine(String.Format(outputFrame, caseIdx, flipCount));
            }
        }

        public static void FlipStack(bool[] stack, int flipSize)
        {
            bool[] temp = new bool[flipSize];
         
            for (int flipIdx = flipSize; flipIdx > 0; flipIdx--)
                temp[flipSize - flipIdx] = !stack[flipIdx - 1];

            for (int tempIdx = 0; tempIdx < flipSize; tempIdx++)
                stack[tempIdx] = temp[tempIdx];
        }

        public static int MakeSadStack(bool[] stack, int limit)
        {
            if (limit == 0)
                return 0;

            int flipReduction = 0;
            int flipCount = 0;
            bool monoFlip = true;
            bool hitSad = false;
            for (int monoIndex = 0; monoIndex < limit; monoIndex++)
            {
                if (stack[monoIndex])
                {
                    if (hitSad)
                        monoFlip = false;
                    else
                        flipReduction++;

                    flipCount = monoIndex + 1;
                }
                else
                {
                    hitSad = true;
                }
            }

            if (monoFlip)
            {
                for (int monoIndex = 0; monoIndex < limit; monoIndex++)
                {
                    stack[monoIndex] = false;
                }

                return 1;
            }
            else
            {
                //Interleaved sad/happy pancakes.
                if (flipReduction > 0)
                {
                    FlipStack(stack, flipCount);
                    return 1 + MakeSadStack(stack, flipCount - flipReduction);
                }
                else
                {
                    while (flipCount > 1 && stack[flipCount - 1])
                        flipCount--;

                    int happyFlipCount = MakeHappyStack(stack, flipCount);
                    FlipStack(stack, flipCount);
                    return 1 + happyFlipCount;
                }
            }
        }

        public static int MakeHappyStack(bool[] stack, int limit)
        {
            if (limit == 0)
                return 0;
           
            bool monoFlip = true;
            for (int monoIndex = 0; monoIndex < limit; monoIndex++)
                if (stack[monoIndex])
                {
                    monoFlip = false;
                    break;
                }

            if (monoFlip)
            {
                for (int monoIndex = 0; monoIndex < limit; monoIndex++)
                    stack[monoIndex] = true;
                return 1;
            }

            //Can't do it in a single flip. Crap. You're going to make me do math, aren't you? :(
            int initialMinusCount = 0;
            int finalMinusCount = 0;
            for (int minusIndex = 0; minusIndex < limit; minusIndex++)
            {
                if (stack[minusIndex])
                    break;
                initialMinusCount++;
            }

            for (int minusIndex = limit - 1; minusIndex >= 0; minusIndex--)
            {
                if (stack[minusIndex])
                    break;
                finalMinusCount++;
            }

            if (initialMinusCount >= finalMinusCount)
            {
                FlipStack(stack, limit);
                return 1 + MakeHappyStack(stack, limit - initialMinusCount);
            }
            else
            {
                //We don't actually need to do this flip. We know we have to do one flip.
                int sadFlipCount = MakeSadStack(stack, limit);
                for (int flipIdx = 0; flipIdx < limit - finalMinusCount; flipIdx++)
                    stack[flipIdx] = true;

                return 1 + sadFlipCount;
            }
        }
    }
}
