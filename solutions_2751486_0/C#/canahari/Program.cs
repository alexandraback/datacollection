using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GoogleCodeJam1
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
                        string[] line = sr.ReadLine().Split(' ');
                        string nameOfMember = line[0];
                        int n = int.Parse(line[1]);
                        sw.WriteLine("Case #{0}: {1}", testCase, NValue(nameOfMember, n));
                    }
                }
            }
        }



        static int NValue(string name, int n)
        {
            int res = 0;

            string consonantString = CreateConsonantString(name);
            for (int start = 0; start < name.Length; start++)
            {
                for (int end = start; end < name.Length; end++)
                {
                    //Console.WriteLine(name.Substring(start, (end - start + 1)));
                    //Console.WriteLine(consonantString.Substring(start, (end - start + 1)));
                    int cLetters = 0;
                    for (int i = start; i <= end; i++)
                    {
                        if (consonantString[i] == '1')
                            cLetters++;
                        else
                        {
                            if (cLetters >= n)
                            {
                                res++;
                                cLetters = 0;
                                break;
                            }
                            else 
                                cLetters = 0;
                        }
                    }
                    if (cLetters >= n)
                    {
                        res++;
                    }
                }
            }

            return res;
        }

        static string CreateConsonantString(string s)
        {
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                    s[i] == 'u')
                {
                    res.Append('0');
                }
                else
                    res.Append('1');
            }
            return res.ToString();
        }
        
    }



}
