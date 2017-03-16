using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {


        public static long SolveC(string line)
        {
            long res = 0;

            int A, B;

            string[] parms = line.Split(' ');

            A = Int32.Parse(parms[0]);
            B = Int32.Parse(parms[1]);

            Dictionary<int, bool> passed = new Dictionary<int, bool>();
            Dictionary<int, long> pairs = new Dictionary<int, long>();

            for (int n = A; n <= B; n++)
            {
                int nn = n;
                long cant = 0;
                int lenght = n.ToString().Length;

                if (n < 10)
                {
                    continue;
                }
                
                while (!passed.ContainsKey(nn))
                {
                    passed[nn] = true;
                    
                    nn = (nn / 10) + (nn % 10) * (int)Math.Pow(10, lenght-1);

                    if (nn >= A && nn <= B && nn != n)
                    {
                        cant++;
                    }
                    

                }

                if (cant > 0)
                {
                    pairs[n] = cant;
                    res += (cant * (cant + 1))/2;
                }
            }

            return res;
        }

        public static string SolveD(string line)
        {


            return "";
        }


        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("C-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("C-large.out"))
                {
                    string ll = sr.ReadLine().Trim();

                    int cases = Int32.Parse(ll);

                    for (int kkk = 1; kkk <= cases; kkk++)
                    {
                        string line = sr.ReadLine().Trim();

                        long res = SolveC(line);

                        sw.WriteLine("Case #{0}: {1}", kkk, res);
                        Console.WriteLine("Case #{0}: {1}", kkk, res);
                    }

                }
            }

            Console.ReadLine();
        }
    }
}
