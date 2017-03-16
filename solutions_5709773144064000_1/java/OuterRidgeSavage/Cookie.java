package com.google.codejam2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Cookie {

	public static void main (String[] args) throws Exception {

//		Scanner scanner=	new Scanner (new BufferedReader(
//				new FileReader ("/Users/dongcaishen/0411/B-large.in")));
		Scanner scanner=	new Scanner (System.in);	
//		PrintWriter pw=	new PrintWriter (new FileWriter ("/Users/dongcaishen/0411/B-large.out"));
		int nTests=	scanner.nextInt ();
		for (int iTest=	1; iTest <= nTests; ++iTest) {
			System.out.print ("Case #" + iTest + ": ");
//			pw.print ("Case #" + iTest + ": ");
			double C=	scanner.nextDouble ();
			double F=	scanner.nextDouble ();
			double y=	scanner.nextDouble ();
			int k=	(int)(y / C - 2 / F + 1e-8);
			k=	(k < 0) ? 0 : k;
//			System.out.println ("k=" + k);
			double x=	y / (2 + k * F);
			double den=	2;
			for (int i=	0; i < k; ++i) {
				x+=	C / den;	
				den+=	F;		
			}
			System.out.format("%.7f\n", x);
//			pw.format("%.7f\n", x);
		}
		scanner.close ();
//		pw.close ();
	}

}
