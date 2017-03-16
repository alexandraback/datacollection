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
public class C {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("C-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("out.txt")));
//        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("in.txt"));
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int C = sc.nextInt();
            int D = sc.nextInt();
            long V = sc.nextLong();
            long den[] = new long[D];
            for (int j = 0; j < D; j++) {
                den[j] = sc.nextLong();
            }
            long maxV = 0;
            int denAdded = 0;
            int j = 0;
            while(maxV < V){
                if(j < den.length) {
                    if(maxV < den[j]-1){
                        denAdded++;
                        maxV += (maxV+1)*C;
                    }else{
                        maxV += den[j]*C;
                        j++;
                    }
                }else {
                    denAdded++;
                    maxV += (maxV+1)*C;
                }
//                System.out.println(maxV);
            }
            
            System.out.println("Case #" + (i + 1) + ": " + denAdded);
            bw.write("Case #" + (i + 1) + ": " + denAdded);
            bw.newLine();
        }
        bw.close();
    }
}
