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
import java.util.ArrayList;
import java.util.LinkedList;

/**
 *
 * @author JLH
 */
public class C {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        new C();
    }

    public C() throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0(1).in"));

        int cases = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < cases; i++) {
            int n = Integer.parseInt(br.readLine().trim());
            ArrayList<String> words = new ArrayList<String>();

            for (int j = 0; j < n; j++) {
                words.add(br.readLine().trim());
            }

            System.out.println(String.format("Case #%d: %s", i + 1, solve(words)));
        }
    }

    public String solve(ArrayList<String> words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            String[] s1 = words.get(i).split(" ");
            String w1p1 = s1[0];
            String w1p2 = s1[1];
            boolean containsFirst = false;
            boolean containsSecond = false;
            for (int j = 0; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }
                String[] s2 = words.get(j).split(" ");
                String w2p1 = s2[0];
                String w2p2 = s2[1];
                if (w1p1.equals(w2p1)){
                    containsFirst = true;
                }
                if (w1p2.equals(w2p2)){
                    containsSecond = true;
                }

                if (containsFirst && containsSecond)
                {
                    count++;
                    break;
                }
            }
        }
        return "" + count;
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
