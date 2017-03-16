using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CountingSheep
{
    class Program
    {
        public static int[] ReadInput(string fileName)
        {
            return File.ReadAllLines(fileName).Skip(1).Select(l => Int32.Parse(l)).ToArray();
        }

        public static void WriteOutput(string fileName, IEnumerable<int> numbers)
        {
            int i = 1;
            var lines = numbers.Select(n => $"Case #{i++}: {(n == -1 ? "INSOMNIA" : n.ToString())}");

            File.WriteAllLines(fileName, lines);
        }

        static void Main(string[] args)
        {
            var input = ReadInput("D:\\A-large.in");

            var testCaseResults = input.Select(GetLastNumber);

            WriteOutput("D:\\output.txt", testCaseResults);
        }

        static int GetLastNumber(int startingNumber)
        {
            HashSet<char> namedCharacters = new HashSet<char>();

            if (startingNumber == 0)
                return -1;

            int currentNumber = 0;
            while (true)
            {
                if (namedCharacters.Count == 10)
                    return currentNumber;

                currentNumber += startingNumber;

                foreach (var c in currentNumber.ToString())
                    namedCharacters.Add(c);
            }
        }
    }
}
