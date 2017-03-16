import java.util.*;

public class B {
	private static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int T = s.nextInt();

		for (int t = 0; t < T; t++) {
			int N = s.nextInt();

			boolean[] complete1 = new boolean[N];
			boolean[] complete2 = new boolean[N];
			int[] star1 = new int[N];
			int[] star2 = new int[N];
			for (int i = 0; i < N; i++) {
				star1[i] = s.nextInt();
				star2[i] = s.nextInt();
			}

			int stars = 0;
			int count = 0;
			int total_complete = 0;

			while (true) {
				while (true) {
					boolean found = false;
					for (int i = 0; i < N; i++) {
						if (complete2[i]) continue;

						if (stars >= star2[i]) {
							count++;
							total_complete++;
							complete2[i] = true;
							found = true;
							stars++;
							if (!complete1[i]) stars++;
							continue;
						}
					}

					if (!found) break;
				}

				if (total_complete == N) {
					System.out.printf("Case #%d: %d\n", t + 1, count);
					break;
				}

				boolean found = false;
				int high_val = 0;
				int high_index = 0;
				for (int i = 0; i < N; i++) {
					if (complete2[i]) continue;
					if (complete1[i]) continue;

					if (stars >= star1[i]) {
						if (star2[i] > high_val) {
							high_val = star2[i];
							high_index = i;
						}
						found = true;
					}
				}

				if (!found) {
					System.out.printf("Case #%d: Too Bad\n", t + 1);
					break;
				}

				count++;
				stars++;
				complete1[high_index] = true;
			}
		}
	}
}
