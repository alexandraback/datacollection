import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class A {
	static String in[] = { "X won", "Draw", "Game has not completed", "O won" };
	static int inf = 1 << 15, TestDraw = 0, tc;

	public static void main(String[] args) throws IOException {
		int[][] a = new int[4][4], b = new int[4][4];
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int n = sc.nextInt();
		for (tc = 1; tc <= n; tc++) {
			boolean containT = false;
			for (int i = 0; i < 4; i++) {
				char[] s = sc.next().toCharArray();
				for (int j = 0; j < 4; j++)
					if (s[j] == 'X')
						a[i][j] = b[i][j] = 2;
					else if (s[j] == 'O')
						a[i][j] = b[i][j] = 1;
					else if (s[j] == 'T') {
						containT = true;
						b[i][j] = 1;
						a[i][j] = 2;
					} else
						a[i][j] = b[i][j] = inf;
			}
			if (check(a))
				continue;
			if (containT && check(b))
				continue;
			System.out.printf("Case #%d: %s\n", tc, (TestDraw < 32) ? in[1]
					: in[2]);
		}
	}

	private static boolean check(int[][] a) {
		TestDraw = 0;
		for (int i = 0; i < 4; i++) {
			int row = 0, col = 0;
			for (int j = 0; j < a.length; j++) {
				row += a[i][j];
				col += a[j][i];
			}
			if (find(row, col))
				return true;
			TestDraw += row;
		}
		int d1 = 0, d2 = 0;
		for (int i = 0; i < 4; i++)
			d1 += a[i][i];
		for (int r = 0, c = 3; c >= 0; r++)
			d2 += a[r][c--];
		if (find(d1, d2))
			return true;
		return false;
	}

	static boolean find(int a, int b) {
		if (a == 4 || b == 4) {
			System.out.printf("Case #%d: %s\n", tc, in[3]);
			return true;
		} else if (a == 8 || b == 8) {
			System.out.printf("Case #%d: %s\n", tc, in[0]);
			return true;
		}
		return false;
	}
}
