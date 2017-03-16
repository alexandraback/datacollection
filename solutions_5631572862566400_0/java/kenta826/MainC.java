package gcj.y2016.R1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainC {

	static final int INF = 10000000;
	static final int[] flg = {1,2,4,8,16,32,64,128,256,512};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/A-small-practice.in"));
		//		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			int N = sc.nextInt();

			int[] F = new int[N];
			for (int i=0; i<N; i++) {
				F[i] = sc.nextInt()-1;
			}
			output(t, solve(N,F));

		}
		sc.close();
	}

	static int solve(int N, int[] F) {
		// 大きな閉路の場合
		int ret1 = 1;
		// サイズ2の場合
		int ret2 = 0;

		int[] rev = new int[N];

		// まずは逆引き最大深さを求める
		for (int i=0; i<N; i++) {
			int[] flg = new int[N];
			int start = i;
			int pre = -1;
			int now = i;
			int next = F[i];
			int cnt = 1;

			flg[now] = 1;

			while (true) {
				if (flg[next] == 1) {
					break;
				}

				rev[now] = Math.max(rev[now], cnt);

				cnt++;
				pre = now;
				now = next;
				next = F[now];
				flg[now] = 1;
			}
		}

		// サイズ3以上の計算
		for (int i=0; i<N; i++) {
			int[] flg = new int[N];
			int start = i;
			int pre = -1;
			int now = i;
			int next = F[i];
			int cnt = 1;

			flg[now] = 1;

			while (true) {
				// 閉路の場合
				if (next == start) {
					ret1 = Math.max(cnt, ret1);
					break;
				}

				if (flg[next] == 1) {
					break;
				}
				cnt++;
				pre = now;
				now = next;
				next = F[now];
				flg[now] = 1;
			}
		}

		// サイズ2の閉路＋アルファの計算
		int[] flg = new int[N];
		for (int i=0; i<N; i++) {
			int now=i;
			int next=F[i];

			if(flg[now] == 1) {
				continue;
			}

			if(now == F[next]) {
				flg[now] = 1;
				flg[next] = 1;

				ret2 = ret2 + rev[now] + rev[next];

//				int max1 = 0;
//				for (int j=0; j<N; j++) {
//					if (F[j] == now) {
//						max1 = Math.max(max1, rev[j]-1);
//					}
//				}
//
//				int max2 = 0;
//				for (int j=0; j<N; j++) {
//					if (F[j] == next) {
//						max2 = Math.max(max2, rev[j]-1);
//					}
//				}
//
//				ret2 = ret2+max1+max2+2;
			}

		}
		return Math.max(ret1, ret2);

	}

	static void output(int i, int a) {
		if (a==0){
			System.out.println("Case #" + i + ": " + a);
		} else {
			System.out.println("Case #" + i + ": " + a);
		}
	}

}