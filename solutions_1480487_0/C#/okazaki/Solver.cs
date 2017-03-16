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
    void Solve(int caseNumber)
    {
        string[] parts = Read().Split(' ');
        int count = Convert.ToInt32(parts[0]);
        int[] jPoints = new int[count];
        int sum = 0;
        for (int index = 0; index < count; index++)
        {
            jPoints[index] = Convert.ToInt32(parts[index + 1]);
            sum += jPoints[index];
        }
        Sum = sum;
        double[] results = NewMethod(count, jPoints, sum);

        string ans = "";
        for (int index = 0; index < count; index++)
        {
            if (index != 0) { ans += " "; }
            ans += results[index].ToString();
        }        
        MakeAnswer(caseNumber, ans);
    }

    private static double[] NewMethod(int count, int[] jPoints, int sum)
    {
        double[] results = new double[count];
        for (int index = 0; index < count; index++)
        {
            double gainPoint = 1.0 * (Sum + sum - count * jPoints[index]) / count;
            bool exists = false;
            int targetIndex = -1;
            for (int index2 = 0; index2 < count; index2++)
            {
                if (index == index2) { continue; }
                if (jPoints[index] + gainPoint < jPoints[index2])
                {
                    exists = true;
                    targetIndex = index2;
                    break;
                }
            }
            if (!exists)
            {
                double result = gainPoint / Sum;
                if (result < 0) { result = 0.0; }
                results[index] = result * 100;
            }
            else
            {
                int count2 = count - 1;
                int[] j2Points = new int[count2];
                int a = -1;
                int b = -1;
                for (int index2 = 0; index2 < count; index2++)
                {
                    a++;
                    if (targetIndex == index2) { continue; }
                    b++;
                    j2Points[b] = jPoints[a];
                }
                double[] results2 = NewMethod(count2, j2Points, sum - jPoints[targetIndex]);
                int target = index;
                if (target > targetIndex) { target--; }
                results[index] = results2[target];
            }
        }
        return results;
    }

    void Initialze()
    {
    }
}

