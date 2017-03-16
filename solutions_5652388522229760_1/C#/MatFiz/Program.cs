using System;
using System.Collections.Generic;
using System.Linq;

namespace CodeJam2016
{
    static class Program
    {
        static void Assert(Func<int, string> solver, int input, string expected)
        {
            var result = solver(input);
            var correct = result == expected;
            Console.WriteLine($"{input} --> {result}");

            if (!correct)
                throw new ApplicationException();
        }

        static void Main(string[] args)
        {
            var console = new TypedConsole();

            var t = console.ReadIntLine();
            for (var i = 0; i < t; i++)
            {
                var n = console.ReadIntLine();
                Console.WriteLine("Case #{0}: {1}", i + 1, A(n));
            }
        }

        class TypedConsole
        {
            public int ReadIntLine()
            {
                return int.Parse(Console.ReadLine());
            }
        }

        static string A(int n)
        {
            var digits = new HashSet<char>("0123456789");

            for (var i = 1; i < 100; i++)
            {
                var name = (n * i).ToString();

                foreach (var c in name)
                    digits.Remove(c);

                if (!digits.Any())
                    return name;
            }

            return "INSOMNIA";
        }
    }
}