using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

    class CodeJam1
    {
        HashSet<char> vovels = new HashSet<char>();

        public void solve()
        {
            vovels.Add('a'); vovels.Add('e'); vovels.Add('i');
            vovels.Add('o'); vovels.Add('u');

            string inputFile = @"C:\Users\teresa\Desktop\cj\A-small-attempt0.in";
            string outputFile = inputFile + ".OUT.txt";
            StringBuilder solution = new StringBuilder();
            string[] ls = load(inputFile);
            int pos = 0;
            long casesCount = parseLong(ls[pos++])[0];
            for (int caseInd = 0; caseInd < casesCount; caseInd++)
            {
                //start parsing------
                string line = ls[pos++];
                string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                string sol = solveSC(arr[0], int.Parse(arr[1]));
                //end parsing----

                solution.AppendLine("Case #"+(caseInd+1)+": " + sol);
            }
            save(outputFile,solution.ToString());
        }

        public string solveSC(string line, int n)
        {
            long count = 0;
            for (int i = 0; i < line.Length; i++)
			{
                int cons = 0;
                int maxCons = 0;
                for (int j = i; j < line.Length; j++)
                {
                    if (vovels.Contains(line[j]))
                        cons = 0;
                    else
                        cons++;
                    maxCons = Math.Max(cons, maxCons);
                    if (maxCons >= n)
                        count++;
                }
			}
            return count.ToString();
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
