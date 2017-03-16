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

    static List<long> groupA;
    static List<long> groupB;
    static List<long> jPoints;
    void Solve(int caseNumber)
    {
        int count = Convert.ToInt32(Read());
        bool[,] dp = new bool[count + 1, count + 1];
        for (int index = 0; index < count; index++)
        {
            int classFrom = index + 1;
            string[] parts = Read().Split(' ');
            for (int index2 = 1; index2 < parts.Length; index2++)
            {
                int classTo = Convert.ToInt32(parts[index2]);
                dp[classFrom, classTo] = true;
            }
        }

        for (int indexFrom = 0; indexFrom < count; indexFrom++)
        {
            int classFrom = indexFrom + 1;
            for (int indexTo = 0; indexTo < count; indexTo++)
            {
                int classTo = indexTo + 1;
//                if (!dp[classFrom, classTo]) { continue; }
                for (int index = 0; index < count; index++)
                {
                    int classTo2 = index + 1;
  //                  if (!dp[classTo, classTo2]) { continue; }
                    
                    if (dp[classTo, classFrom] && dp[classFrom, classTo2])
                    {
                        if (dp[classTo, classTo2])
                        {
                            MakeAnswer(caseNumber, "Yes");
                            return;
                        }
                        dp[classTo, classTo2] = true;
                    }
                }
            }
        }
        MakeAnswer(caseNumber, "No");
        return;
    }


    void Initialze()
    {
    }
}

