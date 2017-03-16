using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader r = new StreamReader("input.txt");
            StreamWriter w = new StreamWriter("output.txt");
            string input = r.ReadToEnd();
            string[] read = input.Split('\n');
            int count = 99;
            bool flag = false;
            for (int x = 1; x <= Convert.ToInt32(read[0]) ; x ++)
            {
                flag = false;
                string[] temp = read[x].Split('/');
                BigInteger p = Convert.ToInt64(temp[0]);
                BigInteger q = Convert.ToInt64(temp[1]);
                if (checkpower(q) == true)
                {
                    flag = true;
                    count = 0;
                    while (p < q)
                    {
                        count++;
                        p += p;
                    }
                }
                if (flag)
                {
                    w.Write("Case #" + x + ": " + count + "\n");
                }
                else
                {
                    w.Write("Case #" + x + ": impossible" + "\n");
                }
            }
            w.Close();
        }

        static bool checkpower(BigInteger input)
        {
            for (int x = 1; x < 41; x++)
            {
                BigInteger a = (BigInteger) System.Math.Pow(2, x);
                if (input == a)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
