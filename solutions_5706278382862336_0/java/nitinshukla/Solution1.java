package com.nitin.ofss.codejam4;

import java.io.*;
import java.util.*;


public class Solution1 {
	static FileReader fr;
	static Scanner scan;
	static PrintWriter out;
	static long P,Q;
	public static void main(String[] args) throws IOException {
		initialize();
		int T = scan.nextInt();
		
		for (int i10 = 1; i10 <= T; i10++) {
			String ans="";
			String m = scan.next();
			String[] p = m.split("/");
			//System.out.println(p[0]+"  "+p[1]);
			P=Long.valueOf(p[0]);
			Q = Long.valueOf(p[1]);
			 double pow=isIt2(Q);
			 double pow1=(double)P/Q;
			// System.out.println(pow1);
			if(pow==-1 || P>Q)ans="impossible";
			else{
				for(int i=1;i<20;i++){
					if(pow1<=1/Math.pow(2, i-1) && pow1>=1/Math.pow(2, i)) {ans=String.valueOf(i);break;}
				}
			}
			System.out.printf("Case #%d: %s\n", i10,ans);
			out.printf("Case #%d: %s\n", i10,ans);
		}
		close();
	}

private static double isIt2(double q2) {
	for(int i=0;i<10;i++)
		if(q2==Math.pow(2, i)) return i;
	return -1;
	}

private static int process(long p2, long q2) {
		double a = Math.log(q2)/Math.log(2);
		if(a==(int)a) return 1;
			
	return 1;
	}

public static void initialize() throws FileNotFoundException{
	fr = new FileReader("in.txt");
	scan = new Scanner(fr);
	out = new PrintWriter("out.txt");
}
public static void close() throws IOException{
	fr.close();
	out.close();
	
}
}
