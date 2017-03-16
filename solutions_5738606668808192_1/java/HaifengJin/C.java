import java.math.BigInteger;
import java.util.Scanner;

class Main {
	int n, m;
	private BigInteger[] factor = new BigInteger[12];

	public static void main(String[] args) {

		Main m = new Main();
		m.solve();

	}

	private void solve() {
		Scanner scanner = new Scanner(System.in);
		int t;
		t = scanner.nextInt();
		for (int i = 0; i < t; i++) {
			System.out.printf("Case #%d:\n", i + 1);
			n = scanner.nextInt();
			n -= 2;
			m = scanner.nextInt();
			initFactors();
			work();
		}
		scanner.close();
	}

	private void initFactors() {
		factor[2] = new BigInteger("3");
		factor[3] = new BigInteger("2");
		factor[4] = new BigInteger("3");
		factor[5] = new BigInteger("2");
		factor[6] = new BigInteger("7");
		factor[7] = new BigInteger("2");
		factor[8] = new BigInteger("3");
		factor[9] = new BigInteger("2");
		factor[10] = new BigInteger("3");
	}

	private void work() {
		int cnt = 0;
		for (int i = 0; i < (1 << n) && cnt < m; i++) {
			String binary = "1" + constructString(i, 2) + "1";
			if (ok(binary)) {
				output(binary);
				cnt++;
			}
		}

	}

	private void output(String binary) {
		System.out.print(binary);
		for (int i = 2; i <= 10; i++)
		{
			System.out.print(" " + factor[i]);
		}
		System.out.println();
	}

	private boolean ok(String binary) {
		for (int i = 2; i <= 10; i++) {
			BigInteger value = new BigInteger(binary, i);
			if (!value.mod(factor[i]).equals(BigInteger.ZERO))
				return false;
		}
		return true;
	}

	private String constructString(int i, int j) {
		String binary = Integer.toString(i, j);
		while (binary.length() < n) {
			binary = "0" + binary;
		}
		return binary;
	}
}
