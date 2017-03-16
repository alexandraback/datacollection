import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class KingdomRush {
	
	public static void main(String[] args) throws Exception {		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			for (int p = 0; p < N; p++) {
				A[p] = in.nextInt();
				B[p] = in.nextInt();
			}
			int answer = compute(N, A, B);
			System.out.println("Case #" + (i + 1) + ": " + (answer == -1 ? "Too Bad" : answer));
		}
	}

	private static int compute(int N, int[] A, int[] B) {
		int stars = 0;
		int played = 0;
		int[] solved = new int[N];
		int fully_solved = 0;
		Arrays.fill(solved, 0);
		
		while (fully_solved < N) {
			int sel = -1;
			for (int i = 0; i < N && sel == -1; i++)
				if (stars >= B[i] && solved[i] < 2)
					sel = i;
			if (sel != -1) {
				stars += (solved[sel] == 1) ? 1 : 2;
				played++;
				solved[sel] = 2;
				fully_solved++;
				continue;
			}
			
			sel = -1;
			int neededB = 0;
			for (int i = 0; i < N; i++)
				if (stars >= A[i] && solved[i] == 0 && B[i] >= neededB) {
					sel = i;
					neededB = B[i];
				}
			if (sel != -1) {
				stars++;
				played++;
				solved[sel] = 1;
				continue;
			}
			return -1;
		}	
		return played;
	}
}
