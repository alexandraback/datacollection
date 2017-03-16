using System;
using System.IO;

class Solution
{
    //put any globals here
    static string inputFilename = "small.in";
    static string outputFilename = "small.out";
    static string workingDirectoryPath = "C:\\codejam\\2013\\Round1C\\A\\";

    static string inputFile = workingDirectoryPath + inputFilename;
    static string outputFile = workingDirectoryPath + outputFilename;
    static StreamReader sr = new StreamReader(inputFile);

    public static void Main()
    {
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
        string name = values[0];
        int n = int.Parse(values[1]);
        int length = name.Length;

        int[] start = new int[length];
        int count= 0;

        for (int i = 0; i < length - n +1; i++)
        {
            int good  = 1;
            for (int j = 0; j < n ; j++)
            {
                string comp = name.Substring(i + j, 1);
                if (name.Substring(i+j,1) == "a" || 
                    name.Substring(i+j,1) == "e" ||
                    name.Substring(i+j,1) == "i" ||
                    name.Substring(i+j,1) == "o"  ||
                        name.Substring(i+j,1) == "u" ) 
                {
                    good = 0;
                }
            }
            if (good == 1)
            {
                start[count] = i;
                count++;
            }
        }
        Int64 numStrings = 0;
        if (count > 0)
        {
            numStrings = numStrings + (start[0] + 1) * (length - start[0] - n + 1);
            for (int i = 1; i < count; i++)
            {
                numStrings = numStrings + (start[i] - start[i - 1]) * (length - start[i] - n + 1);
            }
        }

        answer = answer + numStrings.ToString();


        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c != 0)))
        {
            sw.WriteLine(answer);
        }
    }


}




