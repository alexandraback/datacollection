import java.util.Scanner;

public class ReorderingTrainCarsSmall {
	public static long ans;
	public static long mod = 1000000007;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int N;
		int i, j, k;
		String str[];

		for (k = 0; k < T; k++) {
			N = scanner.nextInt();
			scanner.nextLine();
			str = scanner.nextLine().split(" ");

			ans = 0;
			ComputeAllPermutations(str, 0, N);
			ans %= mod;
			System.out.println("Case #" + (k + 1) + ": " + ans);
		}
	}

	public static void ComputeAllPermutations(String a[], int i, int n) {
		int j;
		if (i == n - 1) {
			boolean isValid = true;
			int componentSize = 1;
			for (int k = 0; k < a.length - 1; k++) {
				if (a[k].charAt(a[k].length() - 1) != a[k + 1].charAt(0)) {
					if (componentSize == 1) {
						isValid = false;
						break;
					} else {
						componentSize = 1;
					}
				} else if (a[k].charAt(a[k].length() - 1) == a[k + 1].charAt(0)) {
					componentSize++;
				}
			}
			if (componentSize == 1) {
				isValid = false;
			}
			// for (int k = 0; k < a.length; k++) {
			// System.out.print("" + a[k] + " ");
			// }
			// System.out.println("isValid=" + isValid);
			if (isValid == true) {
				ans++;
			}
		} else {
			for (j = i; j < n; j++) {
				swap(a, i, j);
				ComputeAllPermutations(a, i + 1, n);
				swap(a, i, j); // backtrack
			}
		}
	}

	public static void swap(String a[], int i, int j) {
		String temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
