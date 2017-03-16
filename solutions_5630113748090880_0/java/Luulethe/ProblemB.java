package com.google.round1a2016;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by luult on 4/9/2016.
 */
public class ProblemB
{
    static String inputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\B-small-attempt2.in";
    static String outputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\B-small-attempt3.out";

    static Scanner in;
    static BufferedWriter bw;
    static int numberTest;


    static Integer n;
    static int[] numberApper = new int[2500];
    static List<Integer> result = new ArrayList();

    public static void main(String[] args) throws IOException
    {
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

    private static void readInput()
    {
        n = in.nextInt();
        for (int i = 0; i < 2500; i++)
        {
            numberApper[i] = 0;
        }
        for (int i = 0; i < 2 * n - 1; i++)
        {
            int pre = 0;
            for (int j = 0; j < n; j++)
            {
                int x = in.nextInt();
                if (x == pre)
                {
                    System.out.println("-----------------------------");
                }
                pre = x;
                numberApper[x]++;
            }
        }
    }


    private static void process()
    {
        result = new ArrayList();
        for (int i = 0; i < 2500; i++)
            if (numberApper[i] > 0 && numberApper[i] % 2 == 1)
            {
                result.add(i);
            }
    }

    private static void writeOutput(int i) throws IOException
    {
        String list = "";
        for (Integer s : result)
            list += s + " ";
        String result1 = "Case #" + (i + 1) + ": " + list + "\n";
        bw.write(result1);
    }
}
