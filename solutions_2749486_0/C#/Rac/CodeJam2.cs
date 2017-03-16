using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

    class CodeJam2
    {
        int j;

        public void solve()
        {
            string inputFile = @"C:\Users\teresa\Desktop\cj\B-small-attempt1.in";
            string outputFile = inputFile + ".OUT.txt";
            StringBuilder solution = new StringBuilder();
            string[] ls = load(inputFile);
            int pos = 0;
            long casesCount = parseLong(ls[pos++])[0];
            for (int caseInd = 0; caseInd < casesCount; caseInd++)
            {
                //start parsing------
                long m, n;
                List<int> c = parseInt(ls[pos++]);
                string sol = solveSC(c[0], c[1]);
                //end parsing----

                solution.AppendLine("Case #"+(caseInd+1)+": " + sol);
            }
            save(outputFile,solution.ToString());
        }

        public string solveSC(int x,int y)
        {
            j = 1;
            string sol = find(x,'E','W');
            sol = sol+find(y,'N','S');
            return sol;
        }

        private string find(int target, char up, char down)
        {
            StringBuilder b = new StringBuilder();
            int c = 0;

            while (c != target)
            {
                int dir = c < target ? 1 : -1;

                int s1 = c + j * dir;
                int totalCost1 = 1 + Math.Abs(target- s1) * 2;

                int s2 = c + dir;
                int totalCost2 = 2 + Math.Abs(target-s2) * 2;

                if (totalCost1 < totalCost2)
                {
                    c = s1;
                    j = j + 1;
                    if (dir > 0)
                        b.Append(up);
                    else
                        b.Append(down);
                }
                else
                {
                    c = s2;
                    j = j + 2;
                    if (dir > 0)
                        { b.Append(down); b.Append(up); }
                    else
                        { b.Append(up); b.Append(down); }
                }
            }

            return b.ToString();
        }


        #region IO

        public static string[] load(string fileName)
        {
            return File.ReadAllLines(fileName);
        }

        public static void save(string fileName, string solution)
        {
            if(File.Exists(fileName))
                File.Delete(fileName);
            File.WriteAllText(fileName, solution);
        }

        private static List<long> parseLong(string line)
        {
            List<long> numbers = new List<long>();
            string[] arr = line.Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
            foreach (string s in arr)
                numbers.Add(long.Parse(s));
            return numbers;
        }

        private static List<double> parseDouble(string line)
        {
            List<double> numbers = new List<double>();
            string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (string s in arr)
                numbers.Add(double.Parse(s));
            return numbers;
        }

        private static List<int> parseInt(string line)
        {
            List<int> numbers = new List<int>();
            string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (string s in arr)
                numbers.Add(int.Parse(s));
            return numbers;
        }

        #endregion io
    }
