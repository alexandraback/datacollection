package round1b;

import java.util.*;

import com.sun.org.apache.bcel.internal.generic.GETSTATIC;

public class ProblemC {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();

		for (int cs = 0; cs < cases; cs++) {
			int N = sc.nextInt();
			int[] a = new int[N];

			for (int i = 0; i < N; i++) {
				a[i] = sc.nextInt();
			}

			int[][] sub = getAllSubsets2(a);
			int[] b = new int[2000000];
			Arrays.fill(b, -1);
			int tmp1 = -1, tmp2 = -1;

			for (int i = 0; i < sub.length; i++) {
				int sum = 0;

				for (int j = 0; j < sub[i].length; j++) {
					sum += sub[i][j];
				}

				if (b[sum] > 0) {
					tmp1 = b[sum];
					tmp2 = i;
					break;
				}

				b[sum] = i;

			}

			System.out.println("Case #" + (cs + 1) + ": ");
			if ((tmp1 == -1) || (tmp2 == -1)) {
				System.out.println("Impossible");
			} else {
				for (int i = 0; i < sub[tmp1].length; i++) {
					System.out.print(sub[tmp1][i] + " ");
				}
				System.out.println();
				for (int i = 0; i < sub[tmp2].length; i++) {
					System.out.print(sub[tmp2][i] + " ");
				}
			}
		}
	}

	public static int[][] getAllSubsets2(int[] elems) {
		int len = elems.length;
		int[][] subsets = new int[(1 << len) - 1][];

		for (int i = 1; i < (1 << len); i++) {
			int count = 0;
			for (int mask = 1; mask <= i; mask *= 2) {
				if ((mask & i) == mask) {
					count++;
				}
			}

			subsets[i - 1] = new int[count];
			count = 0;
			for (int mask = 1, tmp = 0; mask <= i; mask *= 2, tmp++) {
				if ((mask & i) == mask) {
					subsets[i - 1][count++] = elems[tmp];
				}
			}
		}
		return subsets;
	}

}
