package gcj.r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.Scanner;

public class MainC {

	static int[][] map;

	public static void main(String[] args) throws FileNotFoundException {

		map = new int[20][20];


		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (int t=1; t<=T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();

			output(t, solve(Math.max(N,M), Math.min(N,M), K));
		}

	}

	static int solve(int N, int M, int K) {
		int ret = 0;

		// 片方の辺が2以下の場合
		if (M == 1) {
			ret = K;
			return ret;
		}

		// N*M-4 >= K の場合
		if (N*M-4 <= K) {
			ret = (N+M)*2-4;

			int dif = N*M-K;
			ret = ret - dif;

			return ret;
		}

		int a = (int) Math.ceil(Math.sqrt(K+4));
		int b = 0;

		if (a*(a-1) >= K+4) {
			b = a-1;
		} else {
			b = a;
		}

		// 盤内に収まらない場合
		if (b > M) {
			b = M;
			a = (K+4)/b;
			if (a*b != K+4) {
				a = a+1;
			}

		} else if (a > N) {
			a = N;
			b = (K+4)/a;

			if (a*b != K+4) {
				b = b+1;
			}
		}

		a -=2;
		b -=2;

//		System.out.println("a:" + a);
//		System.out.println("b:" + b);

		ret = (a+b)*2;
		int dif = (a+2)*(b+2)-4-K;
		if (dif%2 == 0) {
			ret = ret - dif/2;
		} else {
			ret = ret - (dif+1)/2 + 1;
		}
//		System.out.println("dif:" + dif);

		return ret;
	}

	static void output(int i, Object ans) {
		System.out.println("Case #" + i + ": " + ans);
	}

	static class Vec {
		public int x;
		public int y;

		Vec(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static class VecComparator implements Comparator<Vec> {

		public int compare(Vec v1, Vec v2) {
			if (v1.y > v2.y) {
				return 1;
			} else if (v1.y == v2.y) {
				return 0;
			} else {
				return -1;
			}
		}
	}

	public static class VecComparator2 implements Comparator<Vec> {

		public int compare(Vec v1, Vec v2) {
			if (v1.x > v2.x) {
				return 1;
			} else if (v1.x == v2.x) {
				return 0;
			} else {
				return -1;
			}
		}
	}
}