package gcj2014.R1C;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2014/R1C/";
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

	void debug(Object... o){
		System.out.println(deepToString(o));
	}

	
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

	long gcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
	
	void solve(){
		String s = sc.next();
		long a = Long.parseLong(s.substring(0, s.indexOf('/')));
		long b = Long.parseLong(s.substring(s.indexOf('/') + 1));

		long gcd = gcd(b, a);
		b = b / gcd;
		a = a / gcd;
//		debug(gcd);
		long b2 = b;
		while (b2 % 2 == 0) {
			b2 = b2 >> 1;
		}
		if (b2 != 1) {
			System.out.println("impossible");
			return;
		}

		int cnt = 0;
		while (a < b) {
//			debug (a, b);
			b /= 2;
			cnt++;
		}
		System.out.println(cnt);

	}	
}

/*

 	
Output 
 
5
1/2
3/4
1/4
2/23
123/31488

Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8



*/