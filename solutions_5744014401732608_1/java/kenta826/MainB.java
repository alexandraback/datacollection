package gcj.y2016.R1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainB {

	static final int INF = 10000000;
	static final int[] flg = {1,2,4,8,16,32,64,128,256,512};
	static final char[] A = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/A-small-practice.in"));
		//		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			int B = sc.nextInt();
			long M = sc.nextLong();

			solve(t,B,M);
		}
		sc.close();

	}

	static void solve(int t, int B, long M) {
		System.out.print("Case #" + t + ": ");
		long tmp = 1;
		if (M > (tmp<<(B-2))) {
			System.out.println("IMPOSSIBLE");
			return;
		}

		System.out.println("POSSIBLE");

		int[][] E = new int[B][B];

		init(B, E);

		// 全部つながないといけないとき
		if (M == (1<<(B-2))) {
			for (int i=0; i<B-1; i++) {
				E[i][B-1] = 1;
			}
		}

		// そうでないとき
		else {
			base(B, M, E);
		}

		print(B, E);
	}

	static void init(int B, int[][] E) {
		for (int i=0; i<B; i++) {
			for (int j=i+1; j<B-1; j++) {
				E[i][j] = 1;
			}
		}
	}

	static void base(int B, long M, int[][] E) {
		if(M%2 == 1) {
			E[1][B-1] = 1;
		}

		for (int i=2; i<B-1; i++) {
			M = M>>1;
			if(M%2 == 1) {
				E[i][B-1] = 1;
			}

		}
	}

	static void print(int B, int[][] E) {
		for (int i=0; i<B; i++) {
			for (int j=0; j<B; j++) {
				System.out.print(E[i][j]);
			}
			System.out.println("");
		}
	}

	static void output(int i, String a) {
		System.out.println("Case #" + i + ": " + a);
	}

}