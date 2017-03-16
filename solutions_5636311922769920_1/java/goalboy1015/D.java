import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.print("Case #" + tc + ":");

			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();

			if (C * S < K) {
				System.out.println(" IMPOSSIBLE");
			} else {
				int sequence = 0;
				for (int i = 0; i < S; i++) {
					int[] sequences = new int[C];
					for (int j = 0; j < sequences.length; j++) {
						sequences[j] = sequence;

						sequence = (sequence + 1) % K;
					}

					System.out.print(" " + generatePos(K, sequences));
				}
				System.out.println();
			}
		}

		sc.close();
	}

	static long generatePos(int K, int[] sequences) {
		long pos = 0;
		for (int sequence : sequences) {
			pos = pos * K + sequence;
		}
		return pos + 1;
	}
}
