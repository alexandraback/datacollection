package gcj.y2016.R1A;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainA {

	static final int INF = 10000000;
	static final int[] flg = {1,2,4,8,16,32,64,128,256,512};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
//		Scanner sc = new Scanner(new File("src/A-small-practice.in"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			String S = sc.next();

			output(t, solve(S));

		}
		sc.close();
	}

	static String solve(String S) {
		String ret = new String();

		ret = S.substring(0, 1);

		for (int i=1; i<S.length(); i++) {
			String first = S.substring(i,i+1) + ret;
			String last = ret + S.substring(i,i+1);

			if (first.compareTo(last) >= 0) {
				ret = first;
			} else {
				ret = last;
			}
		}
		return ret;
	}

	static void output(int i, String s) {
		System.out.println("Case #" + i + ": " + s);
	}

}