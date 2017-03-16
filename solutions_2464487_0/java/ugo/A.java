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

public class A {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1A/";
		String READ_FILE = null;
		String WRITE_FILE = null;

				READ_FILE = "asmall.in";
				WRITE_FILE = "asmall.out";
//		READ_FILE = "alarge.in";
//		WRITE_FILE = "alarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new A().run();
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
	
	void solve(){
		long r = sc.nextLong();
		long t = sc.nextLong();
		r += 1;
		long cnt = 0;
		while(compute(r) <= t){
			cnt++;
			t -= compute(r);
			r += 2;
		}
		System.out.println(cnt);
	}
	long compute(long rad){
		return (2*rad - 1);
	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*
5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000


Output 
 
Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 707106780
Case #5: 49

*/