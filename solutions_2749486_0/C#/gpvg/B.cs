using System;
using System.IO;

class Solution
{
    //put any globals here
    static string inputFilename = "small.in";
    static string outputFilename = "small.out";
    static string workingDirectoryPath = "C:\\codejam\\2013\\Round1C\\B\\";

    static string inputFile = workingDirectoryPath + inputFilename;
    static string outputFile = workingDirectoryPath + outputFilename;
    static StreamReader sr = new StreamReader(inputFile);

    public static void Main()
    {
        //call testHarness if required
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
        int X = int.Parse(values[0]);
        int Y = int.Parse(values[1]);
        if (X > 0)
        {
            for (int i = 0; i < X; i++)
            {
                answer = answer + "WE";
            }
        }
        if (X < 0)
        {
            for (int i = 0; i < -X; i++)
            {
                answer = answer + "EW";
            }
        }
        if (Y > 0)
        {
            for (int i = 0; i < Y; i++)
            {
                answer = answer + "SN";
            }
        }
        if (Y < 0)
        {
            for (int i = 0; i < -Y; i++)
            {
                answer = answer + "NS";
            }
        }



        //do some stuff to solve the problem


        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c != 0)))
        {
            sw.WriteLine(answer);
        }
    }


}






