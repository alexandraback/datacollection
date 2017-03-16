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

    int Length;
    bool[] Counted;
    int[] Values;
    Dictionary<char, char> Map = new Dictionary<char, char>();
    void Solve(int caseNumber)
    {
        Map['y'] = 'a';
        Map['n'] = 'b';
        Map['f'] = 'c';
        Map['i'] = 'd';
        Map['c'] = 'e';
        Map['w'] = 'f';
        Map['l'] = 'g';
        Map['b'] = 'h';
        Map['k'] = 'i';
        Map['u'] = 'j';
        Map['o'] = 'k';
        Map['m'] = 'l';
        Map['x'] = 'm';
        Map['s'] = 'n';
        Map['e'] = 'o';
        Map['v'] = 'p';

        Map['z'] = 'q';

        Map['p'] = 'r';
        Map['d'] = 's';
        Map['r'] = 't';
        Map['j'] = 'u';
        Map['g'] = 'v';
        Map['t'] = 'w';
        Map['h'] = 'x';
        Map['a'] = 'y';
        Map['q'] = 'z';

        string input = Read();
        string answer = "";
        foreach (char letter in input)
        {
            if (letter == ' ') { answer += ' '; }
            else
            {
                if (!Map.ContainsKey(letter))
                {
                }
                answer += Map[letter]; 
            }
        }
        MakeAnswer(caseNumber, answer);
    }

}

