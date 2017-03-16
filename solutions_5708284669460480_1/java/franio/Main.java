package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Main {

    public static String name = "B-large";
    public static String inputData = name + ".in";
    public static String outputData = name + ".out";
    public static int numberOfTestCases;

    public static void main(String[] args) throws IOException {
        FileReader fileReader = new FileReader(inputData);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        PrintWriter writer = new PrintWriter(outputData, "UTF-8");
        numberOfTestCases = Integer.parseInt(bufferedReader.readLine());

        for(int i = 0; i < numberOfTestCases; i++) {
            //////////////////first line
            String[] split = bufferedReader.readLine().split(" ");
            int k = Integer.parseInt(split[0]);
            int l = Integer.parseInt(split[1]);
            int s = Integer.parseInt(split[2]);
            String keyboard = bufferedReader.readLine();
            String goal = bufferedReader.readLine();


            writeLine(i+1, Double.toString(calc(k, l, s, keyboard, goal)), writer);
        }

        fileReader.close();
        bufferedReader.close();
        writer.close();
    }

    private static double calc(int k, int l, int s, String keyboard, String goal) {
        int[] decodedKeyboard = decodeKeyboard(keyboard);
        if(notPossible(goal, decodedKeyboard)){
            return 0;
        }
        if(s < l) return 0;
        int delay = maxBananas(goal);
        double m = (int)Math.floor((s - goal.length())/delay) + 1;
        double avgG = avarageGiven(decodedKeyboard, goal, s, delay, k);
        return m - avgG;
    }

    private static double avarageGiven(int[] decodedKeyboard, String goal, int s, int delay, int k) {

        double pOfWord = pfWord(decodedKeyboard, goal, k);
        return (s+ 1 - goal.length()) * pOfWord;

    }

    private static double pfWord(int[] decodedKeyboard, String goal, int k) {
        double p = 1;
        double kd = new Double(k);

        for(char c : goal.toCharArray()){
           p =  p * (decodedKeyboard[c] /kd);
        }
        return p;
    }

    private static int maxBananas(String goal) {
        int delay =  goal.length();

        for(int i = 1 ; i < goal.length(); i++){
            if(goal.startsWith(goal.substring(i))){
                delay = i;
                break;
            }
        }

        return delay;
    }

    private static boolean notPossible(String goal, int[] decodedKeyboard) {
        for(char c:goal.toCharArray()){
            if(decodedKeyboard[c] == 0){
                return true;
            }
        }
        return false;
    }

    private static int[] decodeKeyboard(String keyboard) {
        int [] tab = new int[91];
        for(char c : keyboard.toCharArray()){
           tab[c]++;
        }
        return tab;
    }
    public static void writeLine(int testCase, String result, PrintWriter printWriter) {
        printWriter.println("Case #" + testCase + ": " + result);
    }




}
