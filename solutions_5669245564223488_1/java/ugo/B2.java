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

public class B2 {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2014/R1C/";
		String READ_FILE = null;
		String WRITE_FILE = null;

		//				READ_FILE = "bsmall.in";
		//				WRITE_FILE = "bsmall.out2";
				READ_FILE = "blarge.in";
		//		WRITE_FILE = "blarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new B2().run();
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
	boolean only(String s) {
		for (int i = 1 ; i < s.length(); i++)
			if (s.charAt(i) != s.charAt(0)) {
				return false;
			}
		return true;
	}
	long MOD = 1000000007L;
	long[] fact = new long[1001];
	long fact(int n) {
		if (fact[n] > 0) return fact[n];
		if (n == 0) return fact[n] = 1;
		return fact[n] = fact(n-1) * n % MOD;
	}
	boolean seq(String s) {
		boolean[] seen = new boolean[26];
		for (int i = 0 ; i < s.length() ; i++) {
			char c = s.charAt(i);
			if (seen[c - 'a']) {
				return false;
			}
			seen[c-'a'] = true;
			while(i < s.length() && s.charAt(i) == c) {
				i++;
			}
			i--;
		}
		return true;
	}
	void solve() {
		int n = sc.nextInt();
		String[] ss = new String[n];
		long ret = 1;
		int indep = 0;
		LinkedList<String> list = new LinkedList<String>();
		for (int i = 0 ; i < n ; i++) 
			list.add(sc.next());
			//ss[i] = sc.next();

		for (String s : list){
			if(seq(s) == false){
				System.out.println(0);
				return;
			}
		}
		for (char c = 'a' ; c <= 'z' ; c++) {
			LinkedList<String> list2 = new LinkedList<String>();
			for (int i = 0 ; i < list.size() ; i++) {
				if (list.get(i).indexOf(c) >= 0) {
					list2.add(list.remove(i));
					i--;
				}
			}
			String no_left = null, no_right = null;
			int only_cnt = 0;
			for (String s : list2) {
				if (only(s)) {
					only_cnt++;
				} 
				if (s.charAt(0) != c) {
					if (no_left != null) {
						System.out.println("0");
						return;
					}
					no_left = s;
				} 
				if (s.charAt(s.length() - 1) != c) {
					if (no_right != null) {
						System.out.println(0);
						return;
					}
					no_right = s;
				}
			}
			if (no_left != null && no_right != null) {
				String s;
				if (no_left == no_right) {
					s = no_left;
				} else {
					s = no_left + no_right;
				}
				if (s.charAt(0) < c && s.charAt(s.length() - 1) < c) {
					indep++;
				} else {
					if (seq(s) == false) {
						System.out.println(0);
						return;
					}
					list.add(s);
				}
			} else if (no_left != null) {
				if (no_left.charAt(0) < c) {
					indep++;
				} else {
					if (seq(no_left) == false) {
						System.out.println(0);
						return;
					}

					list.add(no_left);
				}
			} else if (no_right != null) {
				if (no_right.charAt(no_right.length() - 1) < c) {
					indep++;
				} else {
					if (seq(no_right) == false) {
						System.out.println(0);
						return;
					}

					list.add(no_right);
				}
			} else if (list2.size() > 0){
				indep++;
			}
//			debug(list, indep);
//			debug(ret, only_cnt, fact(only_cnt));
			ret = ret * fact(only_cnt) % MOD;
//			debug(ret);
		}
		ret = ret * fact(indep) % MOD;
		System.out.println(ret);
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