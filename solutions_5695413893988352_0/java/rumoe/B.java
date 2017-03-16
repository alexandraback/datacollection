package j2016.r1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final String FILE_NAME = "B-small-attempt3";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = B.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public B () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		char[] A = next().toCharArray();
		char[] B = next().toCharArray();
		
		R r = min(A, B, 0, 0);
		/*
		for (int i = 0; i < A.length; i++) {
			if (A[i] == '?' && B[i] == '?') {
				if (d == 0) {
					if (i > 0) {
						
					} else {
						A[i] = '0';
						B[i] = '0';
					}
				} else if (d == 1) {
					A[i] = '9';
					B[i] = '0';
				} else {
					A[i] = '0';
					B[i] = '9';
				}
			}
			else if (A[i] == '?') {
				if (d == 0) {
					A[i] = B[i];
				} else if (d == 1) {
					A[i] = '9';
				} else {
					A[i] = '0';
				}
			}
			else if (B[i] == '?') {
				if (d == 0) {
					B[i] = A[i];
				} else if (d == 1) {
					B[i] = '0';
				} else {
					B[i] = '9';
				}
			} else if (d == 0){
				if (A[i] > B[i]) {
					d = -1;
				} else {
					d = 1;
				}
			}
		} */
		A = r.A;
		B = r.B;
		String s = String.format("%s %s", new String(A), new String(B));
		print(s);
	}
	
	R min(char[] A, char[] B, int i , int r) {
		if (r != 0) {
			for (; i < A.length; i++) {
				if (A[i] == '?') {
					if (r > 0) A[i] = '9';
					else A[i] = '0';
				}
				if (B[i] == '?') {
					if (r < 0) B[i] = '9';
					else B[i] = '0';
				}
			}
		}
		if (i >= A.length) {
			int a = Integer.valueOf(new String(A));
			int b = Integer.valueOf(new String(B));
			int d = Math.abs(a-b);
			return new R(A,B,d);
		}
		
		R min = new R(null, null, Integer.MAX_VALUE);
		if (A[i] == '?' && B[i] == '?') {
			char[] ac = A.clone();
			char[] bc = B.clone();
			ac[i] = '0'; bc[i] = '0';
			min = mins(min, min(ac, bc, i+1, 0));
			ac = A.clone();
			bc = B.clone();
			ac[i] = '0'; bc[i] = '1';
			min = mins(min, min(ac, bc, i+1, 1));
			ac = A.clone();
			bc = B.clone();
			ac[i] = '1'; bc[i] = '0';
			min = mins(min, min(ac, bc, i+1, -1));
			ac = A.clone();
			bc = B.clone();
			ac[i] = '0'; bc[i] = '9';
			min = mins(min, min(ac, bc, i+1, 1));
			ac = A.clone();
			bc = B.clone();
			ac[i] = '9'; bc[i] = '0';
			min = mins(min, min(ac, bc, i+1, -1));
		} else if (A[i] == '?') {
			char[] ac = A.clone();
			ac[i] = B[i];
			min = mins(min, min(ac, B, i+1, 0));
			if (B[i] != '9') {
				ac = A.clone();
				ac[i] = (char) (B[i]+1);
				min = mins(min, min(ac, B, i+1, -1));
			}
			if (B[i] != '0') {
				ac = A.clone();
				ac[i] = (char) (B[i]-1);
				min = mins(min, min(ac, B, i+1, 1));
			}
		} else if (B[i] == '?') {
			char[] bc = B.clone();
			bc[i] = A[i];
			min = mins(min, min(A,bc, i+1, 0));
			if (A[i] != '9') {
				bc = B.clone();
				bc[i] = (char) (A[i]+1);
				min = mins(min, min(A, bc, i+1, 1));
			}
			if (A[i] != '0') {
				bc = B.clone();
				bc[i] = (char) (A[i]-1);
				min = mins(min, min(A, bc, i+1, -1));
			}
		} else {
			if (A[i] == B[i]) {
				min = min(A, B, i+1, 0);
			} else if (A[i] > B[i]) {
				min = min(A, B, i+1, -1);
			} else {
				min = min(A, B, i+1, 1);
			}
		}
		return min;
	}
	
	R mins(R a, R b) {
		if (a.d != b.d) {
			return a.d < b.d ? a : b;
		}
		
		String A = new String(a.A);
		String B = new String(b.A);
		if (A.compareTo(B) != 0) {
			if (A.compareTo(B) < 0) {
				return a;
			} else {
				return b;
			}
		}
		A = new String(a.B);
		B = new String(b.B);
		if (A.compareTo(B) < 0) {
			return a;
		} else {
			return b;
		}
	}
	
	class R {
		char[] A; char[] B; int d;
		R(char[] A, char[] B, int d) {
			this.A = A;
			this.B = B;
			this.d = d;
		}
	}
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
