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

public class B {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2014/R1C/";
		String READ_FILE = null;
		String WRITE_FILE = null;

						READ_FILE = "bsmall.in";
		//				WRITE_FILE = "bsmall.out";
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

	int n;
	LinkedList<String> list = new LinkedList<String>();
	int[] charcnt = new int[26];
	long cnt;
	void solve(){
		n = sc.nextInt();
		Arrays.fill(charcnt, 0);
		list.clear();
		for (int i = 0 ; i < n ; i++) {
			String s = sc.next();
			for (int j = 0 ; j < s.length(); j++){
				charcnt[s.charAt(j) - 'a']++;
			}
			list.add(s);
		}
		String s = "";
		cnt = 0;
//		debug(charcnt);
		doit(s, list);
		System.out.println(cnt);
	}

	public void doit(String sofar, LinkedList<String> tokens) {
		if (tokens.size() == 0) {
			for (int i = 0 ; i < 26 ; i++) {
				if (charcnt[i] <= 1) {
					continue;
				}
				for (int j = 0 ; j < sofar.length(); j++) {
					if (sofar.charAt(j) - 'a' == i) {
						for (int k = j ; k < j + charcnt[i] ; k++) {
							if (sofar.charAt(k) - 'a' != i) {
								return;
							}
						}
						break;
					}
				}
			}
//			System.out.println(sofar);
			cnt++;
		}
		else {
			for (int i = 0; i < tokens.size(); i++) {
				String token = tokens.remove(i);
				doit(sofar + token, tokens);
				tokens.add(i, token);
			}
		}
	}
}

/*


Output 

3
3
ab bbbc cd
4
aa aa bc c
2
abc bcd

Case #1: 1
Case #2: 4
Case #3: 0


 */