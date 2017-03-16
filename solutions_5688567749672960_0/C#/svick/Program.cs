using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using GCJ_base;

namespace GCJ_1BA
{
    class Number
    {
        public readonly List<int> Digits;

        public Number(long number)
        {
            var digits = new List<int>();

            while (number > 0)
            {
                digits.Add((int)(number % 10));
                number /= 10;
            }

            digits.Reverse();

            if (digits.Count == 0)
                digits.Add(0);

            Digits = digits;
        }

        public Number(IEnumerable<int> digits)
        {
            Digits = digits.ToList();
        }

        public long ToLong()
        {
            long result = 0;

            foreach (int digit in Digits)
            {
                result *= 10;
                result += digit;
            }

            return result;
        }

        public bool IsSymmetric()
        {
            return Digits.SequenceEqual(Digits.AsEnumerable().Reverse());
        }

        public override string ToString()
        {
            return ToLong().ToString();
        }
    }

    class Gcj1BA : Gcj
    {
        private static void Main()
        {
            new Gcj1BA().Run();
            //while (true)
            //{
            //    long number = long.Parse(Console.ReadLine());
            //    Console.WriteLine("Count({0}) = {1}", number, Count(number));
            //}
        }

        public Gcj1BA()
        {
            Problem = 'A';
            Small = true;
            Attempt = 2;
        }

        protected override string ComputeCase(TextReader reader)
        {
            return Count(ReadLongLine(reader).Single()).ToString();
        }

        private static long Count(Number n)
        {
            var digitsCount = n.Digits.Count;
            if (n.ToLong() <= 20)
                return n.ToLong();

            if (n.Digits[0] == 1 && n.Digits.Skip(1).Take(digitsCount / 2 - 1).All(d => d == 0))
            {
                // 99...01
                var targetDigits = new int[digitsCount - 1];
                targetDigits[digitsCount - 2] = 1;
                for (int i = 0; i < (digitsCount - 1) / 2; i++)
                {
                    targetDigits[i] = 9;
                }
                var target = new Number(targetDigits);

                var difference = n.ToLong() - target.ToLong();

                target.Digits.Reverse();

                int reverse = target.Digits.Count > 1 ? 1 : 0;

                return Count(target) + reverse + difference;
            }

            {
                var headDigits = n.Digits.Take((digitsCount) / 2).ToArray();
                var tailDigits = new int[digitsCount - headDigits.Length];
                tailDigits[tailDigits.Length - 1] = 1;

                var target = new Number(headDigits.Concat(tailDigits));

                if (target.ToLong() > n.ToLong())
                {
                    var newHeadDigits = new Number(new Number(headDigits).ToLong() - 1).Digits;

                    target = new Number(newHeadDigits.Concat(tailDigits));
                }

                var difference = n.ToLong() - target.ToLong();

                target.Digits.Reverse();

                int reverse = target.IsSymmetric() ? 0 : 1;

                return Count(target) + reverse + difference;
            }
        }

        private static long Count(long n)
        {
            return Count(new Number(n));
        }
    }
}