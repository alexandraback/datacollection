using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Patrickdev.Gcj.Qualification2016.A_CountingSheep
{
    public class Solution : ISolution
    {
        public string GetInputFile() { return @"D:\Cloud\programming\c#\gcj\gcj\Qualification2016\A_CountingSheep\A-small-attempt0.in"; }

        public string DoIteration(Scanner input, Output output)
        {
            int number = input.NextInt();

            if (number == 0)
                return "INSOMNIA";

            List<char> seen = new List<char>();
            for (int current = number; ; current += number)
            {
                seen.AddRange(current.ToString().ToCharArray());

                if (HasSeenAll(seen))
                    return current.ToString();
            }

        }

        private static bool HasSeenAll(List<char> seen)
        {
            for (char i = '0'; i <= '9'; i++)
            {
                if (!seen.Contains(i))
                    return false;
            }
            return true;
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
                string result = solution.DoIteration(input, output);
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, result));
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
