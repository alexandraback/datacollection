using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam.RecycledNumbers
{
    class Program
    {
        const string inputFile = @"C:\Temp\CodeJam\RecycledNumbers\C-large.in";
        const string outputFile = @"C:\Temp\CodeJam\RecycledNumbers\C-large.out";

        struct IntPair
        {
            public IntPair(int value1, int value2)
            {
                this.value1 = value1;
                this.value2 = value2;
            }

            public int value1;
            public int value2;
        }

        class IntPairEqualityComparer : EqualityComparer<IntPair>
        {
            public override bool Equals(IntPair pair1, IntPair pair2)
            {
                return (pair1.value1 == pair2.value1) && (pair1.value2 == pair2.value2);
            }

            public override int GetHashCode(IntPair pair)
            {
                return (pair.value1 * pair.value2) % int.MaxValue;
            }
        }


        static void Main()
        {
            string[] inputLines = File.ReadAllLines(inputFile);
            int T = int.Parse(inputLines[0]);

            Debug.Assert(inputLines.Length > T);

            string[] outputLines = new string[T];

            for (int x = 1; x <= T; x++)
            {
                Console.WriteLine("Processing case " + x.ToString() + " of " + T.ToString());

                string[] inputValues = inputLines[x].Split();

                Debug.Assert(inputValues[0].Length == inputValues[1].Length);

                HashSet<IntPair> pairs = new HashSet<IntPair>(new IntPairEqualityComparer());

                if (inputValues[0].Length > 1)
                {
                    int A = int.Parse(inputValues[0]);
                    int B = int.Parse(inputValues[1]);

                    int powerOfTen = (int)Math.Pow(10, inputValues[0].Length - 1);

                    for (int n = A; n < B; n++)
                    {
                        int m = n;

                        for (int i = 1; i < inputValues[0].Length; i++)
                        {
                            m = (m / 10) + ((m % 10) * powerOfTen);
                            if ((n < m) && (m <= B)) { pairs.Add(new IntPair(n, m)); }
                        }
                    }
                }

                outputLines[x - 1] = "Case #" + x.ToString() + ": " + pairs.Count.ToString();
            }

            File.WriteAllLines(outputFile, outputLines);
        }
    }
}
