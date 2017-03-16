using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ2012.QR
{
    /// <summary>
    /// Dancing With The Googlers
    /// https://code.google.com/codejam/contest/1460488/dashboard#s=p1
    /// </summary>
    public class ProblemB
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "InputFiles\\B-large.in";
                if (args.Length > 0) inpFilePath = args[0];
                ProblemB p = new ProblemB(inpFilePath);
                p.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        int totalCases,testCase;
        string fileLine,inputFilePath,outputFilePath;

        int n; //the number of Googlers, 
        int s; //the number of surprising triplets of scores
        int p; //best result p.
        int[] t;//Total scores array.
        int m;//max count
        int s1, s2, s3;
        public ProblemB(string inputFilePath)
        {
            this.inputFilePath = inputFilePath;
            this.outputFilePath = Path.Combine(Path.GetDirectoryName(Path.GetFullPath(inputFilePath)), Path.GetFileNameWithoutExtension(inputFilePath) + ".out");
        }

        public void Run()
        {
            this.inputFile = new StreamReader(this.inputFilePath);
            this.outPutFile = new StreamWriter(this.outputFilePath);

            fileLine = this.inputFile.ReadLine();
            totalCases = Convert.ToInt32(fileLine);

            for (testCase = 0; testCase < totalCases; testCase++)
            {
                InitTestCase();
                RunTestCase();
            }

            this.outPutFile.Close();
            this.inputFile.Close();
        }

        private void InitTestCase()
        {
            fileLine = this.inputFile.ReadLine();
            Console.WriteLine("Case#{0}: {1}", this.testCase + 1, fileLine);
            string[] txts = fileLine.Split(new char[] { ' ' },StringSplitOptions.RemoveEmptyEntries);
            //Init test cases.
            n = Convert.ToInt32(txts[0]);
            s = Convert.ToInt32(txts[1]);
            p = Convert.ToInt32(txts[2]);

            this.t = new int[n];
            for (int i = 0; i < n; i++)
            {
                this.t[i] = Convert.ToInt32(txts[i + 3]);
            }
            Array.Sort<int>(t);
            this.m = 0;
            s1 = s2=s3=0;
        }

        private void RunTestCase()
        {
            //Logic goes here
            for (int i = 0; i < t.Length; i++)
            {
                int T = t[i];
                s1 = s2 = s3 = 0;
                if (T == 0 && T==this.p)
                {
                    this.m++;
                }
                else if (T > 1 && (T - 2) % 3 == 0 && checkScores((T - 2) / 3, 3))
                {
                    this.m++;
                }
                else if (T > 2 && (T - 3) % 3 == 0 && checkScores((T - 3) / 3, 4))
                {
                    this.m++;
                }
                else if (T > 3 && (T - 4) % 3 == 0 && checkScores((T - 4) / 3, 5))
                {
                    this.m++;
                }
                else if (T % 3 == 0 && checkScores(T / 3,0))
                {
                    this.m++;
                }
                else if (T>0 && (T - 1) % 3 == 0 && checkScores((T - 1) / 3,1))
                {
                    this.m++;
                }
                
                else if (T>1 && (T - 2) % 3 == 0 && checkScores((T - 2) / 3,2))
                {
                    this.m++;
                }
            }
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}",this.testCase+1,this.m));
            Console.WriteLine(string.Format("Ans.: {1}\r\n", this.testCase + 1, this.m));
        }

        private bool checkScores(int x,int caseNo)
        {
            s1=s2=s3=0;
            if (caseNo == 0)
            {
                s1 = s2 = s3 = x;
            }
            else if (caseNo == 1)
            {
                s1 = s2 = x;
                s3 = x + 1;
            }
            else if (caseNo == 2)
            {
                s1 = x;
                s2 = s3 = x + 1;
            }
            else if (caseNo == 3)
            {
                s1 = s2 = x;
                s3 = x + 2;
            }
            else if (caseNo == 4)
            {
                s1 = x;
                s2 = x + 1;
                s3 = x + 2;
            }
            else if (caseNo == 5)
            {
                s1 = x;
                s2 = s3 = x + 2;
            }

            if (s1 > 10 || s2 > 10 || s3 > 10)
            {
                s1 = s2 = s3 = 0;
                return false;
            }

            if (caseNo >= 3)
            {
                if(this.s > 0 && (s1 >= this.p || s2 >= this.p || s3 >= this.p))
                {
                    this.s--;
                    Console.WriteLine(string.Format("\t\t[{0} {1} {2}]", s1, s2, s3));
                    return true;
                }
            }
            else if (s1 >= this.p || s2 >= this.p || s3 >= this.p)
            {
                Console.WriteLine(string.Format("\t\t[{0} {1} {2}]", s1, s2, s3));
                return true;
            }
            s1 = s2 = s3 = 0;
            return false;
        }
    }
}
