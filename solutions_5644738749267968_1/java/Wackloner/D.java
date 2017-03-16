import java.io.*;
import java.util.*;

public class D implements Runnable {
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			System.out.println("Test #" + testNumber);
			int n = nextInt();
			double[] naomis = new double[n];
			for (int i = 0; i < n; i++)
				naomis[i] = nextDouble();
			Arrays.sort(naomis);
			double[] kens = new double[n];
			for (int i = 0; i < n; i++)
				kens[i] = nextDouble();
			Arrays.sort(kens);
			int deceitful = 0;
			for (int i = 0, j = 0; i < n; i++) {
				if (naomis[i] > kens[n - i + j - 1]) {
					deceitful += n - i;
					break;
				}
				if (naomis[i] > kens[j]) {
					deceitful++;
					j++;
				}			
			}
			int usual = 0;
			for (int i = 0, j = 0; i < n; i++, j++) {
				while (j < n && naomis[i] > kens[j])
					j++;
				if (j == n) {
					usual = n - i;
					break;
				}
			}
			print("Case #");
			print(testNumber);
			print(": ");
			println(deceitful, usual);
		}
	}
	
	public static void main(String[] args) {
		new D().run();
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