import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class B {

	final long mod = 1000000007;

	String[] cars;
	List<Ends> ends;

	class Ends {
		int a, b;
	}

	void solve(int icase) {
		int n = si();
		cars = new String[n];
		for (int i = 0; i < cars.length; i++) {
			cars[i] = ss();
		}

		long res = count();

		printf("Case #%d: %d\n", icase, res);
	}

	long count() {
		ends = new ArrayList<Ends>();

		for (int ic = 0; ic < cars.length; ic++) {
			String c = cars[ic];

			int a = c.charAt(0);
			int b = c.charAt(c.length() - 1);

			for (int i = 0; i < c.length(); i++) {
				int x = c.charAt(i);
				if (x != a && x != b) {
					for (int ik = 0; ik < cars.length; ik++) {
						if (ik != ic) {
							for (int il = 0; il < cars[ik].length(); il++) {
								if (cars[ik].charAt(il) == x) {
									return 0;
								}
							}
						}
					}
				}
			}

			int[] y = new int[256];
			int prev = c.charAt(0);

			for (int il = 0; il < c.length(); il++) {
				int cur = c.charAt(il);
				if (cur != prev && y[cur] > 0) {
					return 0;
				}
				prev = cur;
				y[cur]++;
			}

			Ends e = new Ends();
			e.a = a;
			e.b = b;
			ends.add(e);
		}

		long ret = 1;

		for (int k = 'a'; k <= 'z'; k++) {
			if (rev()) {
				return 0;
			}

			List<Ends> ek = new ArrayList<Ends>();
			for (Ends e : ends) {
				if (e.a == k || e.b == k) {
					ek.add(e);
				}
			}

			if (ek.size() > 0) {
				ends.removeAll(ek);

				int a = -1;
				int b = -1;
				int both = 0;

				for (Ends e : ek) {
					if (e.a == k && e.b == k) {
						both++;
					}
					if (e.a != k) {
						if (a != -1) {
							return 0;
						}
						a = e.a;
					}
					if (e.b != k) {
						if (b != -1) {
							return 0;
						}
						b = e.b;
					}
				}

				Ends ne = new Ends();
				ne.a = a == -1 ? k : a;
				ne.b = b == -1 ? k : b;
				ends.add(ne);

				ret *= sil(both);
				ret %= mod;
			}
		}

		ret *= sil(ends.size());
		ret %= mod;

		return ret;
	}

	long sil(long x) {
		long ret = 1;
		for (long i = 2; i <= x; i++) {
			ret *= i;
			ret %= mod;
		}
		return ret;
	}

	boolean rev() {
		for (int x = 0; x < ends.size(); x++) {
			Ends ex = ends.get(x);
			if (ex.a != ex.b) {
				for (int y = x + 1; y < ends.size(); y++) {
					Ends ey = ends.get(y);
					if (ex.a == ey.b && ex.b == ey.a) {
						return true;
					}
				}
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new B().repSolve();
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

	double sd() {
		return scanner.nextDouble();
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
