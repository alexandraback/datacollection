package jam;

import java.io.*;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static String inputfile = "qual_b.in";
    static String outputfile = "qual_b.out";
    static String answer;
    static BufferedWriter writer;
    static Scanner scanner;

    public static void writeAnswer(int caseNum) throws Exception {
        System.out.println("Case #" + caseNum + ": " + answer);
        writer.write("Case #" + caseNum + ": " + answer);
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(inputfile));
        writer = new BufferedWriter(new FileWriter(outputfile));

        //Case loop:
        int numCases = scanner.nextInt();
        for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            answer = "";
            solve();
            writeAnswer(caseNum);
        }

        //Cleanup:
        scanner.close();
        writer.close();
    }

    public static void solve() {
        // get input from scanner
        // write answer to answer
        int numDiners = scanner.nextInt();
        int[] diners = new int[numDiners];
        int maxHeight = 0;

        for(int i = 0; i < numDiners; i++) {
            diners[i] = scanner.nextInt();
            if(diners[i] > maxHeight) maxHeight = diners[i];
        }

        int bestTime = maxHeight;

        for(int i = 1; i < maxHeight; i++) {
            bestTime = getNumSpecialRequired(diners, i, bestTime);
        }

        answer = String.valueOf(bestTime);
    }

    public static int getNumSpecialRequired(int[] diners, int height, int bestTime) {
        int result = height;
        for(int i = 0; i < diners.length; i++) {
            result += divide(diners[i], height);
            if(result >= bestTime) return bestTime;
        }
        return result;
    }

    public static int divide(int a, int b) {
        if(a <= b) return 0;
        return (a-1)/b;
    }
}

