using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

class Program
{
    const string InputPath = "C:\\CodeJam\\IO\\ProblemA\\A-large.in";

    static void Main()
    {
        using (StreamReader reader = new StreamReader(InputPath))
        {
            using (StreamWriter writer = new StreamWriter(Path.ChangeExtension(InputPath, "out")))
            {
                int T = int.Parse(reader.ReadLine());
                for (int x = 1; x <= T; x++)
                {
                    string[] input = reader.ReadLine().Split(' ');
                    int A = int.Parse(input[0]);
                    int B = int.Parse(input[1]);

                    decimal[] p = reader.ReadLine().Split(' ').Select(s => decimal.Parse(s)).ToArray();

                    decimal[] yBackspaceNTimes = new decimal[A + 1];
                    yBackspaceNTimes[A] = A + B + 1;

                    decimal pFirstAMinusNCorrect = 1;
                    for (int n = (A - 1); n >= 0; n--)
                    {
                        pFirstAMinusNCorrect *= p[A - n - 1];
                        yBackspaceNTimes[n] = (pFirstAMinusNCorrect * (n + n + B - A + 1)) + ((1 - pFirstAMinusNCorrect) * (n + n + B + B - A + 2));
                    }

                    decimal y = yBackspaceNTimes.Min();
                    if (A < B) { y = Math.Min(y, B + 2); }

                    writer.WriteLine("Case #" + x + ": " + y);
                }
            }
        }
    }
}
