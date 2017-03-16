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
        Scanner sc = new Scanner(new File("A-small-attempt2.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("out.txt")));
//        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("in.txt"));
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int W = sc.nextInt();
            int min = (R-1)*((int)(C/W));
            if(C%W==0){
                min += ((int)(C/W)-1)+(W-1)+1;
            }else{
                min += ((int)(C/W))+(W-1)+1;
            }
            
            System.out.println("Case #" + (i + 1) + ": " + min);
            bw.write("Case #" + (i + 1) + ": " + min);
            bw.newLine();
        }
        bw.close();
    }
}
