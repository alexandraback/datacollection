using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam20131B1
{
    class Program
    {
        static uint solve(uint[] M, uint start, uint N, uint A)
        {

            if (A == 1)
            {
                return N;
            }

            uint i = start;
            //Console.WriteLine("N: " + N);
            //Console.WriteLine("1i: " + i);
            //Console.WriteLine("X: " + A);
            //Console.WriteLine("1m: " + M[start]);
            uint X = A;
            while (i < N && X > M[i] )
            {
                //Console.WriteLine("Dans la boucle");
                X += M[i];
               // Console.WriteLine("X: " + X);
                i++;
                //Console.WriteLine("i: " + i);
            }
            //Console.WriteLine("Plus dans la boucle");
     
            if (i==N)
            {
                //Console.WriteLine("1j: 0");
                return 0;
            }
            if (i == N-1)
            {
               // Console.WriteLine("4j: 1");
                return 1;
            }
           // Console.WriteLine("2i: " + i);
            //Console.WriteLine("2m: " + M[i]);

            uint j = 0;
           
            while (X <= M[i] && X >1)
            {
                j++;
                X = 2 * X - 1;
            }
            //Console.WriteLine("j: " + i);
            //Console.WriteLine("X: " + X);
            if (i == N - 1)
            {
               // Console.WriteLine("2j: " + j);
                return j;
            }
            else
            {
                j = (uint)Math.Min(j + solve(M, i + 1, N, X + M[i]), N - i);
               // Console.WriteLine("3j: " + j);
            }



            return j;

        }

        public static void Quicksort(UInt32[] elements, int left, int right)
        {
            int i = left, j = right;
            IComparable pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0)
                {
                    i++;
                }

                while (elements[j].CompareTo(pivot) > 0)
                {
                    j--;
                }

                if (i <= j)
                {
                    // Swap
                    UInt32 tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            // Recursive calls
            if (left < j)
            {
                Quicksort(elements, left, j);
            }

            if (i < right)
            {
                Quicksort(elements, i, right);
            }
        }

        static void Main(string[] args)
        {
            String input = Console.ReadLine();
            int T = Convert.ToInt32(input);
            //Console.WriteLine(T);

            for (int k = 0; k < T; k++)
            {
                UInt32 A;
                UInt32 N;
                input = Console.ReadLine();
                Console.Write("Case #" + (k + 1) + ": ");

                int first = 0;
                int end = 0;
                while (end < input.Length && input.ElementAt(end) != ' ') end++;
                A = Convert.ToUInt32(input.Substring(first, end - first));

                first = end;
                 end++;
                 while (end < input.Length && input.ElementAt(end) != ' ') end++;
                 N = Convert.ToUInt32(input.Substring(first, end - first));

                UInt32 [] m = new UInt32[N];

                 input = Console.ReadLine();
                first = 0;
                end = 0;
               // Console.WriteLine();
                for (int i = 0; i < N; i++)
                {
                    while (end < input.Length && input.ElementAt(end) != ' ') end++;
                    m[i] = Convert.ToUInt32(input.Substring(first, end - first));

                    first = end;
                    end++;
                    //Console.WriteLine(m[i]);
                }

                Quicksort(m, 0, m.Length-1);
                
                uint res = solve(m, 0, N, A);

                Console.WriteLine(res);
                

           
            }
        }

        
    }
}
