import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			int N = in.nextInt();
			int[] a = new int[N];
			int[] b = new int[N];
			for (int i = 0; i < N; i++) {
				a[i] = in.nextInt();
				b[i] = in.nextInt();
			}

			int ans = 0;
			int star = 0;
			boolean[] comp1 = new boolean[N];
			boolean[] comp2 = new boolean[N];
			boolean[] clear = new boolean[N];
			Arrays.fill(clear, true);
			while (true) {
				// System.err.println(star);
				// System.err.println(Arrays.toString(comp1));
				// System.err.println(Arrays.toString(comp2));
				boolean change = false;
				for (int i = 0; i < N; i++) {
					if (!comp2[i] && star >= b[i]) {
						comp2[i] = true;
						star++;
						if (!comp1[i]) {
							comp1[i] = true;
							star++;
						}
						ans++;
						change = true;
					}
				}
				if (!change) {
					int target = -1;
					int max2 = Integer.MIN_VALUE;
					for (int i = 0; i < N; i++) {
						if (!comp1[i] && star >= a[i]) {
							if (b[i] > max2) {
								target = i;
								max2 = b[i];
							}
						}
					}
					if (target != -1) {
						comp1[target] = true;
						star++;
						ans++;
						change = true;
					}
				}

				if (Arrays.equals(comp1, clear) && Arrays.equals(comp2, clear))
					break;
				if (!change) {
					ans = -1;
					break;
				}
			}
			if (ans == -1)
				System.out.printf("Case #%d: Too Bad%n", no);
			else
				System.out.printf("Case #%d: %d%n", no, ans);
		}
	}

}
