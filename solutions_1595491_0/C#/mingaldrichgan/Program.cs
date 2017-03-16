using System.Diagnostics;
using System.IO;

namespace CodeJam.DancingWithTheGooglers
{
    class Program
    {
        const string inputFile = @"C:\Temp\CodeJam\DancingWithTheGooglers\test.in";
        const string outputFile = @"C:\Temp\CodeJam\DancingWithTheGooglers\test.out";

        // Single-letter identifiers in this program correspond to those in the problem statement.

        class Triplet
        {
            public Triplet(int t)
            {
                CanBeSurprising = (t > 1) && (t < 29);
                int quotient = t / 3;

                switch (t % 3)
                {
                    case 0:
                        BestIfSurprising = quotient + 1; // Surprising triplet is (quotient - 1, quotient, quotient + 1)
                        BestIfNotSurprising = quotient; // Unsurprising triplet is (quotient, quotient, quotient)
                        break;

                    case 1:
                        BestIfSurprising = quotient + 1; // Surprising triplet is (quotient - 1, quotient + 1, quotient + 1)
                        BestIfNotSurprising = quotient + 1; // Unsurprising triplet is (quotient, quotient, quotient + 1)
                        break;

                    case 2:
                        BestIfSurprising = quotient + 2; // Surprising triplet is (quotient, quotient, quotient + 2)
                        BestIfNotSurprising = quotient + 1; // Unsurprising triplet is (quotient, quotient + 1, quotient + 1)
                        break;
                }
            }

            public bool CanBeSurprising { get; private set; }
            public int BestIfSurprising { get; private set; }
            public int BestIfNotSurprising { get; private set; }
        }

        static void Main()
        {
            string[] inputLines = File.ReadAllLines(inputFile);
            int T = int.Parse(inputLines[0]);

            Debug.Assert(inputLines.Length > T);

            string[] outputLines = new string[T];

            for (int x = 1; x <= T; x++)
            {
                string[] inputValues = inputLines[x].Split(' ');
                int N = int.Parse(inputValues[0]);

                Debug.Assert(inputValues.Length > N + 2);

                int S = int.Parse(inputValues[1]);
                int p = int.Parse(inputValues[2]);

                Triplet[] triplets = new Triplet[N];
                int y = 0;

                for (int i = 0; i < N; i++)
                {
                    triplets[i] = new Triplet(int.Parse(inputValues[i + 3]));

                    if (triplets[i].BestIfNotSurprising >= p)
                    {
                        y++;
                    }
                    else if (triplets[i].CanBeSurprising && (triplets[i].BestIfSurprising >= p) && (S > 0))
                    {
                        S--;
                        y++;
                    }
                }

                outputLines[x - 1] = "Case #" + x.ToString() + ": " + y.ToString();
            }

            File.WriteAllLines(outputFile, outputLines);
        }
    }
}
