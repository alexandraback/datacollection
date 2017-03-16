using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationC
{
    class TestCase
    {
        public int id;

        public UInt64 C, D, V;
        public List<UInt64> Denominations;

        public TestCase()
        {
        }

        public int solve()
        {
            Denominations.Sort();

            if (Denominations.Last() < V)
            {
                Denominations.Add(V+1);
            }

            int originalCount = Denominations.Count;
            int result = 0;

            if (Denominations.First() != 1)
            {
                Denominations.Insert(0, 1);
            }

            UInt64 totalSingleNote = Denominations[0];

            for (int i = 1; i < Denominations.Count; i++)
            {
                UInt64 value = Denominations[i];
                if (((totalSingleNote * C) + 1) < value)
                {
                    Denominations.Insert(i, ((totalSingleNote * C) + 1));
                }


                totalSingleNote += Denominations[i];
            }

            result = Denominations.Count - originalCount;

            return result;

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationC\ConsoleApplicationC\result.out", false))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationC\ConsoleApplicationC\C-practice.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationC\ConsoleApplicationC\C-small-attempt0.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationC\ConsoleApplicationC\C-large.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;

                    List<UInt64> temp = sr.ReadLine().Split(' ').ToList().ConvertAll(s => UInt64.Parse(s));
                    tempTestCase.C = temp[0];
                    tempTestCase.D = temp[1];
                    tempTestCase.V = temp[2];

                    tempTestCase.Denominations = sr.ReadLine().Split(' ').ToList().ConvertAll(s => UInt64.Parse(s));

                    int result = tempTestCase.solve();

                    Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));
                    //Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, tempTestCase.multiplyOut()));
                    sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));
                }

                Console.ReadLine();
            }
        }

    }
}
