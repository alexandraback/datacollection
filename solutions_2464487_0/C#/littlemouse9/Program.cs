using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestA
{
    class Program
    {
        static long cal(double r, double t)
        {
            double b = 2*r-1;
            double result = ((-b+Math.Sqrt(b*b+8*t)))/4.0;
            return (long)(result);
        }

        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"H:\Program\Test\GoogleTest\roundA\TestA\TestA\A-small-attempt0.in");
            StreamWriter writer = new StreamWriter(@"H:\Program\Test\GoogleTest\roundA\TestA\TestA\A-small-attempt0.out");

            int nTest = int.Parse(reader.ReadLine());
            for (int idxTest = 0; idxTest < nTest; idxTest++)
            {
                String str = reader.ReadLine();
                String[] words = str.Split();
                long result = cal(double.Parse(words[0]), double.Parse(words[1]));
                writer.WriteLine("Case #{0}: {1}", idxTest + 1, result);
            }
            reader.Close();
            writer.Close();
        }
    }
}
