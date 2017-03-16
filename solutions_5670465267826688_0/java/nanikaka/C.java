package gcj2015.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/qual";
	final String PROBLEM = "C";
	
	final int I = 0;
	final int J = 1;
	final int K = 2;
	final int ONE = 3;
	final int MINUS_I = 4;
	final int MINUS_J = 5;
	final int MINUS_K = 6;
	final int MINUS_ONE = 7;
	
	int[][] map = {
			{MINUS_ONE, K, MINUS_J, I, ONE, MINUS_K, J, MINUS_I},
			{MINUS_K, MINUS_ONE, I, J, K, ONE, MINUS_I, MINUS_J},
			{J, MINUS_I, MINUS_ONE, K, MINUS_J, I, ONE, MINUS_K},
			{I, J, K, ONE, MINUS_ONE, MINUS_I, MINUS_J, MINUS_K},
			{ONE, MINUS_K, J, MINUS_I, MINUS_ONE, K, MINUS_J, I},
			{K, ONE, MINUS_I, MINUS_J, MINUS_K, MINUS_ONE, I, J},
			{MINUS_J, I, ONE, MINUS_K, J, MINUS_I, MINUS_ONE, K},
			{MINUS_I, MINUS_J, MINUS_K, MINUS_ONE, I, J, K, ONE}
	};
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int L = sc.nextInt();
			long X = sc.nextLong();
			boolean res = false;
			String s = sc.next();
			if (3 <= L*X) {
				res = solve(L, X, s);
			}
			System.out.println("Case #"+CASE+": "+(res?"YES":"NO"));
		}
	}
	
	boolean solve(int L, long X, String s){
		int n = 0;
		int[] a;
		long x = 0;
		while (x < X) {
			n += L;
			x++;
			if (10000 <= n && (X-x)%4 == 0) break;
		}
		a = new int[n];
		int idx = 0;
		for(int i=0;i<x;i++)for(int j=0;j<L;j++)a[idx++]=s.charAt(j)-'i';
		int resLeft = a[0], iR = 0;
		while(resLeft!=I && resLeft !=MINUS_I && iR+1 < n) {
			resLeft = map[resLeft][a[++iR]];
		}
//		System.out.println("HERE");
		if (iR == n)return false;
		int resRight = a[n-1], iL = n-1;
//		System.out.println(n);
		while(resRight!=K && resRight!=MINUS_K && iR+1 < iL-1) {
			resRight = map[a[--iL]][resRight];
		}
//		System.out.println("HERE2");
		if (iL <= iR+1) return false;
		int res = a[iR+1];
		for(int i=iR+2;i<iL;i++)res = map[res][a[i]];
//		System.out.println("HERE3 "+iR+" "+iL);
		if (res!=J && res!=MINUS_J)return false;
		int sign = 0;
		if (resLeft == MINUS_I)sign++;
		if (res == MINUS_J)sign++;
		if (resRight == MINUS_K)sign++;
		return sign%2==0;
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
