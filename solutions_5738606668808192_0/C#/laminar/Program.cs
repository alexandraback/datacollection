using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConsoleAppilcationC
{
    class TestCase
    {
        public int id;

        public BigInteger N;

        public BigInteger J;

        public List<Coin> Solutions = new List<Coin>();

        public TestCase()
        {
        }

        public List<Coin> Solve()
        {
            long i = 0;
            while(Solutions.Count() < J)
            {
                string inside = Convert.ToString(i, 2);
                while (inside.Length < (N - 2))
                {
                    inside = "0" + inside;
                }

                Coin tempCoin = new Coin("1" + inside + "1");

                if (tempCoin.isValid())
                {
                    Solutions.Add(tempCoin);
                }

                i++;
            }
            return Solutions;
        }
    }

    class Coin
    {
        public ConcurrentDictionary<int, BigInteger> factors = new ConcurrentDictionary<int, BigInteger>();

        public string coinNumber;
        private bool valid;
        public Coin(string p)
        {
            this.valid = true;
            this.coinNumber = p;
        }

        public bool isValid()
        {
            Parallel.For(2, 11, coinBase => {
                BigInteger fd = firstDivisor(BIParse(coinNumber, coinBase));

                if (fd < 0)
                {
                    valid = false;
                }
                else
                {
                    factors[coinBase] = fd;
                }
            });

            return valid;
        }

        private BigInteger firstDivisor(BigInteger num)
        {
            BigInteger temp = 3;

            if (num % 2 == 0)
            {
                return 2;
            }
            else
            {
                while (temp < 32769 && valid)
                {
                    if (num % temp == 0)
                    {
                        return temp;
                    }

                    temp += 2;
                }
            }


            return -1;
        }

        private BigInteger BIParse(string coinNumber, long coinBase)
        {
            BigInteger num = 0;

            coinNumber.ToCharArray().ToList().ForEach(dig => {
                num *= coinBase;
                if (dig == '1')
                {
                    num += 1;
                }
            });

            return num;
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
                    tempTestCase.N = BigInteger.Parse(woot[0]);
                    tempTestCase.J = BigInteger.Parse(woot[1]);


                    tempTestCase.Solve();


                    Console.WriteLine(String.Format("Case #{0}:", tempTestCase.id));
                    sw.WriteLine(String.Format("Case #{0}:", tempTestCase.id));

                    tempTestCase.Solutions.ForEach(c => {

                        Console.WriteLine(c.coinNumber
                            + " " + c.factors[2]
                            + " " + c.factors[3]
                            + " " + c.factors[4]
                            + " " + c.factors[5]
                            + " " + c.factors[6]
                            + " " + c.factors[7]
                            + " " + c.factors[8]
                            + " " + c.factors[9]
                            + " " + c.factors[10]);
                        sw.WriteLine(c.coinNumber
                            + " " + c.factors[2]
                            + " " + c.factors[3]
                            + " " + c.factors[4]
                            + " " + c.factors[5]
                            + " " + c.factors[6]
                            + " " + c.factors[7]
                            + " " + c.factors[8]
                            + " " + c.factors[9]
                            + " " + c.factors[10]);
                    });

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
