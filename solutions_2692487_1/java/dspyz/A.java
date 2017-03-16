import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			System.out.println("Case #" + caseNum + ": " + solveProblem(scan));
		}
	}

	private static int solveProblem(Scanner scan) {
		long a = scan.nextLong();
		int n = scan.nextInt();
		int[] motesizes = new int[n];
		for (int i = 0; i < n; i++) {
			motesizes[i] = scan.nextInt();
		}
		Arrays.sort(motesizes);
		if (a == 1)
			return n;
		int minOps = n;
		int adds = 0;
		for (int i = 0; i < n; i++) {
			if (a > motesizes[i]) {
				a += motesizes[i];
				minOps = Math.min(minOps, adds + n - 1 - i);
			} else {
				a += a - 1;
				i--;
				adds++;
			}
		}
		return minOps;
	}
}
