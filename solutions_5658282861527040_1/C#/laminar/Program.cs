using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationB
{
    class TestCase
    {
        public int id;
        public uint a;
        public uint b;
        public uint k;
        public uint result;

        internal void Calculate()
        {
            result = 0;
            result += (a) * Math.Min(k, b);
            result += (b) * Math.Min(k, a);
            result -= Math.Min(k, a) * Math.Min(k, b);

            for (uint m = Math.Min(k, a); m < a; m++)
            {
                for (uint n = Math.Min(k, b); n < b; n++)
                {
                    if ((m & n) < k) result++;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationB\ConsoleApplicationB\result.out", false))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationB\ConsoleApplicationB\B-small-attempt0.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationB\ConsoleApplicationB\B-large.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    //sr.ReadLine();

                    string[] tempstr = sr.ReadLine().Split(' ');
                    tempTestCase.a = uint.Parse(tempstr[0]);
                    tempTestCase.b = uint.Parse(tempstr[1]);
                    tempTestCase.k = uint.Parse(tempstr[2]);

                    testCases.Add(tempTestCase);

                }

                Parallel.ForEach(testCases, ts => ts.Calculate());

                testCases.ForEach(ts =>
                {
                    Console.WriteLine(String.Format("Case #{0}: {1}", ts.id, ts.result));
                    sw.WriteLine(String.Format("Case #{0}: {1}", ts.id, ts.result));
                });

                Console.ReadLine();
            }
        }
    }
}
