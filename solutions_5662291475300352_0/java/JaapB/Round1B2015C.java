import static org.junit.Assert.assertEquals;

import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

//jaap@beetstra-it.nl
public class Round1B2015C {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void tests() throws Exception {
		assertEquals(0, solve("2 1 1 12 359 1 12"));
	}

	@Test
	public void testB() throws Exception {
		assertEquals(1, solve("2 180 1 1000000 180 1 1"));
	}

	@Test
	public void testC() throws Exception {
		assertEquals(0, solve("1 180 2 1"));
	}

	static int solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Solver {
		private final int count;
		private final int[] d;
		private final int[] h;
		private final int[] m;

		public Solver(Scanner scanner) {
			this.count = scanner.nextInt();
			this.d = new int[count];
			this.h = new int[count];
			this.m = new int[count];
			for (int i = 0; i < count; i++) {
				d[i] = scanner.nextInt();
				h[i] = scanner.nextInt();
				m[i] = scanner.nextInt();
			}
		}

		public int solve() {
			// alleen small 1
			int d0 = d[0];
			int d1 = d[0];
			int m0 = m[0];
			int m1 = m[0] + 1;
			if (count > 1) {
				if (d[0] < d1) {
					d1 = d[1];
					m1 = m[1];
				} else {
					d0 = d[1];
					m0 = m[1];
					m1 = m[0];
				}
			}
			// tijd achter dichtsbijzijnde
			double lap00 = (360.0 - d0) * m0 / 360.0;
			// afstand andere:
			double r1 = lap00 * m1 + d1;
			if (r1 > 720)
				return 1;
			return 0;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
	}
}
