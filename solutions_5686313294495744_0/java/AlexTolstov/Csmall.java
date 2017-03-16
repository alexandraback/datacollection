import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;

	PrintWriter out;

	private static final String path = "/home/alex/Downloads/";

	private static final String task = "C-small-attempt0";

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

	void gen(int sum, int idx, char[] s) {
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

	static class Phrase {

		String first;

		String second;

		public Phrase(String first, String second) {
			this.first = first;
			this.second = second;
		}
		
	}
	
	boolean asFake[];
	
	int maxFakes;
	
	void genAll(List<Phrase> ph, int idx, int cntFakes) {
		if (idx == ph.size()) {
			if (maxFakes > cntFakes) {
				return;
			}
			for (int i = 0; i < ph.size(); i++) {
				if (asFake[i]) {
					Phrase fake = ph.get(i);
					boolean ff = false;
					boolean fs = false;
					for (int j = 0; j < ph.size(); j++) {
						if (!asFake[j]) {
							Phrase good = ph.get(j);
							
							if (fake.first.equals(good.first)) {
								ff = true;
							} 
							
							if (fake.second.equals(good.second)) {
								fs = true;
							}
						}
					}
					if (!(ff && fs)) {
						return;
					}
				}
			}
			maxFakes = cntFakes;
			return;
		}
		asFake[idx] = true;
		genAll(ph, idx + 1, cntFakes + 1);
		asFake[idx] = false;
		genAll(ph, idx + 1, cntFakes);
	}

	void solverOne() {
		int n = in.nextInt();
		asFake = new boolean[n];
		maxFakes = 0;
		List<Phrase> ph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			ph.add(new Phrase(in.next(), in.next()));
		}
		genAll(ph, 0, 0);
		out.print(maxFakes);
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
			solverOne();
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
