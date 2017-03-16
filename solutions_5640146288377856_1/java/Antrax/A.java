/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CodeJam20153A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Andres
 */
public class A {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("out.txt")));
//        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("in.txt"));
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            long N = sc.nextLong();

            System.out.println("Case #" + (i + 1) + ": " + N);
            bw.write("Case #" + (i + 1) + ": " + N);
            bw.newLine();
        }
        bw.close();
    }
}
