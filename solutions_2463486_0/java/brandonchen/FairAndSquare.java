package br.src.codejam;

/*
 * CodeJam

 * Author: Brandon Chen
 * Date: 2013/4/13
 */

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class FairAndSquare {
	//static final String mInput = "Tic-Tac-Toe-Tomek.in";
	static final String mInput = "C-small-attempt0.in";
	static final String mOutput = "C-small-attempt0.out";
	
	//static final String mInput = "A-big-attempt0.in";
	//static final String mOutput = "A-big-attempt0.out";
	
	StringBuilder mSb = new StringBuilder();
	
	static void log (Object o) {
		if (o == null)
			return;
		System.out.println(o.toString());
	}
	
	static void logArr (Object ...o) {
		if (o == null || o.length == 0)
			return;
		System.out.println(Arrays.deepToString(o));
	}

	void ioReadAndRun() {
		log("start ioReadAndRun");
		try {
			Vector vec = new Vector();
			StringTokenizer st;
			File fp = new File(mInput);
			Scanner scanner = new Scanner(fp);
			int caseCnt = 0;
			if (scanner.hasNext())
				caseCnt = scanner.nextInt();
			for (int i = 0; i < caseCnt; i++) {
				String str = String.valueOf(functor(scanner.nextDouble(),
													scanner.nextDouble())
													);
				System.out.println("Case #"+(i+1)+": "+ str);
				mSb.append("Case #"+(i+1)+": "+ str);
				mSb.append("\n");
			}
		
		} catch (IOException e) {
			System.err.println(e.getMessage() + " case:" + e.getCause());
		}
	}

	void ioWrite() {
		log("start ioWrite");
	    try {	
	    	PrintStream out = new PrintStream(new File(mOutput));
	    	out.println(mSb.toString());
	    	out.close();
	    } catch(IOException e) {
	    	System.err.println(e.getMessage() + " case:" + e.getCause());
	    }
	}

	boolean isPalindrome(double d) {
		String str = String.valueOf((int)d);
		int i = 0;
		char[]  ch = str.toCharArray();
		for (i = 0 ; i < ch.length / 2; i++) {
			if (ch[i] != ch[ch.length -1 - i]) {
				return false;
			}
		}
	
		return true;
	} 
	public String functor(double d1, double d2) {
		int count = 0;
		int sum;
		int s = (int)Math.sqrt(d1);
		if (s * s < d1)
			s++;
		int e = (int)Math.sqrt(d2) ;
		log("d1="+d1 +" s :" + s);
		log("d2="+d2+" e :" + e);
		
		for (int i = s; i <= e; i++) {
			sum = i * i;
			if (isPalindrome(i) == true) {
				if (isPalindrome(sum) == true) {
					count++;
				}
			}
		}
		log(count);
		return String.valueOf(count);
	}
	public static void main(String[] args) {
		double t = 10e100;
		double res = Math.sqrt(t);

		FairAndSquare fb= new FairAndSquare();
		log("=== start testing == ");
		fb.ioReadAndRun();
		fb.ioWrite();
		log("=== end testing == ");
	}

}

