package gcj2015.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/r1b";
	final String PROBLEM = "C";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-1-attempt5.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out-1-5.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int Q = sc.nextInt();
			int[] v = new int[1<<4];
			int[] d = new int[1<<4];
			int N = 0;
			while(Q--!=0){
				int D = sc.nextInt(), H = sc.nextInt(), M = sc.nextInt();
				for(int k=0;k<H;k++){
					d[N] = D;
					v[N++] = M+k;
				}
			}
			int res = 0;
			if (N==1){
				res = 0;
			} else {
				double p1 = d[0], p2 = d[1];
				double v1 = v[0], v2 = v[1];
				if (p2 < p1){
					double t = v1; v1 = v2; v2 = t;
					double p = p1; p1 = p2; p2 = p;
				}
				double t2 = (360.-p2)/v2;
				double D1 = p1 + t2*v1;
				if (720 < D1){
					res = 1;
//					System.out.println("D1: "+D1);
				} else {
					double t1 = (360.-p1)/v1;
					double D2 = p2 + t1*v2;
					if (720 < D2)res=1;
				}
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
