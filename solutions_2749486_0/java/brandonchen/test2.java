package br.src.codejam;
/*
 * CodeJam
 * Author: Brandon Chen
 * Date: 2013/05/04
 */

import java.io.File;

import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class test2 {
	//static final String mInput = "myinput.txt";
	static final String mInput = "B-small-attempt0.in";
//	static final String mInput = "B-large-attempt0.in";
	static final String mOutput = "a.out";
	
	StringBuilder mSb = new StringBuilder();
	
	static void log (Object o) {
		if (o == null)
			return;
		System.out.println(o.toString());
	}
	
	static void logn (Object o) {
		if (o == null)
			return;
		System.out.print(o.toString());
	}
	
	static void logArr (Object ...o) {
		if (o == null || o.length == 0)
			return;
		System.out.println(Arrays.deepToString(o));
	}
	void logMatrix(int[][] m , int r, int c)
	{
		for (int i = 0; i < r; i++) {
			for (int j  =0; j < c; j++) {
				logn(m[i][j] +" ");
			}
			log(" ");
		}
		
	}
	void logMatrix(boolean[][] m , int r, int c)
	{
		for (int i = 0; i < r; i++) {
			for (int j  =0; j < c; j++) {
				logn(m[i][j] +" ");
			}
			log(" ");
		}
		
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
				int x =scanner.nextInt();
				int y =scanner.nextInt();
				String str = String.valueOf(functor(x,y
						));
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
	StringBuilder sb ;
    int[] mem= new int[1414];
    static int cs = 1;
   
	public String functor(int x, int y) {
		log(x+"_"+y);
		/*
		int sum = 0;
		int i = 0;
		while (sum < 1000000) {
			sum += (i+1);
			mem[i]=sum;
			i++;
		}
		int diff;
		for (i =0;i<1414;i++) {
			diff =Math.abs(x) - mem[i];
			if (diff < 0) {
				if(diff == 0) {
					cs=i+1;
					for (int j=0;j<i; j++) {
						if (x>=0) {
							sb.append("E");
						} else {
							sb.append("W");
						}
					}
				} else {
					for (int j = 0 ; j < diff; j++) {
						if (x>0)
							sb.append("WE");
						else
							sb.append("EW");
						
					}
				}
				break;
			}
		}
		
		*/
		
		sb= new StringBuilder();
		for (int i =0;i<Math.abs(x); i++) {
			if (x > 0) 
				sb.append("WE");
			else if (x<0)
				sb.append("EW");
		}
		
		for (int i =0; i<Math.abs(y); i++) {
			if (y > 0) 
				sb.append("SN");
			else if (y<0)
				sb.append("NS");
		}
		
		
        return sb.toString();
	}
		
	public static void main(String[] args) {
		
		test2 o = new test2();
		log("=== start testing == ");
		o.ioReadAndRun();
		o.ioWrite();
		log("=== end testing == ");
	}

}

