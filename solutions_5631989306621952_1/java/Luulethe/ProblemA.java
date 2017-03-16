package com.google.round1a2016;

import java.io.*;
import java.util.Scanner;

/**
 * Created by luult on 4/9/2016.
 */
public class ProblemA
{
    static String inputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\A-large.in";
    static String outputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\testa1.out";

    static Scanner in;
    static BufferedWriter bw;
    static int numberTest;


    static Integer n;
    static String s;
    static String result = "";

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
        s = in.next();
        System.out.printf(s);
    }


    private static void process()
    {
        result = s.charAt(0) + "";
        for (int i = 1; i < s.length(); i++)
        {
            if (result.charAt(0) > s.charAt(i))
            {
                result += s.charAt(i);
            }
            else
            {
                result = s.charAt(i) + result;
            }
        }
    }

    private static void writeOutput(int i) throws IOException
    {
        String result1 = "Case #" + (i + 1) + ": " + result + "\n";
        bw.write(result1);
    }
}
