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
    static int Sum;
    static List<int> groupA;
    static List<int> groupB;
    static int[] jPoints;
    void Solve(int caseNumber)
    {
        string[] parts = Read().Split(' ');
        int count = Convert.ToInt32(parts[0]);
        jPoints = new int[count];
        int sum = 0;
        for (int index = 0; index < count; index++)
        {
            jPoints[index] = Convert.ToInt32(parts[index + 1]);
        }

        groupA = new List<int>();
        groupB = new List<int>();
        if (!calc(0))
        {
            MakeAnswer(caseNumber, "Impossible");
            return;
        }


        string firstLine = "";
        for (int index = 0; index < count; index++)
        {
            int value = jPoints[index];
            if (groupA.Contains(value))
            {
                if (firstLine != "") { firstLine += " "; }
                firstLine += value;
            }
        }
        string secondLine = "";
        for (int index = 0; index < count; index++)
        {
            int value = jPoints[index];
            if (groupB.Contains(value))
            {
                if (secondLine != "") { secondLine += " "; }
                secondLine += value;
            }
        }
        string ans = "\r\n" + firstLine + "\r\n" + secondLine;
        MakeAnswer(caseNumber, ans);
    }

    bool calc(int turn)
    {
        if (turn == 20)
        {
            return false;
        }

        int value = jPoints[turn];
        // a
        groupA.Add(value);
        if (Same()) { return true; }
        if (calc(turn + 1)) { return true; }
        groupA.Remove(value);

        // b
        groupB.Add(value);
        if (Same()) { return true; }
        if (calc(turn + 1)) { return true; }
        groupB.Remove(value);

        // none
        return calc(turn + 1);
    }

    private bool Same()
    {
        int sumA = 0;
        for (int index = 0; index < groupA.Count; index++)
        {
            sumA += groupA[index];
        }
        int sumB = 0;
        for (int index = 0; index < groupB.Count; index++)
        {
            sumB += groupB[index];
        }
        return sumA == sumB;
    }


    void Initialze()
    {
    }
}

