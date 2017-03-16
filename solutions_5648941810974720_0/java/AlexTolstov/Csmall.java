import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;
	
	PrintWriter out;
	
	private static final String path = "/home/alex/Downloads/";

	private static final String task = "A-small-attempt1 (1)";
	
	private final String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	private final int[] order = {0, 6, 2, 8, 4, 3, 1, 7, 5, 9};
	
	
	boolean canSubtract(int cnt[], String str) {
		for (int i = 0; i < str.length(); i++) {
			if (cnt[str.charAt(i) - 'A'] == 0) {
				return false;
			}
		}
		return true;
	}
	
	void subtract(int cnt[], String str) {
		for (int i = 0; i < str.length(); i++) {
			cnt[str.charAt(i) - 'A']--;
		}
	}
	
	void solveOne() {
		char []str = in.next().toCharArray();
		int cnt[] = new int[26];
		for (char c : str) {
			cnt[c - 'A']++;
		}
		int ans[] = new int[10];
		for (int dig : order) {
			while (canSubtract(cnt, digits[dig])) {
				subtract(cnt, digits[dig]);
				ans[dig]++;
			}
		}
		for (int c : cnt) {
			asserT(c == 0);
		}
		
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[i]; j++) {
				out.print(i);
			}
		}
	}
	
	void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
		}
	}
	
	void run() {
		try {
			in = new Scanner(new FileReader(path + task + ".in"));
			out = new PrintWriter(new FileWriter(path + task + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String []args) {
		new Csmall().run();
	}
}
