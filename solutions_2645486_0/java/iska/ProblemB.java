import java.util.*;
import java.io.*;

public class ProblemB {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "B-small-attempt0.in";
	private static final String OUT_FILE = "output_b.txt";
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_DIR + "/" + IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_DIR + "/" + OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		int numTests = sc.nextInt();
		sc.nextLine();
		try {
			for (int i = 0; i < numTests; i++) {
				handleTest(sc, out, i+1);
			}

			// clean up
			sc.close();
			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws IOException {
		long E = sc.nextLong();
		long R = sc.nextLong();
		int N = sc.nextInt();
		
		long[] v = new long[N];
		for (int i = 0; i < N; i++) {
			v[i] = sc.nextLong();
		}
		
		long result = recBestResult(E, R, E, 0, v);
		
		out.write("Case #" + caseNum + ": " + result + '\n');
	}

	private static long recBestResult(long maxE, long R, long curE, int findex, long[] v) {
		if (findex == v.length - 1) {
			return curE * v[v.length - 1];
		}
		
		long result = -1;
		for (long i = 0; i <= curE; i++) {
			long curResult = i*v[findex];
			curResult += recBestResult(maxE, R, Math.min(curE - i + R, maxE), findex + 1, v);
			result = Math.max(result, curResult);
		}
		return result;
	}
	
}
