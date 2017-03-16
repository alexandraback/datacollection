import java.util.Scanner;

public class Box {

	static int[] A, B;
	static long[] a, b;
	static long max;
	static long count;
	static int N;
	static int M;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int C = 1; C <= T; C++) {

			N = sc.nextInt();
			M = sc.nextInt();

			A = new int[N];
			a = new long[N+1];
			B = new int[M];
			b = new long[M+1];

			for (int i = 0; i < N; i++) {
				a[i] = sc.nextLong();
				A[i] = sc.nextInt();
			}
			for (int i = 0; i < M; i++) {
				b[i] = sc.nextLong();
				B[i] = sc.nextInt();
			}

			max = 0; count = 0;
			test(0, 0, a[0], b[0]);

			System.out.printf("Case #%d: %d\n", C, max);
		}
	}

	public static void test(int Ai, int Bi, long Ar, long Br) {
		if (Ai>=N || Bi>=M) {
			if (count > max) max = count;
		} else if (A[Ai] == B[Bi]) {
			if (Ar == Br) {
				count += Ar;
				test(Ai+1, Bi+1, a[Ai+1], b[Bi+1]);
				count -= Ar;
			} else if (Ar < Br) {
				count += Ar;
				test(Ai+1, Bi, a[Ai+1], Br-Ar);
				count -= Ar;
			} else {
				count += Br;
				test(Ai, Bi+1, Ar-Br, b[Bi+1]);
				count -= Br;
			}
		} else {
			// differ
			test(Ai+1, Bi, a[Ai+1], Br);
			test(Ai, Bi+1, Ar, b[Bi+1]);
		}
	}
}
