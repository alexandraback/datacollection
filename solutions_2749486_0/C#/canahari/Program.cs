using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GoogleCodeJam2
{
    class Program
    {
        const string outFileName = "out.txt";

        [STAThread]
        static void Main(string[] args)
        {
            string inFileName = null;
            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    inFileName = dlg.FileName;
                }
            }
            if (inFileName == null)
                return;

            using (StreamWriter sw = new StreamWriter(outFileName))
            {
                using (StreamReader sr = new StreamReader(inFileName))
                {
                    int testCaseCount = int.Parse(sr.ReadLine());
                    for (int testCase = 1; testCase <= testCaseCount; testCase++)
                    {
                        //WRITE CODE HERE.  
                        string[] line = sr.ReadLine().Split();
                        int x = int.Parse(line[0]);
                        int y = int.Parse(line[1]);
                        string s = CreateSmallPogoString(x, y);
                        sw.WriteLine("Case #{0}: {1}", testCase, s);
                        if (s.Length > 500)
                            Console.WriteLine("This wont be good");
                    }
                }
            }
        }

        static string CreateSmallPogoString(int x, int y)
        {
            StringBuilder way = new StringBuilder();

            int currentX = 0;
            int currentY = 0;
            while (currentX != x)
            {
                if (currentX > x)
                {
                    way.Append("EW");
                    currentX--;
                }
                else if (currentX < x)
                {
                    way.Append("WE");
                    currentX++;
                }
            }
            while (currentY != y)
            {
                if (currentY > y)
                {
                    way.Append("NS");
                    currentY--;
                }
                else if (currentY < y)
                {
                    way.Append("SN");
                    currentY++;
                }
            }
            return way.ToString();
        }
    }
}
