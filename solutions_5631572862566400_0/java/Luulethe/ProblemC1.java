package com.google.round1a2016;

import java.io.*;
import java.util.*;

/**
 * Created by luult on 4/9/2016.
 */
public class ProblemC1
{
    static String inputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\C-small-attempt0.in";
    static String outputPath = "D:\\contest\\trainning\\round1a2016\\src\\main\\resources\\C-small-attempt0.out";

    static Scanner in;
    static BufferedWriter bw;
    static int numberTest;


    static Integer n;
    static int[] bff = new int[1001];
    static Map<Integer, List<Integer>> bffReverse = new HashMap<Integer, List<Integer>>();
    static int[] currentIndex = new int[1001];
    static boolean[] joined = new boolean[1001];
    static int min = 0;
    static boolean ok = true;

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
        for (int i = 0; i < n; i++)
        {
            Integer x = in.nextInt();
            bff[i] = x - 1;
            if (bffReverse.get(x) == null)
            {
                List<Integer> integerList = new ArrayList<Integer>();
                integerList.add(i);
                bffReverse.put(x, integerList);
            }
            else
            {
                bffReverse.get(x).add(i);
            }
        }
    }


    private static void process()
    {
        min = 1;
        ok = false;
        for (int i = 0; i < n; i++)
        {
            joined[i] = false;
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (ok) return;
                currentIndex[0] = j;
                joined[j] = true;
                tryCreate(1, i);
                joined[j] = false;
            }
        }
    }

    private static void tryCreate(int i, int m)
    {
        if (ok)
        {
            return;
        }
        if (i == m)
        {
            if (check(m))
            {
                min = m;
                ok = true;
            }
        }
        for (int j = 0; j < n; j++)
            if (!joined[j])
            {
                currentIndex[i] = j;
                joined[j] = true;
                tryCreate(i + 1, m);
                joined[j] = false;

            }
    }

    private static boolean check(int m)
    {
        for (int i = 0; i < m; i++)
        {
            int x = currentIndex[i];
            int left = (i + m - 1) % m;
            int right = (i + 1) % m;
            if (bff[x] != currentIndex[left] && bff[x] != currentIndex[right])
            {
                return false;
            }

        }
        return true;
    }

    private static void writeOutput(int i) throws IOException
    {
        String result = "Case #" + (i + 1) + ": " + min + "\n";
        bw.write(result);
    }
}
