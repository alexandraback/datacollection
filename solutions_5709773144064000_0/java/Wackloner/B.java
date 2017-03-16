import java.io.*;
import java.util.*;

public class B implements Runnable {
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			double c = nextDouble(), f = nextDouble(), x = nextDouble();
			double wasted = 0, best = Double.MAX_VALUE;
			for (int farms = 0;; farms++) {
				double current = wasted + x / (farms * f + 2);
				if (current > best + 1e-7)
					break;
				best = current;
				wasted += c / (farms * f + 2);
			}
			print("Case #");
			print(testNumber);
			print(": ");
			Locale.setDefault(Locale.US);
			writer.printf("%.7f", best);
			println();
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	public void run() {
		try {
			String file = "";
//			file = "console";
			if (file.equals("console")) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
			} else if (file.equals("")) {
				reader = new BufferedReader(new FileReader(new File("input.txt")));
				writer = new PrintWriter(new File("output.txt"));
			} else {
				reader = new BufferedReader(new FileReader(new File(file + ".in")));
				writer = new PrintWriter(new File(file + ".out"));
			}
			solve();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(261);
		}
	}
	
	void halt() {
		writer.close();
		System.exit(0);
	}
	
	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(objects[i]);
		}
	}
	
	void println(Object... objects) {
		print(objects);
		writer.println();
	}
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(nextLine());
		return tokenizer.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}