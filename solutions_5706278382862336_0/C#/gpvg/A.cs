using System;
using System.IO;
using System.Collections;
using System.Numerics;
using System.Collections.Generic;

class Solution
{
    //put any globals here#
    //static string inputFilename = "test.in";
    //static string outputFilename = "test.out";
    static string inputFilename = "small.in";
    static string outputFilename = "small.out";
    static string workingDirectoryPath = "C:\\codejam\\2014\\Round1C\\A\\";

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
        string[] values = line.Split('/');
        Int64 top = Int64.Parse(values[0]);
        Int64 bottom = Int64.Parse(values[1]);
        BigInteger tp = new BigInteger(top);
        BigInteger bt = new BigInteger(bottom);
        functions ab = new functions();
        Int64 div = 2;
        Int64[] pt = new Int64[60];
        int gen =60;
        pt[0] = 1;
        for (int i = 1; i < 41; i++)
        {
            pt[i] = pt[i - 1] * 2;
        }
        while (div > 1)
        {
            div = ab.gcd(top, bottom);
            top = top / div;
            bottom = bottom / div;
        }
        tp = top;
        bt = bottom;
        int possible = 1;
        int found = 0;
        while (possible == 1 && found == 0)
        {
            int used = 0;
            for (int i = 1; i < 41; i++)
            {
                BigInteger powerTwo = new BigInteger(0);
                powerTwo = pt[i];
                if (powerTwo * tp > bt || powerTwo * tp == bt)
                {
                    if (gen > 50) gen = i;
                    tp = powerTwo * tp - bt;
                    bt = bt * powerTwo;
                    used = 1;
                    if (tp == 0)
                    {
                        i = 41;
                        found = 1;
                    }
                }
            }
            if (used == 0) possible = 0;
            if (used == 1 && tp > 0) possible = 0;
        }



            if (possible == 0) answer = answer + "impossible";
            if (possible == 1) answer = answer + gen.ToString();
            //write the answer to the output file
            using (StreamWriter sw = new StreamWriter(outputFile, (c != 0)))
            {
                sw.WriteLine(answer);
            }
        }
    }
    class functions
    {
        public Int64 gcd(Int64 a, Int64 b)
        {
            if (b > a)
            {
                Int64 c = b;
                b = a;
                a = c;
            }
            Int64 remainder = 100;
            while (remainder > 0)
            {
                remainder = a % b;
                a = b;
                b = remainder;

            }
            return a;
        }
    }