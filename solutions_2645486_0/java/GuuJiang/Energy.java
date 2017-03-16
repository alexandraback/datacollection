package codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class Energy {

	private Scanner cin;
	private PrintStream cout;
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Energy().solve();
	}
	
	public Energy() throws Exception {
		/*
		cin = new Scanner(System.in);
		cout = System.out;
		/*/
		cin = new Scanner(new File("B-small-attempt0.in"));
		cout = new PrintStream("B-small-attempt0.out");
		//*/
	}

	private void solve() {
		int t = cin.nextInt();
		for (int i = 1; i <= t; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase());
		}
	}
	
	private String solveCase() {
		int E = cin.nextInt();
		int R = cin.nextInt();
		int N = cin.nextInt();
		int[] w = new int[N];
		for (int i = 0; i < N; ++i) {
			w[i] = cin.nextInt();
		}
		int[] prev = new int[E + 1];
		for (int i = 0; i <= E; ++i) {
			prev[i] = i * w[N - 1];
		}
		int[] cur = new int[E + 1];
		for (int i = N - 2; i >=0; --i) {
			for (int j = 0; j <= E; ++j) {
				cur[j] = 0;
				for (int k = 0; k <= j; ++k) {
					int r = j - k + R;
					if (r > E) {
						r = E;
					}
					int c = w[i] * k + prev[r];
					if (c > cur[j]) {
						cur[j] = c;
					}
				}
			}
			int[] t = cur;
			cur = prev;
			prev = t;
		}
		int result = 0;
		for (int i = 0; i <= E; ++i) {
			if (prev[i] > result) {
				result = prev[i];
			}
		}
		return String.valueOf(result);
	}
}
