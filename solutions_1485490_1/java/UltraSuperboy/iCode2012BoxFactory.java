import java.util.Scanner;

public class iCode2012BoxFactory {
	
	static long[] boxQ;
	static int[] boxT;
	static long[] toyQ;
	static int[] toyT;
	static long best;
	static long[][] array;
	static int N;
	static int M;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int index = 1; index <= T; index++) {
			N = in.nextInt();
			M = in.nextInt();
			boxQ = new long[N];
			boxT = new int[N];
			toyQ = new long[M];
			toyT = new int[M];
			for (int i = 0; i < N; i++) {
				boxQ[i] = in.nextLong();
				boxT[i] = in.nextInt();
			}
			for (int i = 0; i < M; i++) {
				toyQ[i] = in.nextLong();
				toyT[i] = in.nextInt();
			}
			array = new long[N+1][M+1];
			for (int i = 0; i <= N; i++)
				for (int j = 0; j <= M; j++)
					array[i][j] = -1;
			best = 0;
			recurse(0, -1, 0, -1, 0);
			System.out.println("Case #" + index + ": " + best);
		}
	}

	private static void recurse(int box, long boxQu, int toy, long toyQu, long total) {
		if (total > array[box][toy])
			array[box][toy] = total;
		else
			return;
		if (best < total)
			best = total;
		if (box >= N || toy >= M)
			return;
		if (boxQu == -1)
			boxQu = boxQ[box];
		if (toyQu == -1)
			toyQu = toyQ[toy];
		if (boxT[box] == toyT[toy]) {
			if (boxQu > toyQu)
				recurse(box, boxQu - toyQu, toy + 1, -1, total + toyQu);
			else if (boxQu < toyQu)
				recurse(box + 1, -1, toy, toyQu - boxQu, total + boxQu);
			else
				recurse(box + 1, -1, toy + 1, -1, total + boxQu);
		} else {
			recurse(box + 1, -1, toy, toyQu, total);
			recurse(box, boxQu, toy + 1, -1, total);
		}
	}

}

/*
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 1
5000000 10
5000000 100
*/