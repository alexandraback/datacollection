using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemC\\C-small.in"))
            {
                using (var writer = new StreamWriter("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemC\\C-small.out"))
                {
                    int testCases = int.Parse(reader.ReadLine());
                    for (int tc = 0; tc < testCases; tc++)
                    {
                        writer.WriteLine("Case #{0}:", tc + 1);
                        Console.WriteLine("Case #{0}:", tc + 1);
                        Solve(tc, reader, writer);
                    }
                }
            }
            Console.ReadKey();
        }

        static string ToBase6(long n)
        {
            var sb = new StringBuilder();
            while(n != 0)
            {
                sb.Append(n % 6);
                n /= 6;
            }
            return string.Join("", sb.ToString().Reverse());
        }

        static List<Tuple<string, long[]>> solutions = new List<Tuple<string, long[]>>();
        static HashSet<long> base6Factors = new HashSet<long>();
        static int _j = 0;

        static void Solve(int caseNumber, StreamReader input, StreamWriter output)
        {
            var line = input.ReadLine().Split(' ');
            var N = int.Parse(line[0]);
            var J = int.Parse(line[1]);
            _j = J;
            var arr = new int[N];
            Recurse(arr, 0, N);
            if (solutions.Count >= J)
            {
                for (int i = 0; i < J; i++)
                {
                    output.Write(solutions[i].Item1);
                    Console.Write(solutions[i].Item1);
                    for (int j = 0; j < 9; j++)
                    {
                        output.Write(" " + solutions[i].Item2[j]);
                        Console.Write(" " + solutions[i].Item2[j]);
                    }
                    output.WriteLine();
                    Console.WriteLine();
                }
            }
            solutions.Clear();
        }

        static long GetFactor(long n)
        {
            long max = (long)Math.Ceiling(Math.Sqrt(n) + 1);
            if(max >= n)
            {
                max = n - 1;
            }
            for (long i = 2; i <= max; i++)
            {
                if (n % i == 0)
                    return i;
            }
            return -1;
        }
        
        static int[] target = new[] { 3, 2, 3, 2, 7, 2, 3, 2, 3 };

        static void CheckSolution(int[] digits, int length)
        {
            var factors = new long[9];
            for(int b = 2; b <= 10; b++)
            {
                long num = 0;
                long factor = 1;
                for(int i = length - 1; i >= 0; i--)
                {
                    num += digits[i] * factor;
                    factor *= b;
                }
                int f = target[b - 2];
                if (num % f != 0)
                    return;
                //long f = GetFactor(num);
                //if (f == -1)
                //{
                //    return;
                //}
                factors[b - 2] = f;
            }
            base6Factors.Add(factors[4]);
            solutions.Add(new Tuple<string, long[]>(string.Join("", digits), factors));

            //int a = solutions.Count - 1;
            //Console.Write(solutions[a].Item1);
            //for (int j = 0; j < 9; j++)
            //{
            //    Console.Write(" " + solutions[a].Item2[j]);
            //}
            //Console.WriteLine();
        }

        static void Recurse(int[] digits, int i, int length)
        {
            if (solutions.Count >= _j)
                return;
            if (i == 0)
            {
                digits[i] = 1;
                Recurse(digits, i + 1, length);
            }
            else if(i == length - 1)
            {
                digits[i] = 1;
                CheckSolution(digits, length);
            }
            else
            {
                digits[i] = 1;
                Recurse(digits, i + 1, length);
                digits[i] = 0;
                Recurse(digits, i + 1, length);
            }
        }
    }
}
