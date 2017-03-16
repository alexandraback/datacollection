import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	private char[][] words;
	private char[] s;
	private int[][] memo;

	private static final int W_LEN = 521196;
	private static final int oo = 5000;

	private void work() throws IOException {

		readWords();

		// Scanner sc = new Scanner(new FileReader("C.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("C.out"));
		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("C-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("C-large.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			s = sc.next().toCharArray();
			memo = new int[5][s.length];
			for (int i = 0; i < 5; i++) {
				Arrays.fill(memo[i], -1);
			}
			pw.printf("Case #%d: %d\n", tc, go(0, 0));
		}
		pw.close();
		sc.close();
	}

	int[] errs = new int[10];

	private int go(int lastError, int k) {
		if (k == s.length)
			return 0;
		if (memo[lastError][k] >= 0)
			return memo[lastError][k];
		int ret = oo;
		for (int i = 0; i < W_LEN && ret > 0; i++) {
			if (k + words[i].length > s.length) {
				continue;
			}
			int en = 0;
			boolean ok = true;
			for (int j = 0; j < words[i].length && ok; j++) {
				if (words[i][j] != s[k + j]) {
					errs[en++] = j;
					if (en > 1 && errs[en - 1] - errs[en - 2] < 5) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				if (lastError > 0) {
					if (en == 0) {
						int nle = lastError + words[i].length;
						if (nle > 4)
							nle = 0;
						int t = en + go(nle, k + words[i].length);
						if (t < ret)
							ret = t;
					} else {
						if (errs[0] + lastError > 4) {
							int nle = words[i].length - errs[en - 1];
							if (nle > 4)
								nle = 0;
							int t = en + go(nle, k + words[i].length);
							if (t < ret)
								ret = t;
						}
					}
				} else {
					int nle = 0;
					if (en > 0) {
						nle = words[i].length - errs[en - 1];
						if (nle > 4)
							nle = 0;
					}
					int t = en + go(nle, k + words[i].length);
					if (t < ret)
						ret = t;
				}
			}
		}
		return memo[lastError][k] = ret;
	}

	private void readWords() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("dict.txt"));
		words = new char[W_LEN][];
		for (int i = 0; i < W_LEN; i++) {
			words[i] = br.readLine().trim().toCharArray();
		}
	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
