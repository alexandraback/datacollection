using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConsoleAppilcationA
{
    class TestCase
    {
        public int id;
        public string letters;

        public TestCase()
        {
        }

        public string solve(int max)
        {
            if (max == 0) return "";

            int lastLow = 0;
            char lowchar = 'A';

            for (int i = 0; i < max; i++)
            {
                if (letters[i] >= lowchar)
                {
                    lowchar = letters[i];
                    lastLow = i;
                }
            }

            string result = lowchar + solve(lastLow);
            if (lastLow + 1 < max) result += letters.Substring(0, max).Substring(lastLow + 1);

            return result;
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
                    tempTestCase.letters = sr.ReadLine();





                    string result = tempTestCase.solve(tempTestCase.letters.Length);

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
