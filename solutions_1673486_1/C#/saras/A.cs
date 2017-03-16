using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ.GCJ2012.Round1A
{
    public class A
    {
        public static void Main()
        {
            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-large.in");
            var outputStream = new StreamWriter(@"C:\Users\asaraswat\Downloads\A-large.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = GetInt();
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                double output = 1.0;

                var ab = GetListOfInt();
                int a = ab[0];
                int b = ab[1];

                var prob = GetListOfDouble();

                for (int i = 0; i < prob.Count; ++i)
                    output *= prob[i];

                output = output * (b - a + 1) + (1 - output) * (2 * b - a + 2);

                for (int i = a - 1, j = 1; i >= 0; --i, ++j)
                {
                    double to = 1.0;
                    for (int ti = 0; ti < i; ++ti)
                        to *= prob[ti];
                    to = to * (b - (a - j) + 1 + j) + (1 - to) * (j + (b - (a - j)) + 1 + b + 1);
                    output = Math.Min(output, to);
                }

                output = Math.Min(output, b + 2);

                Console.WriteLine("Case #{0}: {1:N6}", cs, output);
            }

            inputStream.Close();
            outputStream.Close();
        }

        private static int GetInt()
        {
            string p = Console.ReadLine();
            return Convert.ToInt32(p);
        }

        private static List<int> GetListOfInt(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => int.Parse(t)).ToList();
        }

        private static List<double> GetListOfDouble(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => double.Parse(t)).ToList();
        }
    }
}
