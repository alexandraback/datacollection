import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemC1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt();
		System.out.println();
		for (int i = 1; i <= t; ++i) {
			int j = in.nextInt();
			int p = in.nextInt();
			int s = in.nextInt();
			int k = in.nextInt();

			System.out.print("Case #" + i + ": ");
			getResponse(j, p, s, k);
		}
	}

	private static void getResponse(int jm, int pm, int sm, int k) {
		List<int[]> solution = new ArrayList<int[]>();
		for (int j = 1; j <= jm; j++) {
			for (int p = 1; p <= pm; p++) {
				for (int s = 1; s <= sm; s++) {
					check(j, p, s, k, solution);
				}
			}
		}
		System.out.println(solution.size());
		for (int[] sol : solution) {
			for (int i : sol) {
				System.out.print(i + " ");
			}
			System.out.println();
		}

	}

	private static void check(int j, int p, int s, int k, List<int[]> solution) {
		int rule1 = 0;
		int rule2 = 0;
		int rule3 = 0;
		for (int[] sol : solution) {
			if (sol[0] == j && sol[1] == p) {
				rule1++;
				if (rule1 >= k) {
					return;
				}
			}
			if (sol[0] == j && sol[2] == s) {
				rule2++;
				if (rule2 >= k) {
					return;
				}
			}
			if (sol[1] == p && sol[2] == s) {
				rule3++;
				if (rule3 >= k) {
					return;
				}
			}
		}
		solution.add(new int[] { j, p, s });
	}

}
