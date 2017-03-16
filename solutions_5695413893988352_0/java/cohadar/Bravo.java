import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Bravo {

	final int n;
	final char[] C;
	final char[] J;
	
	public Bravo(char[] C, char[] J) {
		this.n = C.length;
		this.C = C;
		this.J = J;
		assert C.length == J.length;
	}
	
	public static Result makeResult(char[] A, char[] B) {
		long a = Long.valueOf(new String(A));
		long b = Long.valueOf(new String(B));
		return new Result(a, b);
	}

	public boolean next(char[] A, char[] B) {
		for (int i = B.length - 1; i >= 0; i--) {
			if (J[i] == '?') {
				if (B[i] == '9') {
					B[i] = '0';
				} else {
					B[i]++;
					return true;
				}
			}
		}
		for (int i = A.length - 1; i >= 0; i--) {
			if (C[i] == '?') {
				if (A[i] == '9') {
					A[i] = '0';
				} else {
					A[i]++;
					return true;
				}
			}
		}
		return false;
	}

	public String solve(int it) {
		char[] A = Arrays.copyOf(C, n);
		char[] B = Arrays.copyOf(J, n);
		for (int i = 0; i < n; i++) {
			if (A[i] == '?') {
				A[i] = '0';
			}
			if (B[i] == '?') {
				B[i] = '0';
			}			
		}
		Result min = makeResult(A, B);
		while (next(A, B)) {
			Result r = makeResult(A, B);
			if (min.compareTo(r) > 0) {
				min = r;
			}
		}
		return transform(min);
	}

	public String transform(Result r) {
		return String.format("%0#d %0#d".replaceAll("#", ""+n), r.a, r.b);
	}

	public static Bravo load(Scanner scanner) {
		String[] S = scanner.nextLine().split(" ");
		return new Bravo(S[0].toCharArray(), S[1].toCharArray());
	}	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nt = scanner.nextInt();
		scanner.nextLine();
		assert 1 <= nt && nt <= 200 : "out of range, nt: " + nt;
		for (int it = 1; it <= nt; it++) {
			Bravo o = Bravo.load(scanner);
			System.out.printf("Case #%d: %s\n", it, o.solve(it));
		}
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

	static class Result implements Comparable<Result> {
		final long diff;
		final long a;
		final long b;
		Result(long a, long b) {
			this.diff = Math.abs(a - b);
			this.a = a;
			this.b = b;
		}
		public int compareTo(Result that) {
			if (this.diff == that.diff) {
				if (this.a == that.a) {
					return Long.compare(this.b, that.b);
				} else {
					return Long.compare(this.a, that.a);
				}				
			} else {
				return Long.compare(this.diff, that.diff);
			}
		}
		public String toString() {
			return String.format("(a=%d, b=%d)", a, b);
		}	
	}

}
