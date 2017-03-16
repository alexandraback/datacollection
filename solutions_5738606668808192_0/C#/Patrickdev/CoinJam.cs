using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Patrickdev.Gcj.Qualification2016.C_CoinJam
{
    public class Solution : ISolution
    {
        public string GetInputFile() { return @"D:\Cloud\programming\c#\gcj\gcj\Qualification2016\C_CoinJam\C-small-attempt0.in"; }

        public string DoIteration(Scanner input, Output output)
        {
            int jamCoinCharLength = input.NextInt();
            int desiredNumberOfJamCoins = input.NextInt();

            long loopStart = Convert.ToInt64("1" + new string('0', jamCoinCharLength - 2) + "1", 2);
            long loopEnd = Convert.ToInt64(new string('1', jamCoinCharLength), 2);
            
            for (long i = loopStart, found = 0; i <= loopEnd; i += 2)
            {
                string binary = Convert.ToString(i, 2);
                string divisorList = BuildDivisorList(binary);

                if (divisorList != null)
                {
                    output.WriteLine(binary + divisorList);

                    if (++found >= desiredNumberOfJamCoins)
                        break;
                }
            }
            return "";
        }

        public static string BuildDivisorList(string binary)
        {
            StringBuilder testOutput = new StringBuilder();

            for (int fromBase = 2; fromBase <= 10; fromBase++)
            {
                string divisor = GetDivisor(ConvertFromBase(binary, fromBase));
                if (divisor == null)
                {
                    return null;
                }

                testOutput.AppendFormat(" {0}", divisor);
            }

            return testOutput.ToString();
        }

        public static BigInteger ConvertFromBase(string number, int fromBase)
        {
            BigInteger result = BigInteger.Zero;
            BigInteger weight = BigInteger.One;
            int digitIndex = 0;

            for (int i = number.Length - 1; i >= 0; i--, digitIndex++)
            {
                if (number[i] == '1')
                {
                    result = BigInteger.Add(result, weight);
                }

                weight = BigInteger.Multiply(weight, new BigInteger(fromBase));
            }
            return result;
        }

        public static string GetDivisor(BigInteger number)
        {
            if (number.CompareTo(new BigInteger(2)) < 0)
                return null;

            if (number.IsEven)
                return number.CompareTo(new BigInteger(2)) == 0 ? null : "2";

            long root = (long) Math.Exp(BigInteger.Log(number) / 2);
            for (long i = 3; i <= root; i += 2)
            {
                if (number % i == 0)
                    return i.ToString();
            }

            return null;
        }
    }

    #region Boilerplate code identical for every GCJ entry
    public class Program
    {
        public static void Main(string[] args)
        {
            Solution solution = new Solution();
            Scanner input = new Scanner(solution.GetInputFile());
            Output output = new Output(solution.GetInputFile().Replace(".in", ".out"));

            int tests = input.NextInt();
            for (int i = 0; i < tests; i++)
            {
                output.WriteLine(string.Format("Case #{0}:", i + 1));
                string result = solution.DoIteration(input, output);
            }
        }
    }
    public interface ISolution
    {
        string GetInputFile();
        string DoIteration(Scanner input, Output output);
    }
    public class Scanner
    {
        public readonly string[] lines;

        public int cursorChar,
            cursorLine;

        public Scanner(string file)
        {
            lines = File.ReadAllLines(file);
        }

        public string NextLine()
        {
            string result = string.Empty;

            if (lines[cursorLine].Length >= cursorChar)
            {
                result = lines[cursorLine].Substring(cursorChar).TrimEnd('\r', '\n');
            }

            cursorLine += 1;
            cursorChar = 0;

            return result;
        }

        public string NextWord()
        {
            string result;
            int locationOfSpace = lines[cursorLine].IndexOf(' ', cursorChar);

            if (locationOfSpace == -1)
            {
                result = lines[cursorLine].Substring(cursorChar);
                cursorLine += 1;
                cursorChar = 0;
            }
            else
            {
                int wordLength = locationOfSpace - cursorChar;
                result = lines[cursorLine].Substring(cursorChar, wordLength);
                cursorChar += wordLength + 1;
            }

            return result;
        }

        public int NextInt()
        {
            return int.Parse(NextWord());
        }

        public T Next<T>()
        {
            return (T)Convert.ChangeType(NextWord(), typeof(T));
        }
    }
    public class Output
    {
        private readonly string file;

        public Output(string file)
        {
            this.file = file;
            if (File.Exists(file))
            {
                File.Delete(file);
            }
        }

        public void WriteLine(object line)
        {
            using (StreamWriter writer = new StreamWriter(file, true))
            {
                writer.WriteLine(line.ToString());
            }
            Debug.WriteLine(line.ToString(), "[Out]");
        }
    }
    #endregion
}
