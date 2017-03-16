import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt1.out"));
		// Scanner sc = new Scanner(new FileReader("b.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("b.out"));
		int MAX_N = 1010;
		int[] one = new int[MAX_N];
		int[] two = new int[MAX_N];
		boolean[] gotOne = new boolean[MAX_N];
		boolean[] gotTwo = new boolean[MAX_N];
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			for (int i = 0; i < n; i++) {
				one[i] = sc.nextInt();
				two[i] = sc.nextInt();
				gotOne[i] = gotTwo[i] = false;
			}
			int stars = 0;
			int moves = 0;
			while (true) {
				// try to get two
				int best = -1;
				int besti = -1;
				for (int i = 0; i < n; i++) {
					if (!gotOne[i] && !gotTwo[i] && two[i] <= stars) {
						best = one[i];
						besti = i;
						break;
					}
				}
				if (besti >= 0) {
					stars += 2;
					gotTwo[besti] = true;
				} else {
					// then to top up
					for (int i = 0; i < n; i++) {
						if (gotOne[i] && !gotTwo[i] && two[i] <= stars) {
							best = two[i];
							besti = i;
							break;
						}
					}
					if (besti >= 0) {
						stars++;
						gotTwo[besti] = true;
					} else {
						// then the first one
						for (int i = 0; i < n; i++) {
							if (!gotOne[i] && !gotTwo[i] && one[i] <= stars
									&& best < two[i]) {
								best = two[i];
								besti = i;
							}
						}
						if (besti >= 0) {
							stars++;
							gotOne[besti] = true;
						} else {
							break;
						}
					}
				}
				moves++;
				if (stars == 2 * n)
					break;
			}
			if (stars < 2 * n) {
				pw.printf("Case #%d: Too Bad\n", tc);
			} else {
				pw.printf("Case #%d: %d\n", tc, moves);
			}
		}
		pw.close();
	}

	public static void main(String[] args) throws IOException {
		new B().work();
	}

}
