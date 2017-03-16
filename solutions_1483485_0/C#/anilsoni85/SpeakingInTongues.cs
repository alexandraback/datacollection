using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

namespace GCJ2012.QR
{
    public class SpeakingInTongues
    {
        static class Program
        {
            [STAThread]
            static void Main(string[] args)
            {
                string inpFilePath = "InputFiles\\A-small-attempt0.in";
                if (args.Length > 0) inpFilePath = args[0];
                SpeakingInTongues b = new SpeakingInTongues(inpFilePath);
                b.Run();
            }
        }

        StreamReader inputFile;
        StreamWriter outPutFile;

        int totalCases,testCase;
        string fileLine,inputFilePath,outputFilePath;


        Hashtable alpha;

        public SpeakingInTongues(string inputFilePath)
        {
            this.inputFilePath = Path.GetFullPath(inputFilePath);
            this.outputFilePath = Path.Combine(Path.GetDirectoryName(inputFilePath), Path.GetFileNameWithoutExtension(inputFilePath)+".out");
        }

        public void Run()
        {
            this.inputFile = new StreamReader(this.inputFilePath);
            this.outPutFile = new StreamWriter(this.outputFilePath);

            fileLine = this.inputFile.ReadLine();
            totalCases = Convert.ToInt32(fileLine);

            this.alpha = new Hashtable(26);

            this.alpha.Add('a', 'y');
            this.alpha.Add('b', 'h');
            this.alpha.Add('c', 'e');
            this.alpha.Add('d', 's');
            this.alpha.Add('e', 'o');
            this.alpha.Add('f', 'c');
            this.alpha.Add('g', 'v');
            this.alpha.Add('h', 'x');
            this.alpha.Add('i', 'd');
            this.alpha.Add('j', 'u');
            this.alpha.Add('k', 'i');
            this.alpha.Add('l', 'g');
            this.alpha.Add('m', 'l');
            this.alpha.Add('n', 'b');
            this.alpha.Add('o', 'k');
            this.alpha.Add('p', 'r');
            this.alpha.Add('q', 'z');
            this.alpha.Add('r', 't');
            this.alpha.Add('s', 'n');
            this.alpha.Add('t', 'w');
            this.alpha.Add('u', 'j');
            this.alpha.Add('v', 'p');
            this.alpha.Add('w', 'f');
            this.alpha.Add('x', 'm');
            this.alpha.Add('y', 'a');
            this.alpha.Add('z', 'q');
            this.alpha.Add(' ', ' ');

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
            //Init test cases.
        }

        private void RunTestCase()
        {
            StringBuilder outputText = new StringBuilder(fileLine.Length);
            for (int i = 0; i < fileLine.Length; i++)
            {
                outputText.Append(this.alpha[fileLine[i]]);
            }
            this.outPutFile.WriteLine(string.Format("Case #{0}: {1}",this.testCase+1,outputText.ToString()));
        }

    }
}
