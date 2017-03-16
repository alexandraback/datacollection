import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class A {

	int n;

	class Cont {
		int s;
		int index;
		double min = 0.0;
	}

	Cont[] t;
	int sum;

	void solve(int icase) {
		n = si();
		t = new Cont[n];

		sum = 0;

		for (int i = 0; i < n; i++) {
			t[i] = new Cont();
			t[i].s = si();
			t[i].index = i;
			sum += t[i].s;
		}

		Arrays.sort(t, new Comparator<Cont>() {
			@Override
			public int compare(Cont o1, Cont o2) {
				return o1.s - o2.s;
			}
		});

		int left = sum;

		for (int i = 0; i < n - 1; i++) {
			int k = i + 1;
			int diff = t[k].s - t[i].s;
			if (k * diff <= left) {
				left -= k * diff;
				for (int j = 0; j < k; j++) {
					t[j].min += diff / (double) sum;
				}
			} else {
				for (int j = 0; j < k; j++) {
					t[j].min += (left / (double) k) / sum;
				}
				left = 0;
				break;
			}
		}

		if (left > 0) {
			for (int j = 0; j < n; j++) {
				t[j].min += (left / (double) n) / sum;
			}
		}

		Arrays.sort(t, new Comparator<Cont>() {
			@Override
			public int compare(Cont o1, Cont o2) {
				return o1.index - o2.index;
			}
		});

		printf("Case #%d:", icase);
		for (Cont c : t) {
			printf(" %.6f", c.min * 100.0);
		}
		printf("\n");
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
