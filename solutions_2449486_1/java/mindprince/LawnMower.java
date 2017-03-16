import java.util.*;
import java.io.*;
public class LawnMower {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		nextCase:
		for (int x = 1; x <=T; x++) {
			int N = s.nextInt();
			int M = s.nextInt();
			int[][] lawn = new int[N][M];
			int[] maxRow = new int[N];
			int[] maxColumn = new int[M];
			for (int i = 0; i < N; i++) {
				maxRow[i] = Integer.MIN_VALUE;
			}
			for (int j = 0; j < M; j++) {
				maxColumn[j] = Integer.MIN_VALUE;
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0;  j < M; j++) {
					lawn[i][j] = s.nextInt();
					if (lawn[i][j] > maxRow[i]) {
						maxRow[i] = lawn[i][j];
					}
					if (lawn[i][j] > maxColumn[j]) {
						maxColumn[j] = lawn[i][j];
					}
				}
			}
			// Each cell should either be maximum of its row or of its column.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (lawn[i][j] < maxRow[i] && lawn[i][j] < maxColumn[j]) {
						System.out.println("Case #" + x + ": NO");
						continue nextCase;
					}
				}
			}
			System.out.println("Case #" + x + ": YES");
		}
	}
}
