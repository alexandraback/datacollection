/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamb;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author JLH
 */
public class B {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        new B();
    }

    public B() throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0(1).in"));

        int cases = Integer.parseInt(br.readLine().trim());

        PrintWriter pw = new PrintWriter("out.txt");
        for (int i = 0; i < cases; i++) {
            String line = br.readLine().trim();

            pw.println(String.format("Case #%d: %s", i + 1, solve(line)));
        }
        pw.close();
    }

    public String solve(String line) {
        if (line.contains("?")) {
            int pos = line.indexOf("?");

            String best1 = "0";
            String best2 = "0";
            int minDifference = Integer.MAX_VALUE;
            for (int i = 0; i <= 9; i++) {
                String newS = line.substring(0, pos) + i + line.substring(pos + 1);
//                System.out.println(newS);
                String[] s = solve(newS).split(" ");
                String i1 = (s[0]);
                String i2 = (s[1]);

                int diff = Math.abs(Integer.parseInt(i1) - Integer.parseInt(i2));

                if (diff < minDifference) {
                    minDifference = diff;
                    best1 = i1;
                    best2 = i2;
                } else if (diff == minDifference) {
                    if (Integer.parseInt(i1) < Integer.parseInt(best1)) {
                        best1 = i1;
                        best2 = i2;
                    } else if (Integer.parseInt(i1) == Integer.parseInt(best1) && Integer.parseInt(i2) < Integer.parseInt(best2)){
                        best2 = i2;
                    }
                }
            }
            return best1 + " " + best2;
        } else {
            return line;
        }
    }

    public static void printIntMatrix(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            String s = "";
            for (int col = 0; col < matrix[0].length; col++) {
                s += matrix[row][col] + " ";
            }
            System.out.println(s);
        }

    }

    public static void printCharMatrix(char[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            String s = "";
            for (int col = 0; col < matrix[0].length; col++) {
                s += matrix[row][col] + " ";
            }
            System.out.println(s);
        }
    }
}
