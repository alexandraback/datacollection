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
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class test1 {
	//static final String mInput = "myinput.txt";
	static final String mInput = "A-small-attempt0.in";
//	static final String mInput = "A-large-attempt0.in";
	static final String mOutput = "a.out";
	HashMap map = new HashMap();
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
		log("====");
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
				String s =scanner.next();
				int cnt =scanner.nextInt();
				String str = String.valueOf(functor(s,cnt 
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
	
	String vow = "aeiou";
    boolean check(String str, int k) {
        int n = str.length();
        boolean flag = false;
        for (int i=0; i+k<=n; i++) {
        	flag = true;
            for (int j=0; j<k; j++) {
                char c = str.charAt(i+j);
                if(vow.contains(String.valueOf(c))){
                    flag = false;
                    break;
                }
            }
            if (flag==true)
            	return true;
        }
        return false;
    }
    

	public int functor(String str, int num) {
	     int n = str.length();
        
        int cnt = 0;
        for (int i=0; i<n; i++)
        	for (int j=i; j<n; j++) {
        		if (check(str.substring(i, j+1), num))
        			cnt++;
        }
        return cnt;
	}
		
	public static void main(String[] args) {
		
		test1 o = new test1();
		log("=== start testing == ");
		o.ioReadAndRun();
		o.ioWrite();
		log("=== end testing == ");
	}

}

