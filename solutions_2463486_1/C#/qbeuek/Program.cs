using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace c_FairAndSquare
{
    class Program
    {
        static void Precalculate()
        {
            Enumerable.Range(1, 50).AsParallel().ForAll(digitCount =>
            {
                var startedAt = DateTime.UtcNow;

                using (var outputStream = new StreamWriter(@"..\..\precalc" + digitCount + ".txt", false))
                {
                    var mutableDigitsCount = digitCount / 2 + digitCount % 2;
                    var mutableDigits = new int[mutableDigitsCount];
                    var currentValue = new BigInteger();
                    var multipliers = new BigInteger[mutableDigitsCount];
                    BigInteger multiplier = 1L;
                    for (var i = 0; i < mutableDigitsCount; i++)
                    {
                        multipliers[i] += multiplier;
                        multiplier *= 10;
                    }
                    for (var i = mutableDigitsCount - 1 - digitCount % 2; i >= 0; i--)
                    {
                        multipliers[i] += multiplier;
                        multiplier *= 10;
                    }

                    var squareDigits = new int[1000];
                    while (true)
                    {
                        if (mutableDigits[0] > 0)
                        {
                            var square = currentValue * currentValue;
                            var squareDigitCount = 0;
                            while (square > 0)
                            {
                                squareDigits[squareDigitCount] = (int)(square % 10);
                                squareDigitCount++;
                                square /= 10;
                            }

                            var start = 0;
                            var stop = squareDigitCount - 1;
                            while (stop >= start)
                            {
                                if (squareDigits[start] != squareDigits[stop])
                                    break;

                                start++;
                                stop--;
                            }

                            if (stop <= start)
                            {
                                outputStream.WriteLine("{0} {1}", currentValue, currentValue * currentValue);
                            }
                        }

                        var currentDigit = 0;
                        bool overflow = true;
                        while (overflow && currentDigit < mutableDigitsCount)
                        {
                            mutableDigits[currentDigit]++;
                            currentValue += multipliers[currentDigit];
                            var maxDigit = 1;
                            if (currentDigit == 0 || currentDigit == mutableDigitsCount - 1)
                                maxDigit = 2;
                            if (mutableDigitsCount == 1)
                                maxDigit = 3;
                            overflow = mutableDigits[currentDigit] == maxDigit + 1;
                            if (overflow)
                            {
                                currentValue -= multipliers[currentDigit] * mutableDigits[currentDigit];
                                mutableDigits[currentDigit] = 0;
                            }
                            currentDigit++;
                        }

                        if (overflow)
                            break;
                    }
                }

                Console.WriteLine("{0}:{1}", digitCount, (DateTime.UtcNow - startedAt).TotalMinutes);
            });
        }

        static void Main(string[] args)
        {
            //Precalculate();

            var fairAndSquareNumbers = new List<BigInteger>();

            using (var precalcStream = new StreamReader("..\\..\\precalc.txt"))
            {
                while (true)
                {
                    var line = precalcStream.ReadLine();
                    if (line == null || line.Length == 0)
                        break;

                    fairAndSquareNumbers.Add(BigInteger.Parse(line.Split(' ')[1]));
                }
            }

            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var inputs = inputStream.ReadLine().Split(' ').Select(s => BigInteger.Parse(s)).ToArray();
                    var minSquare = inputs[0];
                    var maxSquare = inputs[1];

                    var result = fairAndSquareNumbers.Where(f => f >= minSquare && f <= maxSquare).Count();

                    outputStream.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }
    }
}
