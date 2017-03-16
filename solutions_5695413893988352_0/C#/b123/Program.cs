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
                var temp = Console.ReadLine().Split(' ');
                string c = temp[0];
                string j = temp[1];
                var Cs = Enumerable.Range(0, 1000).ToArray();
                var Js = Enumerable.Range(0, 1000).ToArray();

                Cs = Cs.Where(num => IsValid(num, c)).ToArray();
                Js = Js.Where(num => IsValid(num, j)).ToArray();

                int minDiff = 1000;
                int cans = 1000;
                int jans = 1000;

                foreach(int cint in Cs)
                {
                    foreach(int jint in Js)
                    {
                        if (Math.Abs(cint - jint) < minDiff)
                        {
                            cans = cint;
                            jans = jint;
                            minDiff = Math.Abs(cint - jint);
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}", t, cans.ToString().PadLeft(c.Length,'0'), jans.ToString().PadLeft(j.Length,'0'));
            }
        }

        //public static void BruteForce(IEnumerable<T> )

        public static bool IsValid(int num, string c)
        {
            if (num.ToString().Length > c.Length)
            {
                return false;
            }

            for (int i = 0; i < c.Length; i++)
            {
                char digit = c[c.Length - i - 1];
                if (digit != '?'
                    && ((int)(num / Math.Pow(10, i)) % 10 != (digit - '0')))
                {
                    return false;
                }
            }

            return true;
        }
    }
}
