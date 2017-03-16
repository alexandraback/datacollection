/*
 * @(#)ProblemA.java $version 2013. 4. 27.
 *
 * Copyright 2007 NHN Corp. All rights Reserved. 
 * NHN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package main.java.codejam.y2013.r1a;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author 정지완
 * @version $Rev$ $Date$
 */
public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
		new ProblemB().run();
		System.out.println("END");
	}
	
	int initEnergy, r, n;
	int[] V;
	int maxSum;
	
	private void run() throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream(new File("/home/mosaick/sample-in.txt")));
		PrintWriter out = new PrintWriter(new FileOutputStream("/home/mosaick/sample-out.txt"));
		
		int T = in.nextInt();
		
		for (int c = 1; c <= T; c++) {
			initEnergy = in.nextInt();
			r = in.nextInt();
			n = in.nextInt();
			V = new int[n];
			for (int i = 0; i < n; i++) {
				V[i] = in.nextInt();
			}
			maxSum = -1;
			getMax(0, initEnergy, 0);
			
			out.println("Case #" + c +": " + maxSum);
		}
		out.flush();
	}

	private void getMax(int i, int energy, int sum) {
		if (i == n) {
			maxSum = Math.max(sum, maxSum);
			return;
		}
		
		for (int e = 0; e <= energy; e++) {
			int nextEnergy = Math.min(energy - e + r, initEnergy);
			getMax(i + 1, nextEnergy, sum + V[i]*e);
		}
	}
}
