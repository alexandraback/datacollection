using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CountingSheep
{
    class Program
    {
        public static void Main(string[] args)
        {
            System.IO.StreamReader input = new System.IO.StreamReader(@"D:\codejam\1\A-small-attempt0.in");
            System.IO.StreamWriter output = new System.IO.StreamWriter(@"D:\codejam\1\A-small-attempt0.out");

            int count = 0;
            int[] data= new int[1];
            string line;
            bool first = true;
            int idx = 0;
            while ((line=input.ReadLine())!=null)
            {
                if(first)
                {
                    count = int.Parse(line);
                    data = new int[count];
                    first = false;
                }
                else
                {
                    data[idx++] = int.Parse(line);
                }
            }
            input.Close();

            
            for (int i = 0; i < count; i++)
            {
                int[] digits = new int[10];
                int n = data[i];
                int k = 1;
                int noChangeTime = 0;
                int limit = 10000;
                while (noChangeTime < limit)
                {
                    n = data[i] * (k++);
                    if(!GetDigits(n, digits))
                    {
                        noChangeTime++;
                    }
                    if(CheckDigits(digits))
                    {
                        output.WriteLine("Case #{0}: {1}", i + 1, n);
                        break;
                    }
                }
                if(noChangeTime == limit)
                {
                    output.WriteLine("Case #{0}: {1}", i + 1, "INSOMNIA");
                }
            }
            
            output.Close();
        }
        public static bool GetDigits(int i, int[] digits)
        {
            bool res = false;
            while(i>0)
            {
                if(digits[i % 10]==0)
                {
                    res = true;
                }
                digits[i % 10] = 1;
                i = i / 10;
            }
            return res;
        }
        public static bool CheckDigits(int[] digits)
        {
            for(int i=0;i<digits.Length;i++)
            {
                if(digits[i]==0)
                {
                    return false;
                }
            }
            return true;
        }
        
    }
}
