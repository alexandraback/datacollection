package net.anzix.learn.codejam.r1a12;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class KingdomRush {

	private List<Pair> stars = new ArrayList<Pair>();

	private InputStream input;
	private PrintStream output;

	public KingdomRush() {

	}

	public KingdomRush(InputStream input, PrintStream output) {
		super();
		this.input = input;
		this.output = output;
	}

	public KingdomRush(File inputFile, File outputFile) throws Exception {
		this.input = new FileInputStream(inputFile);
		output = new PrintStream(outputFile);

	}

	public void run() throws Exception {
		Scanner scanner = new Scanner(input);
		int lines = scanner.nextInt();
		for (int i = 0; i < lines; i++) {
			int pairs = scanner.nextInt();
			reset();
			for (int p = 0; p < pairs; p++) {
				addPair(scanner.nextInt(), scanner.nextInt());
			}
			int res = calculate();
			if (res == -1) {
				output.println("Case #" + (i + 1) + ": " + "Too Bad");
			} else {
				output.println("Case #" + (i + 1) + ": " + res);
			}
		}
		output.close();
	}

	public void reset() {
		stars.clear();

	}

	public void addPair(int a, int b) {
		stars.add(new Pair(a, b));
	}

	public int calculate() {

		int currentStar = 0;
		int tries = 0;
		int ok = 0;

		while (ok < stars.size()) {
			int idx = findForTwoStarForOne(currentStar);
			if (idx != -1) {
				stars.get(idx).starb = true;
				currentStar += 1;
				tries++;
				ok++;
				continue;
			}
			idx = findForTwoStar(currentStar);
			if (idx != -1) {
				stars.get(idx).starb = true;
				currentStar += 2;
				tries++;
				ok++;
				continue;
			}
			idx = findForOneStar(currentStar);
			if (idx != -1) {
				stars.get(idx).stara = true;
				currentStar++;
				tries++;
				continue;
			}
			return -1;

		}
		return tries;

		// while (idx2 < star2.size()) {
		// while (idx2 < star2.size() && star2.get(idx2) <= currentStar) {
		// idx2++;
		// currentStar += 2;
		// tries++;
		// }
		// if (idx2 >= star2.size()) {
		// return tries;
		// }
		// if (idx1 < star1.size()
		// && star1.get(idx1) <= currentStar) {
		// idx1++;
		// currentStar += 1;
		// tries++;
		// } else {
		// return -1;
		// }
		//
		// }
		//return tries;
	}

	private int findForOneStar(int currentStar) {
		int idx = -1;
		int mv = -1;
		int i = 0;
		for (Pair s : stars) {
			if (s.a <= currentStar && s.stara == false && s.starb == false && s.b > mv) {
				idx = i;
				mv = s.b;
			}
			i++;
		}
		return idx;
	}
	private int findForTwoStarForOne(int currentStar) {
		int idx = -1;
		int mv = -1;
		int i = 0;
		for (Pair s : stars) {
			if (s.b <= currentStar && s.stara == true && s.starb == false && s.a > mv) {
				idx = i;
				mv = s.a;
			}
			i++;
		}
		return idx;
	}
	private int findForTwoStar(int currentStar) {
		int idx = -1;
		int mv = -1;
		int i = 0;
		for (Pair s : stars) {
			if (s.b <= currentStar && s.stara == false && s.starb == false && s.a > mv) {
				idx = i;
				mv = s.a;
			}
			i++;
		}
		return idx;
	}

	public static void main(String[] args) {
		try {
			new KingdomRush(new File(args[0]), new File(args[1])).run();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private class Pair {
		public int a;
		public int b;
		public boolean stara;
		public boolean starb;

		public Pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

	}
}
