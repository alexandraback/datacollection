import java.util.*;

public class B {

static int cnt;
static int B;
static boolean error;
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	int[][] fillX = new int[][]{{0}, {0}, {0, 0, 1}, {0, 0, 0, 1, 1, 2, 2}, {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
								{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4}};
	int[][] fillY = new int[][]{{0}, {1}, {1, 2, 2}, {1, 2, 3, 2, 3, 1, 3}, {1, 2, 3, 4, 2, 3, 4, 1, 3, 4, 1, 2, 4},
								{1, 2, 3, 4, 5, 2, 3, 4, 5, 1, 3, 4, 5, 1, 2, 4, 5, 1, 2, 3, 5}};
	int[] nBit = new int[]{0, 1, 3, 7, 13, 21};
	for (int nc = 1; nc <= nCase; nc++) {
		B = scanner.nextInt() - 1;
		long M = scanner.nextInt();
		boolean[][] matrix = new boolean[B+1][B+1];
		
		boolean found = false;
		boolean[] visited = new boolean[B+1];
		for (int mask = (1 << nBit[B]) - 1; mask > 0 && !found; mask--) {
			for (int i = 0; i < nBit[B]; i++) {
				matrix[fillX[B][i]][fillY[B][i]] = ((mask >> i) & 1) == 1;	
			}
			
			cnt = 0;
			error = false;
			for (int i = 1; i <= B && !error; i++) {
				if (matrix[0][i]) {
					visited[i] = true;
					v(i, visited, matrix);
					visited[i] = false;
				}
			}
			if (!error && cnt == M) {
				found = true;
			}
		}
		
		
		
		if (found) {
			System.out.println("Case #" + nc + ": POSSIBLE");
			StringBuilder output = new StringBuilder();
			for (int i = 0; i < B+1; i++) {
				for (int k = 0; k < B+1; k++) {
					output.append(matrix[i][k] ? '1' : '0');
				}
				output.append('\n');
			}
				
			System.out.print(output.toString());
		} else {
			System.out.println("Case #" + nc + ": IMPOSSIBLE");
		}
	}
}
public static void v(int current, boolean[] visited, boolean[][] matrix) {
	if (current == B) {
		cnt++;
	} else {
		for (int i = 1; i <= B; i++) {
			if (i != current && visited[i]) {
				error = true;
			}
		}
		if (!error) {
			for (int i = 1; i <= B; i++) {
				if (!visited[i] && matrix[current][i]) {
					visited[i] = true;
					v(i, visited, matrix);
					visited[i] = false;
				}
			}
		}
	}
}
}