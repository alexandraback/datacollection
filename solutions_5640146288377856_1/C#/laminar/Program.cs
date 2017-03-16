using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationA
{
    class TestCase
    {
        public int id;

        public int rows, cols, shipWidth;
        
        public TestCase()
        {
        }

        public int solve()
        {
            int result = 0;

            result = cols / shipWidth;

            if(cols % shipWidth > 0){
                result ++;
            }


            result *= rows;

            result += shipWidth -1;

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationA\ConsoleApplicationA\result.out", false))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationA\ConsoleApplicationA\A-practice.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationA\ConsoleApplicationA\A-small-attempt0.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151C\ConsoleApplicationA\ConsoleApplicationA\A-large.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    //sr.ReadLine();

                    List<int> temp = sr.ReadLine().Split(' ').ToList().ConvertAll(s => int.Parse(s));
                    tempTestCase.rows = temp[0];
                    tempTestCase.cols = temp[1];
                    tempTestCase.shipWidth = temp[2];

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
