import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		int n = in.nextInt();
		
		for (int i = 1; i <= n; i++) {
			solver.solve(i, in, out);
		}
		out.close();
	}
}

class Solver {
	private HashMap<Integer, Integer> use;
	private int n;
	private int[] s;
	private boolean isFound;
	private int st1, st2;
	private int st;
	private void rec(int step, int sum) {
		if (step < 0) {
			if (use.containsKey(sum)) {
				isFound = true;
				st1 = use.get(sum);
				st2 = st;
			} else {
				use.put(sum, st);
				st++;
			}
			return;
		}
		rec(step - 1, sum);
		if (isFound)
			return;
		rec(step - 1, sum + s[step]);
		return;
	}
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		use = new HashMap<Integer, Integer>();
		isFound = false;
		st = 0;
		n = in.nextInt();
		s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
		}
		rec(n - 1, 0);
		out.format("Case #%d:\n", testNumber);
		if (!isFound) {
			out.println("Impossible");
			return;
		}
		int p = 1;
		for (int i = 0; i < n; i++) {
			if ((st1 & p) != 0)
				out.format("%d ", s[i]);
			p <<= 1;
		}
		out.println();
		p = 1;
		for (int i = 0; i < n; i++) {
			if ((st2 & p) != 0)
				out.format("%d ", s[i]);
			p <<= 1;
		}
		out.println();
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
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

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
