import java.util.Scanner;

public class iCode2012SafetyinNumbers {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int index = 1; index <= T; index++) {
			System.out.print("Case #" + index + ": ");
			int N = in.nextInt();
			int[] array = new int[N];
			int X = 0;
			for (int i = 0; i < N; i++) {
				array[i] = in.nextInt();
				X += array[i];
			}
			//double twoOverN = 2.0 / N;
			int effectiveN = 0;
			int effectiveX = 0;
			for (int i = 0; i < N; i++) {
				if (array[i] * N < 2 * X) {
					effectiveN++;
					effectiveX += array[i];
				}
			}
			if (array[0] * N >= 2 * X)
				System.out.print(0);
			else
				System.out.print(100 * ((double) (X + effectiveX) / effectiveN - array[0]) / X);
			for (int i = 1; i < N; i++)
				if (array[i] * N >= 2 * X)
					System.out.print(" " + 0);
				else
					System.out.print(" " + 100 * ((double) (X + effectiveX) / effectiveN - array[i]) / X);
			System.out.println();
		}
	}

}
/*
4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
*/