import java.util.Scanner;

class Fractiles {
	public static void main(String argv[]) {
		Scanner reader = new Scanner(System.in);
		int T, K, C, S;
		T = reader.nextInt();
		for (long i = 1; i <= T; i++) {
			K = reader.nextInt();
			C = reader.nextInt();
			S = reader.nextInt();
			System.out.print("Case #" + i + ": ");
			if (S < K - C + 1) System.out.println("IMPOSSIBLE");
			else if (C == 1) {
				for (int j = 1; j <= S; j++) {
					System.out.print(j);
					System.out.print(" ");
				}
				System.out.println();
			} else {
				for (int j = 0; j < S; j++) {
					System.out.print(j*K + (j+1)%K + 1);
					System.out.print(" ");
				}
				System.out.println();
			}
		}
	}
}