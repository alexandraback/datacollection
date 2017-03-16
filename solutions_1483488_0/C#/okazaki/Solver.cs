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

    void Solve(int caseNumber)
    {
        string[] input = Read().Split(' ');
        int answer = 0;

        int a = Convert.ToInt32(input[0]);
        int b = Convert.ToInt32(input[1]);
        for (int n = a; n < b; n++)
        {
            Dictionary<int, bool> Map = new Dictionary<int, bool>();
            string number = n.ToString();
            for (int index = 1; index < number.Length; index++)
            {
                string newNumber = number.Substring(index) + number.Substring(0, index);
                int m = Convert.ToInt32(newNumber);
                if (m > b) { continue; }
                if (n < m) 
                {
                    if (Map.ContainsKey(m)) { continue; }
                    answer++;
                    Map[m] = true;
                }
            }
        }

        MakeAnswer(caseNumber, answer.ToString());
    }

}

