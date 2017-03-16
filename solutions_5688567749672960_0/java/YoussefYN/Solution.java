import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;

class pair {
	public int f, s;

	public pair(int ff, int ss) {
		f = ff;
		s = ss;
	}
}

public class Solution {

	static int bfs(int n) {
		boolean[] visited = new boolean[100000000];
		Queue<pair> q = new LinkedBlockingQueue<pair>();
		q.add(new pair(1,1));
		visited[1] = true;
		pair node, temp;
		if(1 == n){
			return 1;
		}
		while (!q.isEmpty()) {
			node = q.poll();
			temp = new pair(node.f + 1, node.s + 1);
			if (!visited[temp.f]) {
				if (temp.f == n) {
					return temp.s;
				}
				visited[temp.f] = true;
				q.add(temp);
			}
			temp = new pair(reverse(node.f), node.s + 1);
			if (!visited[temp.f]) {
				if (temp.f == n) {
					return temp.s;
				}
				visited[temp.f] = true;
				q.add(temp);
			}
		}
		return -1;
	}

	public static int reverse(int n) {
		return Integer.parseInt(new StringBuilder(""+n).reverse().toString());
	}

	public static void main(String[] args) throws IOException {
//		InputReader in = new InputReader(System.in);
//		FastPrinter out = new FastPrinter(System.out);
		 InputReader in = new InputReader(new FileInputStream(
			 "A-small-attempt0.in"));
			 FastPrinter out = new FastPrinter(new FileOutputStream("OUT.txt"));
		int t = in.nextInt();
		for (int i = 1; t-- > 0; i++)
			out.printf("Case #%d: %d\n",i,bfs(in.nextInt()));
		out.close();
	}
}

class ArrayUtils {
	static final Random rand = new Random(System.nanoTime());

	static final public int[] sortAndUnique(int[] a) {
		int[] ret = a.clone();
		sort(ret);
		if (ret.length == 0) {
			return ret;
		}
		int last = ret[0];
		int j = 1;
		for (int i = 1; i < ret.length; i++)
			if (last != ret[i]) {
				ret[j++] = ret[i];
				last = ret[i];
			}
		return Arrays.copyOf(ret, j);
	}

	public static final void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static final void shuffle(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rand.nextInt(i + 1);
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

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

	public String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	public int[] readIntArray(int n) {
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = nextInt();
		return ret;
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

	public BigInteger nextBigInt() {
		return new BigInteger(next());
	}
}

class FastPrinter extends PrintWriter {

	public FastPrinter(OutputStream out) {
		super(out);
	}

	public FastPrinter(Writer out) {
		super(out);
	}

}