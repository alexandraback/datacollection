import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R1B2 {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int K = readInt();
			int L = readInt();
			int S = readInt();

			char[] keys = nextToken().toCharArray();
			String word = nextToken();

			int minPeriod = (word + word).indexOf(word, 1);
			int maxBananas = (S - word.length()) / minPeriod + 1;

			if (S < L || maxBananas < 0) {
				maxBananas = 0;
				pw.println(0);
				continue;
			}

			float[] p = new float['Z' - 'A' + 1];

			for (int i = 0; i < keys.length; i++) {
				p[keys[i] - 'A'] += 1.0 / K;
			}

			float pr = S - L + 1;
			for (int i = 0; i < word.length(); i++) {
				pr *= p[word.charAt(i) - 'A'];
				if (p[word.charAt(i) - 'A'] == 0) {
					maxBananas = 0;
					pr = 0;
				}
			}

			float exp = maxBananas - pr;

			System.out.println("Case #" + qq + ": " + exp);
			pw.println(exp);
		}

		pw.close();
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
