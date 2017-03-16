package codejam.round1A2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class B {

	private final List<Level> levels;
	private int stars = 0;
	private int games = 0;

	public B(List<Level> levels) {
		this.levels = levels;
	}

	public String compute() {

		Collections.sort(levels);
		// System.out.println(levels.toString());

		int newStars = attemptLevels();
		while (newStars != 0) {
			stars += newStars;
			newStars = attemptLevels();
		}

		if (isComplete()) {
			return "" + games;
		} else {
			return "Too Bad";
		}
	}

	private int attemptLevels() {
		int newStars = 0;

		for (Level level : levels) {

			if (stars >= level.twoReq && !level.twoComplete) {
				if (level.oneComplete) {
					newStars++;
				} else {
					newStars += 2;
				}

				games++;

				// newStars++;
				level.twoComplete = true;
				level.oneComplete = true;
			}

		}

		if (newStars > 0) {
			return newStars;
		}

		for (Level level : levels) {
			if (stars >= level.oneReq && !level.oneComplete) {
				newStars++;
				level.oneComplete = true;
				games++;
				return newStars;
			}
		}

		return newStars;
	}

	private boolean isComplete() {
		for (Level level : levels) {
			if (!level.oneComplete || !level.twoComplete) {
				return false;
			}
		}

		return true;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();
			int levels = Integer.parseInt(line);

			List<Level> levelList = new ArrayList<Level>();

			for (int i = 0; i < levels; i++) {
				line = in.readLine();
				String[] data = line.split(" ");

				int one = Integer.parseInt(data[0]);
				int two = Integer.parseInt(data[1]);

				Level l = new Level(one, two);
				levelList.add(l);
			}

			B b = new B(levelList);
			out.println("Case #" + testCase + ": " + b.compute());

		}

		out.flush();
	}

	private static class Level implements Comparable<Level> {
		final int oneReq;
		final int twoReq;
		boolean completed;

		boolean oneComplete;
		boolean twoComplete;

		public Level(int one, int two) {
			oneReq = one;
			twoReq = two;
			completed = false;
		}

		@Override
		public int compareTo(Level o) {
			return o.twoReq - twoReq;
		}

		@Override
		public String toString() {
			return "Level [oneReq=" + oneReq + ", twoReq=" + twoReq + "]";
		}

	}

}
