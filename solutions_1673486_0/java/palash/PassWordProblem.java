package com.afarok.google.codejam2012.firstround;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class PassWordProblem {
    public static void main(String[] ags) throws FileNotFoundException {
System.setIn(new FileInputStream("src/com/afarok/google/codejam2012/firstround/A-small-attempt0.in"));
System.setOut(new PrintStream(new File("src/com/afarok/google/codejam2012/firstround/A-small-attempt0.out")));

        Scanner stdIN = new Scanner(System.in);
        int t = stdIN.nextInt();
        stdIN.nextLine();
        
        for(int tCase = 1; tCase<=t;++tCase) {
            int a = stdIN.nextInt();
            int b = stdIN.nextInt();
            double[] probability = new double[a];
            for(int i=0;i<a;++i) {
                probability[i] = stdIN.nextDouble();
            }
            
            
            printExpectedKeyStroke(tCase, a, b, probability);
        }
    }
    
    public static void printExpectedKeyStroke(int caseno,int a, int b, double[] probability) {
        double minExpecTEdProb = b*2;
        for(int nObspace  = 0; nObspace<=a;++nObspace) {
            int d = a - nObspace;
            double totalRightPartProbPart1 = 1;
            for(int i=0;i<d;++i) {
                totalRightPartProbPart1*=probability[i];
            }
            
            
            double totalWrongPartProbPart2 = 1-totalRightPartProbPart1;
            
            
            int keyStrokeForRightProb = 2*nObspace + b-a+1;
            int keyStrokeForeWrongProb = keyStrokeForRightProb + b+1;
            
            double expecTedProb = keyStrokeForRightProb*totalRightPartProbPart1 + keyStrokeForeWrongProb * totalWrongPartProbPart2;
            if(expecTedProb<minExpecTEdProb) {
                minExpecTEdProb = expecTedProb;
            }
        }
        
        int keyStrokWhenPressEnterRightAway = 1+b+1;
        
        if(keyStrokWhenPressEnterRightAway<minExpecTEdProb) {
            minExpecTEdProb = keyStrokWhenPressEnterRightAway;
        }
        
        System.out.print("Case #" + caseno + ": ");
        System.out.format("%.6f%n", minExpecTEdProb);
    }
}
