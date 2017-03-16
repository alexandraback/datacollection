import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class C {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "C";
	static final String INPUT = "small1";
	static final String ID = "0";
	static final String PATH = "C:\\software installation\\codejam-commandline-1.2-beta1\\source\\";

	static ArrayList<Solution> solutions = new ArrayList<Solution>();

	public static void main(String args[]) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.println("Case #" + t + ": ");

			int R = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();
			int K = in.nextInt();

			buildSolutions(new int[N], 0, M);

			for (int r = 0; r < R; r++) {
				int targets[] = new int[K];
				for (int i = 0; i < targets.length; i++) {
					targets[i] = in.nextInt();
				}
				for (Solution solution : solutions) {
					boolean allin = true;
					for (int target : targets) {
						if (!solution.products.contains(target)) {
							allin = false;
							break;
						}
					}
					if (allin) {
						String result = "";
						for (int digit : solution.digits) {
							result += digit;
						}
						out.println(result);
						break;
					}
				}
			}
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static void buildSolutions(int digits[], int index, int M) {
		if (index == digits.length) {
			solutions.add(new Solution(digits.clone()));
			return;
		}
		for (int i = 2; i <= M; i++) {
			digits[index] = i;
			buildSolutions(digits, index + 1, M);
		}
	}
}

class Solution {
	int digits[];
	HashSet<Integer> products = new HashSet<Integer>();

	Solution(int digits[]) {
		this.digits = digits;

		int length = digits.length;
		for (int code = 0; code < (2 << length); code++) {
			boolean used[] = decode(code, length);
			int product = 1;
			for (int i = 0; i < length; i++) {
				if (used[i]) {
					product *= digits[i];
				}
			}
			products.add(product);
		}
	}

	boolean[] decode(int code, int length) {
		boolean used[] = new boolean[length];
		for (int i = 0; i < used.length; i++) {
			used[i] = (code % 2 != 0);
			code /= 2;
		}
		return used;
	}
}