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

    void Solve(int caseNumber)
    {
        string [] parts = Read().Split(' ');
        int N = Convert.ToInt32(parts[0]);
        int M = Convert.ToInt32(parts[1]);
        string[] partsN = Read().Split(' ');
        long[] countN = new long[N];
        long[] countN2 = new long[N];
        int[] kindN = new int[N];
        for (int index = 0; index < N; index++)
        {
            countN[index] = Convert.ToInt64(partsN[index*2]);
            countN2[index] = countN[index];
            kindN[index] = Convert.ToInt32(partsN[index * 2 + 1]);
        }
        string[] partsM = Read().Split(' ');
        long[] countM = new long[M];
        long[] countM2 = new long[M];
        int[] kindM = new int[M];
        for (int index = 0; index < M; index++)
        {
            countM[index] = Convert.ToInt64(partsM[index * 2]);
            countM2[index] = countM[index];
            kindM[index] = Convert.ToInt32(partsM[index * 2 + 1]);
        }
        long maxCount = 0;

        for (int cut1 = 0; cut1 < M + 1; cut1++)
        {
            for (int cut2 = cut1; cut2 < M + 1; cut2++)
            {
                for (int index4 = 0; index4 < N; index4++)
                {
                    countN[index4] = countN2[index4];
                }
                for (int index4 = 0; index4 < M; index4++)
                {
                    countM[index4] = countM2[index4];
                }
                long count = 0;
                int kind = kindN[0];
                int targetIndex = 0;
                for (int index = 0; index < M; index++)
                {
                    if (kind == kindM[index])
                    {
                        long made = Math.Min(countN[targetIndex], countM[index]);
                        count += made;
                        countN[targetIndex] -= made;
                        countM[index] -= made;
                    }
                    if (cut1 == index)
                    {
                        if (N > 1)
                        {
                            kind = kindN[1];
                            targetIndex = 1;
                        }
                    }
                    if (kind == kindM[index])
                    {
                        long made = Math.Min(countN[targetIndex], countM[index]);
                        count += made;
                        countN[targetIndex] -= made;
                        countM[index] -= made;
                    }
                    if (cut2 == index)
                    {
                        if (N > 2)
                        {
                            kind = kindN[2];
                            targetIndex = 2;
                        }
                    }

                    if (kind == kindM[index])
                    {
                        long made = Math.Min(countN[targetIndex], countM[index]);
                        count += made;
                        countN[targetIndex] -= made;
                        countM[index] -= made;
                    }
                }
                maxCount = Math.Max(maxCount, count);
            }
        }


        MakeAnswer(caseNumber, maxCount.ToString());
        return;
    }


    void Initialze()
    {
    }
}

