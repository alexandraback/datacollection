import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CloseMatch {

	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(bf.readLine());
		for (int testcase = 1; testcase <= T; testcase++) {

			String[] line = bf.readLine().split(" ");
			String codersPart = line[0];
			String jammersPart = line[1];

			int n = codersPart.length();
			int[] cVals = new int[n];
			boolean[] cUnknown = new boolean[n];
			int[] jVals = new int[n];
			boolean[] jUnknown = new boolean[n];
			parseInput(codersPart, cVals, cUnknown);
			parseInput(jammersPart, jVals, jUnknown);
			// System.out.println(Arrays.toString(cUnknown));
			// System.out.println(Arrays.toString(cVals));
			// System.out.println(Arrays.toString(jUnknown));
			// System.out.println(Arrays.toString(jVals));

			// exhaustive search over all assignments =/
			int numPossibilities = 1;
			for (int i = 0; i < n; i++) {
				numPossibilities *= 3;
			}

			long minAbsDiff = Long.MAX_VALUE;
			long minCoderVal = Long.MAX_VALUE;
			long minJammerVal = Long.MAX_VALUE;
			for (int i = 0; i < numPossibilities; i++) {
				long coderSum = 0;
				long jammerSum = 0;
				int curEncoding = i;
				for (int digit = 0; digit < n; digit++) {
					int curSwitch = curEncoding % 3;
					curEncoding /= 3;

					int coderVal = 0;
					int jammerVal = 0;

					// System.out.println(coderSum + " " + jammerSum);
					long curDiff = coderSum - jammerSum;
					// if the coder sum is larger, we need to focus on
					// increasing jammers (0-9 split)
					// if jammer is larger, increase coders (9-0 split)
					// if they're the same, we need to minimize both (0 0)
					// however, sometimes the next digits will change the
					// difference, so we should search all 3 possiblities that
					// minimize the total
					// (1 0), (0 0), (0 1)

					if (curDiff != 0) {
						if (curDiff > 0) {
							jammerVal = 9;
						} else {
							coderVal = 9;
						}
						if (!cUnknown[digit]) {
							coderVal = cVals[digit];
						}
						if (!jUnknown[digit]) {
							jammerVal = jVals[digit];
						}
					} else {
						if (cUnknown[digit] && jUnknown[digit]) {
							switch (curSwitch) {
							case 0:
								coderVal = 0;
								jammerVal = 0;
								break;
							case 1:
								coderVal = 0;
								jammerVal = 1;
								break;
							case 2:
								coderVal = 1;
								jammerVal = 0;
								break;
							}
						} else if (cUnknown[digit]) {
							jammerVal = jVals[digit];
							switch (curSwitch) {
							case 0:
								coderVal = jammerVal;
								break;
							case 1:
								coderVal = (jammerVal + 9) % 10;
								break;
							case 2:
								coderVal = (jammerVal + 1) % 10;
								break;
							}
						} else if (jUnknown[digit]) {
							coderVal = cVals[digit];
							switch (curSwitch) {
							case 0:
								jammerVal = coderVal;
								break;
							case 1:
								jammerVal = (coderVal + 9) % 10;
								break;
							case 2:
								jammerVal = (coderVal + 1) % 10;
								break;
							}
						} else {
							coderVal = cVals[digit];
							jammerVal = jVals[digit];
						}
					}

					coderSum = coderSum * 10L + (long) coderVal;
					jammerSum = jammerSum * 10L + (long) jammerVal;
				}

				// System.out.println("considering " + coderSum + " " +
				// jammerSum);
				long absDiff = Math.abs(coderSum - jammerSum);
				if (absDiff < minAbsDiff
						|| (absDiff == minAbsDiff && coderSum < minCoderVal)
						|| (absDiff == minAbsDiff && coderSum == minCoderVal && jammerSum < minJammerVal)) {
					minAbsDiff = absDiff;
					minCoderVal = coderSum;
					minJammerVal = jammerSum;
				}
			}
			// System.out.println("min abs diff is " + minAbsDiff);
			// System.out.println("min cdr is " + minCoderVal);
			// System.out.println("min jmr  is " + minJammerVal);
			StringBuilder output = new StringBuilder();
			output.append(pad(minCoderVal, n) + " " + pad(minJammerVal, n));
			System.out.println("Case #" + testcase + ": " + output.toString());
		}
	}

	private static String pad(long minCoderVal, int n) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.insert(0, minCoderVal % 10);
			minCoderVal /= 10;
		}
		return sb.toString();
	}

	private static void parseInput(String inputPart, int[] vals,
			boolean[] isUnknown) {
		int n = inputPart.length();
		for (int i = 0; i < n; i++) {
			if (inputPart.charAt(i) == '?') {
				isUnknown[i] = true;
			} else {
				vals[i] = inputPart.charAt(i) - '0';
			}
		}
	}
}
