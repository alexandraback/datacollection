using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CountingSheep
{
    class Solver
    {
        public string Solve(ulong startingNumber)
        {
            if (startingNumber == 0)
                return "INSOMNIA";

            ulong currentNumber = startingNumber;
            int seenDigits = 0 | GetSeenDigits(currentNumber);
            while (seenDigits != AllDigits)
            {
                currentNumber += startingNumber;
                seenDigits = seenDigits | GetSeenDigits(currentNumber);
            }

            return currentNumber.ToString();
        }

        private int GetSeenDigits(ulong number)
        {
            int result = 0;
            string stringNumber = number.ToString();
            for (int i = 0; i < stringNumber.Length; ++i)
                result = result | (1 << (stringNumber[i] - '0'));
            return result;
        }

        private const int AllDigits = (1 << 10) - 1;
    }
    class Program
    {
        static void Main(string[] args)
        {
            int testCases = int.Parse(Console.ReadLine());
            Solver solver = new Solver();
            for (int testCase = 1; testCase <= testCases; ++testCase)
            {
                Console.WriteLine("Case #{0}: {1}", testCase, solver.Solve(ulong.Parse(Console.ReadLine())));
            }
        }
    }
}
