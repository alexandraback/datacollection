using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        static int[] pow = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

        static int maxN = 2000000;
        static int[] preRecord = new int[maxN + 1];

        static void preProcess()
        {
            for (int a = 10; a <= maxN; a++)
                preRecord[a] = preRecord[a - 1] + getSingleCase(a, 0, 0); 
        }

        static int getSingleCase(int a, int A, int B)
        {
            HashSet<int> set = new HashSet<int>();
            List<int> digit = new List<int>();

            int b = a;
            while (b > 0)
            {
                digit.Add(b % 10);
                b /= 10;
            }

            for (int i = 0; i < digit.Count - 1; i++)
                if (digit[i] > 0)
                {
                    b = a / pow[i + 1] + (a % pow[i + 1]) * pow[digit.Count - i - 1];
                    if (b > a && b <= B) set.Add(b);
                }

            return set.Count;
        }

        static void Main(string[] args)
        {
            //preProcess();

            //Console.WriteLine(getSingleCase(12, 10, 40));

            StreamReader inFile = new StreamReader("c.in");
            StreamWriter outFile = new StreamWriter("c.out");

            int cCnt = Convert.ToInt32(inFile.ReadLine());
            for (int cId = 1; cId <= cCnt; cId++)
            {
                string[] spt = inFile.ReadLine().Split();
                int A = Convert.ToInt32(spt[0]);
                int B = Convert.ToInt32(spt[1]);
                int ans = 0;
                for (int a = A; a <= B; a++) ans += getSingleCase(a, A, B);
                outFile.WriteLine("Case #{0}: {1}", cId, ans);
            }


            inFile.Close();
            outFile.Close();
        }

    }
}
