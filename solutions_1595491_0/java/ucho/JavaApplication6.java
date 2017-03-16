/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication6;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author ucho
 */
public class JavaApplication6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            int googlers = scanner.nextInt();
            int sup = scanner.nextInt();
            int passingScore = scanner.nextInt();
            int ok = 0;
            int conditionalOk = 0;
            for(int g = 0;g<googlers;g++) {
                int score = scanner.nextInt();
                if (score >= passingScore) {
                    if ((score + 2) / 3 >= passingScore) {
                        ok++;
                    } else {
                        if ((score + 4) / 3 >= passingScore) {
                            conditionalOk++;
                        }
                    }
                }
            }
            String msg = "Case #"+(t+1)+": "+(ok+Math.min(conditionalOk, sup));
            System.out.println(msg);
            writer.println(msg);
            scanner.nextLine();
        }
        writer.close();
    }
}
