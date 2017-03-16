import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;

public class QC {

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
			pw.println("Case #" + qq + ":");

			generate(readInt(), readInt());
		}

		pw.close();
	}

	static Set<String> coins = new HashSet<String>();
	static Random r = new Random();

	static List<String> patterns;
	static {
		patterns = new ArrayList<String>();
		patterns.add("1001+-+-+-+-+-11");
		patterns.add("10010+-+-+-+-011");
		patterns.add("1001+-0+-+-+-011");
		patterns.add("1001+-+-0+-+-011");
		patterns.add("1001+-+-+-0+-011");
		patterns.add("1001+-0+-0+-0011");

	}
	static char[] pattern;
	static int pattern_limit;
	static int seed;

	private static void generate(int n, int j) throws IOException {

		char[] chars = new char[16];

		while (coins.size() < j) {

			if (pattern == null || seed > pattern_limit) {
				pattern = patterns.remove(0).toCharArray();
				int temp = 0;
				for (char c : pattern) {
					if (c == '+')
						temp++;
				}
				pattern_limit = (1 << temp) - 1;
				seed = 0;
			}

			int temp = seed << 1;

			for (int i = 0; i < chars.length; i++) {
				if (pattern[i] == '-') {
					chars[i] = (char) (temp % 2 + '0');
				} else if (pattern[i] == '+') {
					temp = temp >>> 1;
					chars[i] = (char) (temp % 2 + '0');
				} else {
					chars[i] = pattern[i];
				}
			}

			String candidate = new String(chars);

			if (coins.add(candidate)) {
				pw.print(candidate + ' ');
				for (int i = 2; i <= 10; i++) {
					pw.print(String.valueOf(i + 1) + ' ');
				}
				pw.println();
			}

			seed++;
		}

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
