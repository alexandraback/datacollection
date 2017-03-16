namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Text.RegularExpressions;

    class Program
    {
        private static NumberFormatInfo ni;

        static int Main(string[] args)
        {
            ni = (NumberFormatInfo)CultureInfo.CurrentCulture.NumberFormat.Clone();
            ni.NumberGroupSeparator = String.Empty;

            StreamWriter writer = null;
            if (args.Length < 2) { return 1; }

            try
            {
                // Attempt to open output file.
                writer = new StreamWriter(args[1]);
                // Redirect standard output from the console to the output file.
                Console.SetOut(writer);
                // Redirect standard input from the console to the input file.
                Console.SetIn(new StreamReader(args[0]));
            }
            catch (IOException e)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine(e.Message);
                return 1;
            }

            Solve();

            writer.Close();
            // Recover the standard output stream so that a  
            // completion message can be displayed.
            StreamWriter standardOutput = new StreamWriter(Console.OpenStandardOutput());
            standardOutput.AutoFlush = true;
            Console.SetOut(standardOutput);
            Console.WriteLine("Complete");
            return 0;
        }

        public static List<T> ReadLine<T>()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(s => (T)Convert.ChangeType(s, typeof(T))).ToList();
        }

        public static void Solve()
        {
            int T = int.Parse(Console.ReadLine());
            
            for (int t = 1; t <= T; t++)
            {
                var S = Console.ReadLine().ToCharArray();

                var letters = new int[26];
                for (int i = 0; i < 26; i++)
                {
                    letters[i] = S.Count(c => c - 'A' == i);
                }

                var numbers = Enumerable.Repeat(0, 10).ToArray();

                numbers[0] = CheckLetter('Z', "ZERO", letters);
                numbers[2] = CheckLetter('W', "TWO", letters);
                numbers[6] = CheckLetter('X', "SIX", letters);
                numbers[8] = CheckLetter('G', "EIGHT", letters);
                numbers[7] = CheckLetter('S', "SEVEN", letters);
                numbers[5] = CheckLetter('V', "FIVE", letters);
                numbers[4] = CheckLetter('F', "FOUR", letters);
                numbers[1] = CheckLetter('O', "ONE", letters);
                numbers[9] = CheckLetter('N', "NINE", letters);
                numbers[3] = CheckLetter('T', "THREE", letters);

                var ans = "";
                for (int i = 0; i < 10; i++)
                {
                    ans += new string((char)(i + '0'), numbers[i]);
                }

                Console.WriteLine("Case #{0}: {1}", t, ans);
            }
        }

        //public static void BruteForce(IEnumerable<T> )

        public static int CheckLetter(char letter, string spelling, int[] remainingLetters)
        {
            int count = 0;
            while (remainingLetters[letter - 'A'] > 0)
            {
                count++;
                foreach (char ch in spelling)
                {
                    remainingLetters[ch - 'A']--;
                }
            }

            return count;
        }
    }
}
