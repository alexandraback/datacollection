package br.src.codejam;
/*
 * CodeJam
 * Author: Brandon Chen
 * Date: 2013/4/13
 * Question: TicTacToe-Tomek
 */

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class TicTacToe {
	//static final String mInput = "Tic-Tac-Toe-Tomek.in";
	static final String mInput = "A-large.in";
	static final String mOutput = "A-large.out";
	
	//static final String mInput = "A-big-attempt0.in";
	//static final String mOutput = "A-big-attempt0.out";
	
	StringBuilder mSb = new StringBuilder();
	
	static void log (Object o) {
		if (o == null)
			return;
	///	System.out.println(o.toString());
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
				String str = String.valueOf(functor(scanner.next(),
						scanner.next(),
						scanner.next(),
						scanner.next())
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

	
	public String functor(String r1, String r2, String r3, String r4) {
		log(r1);
		log(r2);
		log(r3);
		log(r4);
		String xwin = "X won";
		String owin = "O won";
		String notCompleted = "Game has not completed";
		String draw = "Draw";
		char[] c1 = r1.toCharArray();
		char[] c2 = r2.toCharArray();
		char[] c3 = r3.toCharArray();
		char[] c4 = r4.toCharArray();
		
		
		int sum = 0;
		int XwinSum = 'X' +'X'+'X'+'T';
		int XwinSum1 = 'X' +'X'+'X'+'X';
		int OwinSum = 'O' +'O'+'O'+'T';
		int OwinSum1 = 'O' +'O'+'O'+'O';
		

		Vector vec = new Vector();
		vec.add(c1);
		vec.add(c2);
		vec.add(c3);
		vec.add(c4);
		
		for (int i = 0 ; i < 4; i++) {
			//check columns
			sum= c1[i]+c2[i]+c3[i]+c4[i];
			if (sum ==XwinSum || sum== XwinSum1) {
				log(0);
				return xwin;
			}
			if (sum ==OwinSum || sum== OwinSum1) {
				log(1);
				return owin;
			}
		}
		
		char[] tmp;
		for (int i = 0; i < vec.size(); i++) {
			tmp = (char[])vec.get(i);
			sum = 0;
			//check rows
			for (int j =0; j < 4; j++) {
				sum +=tmp[j];		
				log("row sum="+sum);
			}
			if (sum ==XwinSum || sum== XwinSum1) {
				log(2);
				return xwin;
			}
			if (sum ==OwinSum || sum== OwinSum1) {
				log(3);
				return owin;
			}
			
		}


		//diagnoal
		sum = c1[0] + c2[1] + c3[2] + c4[3];
		if (sum ==XwinSum || sum== XwinSum1) {
			log(4);
			return xwin;
		}
		if (sum ==OwinSum || sum== OwinSum1) {
			log(5);
			return owin;			
		}
		
		sum = c1[3] + c2[2] + c3[1] + c4[0] ;
		if (sum ==XwinSum || sum== XwinSum1) {
			log(6);
			return xwin;
		}
		if (sum ==OwinSum || sum== OwinSum1) {
			log(7);
			return owin;			
		}
		
		if (r1.contains(".")) {
			log(8);
			return notCompleted;
		}
		
		if (r2.contains(".")) {
			log(9);
			return notCompleted;
		}
		
		if (r3.contains(".")) {
			log(10);
			return notCompleted;
		}
		
		if (r4.contains(".")) {
			log(11);
			return notCompleted;
		}
		
		
		return draw;
	}
	public static void main(String[] args) {
		

		TicTacToe fb= new TicTacToe();
		log("=== start testing == ");
		fb.ioReadAndRun();
		fb.ioWrite();
		log("=== end testing == ");
	}

}

