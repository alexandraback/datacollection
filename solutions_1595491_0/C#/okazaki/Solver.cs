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
        int cases = Convert.ToInt32(Read());
        for (int caseIndex = 0; caseIndex < cases; caseIndex++)
        {
            Solve(caseIndex + 1);
        }
    }

    Dictionary<char, char> Map = new Dictionary<char, char>();
    void Solve(int caseNumber)
    {
        string[] input = Read().Split(' ');
        int answer = 0;

        int n = Convert.ToInt32(input[0]);
        int s = Convert.ToInt32(input[1]);
        int p = Convert.ToInt32(input[2]);
        int p3 = p * 3;
        for (int index = 3; index < input.Length; index++)
        {
            int total = Convert.ToInt32(input[index]);
            if (total == 0)
            {
                if (p == 0) { answer++; }
                continue;
            }
            if (total == 1)
            {
                if (p == 0 || p == 1) { answer++; }
                continue;
            }
            if (total == 2)
            {
                if (p == 0 || p == 1) { answer++; }
                else if (s != 0 && p == 2) { s--; answer++; }
                continue;
            }
            if (total == 3)
            {
                if (p == 0 || p == 1) { answer++; }
                else if (s != 0 && p == 2) { s--; answer++; }
                continue;
            }
            if (total == 4)
            {
                if (p == 0 || p == 1 || p == 2) { answer++; }
                continue;
            }
            if (total >= p3 - 2) { answer++; continue; }
            if (s != 0 && total >= p3 - 4) { s--; answer++; continue; }
        }


        MakeAnswer(caseNumber, answer.ToString());
    }

}

