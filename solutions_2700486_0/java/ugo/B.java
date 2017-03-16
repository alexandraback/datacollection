package gcj2013.R1B;

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
		String DIR = "src/gcj2013/R1B/";
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
	static double[][] prec = new double[2000][2000];
	static void precalc(){
		for(int i = 0 ; i < 2000 ; i++){
			prec[i][i] = Math.pow(0.5, i+1);
			for(int j = 1 ; j < i ; j++){
				prec[i][j] = (prec[i-1][j] + prec[i-1][j-1]) / 2.0;
			}
			prec[i][0] = 1 - prec[i][i];
		}
	}

	void run(){
		sc = new Scanner(System.in);
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			solve();
			System.out.flush();
		}
	}
	int D, X, Y;
	int n, left;
	void solve(){
		D = sc.nextInt();
		X = Math.abs(sc.nextInt());
		Y = sc.nextInt();
		get();
//		debug(D,X,Y,n);
		if(X+Y < 2*n){
			System.out.println(1.0);
			return;
		}else if(X+Y > 2*n){
			System.out.println(0.0);
			return;
		}

		if(left <= (n)*2){
//			debug(left , X);
			System.out.println(prec[left-1][2*n - X]);
			return;
		}else if(left == 4*n + 1){
			System.out.println(1.0);
			return;
		}else if(left == 4*n){
			if(Y == 0) System.out.println(0.0);
			else System.out.println(1.0);
			return;
		}
		int x = left - (2*n) - 1;
		int y = x - X + 1;
//		debug(left, n, x, y);
		if(y < 0){
			System.out.println(1.0);
		}else{
			System.out.println(prec[x][y]);
		}
		
		
		
		
	}
	void get(){
		for(int i = 1 ; i < 10000 ; i+= 2){
			if(D <= i * (i+1) / 2){
				n = i/2;
				left = D - ((i-1) * (i-2) / 2);
				return;
			}
		}
		throw new IllegalArgumentException("hull");
	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*
Input 
 	
Output 
 
7
1 0 0
1 0 2
3 0 0
3 2 0
3 1 1
4 1 1
4 0 2
Case #1: 1.0
Case #2: 0.0
Case #3: 1.0
Case #4: 0.75
Case #5: 0.25
Case #6: 0.5
Case #7: 0.0

*/