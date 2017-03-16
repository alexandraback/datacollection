import java.util.*;
public class B {
	B(Scanner in) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int[][] vals = new int[R][C];
			int[] colMaxHeight = new int[C], rowMaxHeight = new int[R];
			for (int r=0; r<R; r++)
				for (int c=0; c<C; c++) {
					vals[r][c] = in.nextInt();
					colMaxHeight[c] = Math.max(colMaxHeight[c],vals[r][c]);
					rowMaxHeight[r] = Math.max(rowMaxHeight[r],vals[r][c]);
				}
			int[][] bestVals = new int[R][C];
			boolean valid = true;
			for (int r=0; r<R; r++)
				for (int c=0; c<C; c++) {
					bestVals[r][c] = Math.min(colMaxHeight[c],rowMaxHeight[r]);
					valid &= bestVals[r][c] == vals[r][c];
				}
			System.out.printf("Case #%d: %s\n",t+1,valid ? "YES" : "NO");
		}
	}
	public static void main(String[] args) {
		new B(new Scanner(System.in));
	}
}
