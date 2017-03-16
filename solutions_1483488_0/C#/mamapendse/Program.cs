using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam_2
{
    class RecycleTest
    {
        String num;
        String doublenum;
        int length;
        public RecycleTest(Int32 n)
        {
            num = String.Format("{0}", n);
            doublenum = String.Format("{0}{0}", num);
            length = num.Length;
        }

        public int GetRecycledCount(int limit)
        {
            int i = 0;
            int numrecycles = 0;
            int num1 = Int32.Parse(num);
            List<int> temp = new List<int>();
            for (i = 1; i < length; i++)
            {
                if (num[i] >= num[0])
                {
                    string substr = doublenum.Substring(i, length);
                    
                    int num2 = Int32.Parse(substr);
                    if (temp.Contains(num2))
                    {
                        continue;
                    }
                    temp.Add(num2);
                    if(num2 <= limit)
                    if (Int32.Parse(num) < Int32.Parse(substr))
                        numrecycles++;
                }
            }

            return numrecycles;
        }

    }

    class Program
    {

        static int GetNumRecycles(int min, int max)
        {
            int i = 0;
            int count = 0;
            for (i = min; i <= max; i++)
            {
                RecycleTest test = new RecycleTest(i);
                int c = test.GetRecycledCount(max);

                count += c;
            }

            return count;

        }


        static void Main(string[] args)
        {
            TextReader tr = new StreamReader(@"c:\bhargav\C-small-attempt0.in");
            TextWriter of = new StreamWriter(@"c:\bhargav\out.txt");
            string line = tr.ReadLine();

            int numCases = 0;
            try
            {
                numCases = Int32.Parse(line);
            }
            catch (Exception e)
            {
                Console.Out.WriteLine("Parse exception while getting count");
            }

            int i = 0;
            for (i = 0; i < numCases; i++)
            {
                Console.Out.WriteLine("Reading case {0}", i + 1);
                line = tr.ReadLine();
                string[] words = line.Split(' ');
                int min = int.Parse(words[0]);
                int max = int.Parse(words[1]);
                of.WriteLine("Case #{0}: {1}", i + 1, GetNumRecycles(min, max));
                of.Flush();
            }
            of.Close();
        }
    }
}
