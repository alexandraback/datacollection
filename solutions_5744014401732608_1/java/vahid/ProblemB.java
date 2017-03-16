package com.vahid.codejam.codejam2016.round1c;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String POSSSIBLE = "POSSIBLE";

    public static void main(String[] args) throws IOException {
        Scanner scanner = null;
        BufferedWriter output = null;
        try {
            scanner = new Scanner(new BufferedReader(
                    new FileReader("input.txt")));
            output = new BufferedWriter(new FileWriter("output.txt"));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i=0; i < n; i++){
            int b = scanner.nextInt();
            long m = scanner.nextLong();
            List<String> resList = new ArrayList<>();
            output.write( "Case #"+(i+1)+": " + solve(b,m, resList));
            if (resList.size()>0) {
                for (String str : resList) {
                    output.newLine();
                    output.write( str);
                }
            }
            output.newLine();
        }

        output.close();
    }

    private static String solve(int b, long m, List<String> resList) {
        long max = 1L << (b - 2);
        if (m > max) return IMPOSSIBLE;

        int[][] table = new int[b][b];
        for (int i=0; i<b; i++) {
            for (int j = 0; j<b; j++) {
                table[i][j] = j>i ? 1 : 0; 
            }
        }
        
        int row = b-1;
        while (max - m > 0 ) {
            long ways = 1L << (row-2);
            if ((max - m) >= ways) {
                max -= ways;
                table[row-1][b-1] = 0;
            }
            row--;
        }

        for (int i = 0; i<b ; i++) {
            resList.add(convert(table[i]));
        }

        return POSSSIBLE;
    }

    private static String convert(int[] ints) {
        String response ="";
        for (int i : ints) {
            response += i;
        }
        return response;
    }

}
