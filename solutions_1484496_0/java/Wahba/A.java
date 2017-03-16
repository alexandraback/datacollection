import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class A {

	private void solve() throws IOException {
		int T = nextInt();
		end2: while (T-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			HashMap<Integer, ArrayList<ArrayList<Integer>>> H = new HashMap<Integer,ArrayList<ArrayList<Integer>>>();
			for (int i = 0; i < 1 << n; i++) {
				ArrayList<Integer> S = new ArrayList<Integer>();
				int res = 0;
				for (int j = 0; j < n; j++) {
					if ((i & (1 << j)) != 0) {
						S.add(a[j]);
						res += a[j];
					}
				}
				if (!S.isEmpty()) {
					if (H.containsKey(res)) {
						ArrayList<ArrayList<Integer>> cur = H.get(res);
						cur.add(S);
						H.put(res, cur);
					} else {
						ArrayList<ArrayList<Integer>> A = new ArrayList<ArrayList<Integer>>();
						A.add(S);
						H.put(res, A);
					}
				}
			}
			
			for (int sum : H.keySet()) {
				ArrayList<ArrayList<Integer>> cur = H.get(sum);
				if (cur.size() < 2) continue;
				for (ArrayList<Integer> S : cur)
					for (ArrayList<Integer> S1 : cur)
						if (!equal(S, S1)) {
							pf();
							pl();
							println(S);
							println(S1);
							continue end2;
						}
			}
		}

	}

	private void println(ArrayList<Integer> s) {
		StringBuilder sb = new StringBuilder();
		for (int a : s)
			sb.append(a + " ");
		pl(sb.toString().trim());
	}

	private boolean equal(ArrayList<Integer> a, ArrayList<Integer> b) {

		end: for (int R : a) {
			for (int R1 : b)
				if (R == R1)
					continue end;
			return false;
		}
		return true;
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			 reader = new BufferedReader(new FileReader("A.in"));
//			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
//			writer = new PrintWriter(System.out);
			 writer = new PrintWriter("A.out");
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.flush();
			writer.print(objects[i]);
			writer.flush();
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.flush();
		writer.println();
		writer.flush();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
		writer.flush();
	}

}
