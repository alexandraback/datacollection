package round1b;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A {
	Scanner sc;
	PrintWriter out;

	public static void main(String[] args) throws IOException {
		long iniTime = System.currentTimeMillis();
		
		Locale.setDefault(Locale.US);
		File in = new File("round1b/" + A.class.getSimpleName() + "2.in");
		File out = new File(in.getAbsolutePath().replace(".in", ".out"));
		new A(new Scanner(in), new PrintWriter(out)).solve();
		
		System.out.println("Time: " + (System.currentTimeMillis() - iniTime));
	}

	private void solveCase() throws IOException {
		long a = sc.nextLong();
		int n = sc.nextInt();
		long [] motes = new long[n];
		long cont = 0;
		long contAux = n;
		
		for (int i = 0; i < n; i++) {
			motes[i] = sc.nextLong();
		}
		
		Arrays.sort(motes);
		
		for (int i = 0; i < motes.length; i++) {
			long ms = motes[i];
			
			if (a > ms) {
				a += ms;
			} else {
				contAux = Math.min(contAux, cont + motes.length - i);
				cont++;
				a += a - 1;
				i--;
				if (cont > contAux) {
					break;
				}
			}
		}
		
		out.println(Math.min(cont, contAux));
		System.out.println(Math.min(cont, contAux));
	}

	public A(Scanner sc, PrintWriter out) {
		this.sc = sc;
		this.out = out;
	}

	public void solve() throws NumberFormatException, IOException {
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.printf("Case #%d: ", i);
			out.printf("Case #%d: ", i);
			solveCase();
		}

		sc.close();
		out.close();
	}
}