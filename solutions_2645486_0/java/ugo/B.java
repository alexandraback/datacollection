package gcj2013.R1A;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1A/";
		String READ_FILE = null;
		String WRITE_FILE = null;

				READ_FILE = "bsmall.in";
				WRITE_FILE = "bsmall.out";
//		READ_FILE = "blarge.in";
//		WRITE_FILE = "blarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new B().run();
	}

	Scanner sc;
	static void precalc(){}

	void run(){
		sc = new Scanner(System.in);
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			solve();
			System.out.flush();
		}
	}

	long[][] dp;
	int[] jobs;
	int E, R, n;
	void solve(){
		E = sc.nextInt();
		R = sc.nextInt();
		n = sc.nextInt();
		jobs = new int[n];
		for(int i = 0 ; i < n ; i++) jobs[i] = sc.nextInt();
		dp = new long[n][E+1];
		for(long[] dd : dp) Arrays.fill(dd, -1);
		System.out.println(doit(0, E));
//		for(long[] dd : dp){
//			System.out.println(Arrays.toString(dd));
//		}
	}
	long doit (int pos, int en) {
		if(dp[pos][en] != -1) return dp[pos][en];
		if(pos == n-1) return dp[pos][en] = jobs[pos] * en;
		long ret = 0;
		for(int i = 0 ; i <= en ; i++){
			int after = (en - i + R > E) ? E : (en - i + R);
			ret = Math.max(ret, doit(pos+1, after) + jobs[pos] * i);
		}
		return dp[pos][en] = ret;
	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*
Input 
 	
Output 
 
3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
Case #1: 12
Case #2: 12
Case #3: 39



*/