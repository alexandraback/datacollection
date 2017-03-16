import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LessMoneyLessProblems {
	public static final String FILENAME = "C-small-0";

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/" + FILENAME
				+ ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"
				+ FILENAME + ".out"));
		Scanner sc = new Scanner(in);
		int t = sc.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();
			int[] coins = new int[d];
			for (int i = 0; i < coins.length; i++) {
				coins[i] = sc.nextInt();
			}
			boolean[] ok = new boolean[v + 1];
			ok[0] = true;
			int maxsum = 0;
			for (int j = 0; j < coins.length; j++) {
				maxsum += coins[j];
				for (int i = Math.min(maxsum, ok.length - 1); i >= 0; i--) {
					for (int k = 1; !ok[i] && i - k * coins[j] >= 0 && k <= c; k++) {
						if (ok[i - k * coins[j]]) {
							ok[i] = true;
						}
					}
				}
			}
			int ret = 0;
			for (int i = 0; i < ok.length; i++) {
				if (!ok[i]) {
					ret++;
					for (int j = 0; j < c; j++) {
						for (int k = ok.length-i-1; k >= 0; k--) {
							if (ok[k]) {
								ok[k + i] = true;
							}
						}
					}
				}
			}
			out.write("Case #" + tt + ": " + ret + "\n");
		}
		in.close();
		out.close();
	}

	private static int minPrefix(char[] word) {
		for (int i = 1; i < word.length; i++) {
			boolean ok = true;
			for (int j = 0; ok && j + i < word.length; j++) {
				if (word[j] != word[j + i]) {
					ok = false;
				}
			}
			if (ok) {
				return i;
			}
		}
		return word.length;
	}
}
