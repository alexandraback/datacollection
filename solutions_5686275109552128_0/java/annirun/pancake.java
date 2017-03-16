import java.util.Scanner;

public class pancake {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			int stacks = in.nextInt();
			int[] sizes = new int[stacks];

			for (int i = 0; i < sizes.length; i++) {
				sizes[i] = in.nextInt();
			}

			int best = Integer.MAX_VALUE;

			for (int i = 1; i <= 1000; i++) {
				int splits = 0;
				for (int size : sizes) {
					splits += (size / i) - (size % i == 0 ? 1 : 0);
				}

//				System.out.println(i + " " + splits);
				best = Math.min(best, splits + i);
			}
			System.out.printf("Case #%d: %d\n", cn, best);
		}
	}
}
