package round1Aj2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	private final String f = "src\\round1Aj2012\\A-large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer token;
		
	private A() throws IOException {
		in = new BufferedReader(new FileReader(f+".in"));
		out = new PrintWriter(f + ".out");
		eat("");
		
		int tests = nextInt();
		for (int i = 1; i <= tests; i++) {
			write("Case #" + i + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		
		double[] prob = new double[a];
		for (int i = 0; i < a; i++) {
			prob[i] = nextDouble();
		}
		
				
		double min = b + 2;
	
		double probCorrect = 1;
		for (int i = 0; i < a; i++) {
			probCorrect *= prob[i];
			
			double correct = probCorrect * ((a - i - 1) + (b - i - 1) + 1);
			double inCorrect = (1 - probCorrect) * ((a - i - 1) + (b - i - 1) + 1 + b + 1);
			double tmpVal = correct + inCorrect;
			min = Math.min(min, tmpVal);
		}
		
		min = Math.min(min, b + a + 1);
		write(min + "\n");
		
	}

	private void printArray(char[][] c) {
		for (char[] i : c) {
			System.out.println(i);
		}
	}
	
	private String next() throws IOException {
		while (!token.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return token.nextToken();
	}
		
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private long nextLong() throws IOException {
		return  Long.parseLong(next());
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	private void eat(String s) {
		token = new StringTokenizer(s);
	}

	private void write(String s) {
		System.out.print(s);
		out.print(s);
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
