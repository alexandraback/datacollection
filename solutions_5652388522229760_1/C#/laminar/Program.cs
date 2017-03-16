using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StandingOvation
{
    class TestCase
    {
        public int id;
        public BigInteger n;

        public bool[] numsSeen = new bool[10] { false, false, false, false, false, false, false, false, false, false };

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
                    string woot = sr.ReadLine();
                    tempTestCase.n = BigInteger.Parse(woot);
                    
                    BigInteger lastNumber = 0;

                    for (int j = 1; j <= 100; j++)
                    {
                        BigInteger temp = tempTestCase.n * j;
                        lastNumber = temp;
                        do
                        {
                            int rem = (int)(temp % 10);
                            temp = temp / 10;

                            tempTestCase.numsSeen[rem] = true;
                        } while (temp > 0);

                        if (!tempTestCase.numsSeen.Any(n => n == false))
                        {
                            break;
                        }
                    }

                    if (lastNumber > 0)
                    {
                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, lastNumber));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, lastNumber));
                    }
                    else
                    {
                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "INSOMNIA"));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "INSOMNIA"));
                    }
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
