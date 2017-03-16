package com.google.round1c;

import java.io.*;
import java.util.Scanner;

/**
 * Created by luult on 4/9/2016.
 */
public class ProblemB
{
    static String inputPath = "D:\\contest\\trainning\\round1c\\src\\main\\java\\com\\google\\round1c\\B-small-attempt1.in";
    static String outputPath = "D:\\contest\\trainning\\round1c\\src\\main\\java\\com\\google\\round1c\\b.out";
    static Scanner in;
    static BufferedWriter bw;
    static int numberTest;


    static long n, m;
    static int b;
    static String s = "";
    static long[] d = new long[55];
    static String result = "";
    static int[][] a;

    public static void main(String[] args) throws IOException
    {
        init();

        bw = new BufferedWriter(new FileWriter(outputPath));
        in = new Scanner(new BufferedReader(new FileReader(inputPath)));

        numberTest = in.nextInt();
        for (int i = 0; i < numberTest; i++)
        {
            System.out.println("test :" + (i + 1));
            readInput();
            process();
            writeOutput(i);
        }

        bw.close();
    }

    private static void init()
    {
        d[0] = 1;
        d[1] = 1;
        for (int i = 2; i < 51; i++)
        {
            d[i] = d[i - 1] * 2;
            System.out.println(d[i]);
        }
    }

    private static void readInput()
    {
        b = in.nextInt();
        m = in.nextInt();
        a = new int[51][51];
        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
            {
                a[i][j] = 0;
            }
        {

        }
        for (int i = 0; i < b - 1; i++)
            for (int j = i + 1; j < b - 1; j++)
            {
                a[i][j] = 1;
            }
        System.out.println();
    }


    private static void process()
    {
        if (m > d[b - 1])
        {
            result = "IMPOSSIBLE";
            return;
        }
        result = "POSSIBLE";
        for (int i = b - 2; i >= 0; i--)
            if (m >= d[i])
            {
                a[i][b-1] = 1;
                m = m - d[i];
            }
    }


    private static void writeOutput(int i) throws IOException
    {
        String result1 = "Case #" + (i + 1) + ": " + result + "\n";
        bw.write(result1);
        if (result.equals("POSSIBLE"))
        {
            for (int j = 0; j < b; j++)
            {
                for (int k = 0; k < b; k++)
                {
                    bw.write("" + a[j][k]);
                }
                bw.write("\n");
            }
        }
    }
}
