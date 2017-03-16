package com.google.codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

//import org.apache.commons.io.output.TeeOutputStream;

public class War {

	public static void main (String[] args) throws Exception {
		
//		FileOutputStream fos=	new FileOutputStream (new File ("/Users/dongcaishen/0411/D.out"));
//		TeeOutputStream tee=	new TeeOutputStream (System.out, fos);
//		PrintStream ps=	new PrintStream (tee);
//		System.setOut (ps);

//		Scanner scanner=	new Scanner (new BufferedReader (new FileReader ("/Users/dongcaishen/0411/D-large.in")));
		Scanner scanner=	new Scanner (System.in);
		int nTests=	scanner.nextInt ();
		for (int iTest=	1; iTest <= nTests; ++iTest) {
			System.out.print ("Case #" + iTest + ": ");
			int n=	scanner.nextInt ();
			double a[]=	new double[n];
			double b[]=	new double[n];
			for (int i=	0; i < n; ++i) a[i]=	scanner.nextDouble ();
			for (int i=	0; i < n; ++i) b[i]=	scanner.nextDouble ();
			Arrays.sort (a);
			Arrays.sort (b);
			int i, j;
			int war=	0;
			for (i=j=	n - 1; j >= 0 && i >= 0; --i, --j) {
				for (; i >= 0 && a[i] > b[j]; --i);
				if (i >= 0) ++war;	// Ken scores 1 pt w/ his unique optimal strategy
			}
			int dwar=	0;
			for (i=j=	n - 1; j >= 0 && i >= 0; --i, --j) {
				for (; j >= 0 && a[i] < b[j]; --j);
				if (j >= 0) ++dwar;	// Naomi scores 1 pt by deceiving Ken
			}			
			System.out.println (dwar + " " + (n - war));
		}
		scanner.close ();
		
//		fos.close ();
//		ps.close ();
	}

}
