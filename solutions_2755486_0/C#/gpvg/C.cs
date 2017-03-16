using System;
using System.IO;

class Solution
{
    //put any globals here#
    static string inputFilename = "small.in";
    static string outputFilename = "small.out";
    static string workingDirectoryPath = "C:\\codejam\\2013\\Round1C\\C\\";

    static string inputFile = workingDirectoryPath + inputFilename;
    static string outputFile = workingDirectoryPath + outputFilename;
    static StreamReader sr = new StreamReader(inputFile);

    public static void Main()
    {
        //call testHarness if required
        //testHarness();
        //reads one-time information from input file, especially number of test cases
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int cases = int.Parse(values[0]);
        for (int c = 0; c < cases; c++)
        {
            //loop over all the cases
            runCase(c);
        }
    }

    private static void runCase(int c)
    {
        string answer = "Case #" + (c + 1).ToString() + ": ";

        //read input for this particular case
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int N = int.Parse(values[0]);
        int[] d = new int[N];
        int[] n = new int[N];
        int[] w = new int[N];
        int[] e = new int[N];
        int[] s = new int[N];
        int[] deltad = new int[N];
        int[] deltap = new int[N];
        int[] deltas = new int[N];
        int successful = 0;
        for (int i = 0; i < N; i++)
        {
            line = sr.ReadLine();
            values = line.Split(' ');
            d[i] = int.Parse(values[0]);
            n[i] = int.Parse(values[1]);
            w[i] = int.Parse(values[2]) + 200;
            e[i] = int.Parse(values[3]) + 200;
            s[i] = int.Parse(values[4]);
            deltad[i] = int.Parse(values[5]);
            deltap[i] = int.Parse(values[6]);
            deltas[i] = int.Parse(values[7]);
        }

        Int64[] origheight = new Int64[500];
        Int64[] newheight = new Int64[500];
        Int64[] origheightmiddle = new Int64[500];
        Int64[] newheightmiddle = new Int64[500];
        for (int i = 0; i < 500; i++)
        {
            origheight[i] = 0;
           newheight[i] = 0;
           origheightmiddle[i] = 0;
           newheightmiddle[i] = 0;

        }
        for (int day = 0; day < 700000; day++)
        {
            for (int i = 0 ; i <500; i++)
            {
            origheight[i] = newheight[i];
            origheightmiddle[i] = newheightmiddle[i];
        }
            for (int tribe = 0; tribe < N; tribe++)
            {
                for (int attack = 0; attack < n[tribe]; attack++)
                {
                    if (d[tribe] + deltad[tribe] == day)
                    {
                        int eastmost = e[tribe] + attack*deltap[tribe];
                        int westmost = w[tribe] + attack * deltap[tribe];
                        int strength = s[tribe] + attack * deltas[tribe];
                            int good =0;
                        for (int i = westmost; i < eastmost+1; i++)
                        {
                            if (origheight[i] < strength) good = 1;
                            if (origheightmiddle[i] < strength && i < eastmost) good = 1;
                            newheight[i] = Math.Max(strength, origheight[i]);
                            if (i < eastmost) newheightmiddle[i] = Math.Max(strength, origheightmiddle[i]);
                        }
                        if (good ==1) successful++;
                    }
                }
            }
        }

        answer = answer + successful.ToString();
       

        //do some stuff to solve the problem


        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c != 0)))
        {
            sw.WriteLine(answer);
        }
    }


}






