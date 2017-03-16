package codeJamA;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	public static int getRev(int x) {
		String t = String.valueOf(x);
		StringBuilder y = new StringBuilder("");
		for (int i = t.length() - 1; i >= 0; i--) {
			y.append(t.charAt(i));
		}
		return Integer.valueOf(y.toString());
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		 InputReader in = new InputReader(new FileInputStream(new File("src/input.txt")));
		 PrintWriter out = new PrintWriter(new File("src/output.txt"));
		 int t = in.nextInt();
		 for (int j = 0; j < t; j++) {
			 int n = in.nextInt();
			 boolean found[] = new boolean[n + 1];
			 List<Integer> o = new LinkedList<Integer>();
			 List<Integer> oo = new LinkedList<Integer>();
			 int step = 1;
			 o.add(1); found[1] = true;
			 while (!found[n]) {
				 step++;
				 for (int x : o) {
					 if (!found[x + 1]) {
						 found[x + 1] = true;
						 oo.add(x + 1);
					 }
					 int y = getRev(x);
					 if (y <= n) {
						 if (!found[y]) {
							 found[y] = true;
							 oo.add(y);
						 }
					 }
				 }
				 o = oo;
				 oo = new LinkedList<Integer>();
			 }
			 out.println("Case #" + (j + 1) + ": " + step);			 
		 }
		 out.close();
	}	
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public String nextLine() throws IOException {
		return reader.readLine();
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
	
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}