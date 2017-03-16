import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Part_Elf {

	private Scanner sc = new Scanner(System.in);
	private PrintStream ps = new PrintStream(System.out);

	private void setIO(InputStream is, OutputStream os) {
		sc = new Scanner(is);
		ps = new PrintStream(os);
	}

	private void solve() throws FileNotFoundException {
		int cases = sc.nextInt();

		for (int tCases = 1; tCases <= cases; ++tCases) {
			String[] pq = sc.next().split("/");
			long p = Long.parseLong(pq[0]);
			long q = Long.parseLong(pq[1]);
			int generation = 0, otherGeneration = 0;
			boolean other = false;

			while (p < q) {
				p *= 2;
				long gcd = gcd(p, q);
				p /= gcd;
				q /= gcd;

				if (other) {
					if (++otherGeneration > 40) {
						break;
					}
				} else {
					if (++generation > 40) {
						break;
					}
				}

				if (p == q) {
					break;
				} else if (p > q) {
					p -= q;

					if (!other) {
						other = true;
						otherGeneration = generation;
					}
				}
			}

			if (otherGeneration > 0 && otherGeneration > 40 || generation > 40) {
				ps.println("Case #" + tCases + ": impossible");
			} else {
				ps.println("Case #" + tCases + ": " + generation);
			}
		}

		sc.close();
	}

	private long gcd(long a, long b) {
		long temp;

		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}

		while (b > 0) {
			temp = a % b;
			a = b;
			b = temp;
		}

		return a;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Part_Elf solver = new Part_Elf();

		InputStream is = new FileInputStream("Problems\\Part_Elf\\A-large.in");
		OutputStream os = new FileOutputStream(
				"Problems\\Part_Elf\\A-large.out");
		solver.setIO(is, os);

		solver.solve();
	}
}
