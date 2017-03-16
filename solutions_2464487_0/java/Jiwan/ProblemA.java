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
public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
		new ProblemA().run();
		System.out.println("END");
	}
	
	private void run() throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream(new File("/home/mosaick/sample-in.txt")));
		PrintWriter out = new PrintWriter(new FileOutputStream("/home/mosaick/sample-out.txt"));
		
		int T = in.nextInt();
		
		for (int c = 1; c <= T; c++) {
			
			long r = in.nextLong();
			long t = in.nextLong();
			
			long y = -1;
			for (long n = 1; ; n++) {
				long res = 2 * n * n + (2 * r - 1) * n;
				if (res > t) {
					break;
				} else {
					y = n;
				}
			}
			out.println("Case #" + c +": " + y);
		}
		out.flush();
	}
}
