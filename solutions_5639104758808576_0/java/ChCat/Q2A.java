import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Q2A {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		final int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int sMax = readInt();
			String spectrumString = nextToken();
			char[] spectrum = spectrumString.toCharArray();
			int currentStanding = 0;
			int add = 0;

			for (int i = 0; i <= sMax; i++) {
				if (currentStanding < i) {
					add += i - currentStanding;
					currentStanding = i;
				}
				currentStanding += (spectrum[i] - '0');
			}

			pw.println(add);

		}

		pw.close();
	}

	private static BitSet makeGuessClear() throws IOException {
		int a1 = readInt();

		skip(a1 - 1);

		BitSet g1 = makeGuess();

		skip(4 - a1);

		return g1;
	}

	private static BitSet makeGuess() throws IOException {
		BitSet g1 = new BitSet(17);

		for (int i = 0; i < 4; i++) {
			int n = readInt();
			g1.set(n);
		}

		return g1;
	}

	private static void skip(int n) throws IOException {
		int i = 1;
		while (i <= n) {
			br.readLine();
			i++;
		}
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}
