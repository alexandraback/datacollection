import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;

	PrintWriter out;

	private static final String path = "/home/alex/Downloads/";

	private static final String task = "B-small-attempt0";

	static class Pair {

		String value;

		int score;

		public Pair(String value, int score) {
			this.value = value;
			this.score = score;
		}
		
		public String toString() {
			return value;
		}
	}
	
	List<Pair> rezz;
	
	void gen(int sum, int idx, char []s) {
		if (idx == s.length) {
			rezz.add(new Pair(new String(s), sum));
			return;
		}
		if (s[idx] == '?') {
			for (int i = 0; i <= 9; i++) {
				char prev = s[idx];
				s[idx] = (char)(i + '0');
				gen(sum * 10 + i, idx + 1, s);
				s[idx] = prev;
			}
		} else {
			gen(sum * 10 + s[idx] - '0', idx + 1, s);
		}
	}

	List<Pair> getScores(char[] scores) {
		rezz = new ArrayList<>();
		gen(0, 0, scores);
		return new ArrayList<>(rezz);
	}

	void solveOne() {
		char[] coders = in.next().toCharArray();
		char[] jammers = in.next().toCharArray();
		List<Pair> c = getScores(coders);
		List<Pair> j = getScores(jammers);

		Pair bestC = c.get(0);
		Pair bestJ = j.get(0);

		for (Pair cc : c) {
			for (Pair jj : j) {

				int diff = Math.abs(cc.score - jj.score);

				int best = Math.abs(bestC.score - bestJ.score);
				if (diff < best) {
					bestC = cc;
					bestJ = jj;
				} else if (diff == best && cc.score < bestC.score) {
					bestC = cc;
					bestJ = jj;
				} else if (diff == best && cc.score == bestC.score && jj.score < bestJ.score) {
					bestC = cc;
					bestJ = jj;
				}
				
			}
		}
		out.print(bestC.value + " " + bestJ.value);
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

	public static void main(String[] args) {
		new Csmall().run();
	}
}
