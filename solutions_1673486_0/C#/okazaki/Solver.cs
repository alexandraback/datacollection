using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Solver
{
    const string Folder = @"D:\GCJ\GCJ\";
    string FileName;
    string GetFile { get { return Folder + FileName; } }
    List<string> Lines;
    public Solver(List<string> lines) 
    {
        Lines = lines;
        FileName = DateTime.Now.ToShortTimeString().Replace(":", "") + DateTime.Now.Second + ".txt";
    }
    void MakeAnswer(int caseNumber, string answer)
    {
        using (StreamWriter sw = File.AppendText(GetFile))
        {
            sw.WriteLine(string.Format("Case #{0}: {1}", caseNumber, answer));
        }
    }
    string Read()
    {
        string value = Lines[0];
        Lines.RemoveAt(0);
        return value;
    }
    public void Execute()
    {
        Initialze();
        int cases = Convert.ToInt32(Read());
        for (int caseIndex = 0; caseIndex < cases; caseIndex++)
        {
            Solve(caseIndex + 1);
        }
    }

    void Initialze()
    {
    }

    void Solve(int caseNumber)
    {
        double bestAnswer = double.MaxValue;
        string[] parts = Read().Split(' ');
        string[] parts2 = Read().Split(' ');

        int A = Convert.ToInt32(parts[0]);
        int B = Convert.ToInt32(parts[1]);

        double[] p = new double[A];
        for (int index = 0; index < A; index++)
        {
            p[index] = Convert.ToDouble(parts2[index]);
        }

        // enter right away
        bestAnswer = B + 2;

        // keep typing
        double pOK = 1.0;
        for (int index = 0; index < p.Length; index++) { pOK *= p[index]; }
        double answer = pOK * (B + 1 - A) + (1 - pOK) * ((B + 1) * 2 - A);
        if (bestAnswer > answer) { bestAnswer = answer; }

        // backspace n times
        for (int n = 1; n < A; n++)
        {
            double pOK2 = 1.0;
            for (int index = 0; index < p.Length - n; index++) { pOK2 *= p[index]; }
            double answer2 = pOK2 * (B + 1 - A + n + n) + (1 - pOK2) * (B + 1 - A + n + n + B + 1);
            if (bestAnswer > answer2) { bestAnswer = answer2; }
        }

        MakeAnswer(caseNumber, bestAnswer.ToString("0.000000"));
    }
}

