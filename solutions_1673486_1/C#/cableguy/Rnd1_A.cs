using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Rnd1_A
{
    class Rnd1_A
    {

        static string ProcessCase(TextReader rd)
        {
            var tokens = rd.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int a = tokens[0];
            int b = tokens[1];

            double[] probs = rd.ReadLine().Split(' ').Select(double.Parse).ToArray();

            double result = ExpectedKeystrokes(a, b, probs);

            return result.ToString("0.000000");
        }

        private static double GiveUpChars(int b)
        {
            return 2 + b;   // 2 enters required
        }

        private static double BackThenCompleteChars(int a, int b, double[] probs, int numBack)
        {
            double probOkSoFar = 1;
            for (int i = 0; i < (a - numBack); i++)
                probOkSoFar *= probs[i];

            int numIfFirstOk = (b - a + 2*numBack + 1); // 2 * numBack -> backsp + retype
            double result = probOkSoFar * numIfFirstOk;
            result += (1.0 - probOkSoFar) * (numIfFirstOk + b + 1); // retype whole pwdm then enter

            return result;
        }

        private static double ExpectedKeystrokes(int a, int b, double[] probs)
        {
            var result = GiveUpChars(b);
            for (int numBack = 0; numBack < a; numBack++)
            {
                result = Math.Min(result, BackThenCompleteChars(a, b, probs, numBack));
            }

            return result;
        }

        static void Main(string[] args)
        {
            //const string InFile = @"C:\Users\Owen\Downloads\A-Eg.txt";
            //const string InFile = @"C:\Users\Owen\Downloads\A-small-attempt0.in";
            const string InFile = @"C:\Users\Owen\Downloads\A-large.in";

            using (var rd = File.OpenText(InFile))
            using (var wr = File.CreateText(@"C:\Users\Owen\Documents\Visual Studio 2010\Projects\Jam\Rnd1_A\Out.txt"))
            {
                int t = int.Parse(rd.ReadLine());

                for (int i = 1; i <= t; i++)
                {
                    var result = ProcessCase(rd);
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    wr.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
