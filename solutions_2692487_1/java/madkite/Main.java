import java.io.*;
import java.util.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class Main extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String[] ss = br.readLine().split(" ");
				assert ss.length == 2;
				int a = Integer.parseInt(ss[0]);
				int n = Integer.parseInt(ss[1]);
				ss = br.readLine().split(" ");
				assert ss.length == n;
				int[] m = new int[n];
				for(int i = 0; i < n; i++)
					m[i] = Integer.parseInt(ss[i]);
				return new Main(a, m);
			}
		}, "google/src/gcj2013r1b/" + "A-large.in");
	}
	private final int a, m[];
	public Main(int a, int[] m) {
		this.a = a;
		this.m = m;
	}
	public String call() throws Exception {
		LArrays.qrsort(m);
		return Integer.toString(solve(a, 0));
	}
	private int solve(long q, int p) {
		for(; p < m.length; p++) {
			if(m[p] >= q)
				break;
			q += m[p];
		}
		if(p == m.length)
			return 0;
		if(q == 1)
			return m.length - p;
		return Math.min(m.length - p, 1 + solve(q + q - 1, p));
	}
}
interface SolutionFactory<V> {
	Callable<V> read(BufferedReader br) throws IOException;
}
abstract class SingleThreadSolution<V> implements Callable<V> {
	protected static void solve(SolutionFactory factory, String input) throws Exception {
		String output = null;
		if(input.endsWith(".in"))
			output = input.substring(0, input.length() - 2) + "out";
		solve(factory, input, output);
	}
	protected static void solve(SolutionFactory factory, String input, String output) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(input));
		if(output != null)
			System.setOut(new PrintStream(output));
		solve(factory, br);
	}
	protected static void solve(SolutionFactory factory, BufferedReader br) throws Exception {
		long time = System.currentTimeMillis();
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++)
			System.out.println("Case #" + (i + 1) + ": " + factory.read(br).call());
		time = System.currentTimeMillis() - time;
		Thread.sleep(100);
		System.err.println(time);
	}
}
abstract class LArrays {
	private static final int Hs[] = new int[]{1, 4, 9, 24, 85, 126};

	public static void ssort(int[] a, int lo, int hi) {
		for(int k = Hs.length - 1; k >= 0; k--) {
			for(int h = Hs[k], i = lo + h, j; i <= hi; i++) {
				int m = a[i];
				for(j = i - h; j >= lo && a[j] > m; j -= h)
					a[j + h] = a[j];
				a[j + h] = m;
			}
		}
	}
	public static void qrsort(int[] a) {
		qrsort(a, 0, a.length - 1);
	}
	public static void qrsort(int[] a, int lo, int hi) {
		XorRandom random = new Xor64Random();
		while(hi - lo >= 255) {
			int i = lo, j = hi;
			for(int m = a[lo + random.nextInt(hi - lo)];;) {
				while(i < hi && a[i] < m)
					i++;
				while(j > lo && a[j] > m)
					j--;
				if(i >= j)
					break;
				int t = a[i]; a[i++] = a[j]; a[j--] = t;
			}
			if((--i - lo) < (hi - ++j)) {
				qrsort(a, lo, i);
				lo = j;
			} else {
				qrsort(a, j, hi);
				hi = i;
			}
		}
		ssort(a, lo, hi);
	}

	public static interface IntComparator {
	}
}
abstract class XorRandom extends Random {
	@Override
	public abstract int nextInt();
	@Override
	protected int next(int bits) {
		return nextInt() >>> (32 - bits);
	}
	@Override
	public int nextInt(int n) {
		return (nextInt() >>> 1) % n;
	}
	@Override
	public long nextLong() {
		return ((long)(nextInt()) << 32) + nextInt();
	}
	private static final double MAX_DOUBLE = (double)(1l << 53);
	@Override
	public double nextDouble() {
		return (nextLong() >>> 11) / MAX_DOUBLE;
	}
	private double dGaussian;
	private boolean bGaussian;
	public double nextGaussian() {
		if(bGaussian) {
			bGaussian = false;
			return dGaussian;
		} else {
			double v1, v2, s;
			do {
				v1 = 2 * nextDouble() - 1;
				v2 = 2 * nextDouble() - 1;
				s = v1 * v1 + v2 * v2;
			} while(s >= 1 || s == 0);
			dGaussian = v2 * (s = Math.sqrt(-2 * Math.log(s) / s));
			bGaussian = true;
			return v1 * s;
		}
	}
}
class Xor64Random extends XorRandom {
	private long x;
	public Xor64Random(long seed) {
		x = seed != 0 ? seed : 88172645463325252l;
	}
	public Xor64Random() {
		this(System.nanoTime());
	}
	@Override
	protected int next(int bits) {
		return (int)(nextLong() >>> (64 - bits));
	}
	@Override
	public long nextLong() {
		x ^= (x << 13);
		x ^= (x >>> 7);
		x ^= (x << 17);
		return x;
	}
	@Override
	public int nextInt() {
		return (int)nextLong();
	}
}
