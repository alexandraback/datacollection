import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class C implements Runnable {

	ArrayList<Long> res;
	
	public boolean is(String s) {
		long n = Long.parseLong(s);
		double nn = Math.sqrt(n);
		if (nn == (long) nn) {
			if (isPalin("" + (long) nn)) {
				return true;
			}
		}
		return false;
	}
	
	private boolean isPalin(String s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++) {
			if (s.charAt(i) != s.charAt(n - i - 1))
				return false;
		}
		return true;
	}
	
	public String rev(String s) {
		return new StringBuilder(s).reverse().toString();
	}
	public void dfs(long cur) {
		if (cur > 100000000L) return;
		String s = "" + cur;
		String a = s + "" + rev(s);
		String b = s + "" + rev(s.substring(0, s.length() - 1));
		if (is(a)) {
			res.add(Long.parseLong(a));
		}
		if (is(b)) {
			res.add(Long.parseLong(b));
		}
		for (int i = 0; i < 10; i++) {
			if (cur == 0 && i == 0) continue;
			dfs(cur * 10 + i);
		}
	}
	private void solve() throws IOException {
//		res = new ArrayList<Long>();
//		dfs(0);
//
//		for (long e : res) System.out.println(e + "L,");
//		
//		for (int i = 0; i < 100000; i++) {
//			if (isPalin("" + i) && is("" + i)) {
//				System.err.println(i);
//			}
//		}
		
		long[] pre = {1L,
				100000020000001L,
				1000002000001L,
				10000200001L,
				100020001L,
				1002001L,
				1002003002001L,
				100220141022001L,
				1004006004001L,
				10201L,
				102012040210201L,
				102030201L,
				1020304030201L,
				10221412201L,
				1022325232201L,
				102234363432201L,
				1024348434201L,
				104060401L,
				121L,
				121000242000121L,
				1210024200121L,
				12102420121L,
				1212225222121L,
				121242121L,
				121242363242121L,
				1214428244121L,
				12321L,
				123212464212321L,
				1232346432321L,
				1234321L,
				123454321L,
				12345654321L,
				1234567654321L,
				123456787654321L,
				125686521L,
				14641L,
				4L,
				400000080000004L,
				4000008000004L,
				40000800004L,
				400080004L,
				4004009004004L,
				4008004L,
				404090404L,
				40804L,
				44944L,
				484L,
				9L};

		int t = nextInt();
			
		while (t-- > 0) {
			int a = nextInt();
			int b = nextInt();
			
			int res = 0;
			for (int i = 0; i < pre.length; i++) {
				if (pre[i] >= a && pre[i] <= b) {
					++res;
				}
			}
			pf();
			pl(res);
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader("C-small-attempt0.in"));
			writer = new PrintWriter("C.out");
			tokenizer = null;
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
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}