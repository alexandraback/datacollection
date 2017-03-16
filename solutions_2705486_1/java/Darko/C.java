import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class C {

	private char[][] words;
	private char[] s;
	private int[][] memo;

	private static final int W_LEN = 521196;
	private static final int oo = 5000;

	boolean[][][][][] canDo;

	private void work() throws IOException {

		readWords();

//		generateLargeInput();

		// Scanner sc = new Scanner(new FileReader("C.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("C.out"));
//		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
//		PrintWriter pw = new PrintWriter(new FileWriter(
//				"C-small-attempt0_2.out"));
//		Scanner sc = new Scanner(new FileReader("C-my-large.in"));
//		PrintWriter pw = new PrintWriter(new FileWriter("C-my-large.out"));
		Scanner sc = new Scanner(new FileReader("C-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-large.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			s = sc.next().toCharArray();

			canDo = new boolean[s.length][11][3][10][10];

			for (int pos = 0; pos < s.length; pos++) {
				for (int i = 0; i < W_LEN; i++) {
					int len = words[i].length;
					if (len + pos > s.length)
						continue;
					int en = 0;
					boolean ok = true;
					for (int j = 0; j < len; j++) {
						if (words[i][j] != s[pos + j]) {
							errs[en++] = j;
							if (en > 1 && errs[en - 1] - errs[en - 2] < 5) {
								ok = false;
								break;
							}
						}
					}
					if (ok) {
						if (en == 0) {
							canDo[pos][len][0][0][0] = true;
						} else {
							canDo[pos][len][en][errs[0]][errs[en - 1]] = true;
						}
					}
				}
			}

			memo = new int[5][s.length];
			for (int i = 0; i < 5; i++) {
				Arrays.fill(memo[i], -1);
			}
			pw.printf("Case #%d: %d\n", tc, go(0, 0));
		}
		pw.close();
		sc.close();
	}

	private void generateLargeInput() {
		Random rnd = new Random();
		System.out.println(4);
		for (int i = 1; i <= 4; i++) {
			char[] blah = new char[4010];
			int cur = 0;
			while (cur < 4000) {
				int k = rnd.nextInt(W_LEN);
				System.arraycopy(words[k], 0, blah, cur, words[k].length);
				cur += words[k].length;
			}
			for (int j = rnd.nextInt(5); j < cur; j += 5) {
				blah[j] = 'x';
			}
			System.out.println(new String(blah, 0, cur));
		}
	}

	int[] errs = new int[10];

	private int go(int lastError, int k) {
		if (k == s.length)
			return 0;
		if (memo[lastError][k] >= 0)
			return memo[lastError][k];
		int ret = oo;
		int le = lastError;
		if (le == 0)
			le = 5;
		for (int len = 1; len < 11; len++) {
			if (len + k > s.length)
				break;
			if (canDo[k][len][0][0][0]) {
				int nle = le + len;
				if (nle > 4)
					nle = 0;
				int t = go(nle, k + len);
				if (t < ret)
					ret = t;
			}
			for (int fst = 5 - le; fst < len; fst++) {
				if (canDo[k][len][1][fst][fst]) {
					int nle = len - fst;
					if (nle > 4)
						nle = 0;
					int t = 1 + go(nle, k + len);
					if (t < ret)
						ret = t;
				}
			}
			for (int fst = 5 - le; fst < len; fst++) {
				for (int snd = fst + 5; snd < len; snd++) {
					if (canDo[k][len][2][fst][snd]) {
						int nle = len - snd;
						if (nle > 4)
							nle = 0;
						int t = 2 + go(nle, k + len);
						if (t < ret)
							ret = t;
					}
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
