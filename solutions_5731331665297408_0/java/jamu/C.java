import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class C {

	class City {
		String code;
		int codeIdx;
		List<City> n = new ArrayList<City>();
		City prev;
		boolean accessible = false;
		boolean tmp;
	}

	int n;
	City[] cities;

	Comparator<City> comparator = new Comparator<City>() {
		@Override
		public int compare(City o1, City o2) {
			return o1.code.compareTo(o2.code);
		}
	};

	void solve(int icase) {
		n = si();
		int m = si();
		cities = new City[n];

		for (int i = 0; i < n; i++) {
			cities[i] = new City();
			cities[i].code = ss();
		}

		for (int i = 0; i < m; i++) {
			int a = si() - 1;
			int b = si() - 1;

			cities[a].n.add(cities[b]);
			cities[b].n.add(cities[a]);
		}

		Arrays.sort(cities, comparator);
		for (int i = 0; i < n; i++) {
			cities[i].codeIdx = i;
			Collections.sort(cities[i].n, comparator);
		}

		visit(cities[0], true);
		cities[0].prev = cities[0];

		for (int i = 1; i < n; i++) {
			City best = getBestAccessible();
			if (best == null) {
				break;
			}
			visit(best, false);
		}

		String result = rek(cities[0]);

		printf("Case #%d: %s\n", icase, result);
	}

	void visit(City city, boolean first) {
		City from = null;
		for (City n : city.n) {
			n.accessible = true;
			if (n.prev != null && (from == null || from.codeIdx < n.codeIdx)) {
				from = n;
			}
		}
		city.prev = from;

		if (!first) {
			int maxOneWayIdx = -1;
			for (City n : city.n) {
				if (n.prev == null && oneWay(n)) {
					maxOneWayIdx = Math.max(maxOneWayIdx, n.codeIdx);
				}
			}
			for (City n : city.n) {
				if (n.prev == null && n.codeIdx <= maxOneWayIdx) {
					n.prev = city;
					for (City x : n.n) {
						x.accessible = true;
					}
				}
			}
		}
	}

	boolean oneWay(City city) {
		for (City x : cities) {
			x.tmp = false;
		}

		return numWays(city) == 1;
	}

	int numWays(City city) {
		city.tmp = true;

		int sum = 0;
		for (City n : city.n) {
			if (n.prev != null) {
				sum++;
			} else if (!n.tmp) {
				sum += numWays(n);
			}
		}
		return sum;
	}

	String rek(City city) {
		String result = city.code;
		for (City n : city.n) {
			if (n.prev == city) {
				result += rek(n);
			}
		}
		return result;
	}

	City getBestAccessible() {
		City best = null;
		for (City c : cities) {
			if (c.prev == null && c.accessible && (best == null || best.codeIdx > c.codeIdx)) {
				best = c;
			}
		}
		return best;
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new C().repSolve();
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
