using System;
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
        public int solution;
        public List<Kid> kids;

        public TestCase()
        {
            kids = new List<Kid>();
            solution = 0;
        }

        public bool valid(List<Kid> circle)
        {
            bool result = true;

            for (int i = 0; (i < circle.Count) && result; i++)
            {
                int bff = circle[i].BFFid;
                if(circle[(i+1) % circle.Count].id != bff
                    && circle[((i - 1) + circle.Count) % circle.Count].id != bff)
                {
                    result = false;
                }
            }

                return result; 
        }

        public int solve()
        {
            solution = 0;
            List<List<Kid>> perms = GetPerms(kids);

            perms.ForEach(circle => {
                if (circle.Count > solution)
                {
                    if (valid(circle)) solution = circle.Count;
                }
            });

            return solution;
        }

        public List<List<Kid>> GetPerms(List<Kid> kids)
        {
            List<List<Kid>> perms = new List<List<Kid>>();

            kids.ForEach(kid =>{
                var temp = kids.ToList();
                temp.RemoveAll(k => k.id == kid.id);
                GetPerms(temp).ForEach(p => {
                    p.Add(kid); 
                    perms.Add(p);
                });
                perms.Add(new List<Kid>() { kid });
            });

            return perms;
        }

        public void solveTestPerms()
        {
            TestPerms(this.kids, new List<Kid>());
        }

        public void TestPerms(List<Kid> kidsleft, List<Kid> circle)
        {
            if (kidsleft.Count == 0)
            {
                if (circle.Count > solution)
                {
                    if (valid(circle)) solution = circle.Count;
                }
            }else{

                List<List<Kid>> perms = new List<List<Kid>>();

                kidsleft.ForEach(kid =>
                {
                    var temp = kidsleft.ToList();
                    var tempc = circle.ToList();
                    temp.RemoveAll(k => k.id ==kid.id);
                    tempc.Add(kid);
                    TestPerms(temp, tempc);
                });

                TestPerms(new List<Kid>(), circle);
            }

        }
    }

    class Kid
    {
        public int id;
        public int BFFid;
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
                    sr.ReadLine();
                    var woot = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();

                    for (int j = 0; j < woot.Count(); j++)
                    {
                        tempTestCase.kids.Add(new Kid() { id = j + 1, BFFid = woot[j] });
                    }

                    testCases.Add(tempTestCase);

                }

                Parallel.ForEach(testCases, new ParallelOptions { MaxDegreeOfParallelism = 8 },
                    tc => {
                        tc.solveTestPerms();

                    });

                testCases.ForEach(tc => {
                    Console.WriteLine(String.Format("Case #{0}: {1}", tc.id, tc.solution));
                    sw.WriteLine(String.Format("Case #{0}: {1}", tc.id, tc.solution));
                });
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
