import java.io.File;
import java.util.Scanner;

public class ReorderingTrainCars {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("B-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int N = s.nextInt();
			s.nextLine();
			String[] strs = s.nextLine().split(" ");

			System.out.println("Case #" + t + ": " + ReorderingTrainCars.solve(N, strs));
		}
	}

	public static long solve(int N, String[] strs) {
		long count = 0;

		Integer[] array = new Integer[N];
		for (int i = 0; i < N; ++i) {
			array[i] = i;
		}
		Permutation<Integer> p = new Permutation<Integer>(array);
		do {
			if (ReorderingTrainCars.check(p.getTarget(), strs)) {
				count++;
			}
		} while (p.next());
		return count;
	}

	public static boolean check(Integer[] array, String[] strs) {
		boolean[] checked = new boolean[26];
		boolean checkFlg = false;
		char last = strs[array[0]].charAt(0);
		//checked[last - 'a'] = true;
		for (int i = 0; i < array.length; ++i) {
			for (int j = 0; j < strs[array[i]].length(); ++j) {
				char c = strs[array[i]].charAt(j);
				if (last != c) {
					checked[last - 'a'] = true;
					if (checked[c - 'a']) {
						return false;
					}
					last = c;
				}
			}
		}
//		for (int i=0;i<array.length; ++i) {
//			System.out.print(array[i] + " ");
//		}
//		System.out.println();
		return true;
	}
}
