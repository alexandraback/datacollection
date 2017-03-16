using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static double CountRecycle (double a, double b)
        {
            List<string> list = new List<string>();

            for (double x = a; x <= b; x++)
            {
                string n1 = x.ToString();

                int y = n1.Length - 1;
                while (y > 0)
                {
                    string n2 = n1.Substring(y, n1.Length - y) + n1.Substring(0, y);

                    if (n2 != n1 && double.Parse(n2) >= a && double.Parse(n2) <= b)
                    {
                        list.Add(n1 + "," + n2);
                    }

                    y--;
                }
            }

            return list.Distinct().Count() / 2;
        }

        static void Main(string[] args)
        {
            string fileName = "C-Small";

            // Load file
            TextReader tr = new StreamReader(@"D:\Kiguti\Google Code Jam\2012\Qualification\C.Recycled Numbers\Input\" + fileName + ".in");
            string sCases = tr.ReadLine();

            // create a writer and open the file
            TextWriter tw = new StreamWriter(@"D:\Kiguti\Google Code Jam\2012\Qualification\C.Recycled Numbers\Output\" + fileName + ".out");

            int Cases = Int32.Parse(sCases);

            char[] delim = { ' ' };

            // Run cases
            for (int k = 1; k <= Cases; k++)
            {
                string[] numbers = tr.ReadLine().Split(delim);

                double a = double.Parse(numbers[0]);
                double b = double.Parse(numbers[1]);

                double count = CountRecycle(a, b);

                tw.WriteLine(string.Format("Case #{0}: {1}", k.ToString(), count.ToString()));
            }

            // close the stream
            tw.Close();
            tr.Close();
        }
    }
}
