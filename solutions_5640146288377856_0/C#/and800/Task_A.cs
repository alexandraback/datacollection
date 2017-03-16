using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task_A
{
    class Solution
    {
        static void Main()
        {
            StreamReader input = new StreamReader("input");
            StreamWriter output = new StreamWriter("output");

            int TestsAmount = int.Parse(input.ReadLine());
            for (int currentTest = 1; currentTest <= TestsAmount; currentTest++)
            {
                string[] data = input.ReadLine().Split(' ');
                int height = int.Parse(data[0]);
                int width = int.Parse(data[1]);
                int shipWidth = int.Parse(data[2]);

                output.WriteLine("Case #{0}: {1}", currentTest, Solve(height, width, shipWidth));
            }

            input.Close();
            output.Close();
        }

        static int Solve(int height, int width, int shipWidth)
        {
            if (shipWidth == 1) return width * height;
            if (shipWidth == width) return width + height - 1;
            int score;
            int firstFound;

            score = SolveLine(width, shipWidth, out firstFound);
            return score + ((firstFound) * (height - 1));

        }

        static int SolveLine(int width, int shipWidth, out int firstFound)
        {
            int score = 0;
            while (width >= shipWidth * 2)
            {
                score++;
                width -= shipWidth;
            }
            firstFound = score + 1;
            if (shipWidth<width)
            {
                score++;
            }
            score += shipWidth;
            return score;
        }
    }
}
