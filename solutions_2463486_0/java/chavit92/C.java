import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	HashSet<String> numbers = new HashSet<>();

	boolean palin(String s) {
		if (!s.equals(new StringBuilder(s).reverse().toString())) {
			return false;
		}
		BigInteger res = new BigInteger(s);
		res = res.multiply(res);
		if (res.toString().length() >= 100) {
			return false;
		}
		String str = res.toString();
		return (str.equals(new StringBuilder(str).reverse().toString()));

	}

	void checkAndAdd(String s, int i) {
		String str1 = s + 2;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}
		str1 = 2 + s;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}
		str1 = 1 + s;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}
		str1 = s + 1;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}
		for (int j = 0; j < i - 1; j++) {
			s = 0 + s + 0;
		}
		str1 = 1 + s + 1;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}
		str1 = 2 + s + 2;
		if (palin(str1) && !numbers.contains(str1)) {
			numbers.add(str1);
			que.add(str1);
		}

	}

	Queue<String> que = new ArrayDeque<>();

	void solve() throws IOException {
		que.add("0");
		que.add("1");
		que.add("2");
		que.add("3");
		numbers.add("1");
		numbers.add("2");
		numbers.add("3");
		numbers.add("0");
		while (!que.isEmpty()) {
			String v = que.poll();
			System.err.println(v);
			for (int i = 1; i <= 30; i++) {
				checkAndAdd(v, i);
			}
		}
		ArrayList<String> strings = new ArrayList<>();
		for (String s : numbers) {
			strings.add(s);
		}
		Collections.sort(strings);
		for (String s : strings) {
			out.println(s);
		}

	}

	public void run() throws IOException {
		// br = new BufferedReader(new FileReader("res.in"));
		out = new PrintWriter("res.out");
		solve();
		// br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer str;
	PrintWriter out;

	String next() throws IOException {
		while (str == null || !str.hasMoreTokens()) {
			String s = br.readLine();
			if (s != null) {
				str = new StringTokenizer(s);
			} else {
				return null;
			}
		}
		return str.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

}
