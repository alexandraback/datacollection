import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class QA {

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

			solve();
		}

		pw.close();
	}

	private static void solve() throws IOException {
		BigInteger base = BigInteger.valueOf(readInt());

		if (base.equals(BigInteger.ZERO)) {
			pw.println("INSOMNIA");
			return;
		}

		BigInteger current = base;

		map = new boolean[10];
		mapCount = 0;

		while (!updateMap(current)) {
			current = current.add(base);
		}

		pw.println(current);
	}

	private static boolean updateMap(BigInteger current) {
		char[] chars = current.toString().toCharArray();
		for (char c : chars) {
			int i = c - '0';
			if (!map[i]) {
				map[i] = true;
				mapCount++;
				if (mapCount == 10)
					return true;
			}
		}
		return false;
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
