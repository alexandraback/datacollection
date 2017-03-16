package com.google.codejam;

import hu.mapro.jam.commons.Problem;

import java.util.Scanner;

/**
 *  Using <a href="http://code.google.com/p/maprohu-codejam-lib/">Google Code Jam library</a>. 
 */
public class FairAndSquare extends Problem {

	public FairAndSquare() {
		super("C", false);
	}

	private final static boolean pal(long n) {
		String s = Long.toString(n);
		int l = s.length();
		for (int i=0;i<l/2;i++) {
			if (s.charAt(i)!=s.charAt(l-i-1)) return false;
		}
		return true;
	}
	
	@Override
	protected String solve(Scanner in) {
		long A = in.nextLong();
		long B = in.nextLong();
			
		long n = (long) Math.sqrt(A);
		
		long c = 0;
		
		while (true) {
			long nsq = n*n;
			
			if (nsq >= A) {
				
				if (nsq>B) break;
				
				if (pal(n) && pal(nsq)) c++;
				
			}
			n++;
		}
		
		return Long.toString(c);
	}

}
