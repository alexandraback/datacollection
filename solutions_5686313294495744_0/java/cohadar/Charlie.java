import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Charlie {

	final int nn;
	final Edge[] E;
	final int na;
	final int nb;
	
	public Charlie(int nn, Edge[] E, int na, int nb) {
		this.nn = nn;
		this.E = E;
		this.na = na;
		this.nb = nb;
	}

	public static Integer[] sortedBits(int nb) {
		Integer[] B = new Integer[1<<nb];
		for (int i = 0; i < B.length; i++) {
			B[i] = i;
		}
		Arrays.sort(B, new Comparator<Integer> () {
			public int compare(Integer a, Integer b) {
				return Integer.compare(Integer.bitCount(a), Integer.bitCount(b));
			}
		});
		return B;
	}

	public boolean ok(int bits) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < nn; i++) {
			if ((bits & (1 << i)) != 0) {
				a |= (1 << E[i].a);
				b |= (1 << E[i].b);
			}
		}
		return a == (1 << na) - 1 && b == (1 << nb) - 1;
	}

	public int solve(int it) {
		Integer[] B = sortedBits(nn);
		for (int i = 1; i < B.length; i++) {
			if (ok(B[i])) {
				return nn - Integer.bitCount(B[i]);
			}
		}
		return 0;
	}

	public static int index(String s, Map<String, Integer> M) {
		Integer r = M.get(s);
		if (r == null) {
			r = M.size();
			M.put(s, r);
		}
		return r;
	}

	public static Charlie load(Scanner scanner) {
		int nn = scanner.nextInt();
		scanner.nextLine();
		Map<String, Integer> A = new HashMap<>();
		Map<String, Integer> B = new HashMap<>();
		Edge[] E = new Edge[nn];
		for (int i = 0; i < nn; i++) {
			String[] S = scanner.nextLine().split(" ");
			int a = index(S[0], A);
			int b = index(S[1], B);
			E[i] = new Edge(a, b);
		}
		return new Charlie(nn, E, A.size(), B.size());
	}	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nt = scanner.nextInt();
		scanner.nextLine();
		assert 1 <= nt && nt <= 100 : "out of range, nt: " + nt;
		for (int it = 1; it <= nt; it++) {
			Charlie o = Charlie.load(scanner);
			System.out.printf("Case #%d: %d\n", it, o.solve(it));
		}
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

	static class Edge implements Comparable<Edge> {
		final int a;
		final int b;
		Edge(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Edge that) {
			if (this.a == that.a) {
				return Integer.compare(this.b, that.b);
			} else {
				return Integer.compare(this.a, that.a);
			}
		}
		public String toString() {
			return String.format("(a=%d, b=%d)", a, b);
		}	
	}

}
