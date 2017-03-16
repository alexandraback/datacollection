using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CoinJam
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader input = new System.IO.StreamReader(@"D:\codejam\CoinJam\C-large.in");
            System.IO.StreamWriter output = new System.IO.StreamWriter(@"D:\codejam\CoinJam\C-large.out");

            int n = 0, j = 0;
            string line;
            bool first = true;
            while ((line = input.ReadLine()) != null)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    string[] row = line.Split(' ');
                    n = int.Parse(row[0]);
                    j = int.Parse(row[1]);
                }
            }
            n = n / 2;
            input.Close();

            int[] number = new int[n];
            number[0] = 1;
            number[number.Length - 1] = 1;

            output.WriteLine("Case #1:");

            while (j>0)
            {
                { }
                bool valid = true;
                StringBuilder divisor = new StringBuilder();
                for(int b=2;b<=10;b++)
                {
                    long d = 0;
                    if(GetDivisor(number, b,out d))
                    {
                        divisor.Append(" " + d);
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    string cur = string.Join("", number) + string.Join("", number) + divisor;
                    output.WriteLine(cur);
                    j--;
                }
                AddNumber(number);
            }
            output.Close();
        }

        public static bool GetDivisor(int[] number, int b, out long d)
        {
            long value = 0;
            long weight = 1;
            for(int i=number.Length-1;i>=0;i--)
            {
                value += number[i] * weight;
                weight *= b;
            }
            for(long i=2;i<= Math.Sqrt(value); i++)
            {
                if(value%i==0)
                {
                    d = i;
                    return true;
                }
            }
            d = 0;
            return false;
        }

        public static void AddNumber(int[] number)
        {
            int add = 1;
            for (int i = number.Length - 2; i >= 0; i--)
            {
                int cur = add + number[i];
                if (cur<=1)
                {
                    number[i] = cur;
                    return;
                }
                else
                {
                    number[i] = cur % 2;
                    add = 1;
                }
            }
        }
    }
}
