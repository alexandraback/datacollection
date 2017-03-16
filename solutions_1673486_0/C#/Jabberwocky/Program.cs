using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Threading;
using System.Globalization;

namespace CodeJam2012
{
    class Program
    {
        private static TextWriter _Output;
        private static TextReader _Input;
        
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
            _Input = new StreamReader("..\\..\\A-small-attempt0.in");
            _Output = new StreamWriter("..\\..\\Output.txt");

            A();

            _Input.Close();
            _Output.Close();
        }

        static void A()
        {
            int lines = int.Parse(_Input.ReadLine());
            for (int i = 0; i < lines; i++)
            {
                List<int> line1 = _Input.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                List<double> line2 = _Input.ReadLine().Split(' ').Select(s => double.Parse(s)).ToList();
                _Output.Write(String.Format("Case #{0}: {1:0.00000000}", i + 1, ExpectedStrokes(line1[0], line1[1], line2)));
                if (i < lines - 1)
                {
                    _Output.WriteLine();
                }
            }
        }

        static double ExpectedStrokes(int chars, int len, List<double> prob)
        {
            return Math.Min(Math.Min(ES1(chars,len,prob), ES2(chars,len,prob)),  ES3(chars,len,prob));
        }

        static double ES1(int chars, int len, List<double> prob)
        {
            double p1 = CorProb(prob, chars) * (len - chars);
            double p2 = (1 - CorProb(prob, chars)) * (2 * len - chars + 1);
            return p1 + p2 + 1;
        }

        static double CorProb(List<double> prob, int correctTo)
        {
            double result = 1;
            for (int i = 0; i < correctTo; i++)
            {
                result *= (prob[i]);
            }
            return result;
        }

        static double ES2(int chars, int len, List<double> prob)
        {
            double result = double.MaxValue;
            for (int i = 0; i < chars; i++)
            {
                result = Math.Min(result, ProbBack(chars, len, prob, i));
            }
            return result;
        }

        static double ProbBack(int chars, int len, List<double> prob, int backsp)
        {
            int charsNew = chars - backsp;
            return (CorProb(prob, charsNew) * (len - charsNew) + (1 - CorProb(prob, charsNew)) * (2 * len - charsNew + 1)) + backsp + 1;
        }

        static double ES3(int chars, int len, List<double> prob)
        {
            return len + 2;
        }

    }
}
