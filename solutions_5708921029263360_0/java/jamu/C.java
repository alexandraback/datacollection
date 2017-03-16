import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class C {

	void solve(int icase) {
		int a = si();
		int b = si();
		int c = si();
		int k = si();

		int[][] ab = new int[a][b];
		int[][] bc = new int[b][c];
		int[][] ca = new int[c][a];

		ArrayList<String> str = new ArrayList<>();

		for (int ia = 0; ia < a; ia++) {
			for (int ib = 0; ib < b; ib++) {
				for (int ic = 0; ic < c; ic++) {
					if (ab[ia][ib] < k && bc[ib][ic] < k && ca[ic][ia] < k) {
						ab[ia][ib]++;
						bc[ib][ic]++;
						ca[ic][ia]++;
						str.add((ia + 1) + " " + (ib + 1) + " " + (ic + 1));
					}
				}
			}
		}

		printf("Case #%d: %d\n", icase, str.size());
		for (String s : str) {
			printf(s + "\n");
		}
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
			// System.err.println("[[ " + icase + " ]]");
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