using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Collections;

namespace Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader(@"c:\cjData\q3sample.txt");
            StreamWriter output = new StreamWriter(@"c:\cjData\q3output.txt");

            int totalCount = int.Parse(input.ReadLine());

            for (int i = 0; i < totalCount; i++)
            {
                string line = input.ReadLine();
                string[] splits = line.Split(new char[] { ' ' });

                int A = int.Parse(splits[0]);
                int B = int.Parse(splits[1]);

                int solution = Solve(A, B);
                output.WriteLine("Case #" + (i + 1) + ": " + solution);
                Debug.WriteLine("Case #" + (i + 1) + ": " + solution);
            }

            output.Close();
            input.Close();
        }

        static int Solve(int A, int B)
        {
            if (A < 10) 
                return 0;

            int size = B - A + 1;
            BitArray checker = new BitArray(size,false);

            int count = 0;

            for (int i = 0; i < size; i++)
            {
                int m = A + i;
                if (checker.Get(i))
                    continue;

                int mDigits = NumOfDigits(m);

                int recCount = 1;
                int n = m;

                while (true)
                {
                    n = Shift(n, mDigits);

                    if (m == n)
                        break;
                    else if ( n >= A && n <= B )
                    {
                        checker.Set(n - A, true);
                        recCount++;
                    }

                }

                if (recCount > 1)
                {
                    count += recCount * (recCount - 1) / 2;
                }
            }

            return count;
        }

        static int Shift(int x , int mDigits)
        {
            int lastDigit = x % 10;

            if (lastDigit == 0)
                return Shift(x / 10, mDigits);

            for(int i =0; i < mDigits -1 ; i++){
                lastDigit *= 10;
            }

            return lastDigit + x / 10;
        }

        static int NumOfDigits(int x)
        {
            int count = 0;
            while (x > 0)
            {
                x = x / 10;
                count++;
            }
            return count;
        }
    }
}
