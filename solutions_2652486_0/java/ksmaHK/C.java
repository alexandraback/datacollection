import java.util.*;
import java.math.*;

public class C {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = Integer.parseInt(scanner.nextLine());
	
	for (int nc = 1; nc <= nCase; nc++) {
		int R = scanner.nextInt();
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int K = scanner.nextInt();
		int[][] products = new int[R][K];
		for (int i = 0; i < R; i++)
		for (int j = 0; j < K; j++)
			products[i][j] = scanner.nextInt();
		System.out.println("Case #"+nc+":");
		int[] guess = new int[N];
		for (int r = 0; r < R; r++) {
			boolean ended = false;
			for (int i = 0; i < N; i++)
				guess[i] = 2;
			while (!ended) {
				boolean ok = true;
				for (int k = 0; k < K; k++) {
					int end = 1<<N;
					boolean Kok = false;
					for (int pp = 0; pp < end; pp++) {
						long thisP = 1;
						for (int i = 0; i < N; i++)
							if (((pp >> i) & 1) > 0)
								thisP *= guess[i];
						if (thisP == products[r][k]) {
							Kok = true;
							break;
						}
					}
					if (!Kok) {
						ok = false;
						break;
					}
				}
				if (ok)
					break;
				ended = next(guess, N, M);
			}
			for (int i = 0; i < N; i++)
				System.out.print(guess[i]);
			System.out.println();
		}
	}
}
static boolean next(int[] guess, int N, int M) {
	int index = -1;
	boolean ended = true;
	for (int i = 0; i < N; i++) {
		ended &= (guess[i] == M);
	}
	if (ended)
		return ended;
	for (int i = 0; i < N; i++) {
		if (guess[i] < M) {
			guess[i]++;
			break;
		} else {
			while (guess[i+1] == M)
				i++;
			for (int k = 0; k <= i; k++)
				guess[k] = 2;
			guess[i+1]++;
			break;
		}
	}
	return ended;
}
}