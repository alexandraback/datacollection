using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

namespace GCJ2012.QR
{
    public class ProblemC
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "InputFiles\\C-small-attempt0.in";
                if (args.Length > 0) inpFilePath = args[0];
                ProblemC p = new ProblemC(inpFilePath);
                p.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        int totalCases,testCase;
        string fileLine,inputFilePath,outputFilePath;

        int A, B, m;
        Hashtable distinctPairs;
        public ProblemC(string inputFilePath)
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
            string[] txts = fileLine.Split(new char[] { ' ' },StringSplitOptions.RemoveEmptyEntries);
            //Init test cases.
            this.A = Convert.ToInt32(txts[0]);
            this.B = Convert.ToInt32(txts[1]);
            this.m = 0;
            this.distinctPairs = new Hashtable();
        }

        private void RunTestCase()
        {
            //Logic goes here
            for (int i = A; i < B; i++)
            {
                int n = i;
                string ns = n.ToString();
                for (int j = 1; j <ns.Length; j++)
                {
                    if (ns[j] != '0')
                    {
                        string ms = ns.Substring(j) + ns.Substring(0, j);
                        int m = Convert.ToInt32(ms);
                        if (A <= n && n < m && m <= B)
                        {
                            string pair = ns+":"+ms;
                            if (!this.distinctPairs.ContainsKey(pair))
                            {
                                this.distinctPairs.Add(pair, null);
                                Console.WriteLine("({0},{1})", n, m);
                                this.m++;
                            }
                        }

                    }
                }
            }
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}",this.testCase+1,this.m));
        }

    }
}
