package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Main {

    public static String name = "A-large";
    public static String inputData = name + ".in";
    public static String outputData = name + ".out";
    public static int numberOfTestCases;

    public static void main(String[] args) throws IOException {
        FileReader fileReader = new FileReader(inputData);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        PrintWriter writer = new PrintWriter(outputData, "UTF-8");
        numberOfTestCases = Integer.parseInt(bufferedReader.readLine());

        for(int i = 0; i < numberOfTestCases; i++) {

            writeLine(i+1, calc(bufferedReader), writer);
        }

        fileReader.close();
        bufferedReader.close();
        writer.close();
    }


    public static void writeLine(int testCase, String result, PrintWriter printWriter) {
        printWriter.println("Case #" + testCase + ": " + result);
    }



         public static String calc(BufferedReader br) throws IOException{
            String line = br.readLine();
            String[] splitted = line.split(" ");
            int r = Integer.parseInt(splitted[0]);
            int c = Integer.parseInt(splitted[1]);
            int w = Integer.parseInt(splitted[2]);

             if(w == 1) return Integer.toString(c*r);

             int base = (int) (r * Math.floor(c/w)) + w;
             if(c%w == 0) base--;
            return Integer.toString(base);
        }


}
