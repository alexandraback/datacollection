namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;

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
                var fraction = Console.ReadLine().Split(new char[] { '/' });
                var P = long.Parse(fraction[0]);
                var Q = long.Parse(fraction[1]);
                bool possible = false;
                bool done = false;
                int y = 0;
                int ans = 0;

                while (!done && y <= 40)
                {
                    if (P < 0 || P > Q)
                    {
                        done = true;
                    }
                    else if (P == 0)
                    {
                        done = true;
                    }
                    else if (P == Q)
                    {
                        possible = true;
                        if (ans == 0)
                        {
                            ans = y;
                        }
                        done = true;
                    }
                    else if (P * 2 < Q)
                    {
                        P *= 2;
                    }
                    else if (P * 2 > Q)
                    {
                        if (ans == 0)
                        {
                            ans = y + 1;
                        }
                        P += P - Q;
                    }
                    else if (P * 2 == Q)
                    {
                        if (ans == 0)
                        {
                            ans = y + 1;
                        }
                        P = Q;
                    }
                    y++;
                }

                if (!possible)
                {
                    Console.WriteLine("Case #{0}: impossible", t);
                }
                else
                {
                    Console.WriteLine("Case #{0}: {1}", t, ans);
                }
            }
        }
    }
}
