import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution {

	static InputReader in = new InputReader(System.in);
	static int mod = (int) (1e9 + 7);

	public static void main(String[] args) throws IOException {

		int n = in.nextInt();

		PrintWriter pw = new PrintWriter(new File("/home/omar/Desktop/out.txt"));

		for (int j = 1; j <= n; j++) {
			StringBuilder sb = new StringBuilder();

			String str = in.readLine();

			sb.append(str.charAt(0));

			for (int i = 1; i < str.length(); i++) {
				if (str.charAt(i) >= sb.charAt(0)) {
					sb.insert(0, str.charAt(i));
				} else {
					sb.append(str.charAt(i));
				}
			}

			pw.println("Case #" + j + ": " + sb);

		}

		pw.close();
	}
}

class ListComparator implements Comparator<Integer> {

	@Override
	public int compare(Integer e1, Integer e2) {
		return e2.compareTo(e1);
	}
}

class ArrayComparator implements Comparator<Integer[]> {
	@Override
	public int compare(Integer[] o1, Integer[] o2) {
		return o1[0].compareTo(o2[0]);
	}
};

class Pair {

	int x;
	int y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String readLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public float nextFloat() {
		return Float.parseFloat(next());
	}

}