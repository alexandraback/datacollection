using System;
using System.IO;
using System.Text;

namespace Qualification
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("Problems\\B-small-attempt0.in");

            var sb = new StringBuilder();

            int testCaseCount = Int32.Parse(input[0]);
            for (int i = 1; i <= testCaseCount; i++)
            {
                string[] target = input[i].Split(' ');
                string output = "Case #" + i + ": " + ProblemB.Solve(Int32.Parse(target[0]), Int32.Parse(target[1]));
                sb.AppendLine(output);
                Console.WriteLine(output);
            }

            File.WriteAllText("ouput.txt", sb.ToString().Trim());
            Console.WriteLine(DateTime.Now);
            Console.ReadLine();
        }
    }

    public class ProblemB
    {
        public static string Solve(int targetX, int targetY)
        {
            for (int steps = 5; steps < 500; steps++)
            {
                string result = Solve(targetX, targetY, steps);

                if (!result.EndsWith("X")) return Reverse(result);
            }

            return null;
        }

        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        private static double CalculateDistance(int posX, int posY)
        {
            return Math.Sqrt(posX*posX + posY*posY);
        }

        private static string Solve(int posX, int posY, int stepSize)
        {
            if (posX == 0 && posY == 0 && stepSize == 0) return "";
            if (stepSize == 0) return "X";
            
            double distW = CalculateDistance(posX - stepSize, posY);
            double distN = CalculateDistance(posX, posY + stepSize);
            double distE = CalculateDistance(posX + stepSize, posY);
            double distS = CalculateDistance(posX, posY - stepSize);

            double distMin = Math.Min(distW, Math.Min(distN, Math.Min(distE, distS)));
            
            if (distW == distMin)
            {
                return "E" + Solve(posX - stepSize, posY, stepSize - 1);
            }
            if (distN == distMin)
            {
                return "S" + Solve(posX, posY + stepSize, stepSize - 1);
            }
            if (distE == distMin)
            {
                return "W" + Solve(posX + stepSize, posY, stepSize - 1);
            }

            return "N" + Solve(posX, posY - stepSize, stepSize - 1);
        }
    }
}