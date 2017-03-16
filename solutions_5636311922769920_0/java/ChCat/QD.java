import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QD {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static boolean[] map;
	static int mapCount;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int K = readInt();
			int C = readInt();
			int S = readInt();

			if (K <= S) {
				for (int i = 1; i <= K; i++) {
					pw.print(String.valueOf(i) + ' ');
				}
				pw.println();
			} else {
				pw.println("IMPOSSIBLE");
			}

		}

		pw.close();
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
