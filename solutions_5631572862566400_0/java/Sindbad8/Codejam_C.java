
import java.io.*;
import java.math.*;
import java.util.*;

public class Codejam_C {

	static int mod = (int) 1e9 + 7;
	static int MAX = (int) 1e9;
	static ArrayList<Integer>[] g;
	static int[] a;
	static boolean[] done;
    static FasterScanner inputReader;
    static PrintWriter outputWriter;
	public static void main(String[] args) {
		inputReader = new FasterScanner();
		outputWriter = new PrintWriter(System.out);
		int testecases = inputReader.nextInt();
		int test = 0;
		while(testecases-->0) {
			test++;
			function(test);
		}
		outputWriter.close();
	}
	static void function(int test){
		int length = inputReader.nextInt();
		int finalAnswer = 0;
		int tempAnswer = 0;
		length = 1+length;
		boolean[] x = new boolean[length-1];
		length--;
		a = new int[length];
		for(int i=0;i<length;i++)
			a[i] = inputReader.nextInt();
		done = new boolean[length];
		len = new int[length];
		for (int i = 0; i < length; i++)
			a[i]--;
		visited = new boolean[length];
		g = new ArrayList[length];
		for (int i = 0; i< length ; i++){
			g[i] = new ArrayList<>();
		}
		for(int i=0;i<length;i++)
			g[a[i]].add(i);
		for (int i = 0; i < length; i++) {
			if(a[a[i]] == i) {
				x[i] = true;
				dfs(i,a[i]);
			}
		}
		finalAnswer = 0;
		tempAnswer = 0;
		for(int i = 0; i <length;i++){
			if(x[i] == true){
				tempAnswer += len[i];
			}
		}
		finalAnswer = tempAnswer;
		boolean tmpvisited[] = new boolean[length];
		for (int i = 0; i < length; i++) {
			if(visited[i])
				continue;
			int j = i;
			int count = 0;
			tmpvisited = new boolean[length];
			while(tmpvisited[j]!=true){
				tmpvisited[j] = true;
				j = a[j];
				count++;
			}
			if(j==i){
				finalAnswer = Math.max(finalAnswer, count);
				for(int xx=0;xx<length;xx++)
					visited[xx] |= tmpvisited[xx];
			}
		}

		outputWriter.println("Case #"+test+": "+finalAnswer);
	}
	static int len[];
	static boolean visited[];
	static void dfs(int u ,int parent){
		done[u] = true;
		for(int v:g[u]){
			if(v!=parent && !visited[v]){
				dfs(v,u);
				len[u] = Math.max(len[u], len[v]);
			}
		}
		len[u]++;
	}

	static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int snumChars;

		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}