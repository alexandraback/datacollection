package gcj2013.Pre;

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

public class C {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/Pre/";
		String READ_FILE = null;
		String WRITE_FILE = null;

//				READ_FILE = "csmall.in";
//				WRITE_FILE = "csmall.out";
		READ_FILE = "clarge.in";
		WRITE_FILE = "clarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new C().run();
	}

	Scanner sc;
	static long[] prec;
	static void precalc(){
		prec = new long[1000];
		Arrays.fill(prec, -1);
		long i = 1;
		int index = 0;
		while(i * i <= 1000000000000000L){
			if(chk(i) && chk(i*i)){
				prec[index] = i*i;
				index++;
			}
			i++;
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
	
	void solve(){
		long a = sc.nextLong();
		long b = sc.nextLong();
		long cnt = 0;
		for(long i : prec){
			if(i < a) continue;
			else if(i <= b) cnt++;
			else if(b < i) break;
		}
		System.out.println(cnt);
	}

	static boolean chk(long a){
		return ("" + a).equals(new StringBuilder("" + a).reverse().toString());
	}
	void debug(Object... o){
		System.out.println(deepToString(o));
	}
}

/*

 
3
1 4
10 120
100 1000
Case #1: 2
Case #2: 0
Case #3: 2



 *
 */