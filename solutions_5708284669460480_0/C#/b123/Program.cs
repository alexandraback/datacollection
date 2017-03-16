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
                var temp = ReadLine<int>();
                int K = temp[0];
                int L = temp[1];
                int S = temp[2];

                var keys = Console.ReadLine();
                var target = Console.ReadLine();
                var ind = Enumerable.Range(0, S).Select(x => 0).ToArray();

                bool isDone = false;
                int max = 0;
                int sum = 0;
                int num = 0;

                while (!isDone)
                {
                    var typed = new string(ind.Select(i => keys[i]).ToArray());

                    int count = CountOverlappingInstances(typed, target);
                    max = count > max ? count : max;
                    sum += count;
                    num++;

                    ind[0] = ind[0] + 1;
                    for (int s = 0; s < S; s++)
                    {
                        if (ind[s] == K)
                        {
                            ind[s] = 0;
                            if (s + 1 < S)
                            {
                                ind[s + 1] = ind[s + 1] + 1;
                            }
                            else
                            {
                                isDone = true;
                            }
                        }
                    }
                }

                var average = Convert.ToDouble(sum) / Convert.ToDouble(num);

                Console.WriteLine("Case #{0}: {1:N7}", t, Convert.ToDouble(max) - average);
            }
        }

        public static int CountOverlappingInstances(string a, string pat)
        {
            int count = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if (a.IndexOf(pat, i) == i)
                {
                    count++;
                }
            }

            return count;
        }
    }
}
