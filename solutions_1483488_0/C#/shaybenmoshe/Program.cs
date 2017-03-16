using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("input.txt");
            TextWriter tw = new StreamWriter("output.txt");

            int T = int.Parse(tr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] s = tr.ReadLine().Split(' ');
                tw.WriteLine("Case #" + i + ": " + TestCase(int.Parse(s[0]), int.Parse(s[1])));
            }

            tr.Close();
            tw.Close();
        }

        static int TestCase(int A, int B)
        {
            int digits = 0; // Number of digits.
            int multiplier = 1; // Multiplier ( = 10^(digits - 1) ).
            int temp = A;
            while (temp > 0)
            {
                temp /= 10;
                digits++;
                multiplier *= 10;
            }
            multiplier /= 10;

            int count = 0;

            // Iterate the m variable, and find all cycles. If a cycle matches the conditions for n, count it.
            for (int m = A + 1; m <= B; m++)
            {
                temp = m;
                for (int i = 0; i < digits; i++)
                {
                    int t1 = temp % 10;
                    temp = (temp / 10) + t1 * multiplier;
                    if (temp == m)
                    {
                        break;
                    }

                    if (temp < m && temp >= A)
                    {
                        count++;
                    }
                }
            }

            return count;
        }
    }
}
