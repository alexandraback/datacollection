package gcj.y2015.r1c;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainC {

	static int t;

	public static void main(String[] args) throws Exception {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (t=1; t<=T; t++) {

			int C = sc.nextInt(); // 最大使用可能枚数
			int D = sc.nextInt(); // 通貨種類数
			int V = sc.nextInt(); // 最大価格

			List<Integer> d = new ArrayList<Integer>();
			for (int i=0; i<D; i++) {
				d.add(sc.nextInt());
			}

			solve(C, D, V, d);
		}
	}

	static void solve(int C, int D, int V, List<Integer> d) {
		if ( C != 1) {
			// 未実装
		}

		output(t, dfs(V,1,d)-D);

	}

	static int dfs(int V, int v, List<Integer> d) {
		if (v > V) {
			return d.size();
		}

		// 可能な貨幣の組み合わせ数
		int count = 1;
		for (int i=0; i<d.size(); i++) {
			count = count * 2;
		}

		// 今の組み合わせでvが作れるか確認
		for (int i=0; i<count; i++) {

			// 貨幣の組み合わせを作る
			int[] U = new int[d.size()];
			int tmp = i;
			for (int j=0; j<d.size(); j++) {
				U[j] = tmp%2;
				tmp = tmp/2;
			}

			int value = 0;
			for (int j=0; j<d.size(); j++) {
				if (U[j] == 1) {
					value += d.get(j);
				}
			}

			if (value == v) {
				return dfs(V, v+1, d);
			}
		}

		// 今の組み合わせでvが作れなかった場合

		int min = 10000;
		for (int i=1; i<=v; i++) {
			if (!d.contains(i)) {
				List<Integer> nd = new ArrayList<Integer>(d);
				nd.add(i);
				int tmp = dfs(V,v+1,nd);
				if(tmp < min) {
					min = tmp;
				}
			}
		}

		return min;
	}

	static boolean contain(int n, int[] d) {
		for (int i=0; i<d.length; i++) {
			if(d[i] == n) {
				return true;
			}
		}

		return false;
	}

	static void output(int i, Object ans) {
		System.out.println("Case #" + i + ": " + ans);
	}
}