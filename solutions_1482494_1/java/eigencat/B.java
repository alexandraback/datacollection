import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		// String file = "sample.in";
		//String file = "B-small-attempt1.in";
		String file = "B-large.in";
		System.setOut(new PrintStream("B-large.out"));
		Scanner scan = new Scanner(new File(file));
		int t = scan.nextInt();
		for (int i = 0; i < t; i++)
			solve(scan, i + 1);
	}

	private static void solve(Scanner scan, int caseNum) {
		int n = scan.nextInt(); // num levels
		int[] a = new int[n]; // stars needed for 1 star
		int[] b = new int[n]; // stars needed for 2 star
		for (int i = 0; i < n; i++) {
			a[i] = scan.nextInt();
			b[i] = scan.nextInt();
		}

		// greedy
		// always 0->2 or 1->2
		// do 0->1 to highest bi

		class StarComparator implements Comparator<Integer> {
			private int[] arr;

			public StarComparator(int[] arr) {
				this.arr = arr;
			}

			public int compare(Integer o1, Integer o2) {
				if (arr[o1] < arr[o2])
					return -1;
				if (arr[o1] > arr[o2])
					return 1;
				return o1 - o2;
			}
		}

		Set<Integer> unfinished1 = new TreeSet<Integer>(new StarComparator(a));
		Set<Integer> unfinished2 = new TreeSet<Integer>(new StarComparator(b));

		for (int i = 0; i < n; i++) {
			unfinished1.add(i);
			unfinished2.add(i);
		}

		int stars = 0;
		int games = 0;
		while (true) {
			int oldStars = stars;

			// go to 2 anywhere possible
			Iterator<Integer> it = unfinished2.iterator();
			while (it.hasNext()) {
				int l = it.next();
				// start with lowest num stars
				if (b[l] <= stars) {
					it.remove();
					boolean firsttime = unfinished1.remove(l);
					stars += firsttime ? 2 : 1;
					games++;
				} else {
					break;
				}
			}

			// at this point can't do any more 2s

			// go to 1 on highest b
			int bestLevel = -1;
			int bestB = -1;
			it = unfinished1.iterator();
			while (it.hasNext()) {
				int l = it.next();
				if (a[l] <= stars) {
					if (b[l] > bestB) {
						bestB = b[l];
						bestLevel = l;
					}
				} else {
					break;
				}
			}
			if (bestLevel != -1) {
				unfinished1.remove(bestLevel);
				stars++;
				games++;
			}

			if (stars == oldStars)
				break;
		}

		if (stars == 2 * n)
			System.out.printf("Case #%d: %d%n", caseNum, games);
		else
			System.out.printf("Case #%d: %s%n", caseNum, "Too Bad");
	}
}