import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
	private static String PROG_NAME = Osmos.class.getSimpleName();
	private static PrintWriter out;

	public static void main(String[] args) throws Exception {
		// main(new FileReader(PROG_NAME + ".small.in"), new
		// FileWriter(PROG_NAME + ".small.out"));
		main(new FileReader(PROG_NAME + ".large.in"), new FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			long A = Long.parseLong(st.nextToken());
			int N = Integer.parseInt(st.nextToken());

			long[] motes = new long[N];
			st = new StringTokenizer(f.readLine());
			for (int i = 0; i < N; i++) {
				motes[i] = Long.parseLong(st.nextToken());
			}
			Arrays.sort(motes);

			System.out.println(A);
			System.out.println(Arrays.toString(motes));
			int ans = recurse(motes, 0, A, 0);
			System.out.println(caseStr(caseId) + " " + ans);
			out.println(caseStr(caseId) + " " + ans);
		}

		out.close(); // close the output file
	}

	private static int recurse(long[] motes, int depth, long currMote, int added) {
		long newCurrMote = currMote;
		int newDepth = depth;
		for (; newDepth < motes.length; newDepth++) {
			if (newCurrMote > motes[newDepth]) {
				newCurrMote += motes[newDepth];
			} else {
				break;
			}
		}
		if (newDepth == motes.length) {
			return added;
		}
		long newAddedMote = newCurrMote * 2 - 1;
		int mods = Integer.MAX_VALUE;
		if (newAddedMote > newCurrMote) {
			mods = recurse(motes, newDepth, newAddedMote, added + 1);
		}
		return Math.min(mods, motes.length - newDepth + added);

	}
}
