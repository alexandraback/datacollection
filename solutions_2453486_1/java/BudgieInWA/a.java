import java.util.*;

public class a {
	private static void p(String p) { System.out.print(p);   }
	private static void pln(String p) { System.out.println(p); }

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int P = in.nextInt();

		for (int p = 1; p <= P; p++) {
			in.nextLine(); // empty line
			char[][] g = new char[4][4];
			boolean done = true;
			for (int i = 0; i < 4; i++) {
				String s = in.nextLine();
				for (int j = 0; j < 4; j++) {
					g[i][j] = s.charAt(j);
					if (g[i][j] == '.') done = false;
				}
			}

			System.out.printf("Case #%d: ", p);
			switch(solve(g)) {
				case 'X': pln("X won"); break;
				case 'O': pln("O won"); break;
				default:
					if (done) pln("Draw");
					else pln("Game has not completed");
			}

		}
	}

	static char solve(char[][] g) {
		boolean x1 = true, o1 = true;
		for (int i = 0; i < 4; i++) {
			switch(g[i][i]) {
				case 'X': o1 = false; break;
				case 'O': x1 = false; break;
				case '.': x1 = false; o1 = false; break;
			}
		}
		if (x1) return 'X';
		if (o1) return 'O';
		x1 = true; o1 = true;
		for (int i = 0; i < 4; i++) {
			switch(g[i][3-i]) {
				case 'X': o1 = false; break;
				case 'O': x1 = false; break;
				case '.': x1 = false; o1 = false; break;
			}
		}
		if (x1) return 'X';
		if (o1) return 'O';

		char l = line(g, 0, 1);
		if (l != '.') return l;
		return line(g, 1, 0);
	}
	
	static char line(char[][] g, int di, int dj) {
		for (int i = 0, j = 0; i < 4 && j < 4; i += di, j += dj) {
			boolean o = true, x = true;
			for (; i < 4 && j < 4; i += dj, j += di) {
				if (g[i][j] == 'T') continue;
				if (g[i][j] == '.') { o = false; x = false; }
				if (g[i][j] == 'O') x = false;
				if (g[i][j] == 'X') o = false;
			}
			i -= 4*dj;
			j -= 4*di;

			if (x) return 'X';
			if (o) return 'O';
		}
		return '.';
	}
}
