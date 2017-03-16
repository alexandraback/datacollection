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

    string TooBad = "Too Bad";
    void Solve(int caseNumber)
    {
        int StarCount = 0;
        int times = 0;
        int levelCount = Convert.ToInt32(Read());
        List<int> p1 = new List<int>();
        List<int> p2 = new List<int>();
        List<bool> solved1 = new List<bool>();
        List<bool> solved2 = new List<bool>();
        for (int index = 0; index < levelCount; index++)
        {
            string[] parts = Read().Split(' ');
            p1.Add(Convert.ToInt32(parts[0]));
            p2.Add(Convert.ToInt32(parts[1]));
            solved1.Add(false);
            solved2.Add(false);
        }
        int solvedCount = 0;
        while (true)
        {
            for (int index = 0; index < levelCount; index++)
            {
                if (solved2[index]) { continue; }
                if (p2[index] <= StarCount)
                {
                    solved2[index] = true;
                    times++;
                    if (solved1[index])
                    {
                        StarCount++;
                    }
                    else
                    {
                        StarCount += 2;
                    }
                    solvedCount++;
                    index = -1;
                    continue;
                }
            }
            if (solvedCount == levelCount) { break; }
            int targetIndex = -1;
            int min1 = int.MaxValue;
            int min2 = int.MinValue;
            for (int index = 0; index < levelCount; index++)
            {
                if (solved2[index] || solved1[index]) { continue; }
                if (p1[index] > StarCount) { continue; }
                if (min1 < p1[index]) { continue; }
                if (min2 > p2[index]) { continue; }
                targetIndex = index;
                min1 = p1[index];
                min2 = p2[index];
            }
            if (targetIndex == -1)
            {
                MakeAnswer(caseNumber, TooBad);
                return;
            }

            solved1[targetIndex] = true;
            StarCount++;
            times++;
        }

        MakeAnswer(caseNumber, times.ToString());
    }
}

