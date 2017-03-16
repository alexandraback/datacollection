package google.codejam;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.io.Closeables;
import com.google.common.io.Files;

public class Dancing {

	public static final int MIN_SCORE = 0, MAX_SCORE = 10, COUNT_JUDGES = 3;

	private static Map<Integer, Set<Triplet>> scoreCache = createScoreCache();

	public static void main(String[] args) throws IOException {
		File cwd = new File("C:\\Users\\TaG\\workspace\\CodeJam\\");
		File inputFile = new File(cwd, "input.txt");
		File outputFile = new File(cwd, "output.txt");
		if (outputFile.exists())
			outputFile.delete();
		PrintStream out = null;
		try {
			out = new PrintStream(outputFile);

			List<String> lines = Files.readLines(inputFile, Charsets.UTF_8);
			int cases = Integer.parseInt(lines.remove(0));
			int caseNo = 1;
			for (String line : lines) {
				String[] tokens = line.split("\\s");
				List<String> list = new ArrayList<String>(Arrays.asList(tokens));
				int nDancers = Integer.parseInt(list.remove(0));
				int surprising = Integer.parseInt(list.remove(0));
				int p = Integer.parseInt(list.remove(0));
				int max = 0;
				while (!list.isEmpty()) {
					int score = Integer.parseInt(list.remove(0));
					if (surprising > 0 && shouldApplySurprise(score, p)) {
						surprising--;
						max++;
						continue;
					}

					int high = calcHighestScore(score);
					if (high >= p) {
						max++;
					}
				}

				out.printf("Case #%d: %d\n", caseNo, max);
				System.out.printf("Case #%d: %d\n", caseNo, max);
				caseNo++;
			} // end for-each lines
		} finally {
			Closeables.closeQuietly(out);
		}
	}

	private static boolean shouldApplySurprise(int total, int p) {
		Set<Triplet> set = scoreCache.get(total);
		for (Triplet triplet : set) {
			if (!triplet.isSurprising() && triplet.getHigh() >= p) {
				return false;
			}
		}
		for (Triplet triplet : set) {
			if (triplet.isSurprising() && triplet.getHigh() >= p) {
				return true;
			}
		}
		return false;
	}

	private static int calcHighestScore(int total) {
		Set<Triplet> set = scoreCache.get(total);
		int max = 0;
		for (Triplet triplet : set) {
			if (!triplet.isSurprising()) {
				max = Math.max(max, triplet.getHigh());
			}
		}
		return max;
	}

	public static Map<Integer, Set<Triplet>> createScoreCache() {
		Map<Integer, Set<Triplet>> list = new HashMap<Integer, Set<Triplet>>();
		for (int score = MIN_SCORE; score <= (MAX_SCORE * COUNT_JUDGES); score++) {
			Set<Triplet> set = calcPossibleCombos(score);
			list.put(score, set);
			// System.out.println(score + ":");
			// for (Triplet triplet : set) {
			// System.out.println(triplet.getLow() + ", " + triplet.getMid()
			// + ", " + triplet.getHigh() + " ? " + triplet.isSurprising());
			// }
		}
		return list;
	}

	private static Set<Triplet> calcPossibleCombos(int score) {
		// I am too tired to think this through
		// so I'll brute-force it
		Set<Triplet> set = new HashSet<Triplet>();
		for (int a = MIN_SCORE; a <= MAX_SCORE; a++) {
			for (int b = MIN_SCORE; b <= MAX_SCORE; b++) {
				for (int c = MIN_SCORE; c <= MAX_SCORE; c++) {
					int total = a + b + c;
					if (total == score) {
						Triplet triplet = new DefaultTriplet(a, b, c);
						if (triplet.isPossible()) {
							set.add(triplet);
						}
					}
				}
			}
		}
		return set;
	}

	private static interface Triplet {

		int getLow();

		int getMid();

		int getHigh();

		boolean isSurprising();

		boolean isPossible();

	}

	private static class DefaultTriplet implements Triplet {

		private int[] ints;
		private boolean isSurprising, isPossible;

		public DefaultTriplet(int score1, int score2, int score3) {
			super();

			ints = new int[] { score1, score2, score3 };
			Arrays.sort(ints);
			int diff = ints[2] - ints[0];
			switch (diff) {
			case 2:
				isSurprising = true;
			case 1:
			case 0:
				isPossible = true;
				break;
			default:
				isPossible = false;
			}
		}

		private void validate() {
			if (!isPossible())
				throw new IllegalStateException("this should never happen");
		}

		@Override
		public int getLow() {
			validate();
			return ints[0];
		}

		@Override
		public int getMid() {
			validate();
			return ints[1];
		}

		@Override
		public int getHigh() {
			validate();
			return ints[2];
		}

		@Override
		public boolean isSurprising() {
			validate();
			return this.isSurprising;
		}

		@Override
		public boolean isPossible() {
			return this.isPossible;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(ints);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			DefaultTriplet other = (DefaultTriplet) obj;
			if (!Arrays.equals(ints, other.ints))
				return false;
			return true;
		}

	}

}