/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.demister.gcj;


import java.util.*;
import java.io.*;


/**
 *
 * @author rock
 */
public class SafetyInNumbers {

    public SafetyInNumbers() {
    }
    
    public double[] getSafety(int[] judges) {
        double sum = 0;
        for (int i : judges) {
            sum += i;
        }
        
        double average = 2 * sum / judges.length;
        
        double[] reval = new double[judges.length];
        double newSum = 0;
        int newCount = 0;
        Arrays.fill(reval, -1);
        for (int i = 0; i < reval.length; i++) {
            if (judges[i] < average) {
                newSum += judges[i];
                newCount++;
            } else {
                reval[i] = 0;
            }
        }
        newSum += sum;
        double newAverage = newSum / newCount;
        for (int i = 0; i < reval.length; i++) {
            if (reval[i] < 0) {
                reval[i] = (newAverage - judges[i]) / sum * 100;
            }
            
        }
        return reval;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        SafetyInNumbers dealer = new SafetyInNumbers();

        int numOfTests = in.nextInt();

        for (int i = 0; i < numOfTests; i++) {
            out.printf("Case #%d: ", i + 1);

            int cs = in.nextInt();
            int[] judges = new int[cs];
            for (int j = 0; j < judges.length; j++) {
                judges[j] = in.nextInt();
            }

            double[] safe = dealer.getSafety(judges);
            for (int j = 0; j < safe.length; j++) {
                out.print(safe[j] + " ");
            }

            out.println();
            out.flush();
        }

        in.close();
        out.close();
    }
}
