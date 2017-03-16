using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pancakes
{
    class Program
    {
        public static string[] ReadInput(string fileName)
        {
            return File.ReadAllLines(fileName).Skip(1).ToArray();
        }

        public static void WriteOutput(string fileName, IEnumerable<int> numbers)
        {
            int i = 1;
            var lines = numbers.Select(n => $"Case #{i++}: {n}");

            File.WriteAllLines(fileName, lines);
        }

        public static int Solve(string input)
        {
            int i;
            for (i = 0; i < input.Length; i++)
            {
                if (input[input.Length - i - 1] != '+')
                    break;
            }
            if (i == input.Length)
                return 0;
            if (i > 0)
                return Solve(input.Substring(0, input.Length - i));

            for (i = 0; i < input.Length; i++)
            {
                if (input[i] == '+')
                    break;
            }
            if (i > 0)
                return Solve(Flip(input, input.Length)) + 1;

            for (i = 0; i < input.Length; i++)
            {
                if (input[i] == '-')
                    break;
            }
            return Solve(Flip(input, i)) + 1;
        }

        public static string Flip(string input, int n)
        {
            StringBuilder s = new StringBuilder(input);

            for (int i = 0; i < n; i++)
            {
                s[i] = input[n - i - 1] == '-' ? '+' : '-';
            }

            return s.ToString();
        }

        static void Main(string[] args)
        {
            var input = ReadInput(args[0]);
            WriteOutput(args[1], input.Select(Solve));
        }
    }
}
