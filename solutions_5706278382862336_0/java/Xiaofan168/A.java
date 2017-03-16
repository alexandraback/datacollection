package com.my.algo.gcj2014.r1c;

import java.util.*;
import java.io.*;

public class A {
    final static String PROBLEM_NAME = "A";
    final static String WORK_DIR = "D:\\GCJ\\2014\\r1c\\" + PROBLEM_NAME + "\\";
    final static String INPUT_FILE = "A-small-attempt2.in";
//    final static String INPUT_FILE = "in.txt";

    void solve(Scanner sc, PrintWriter pw) {
       	String s = sc.next();
    	String[] sArray = s.split("/");
    	long p = Long.parseLong(sArray[0]);
    	long q = Long.parseLong(sArray[1]);

    	int counter = 0;
    	boolean reachedFirstAnswer = false;
    	
    	for (int genCounter = 0; genCounter < 40; genCounter++){
    		p = p * 2;
    		
    		if(p == q){
    			counter++;
    			reachedFirstAnswer = true;
    			break;
    		}
    		
    		if(p > q){
    			reachedFirstAnswer = true;
    			p = p - q;
    		}
    		
    		if(!reachedFirstAnswer){
    			counter++;
    		}
    	}
    	
    	System.out.println("40 gen ago: " + p + "/" + q);
    	if(p != q){
    		System.out.println("impossible");
    		pw.println("impossible");
    	} else {
			System.out.println(counter);
			pw.println(counter);
    	}
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + INPUT_FILE));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new A().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}