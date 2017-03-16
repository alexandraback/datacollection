using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConsoleAppilcationD
{
    class TestCase
    {
        public int id;

        public BigInteger K;
        public BigInteger C;
        public BigInteger S;

        public TestCase()
        {
        }
    }

    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            string fileName = OpenFileDialog();

            using (StreamReader sr = new StreamReader(fileName))
            using (StreamWriter sw = new StreamWriter(Path.ChangeExtension(fileName, ".out"), false))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    string[] woot = sr.ReadLine().Split(' ');
                    tempTestCase.K = BigInteger.Parse(woot[0]);
                    tempTestCase.C = BigInteger.Parse(woot[1]);
                    tempTestCase.S = BigInteger.Parse(woot[2]);

                    List<BigInteger> results = new List<BigInteger>();

                    BigInteger kCounter = 0;

                    while (kCounter < tempTestCase.K)
                    {
                        BigInteger tempResult = 0;
                        BigInteger placeCounter = 0;

                        while (placeCounter < tempTestCase.C && kCounter < tempTestCase.K)
                        {
                            tempResult *= tempTestCase.K;
                            tempResult += kCounter;
                            
                            
                            kCounter++;
                            placeCounter++;
                        }

                        results.Add(tempResult + 1);

                    }

                    string result = "";

                    if (results.Count > tempTestCase.S)
                    {
                        result = "IMPOSSIBLE";
                    }
                    else
                    {
                        result = string.Join(" ", results.Select(r => r.ToString()));
                    }


                    Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));
                    sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));

                }
            }

            Console.ReadLine();
        }

        private static string OpenFileDialog()
        {
            string fileName;
            OpenFileDialog fd = new OpenFileDialog();
            fd.InitialDirectory = "Desktop";
            fd.Filter = "in files (*.in)|*.in|All files (*.*)|*.*";
            fd.ShowDialog();
            fileName = fd.FileName;
            return fileName;
        }

        static BigInteger GetGCD(BigInteger num1, BigInteger num2)
        {
            while (num1 != num2)
            {
                if (num1 > num2)
                {
                    num1 = num1 - num2;
                }
                else
                {
                    num2 = num2 - num1;
                }
            }

            return num1;
        }


        static BigInteger GetLCM(BigInteger num1, BigInteger num2)
        {
            return (num1 * num2) / GetGCD(num1, num2);
        }
    }
}
