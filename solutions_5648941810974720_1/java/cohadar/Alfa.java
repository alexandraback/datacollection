import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Alfa {

	static final String[] D = new String[] {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE"};
	static final int[] E = new int[] {0, 2, 6, 8, 3, 4, 1, 5, 7, 9};
	final char[] C;
	final int[] F;
	final List<Integer> L;
	
	public Alfa(char[] C) {
		this.C = C;
		this.F = new int[256];
		this.L = new ArrayList<>();
		for (int i = 0; i < C.length; i++) {
			F[C[i]]++;
		}
	}

	public boolean ok(String name) {
		for (int i = 0; i < name.length(); i++) {
			if (F[name.charAt(i)] == 0) {
				return false;
			}
		}
		return true;
	}

	public void sub(String name) {
		for (int i = 0; i < name.length(); i++) {
			F[name.charAt(i)]--;
		}
	}

	public void solve(String name, int digit) {
		while (ok(name)) {
			sub(name);
			L.add(digit);
		}
	}

	public String solve(int it) {
		for (int i = 0; i < D.length; i++) {
			solve(D[i], E[i]);
		}
		for (int i = 0; i < F.length; i++) {
			assert F[i] == 0;
		}
		Collections.sort(L);
		return join(L, "");
	}

	static String join(List<Integer> A, String delimiter) {
		StringBuilder sb = new StringBuilder();
		for (int a : A) {
			sb.append(a);
			sb.append(delimiter);
		}
		if (sb.length() >= delimiter.length()) {
			sb.setLength(sb.length() - delimiter.length());
		}			
		return sb.toString();
	}

	public static Alfa load(Scanner scanner) {
		char[] C = scanner.nextLine().toCharArray();
		return new Alfa(C);
	}	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nt = scanner.nextInt();
		scanner.nextLine();
		assert 1 <= nt && nt <= 100 : "out of range, nt: " + nt;
		for (int it = 1; it <= nt; it++) {
			Alfa o = Alfa.load(scanner);
			System.out.printf("Case #%d: %s\n", it, o.solve(it));
		}
	}

	static void debug(Object...os) {
		System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

}
