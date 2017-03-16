package a;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Problem solver = new Problem();
		int testCases = in.nextInt();
		for (int i = 1; i <= testCases; i++)
			solver.solve(i, in, out);

		out.close();
	}
}

class Problem implements Solver {

	public void solve(int testCase, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		boolean isDiamond = false;

		Node[] nodes = new Node[n + 1];
		for (int i = 1; i <= n; i++) {
			nodes[i] = new Node(i);
		}

		Log.o(Log.getCurrentMethodName() + "Case " + testCase + " nodes " + n);

		for (int i = 1; i <= n; i++) {
			Node node = nodes[i];
			int liczbaPrzodkow = in.nextInt();
			for (int ii = 0; ii < liczbaPrzodkow; ii++) {
				int przodekNumber = in.nextInt();
				Node przodek = nodes[przodekNumber];
				node.storePrzodek(przodek);
			}
		}
		
		for (int i = 1; i <= n; i++) {
			Node node = nodes[i];
			if (node.setAllPrzodek()){
				isDiamond = true;
				break;
			}
		}

		out.println("Case #" + testCase + ": " + (isDiamond ? "Yes" : "No"));
	}

	private class Node {
		int number;
		Set<Node> przodkowie = new HashSet<Node>();
		Set<Node> przodStore = new HashSet<Node>();
		Set<Node> potomkowie = new HashSet<Node>();

		public Node(int number) {
			this.number = number;
		}
		
		public void storePrzodek(Node przodek){
			przodStore.add(przodek);
			przodek.potomkowie.add(this);
		}
		
		public boolean setAllPrzodek(){
			for(Node przodek : przodStore){
				if(setPrzodek(przodek))
					return true;
			}
			return false;
		}

		public boolean setPrzodek(Node przodek) {
			Log.o(Log.getCurrentMethodName() + "ustawiam przodka "
					+ przodek.number + " dla node " + number);

			boolean changed = przodkowie.add(przodek);
			if (!changed)
				return true;

			for (Node potomek : potomkowie) {
				boolean common = potomek.setPrzodek(przodek);
				if (common)
					return true;
			}

			return false;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + number;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Node other = (Node) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (number != other.number)
				return false;
			return true;
		}

		private Problem getOuterType() {
			return Problem.this;
		}
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

	public boolean haveNextInCurrentLine() {
		return (tokenizer != null && tokenizer.hasMoreTokens());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}

interface Solver {
	void solve(int testCase, InputReader in, PrintWriter out);
}

class Log {

	private static final String EMPTY_STRING = "";

	private Log() {
	}

	public static boolean isLoggable() {
		return false;
	}

	public static void o(String message) {
		if (isLoggable()) {
			System.out.println(message);
		}
	}

	public static void e(String message) {
		if (isLoggable()) {
			System.err.println(message);
		}
	}

	public static String getCurrentMethodName() {
		if (!isLoggable())
			return EMPTY_STRING;

		StackTraceElement[] stackTraceElements = Thread.currentThread()
				.getStackTrace();

		return String.format("%s() ", stackTraceElements[2].getMethodName());
	}
}
