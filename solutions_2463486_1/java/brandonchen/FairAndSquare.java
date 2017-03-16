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
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class FairAndSquare {
	static final String mInput = "C-large-1.in"; //C-large-1.in
	static final String mOutput = "C-large-1.out";
	static Vector mVec = new Vector();
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
				String str = String.valueOf(functor(scanner.nextLong(),
													scanner.nextLong())
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
	

	String reverse(String str) {
		return new StringBuffer(str).reverse().toString();
	}
	
	
	
	void createPalindrome(int start, int end) {
		int digilen ;
		int middle;
		String str ;
		for (int i=start ; i <=end; i++) {
			if (i == 1) {
				mVec.add(1);
				mVec.add(4);
				mVec.add(9);
			} else if (i == 2) {
				
			} else {
				long startValue = (long)Math.pow((double)10, (double)(i-1));
				//for (long v = startValue; v < startValue * 10; v++) {
					str = String.valueOf(startValue);
					String ss;
					digilen = str.length();
					if (digilen % 2 == 0) {  //xxxx case
						middle = digilen / 2;
						long left = (long)Math.pow((double)10, (double)(middle-1));
						//long left =  10^ (digilen / 2 - 1);
						for (long j = left ; j <left * 10; j++ ) {
							ss= String.valueOf(j) + reverse(String.valueOf(j));	
							//log(ss);
							double d = Math.sqrt(Double.valueOf(ss));
							long ld = (long)d;
							if (ld - d == 0 && isPalindrome(d) == true)
								mVec.add(ss);
						}
						
					} else {  //xxPxx case
						middle = digilen / 2;
						long left = (long)Math.pow((double)10, (double)(middle-1));
						for (int j = 0 ; j < 10; j++) {
							for (long k = left; k < left*10; k++) {
								ss= String.valueOf(k) + String.valueOf(j) + reverse(String.valueOf(k));
								//log(ss);
//								vec.add(ss);
								double d = Math.sqrt(Double.valueOf(ss));
								long ld = (long)d;
								if (ld - d == 0 && isPalindrome(d) == true)
									mVec.add(ss);
								//if (isPalindrome(Math.sqrt(Double.valueOf(ss))) == true)
//									vec.add(ss);
							}
						}
						
					}
				//}
			}
		}
		///Collections.sort(mVec);
		
		log("start count="+mVec.size());
		for (int i = 0; i < mVec.size(); i++) {
				log(mVec.get(i));
		}
		
		log("end");
		//logArr(vec);
	}
/*	public String functor(double d1, double d2) {
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
	}*/
	
	public String functor (long start, long end) {
		int startIdx =0;
		int endIdx=0;
		int count = 0;
		for (int i = 0 ; i < mVec.size(); i++) {
			long ld = Long.parseLong(mVec.get(i).toString());
	/*		if (start < ld)
				startIdx = i;
			if (end < ld)
				endIdx = i;
			*/
			if (ld >= start && ld <= end) {
				log("start:"+start);
				log("end:"+end);
				log("ld:"+ld);
				count++;
				log("count:"+count);
			}
		}
		
		return String.valueOf(count);
	}
	public static void main(String[] args) {
		
		
		FairAndSquare fb= new FairAndSquare();
		
		System.out.println("=== start testing == ");
		fb.createPalindrome(1, 14);
		fb.ioReadAndRun();
		fb.ioWrite();
		System.out.println("=== end testing == ");
	}

}

