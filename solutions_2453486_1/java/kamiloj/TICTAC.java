import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class TICTAC {

	Scanner s;
	PrintWriter pw;
	char[][] tablero = new char[4][4];
	boolean draw;

	public TICTAC() throws FileNotFoundException {
		s = new Scanner(new File("A-large.in"));
		pw = new PrintWriter(new File("salida.out"));

		int T = s.nextInt();

		for (int i = 1; i <= T; i++) {
			pw.println("Case #" + i + ": " + solve());
		}

		s.close();
		pw.close();
	}

	private String solve() {
		draw = true;
		read();
		if (win('X'))
			return "X won";
		if (win('O'))
			return "O won";
		if (draw)
			return "Draw";
		return "Game has not completed";
	}

	private boolean win(char c) {
		for (int i = 0; i < 4; i++) {
			boolean win = true;
			for (int j = 0; j < 4; j++) {
				if (tablero[i][j] != c && tablero[i][j] != 'T') {
					win = false;
					break;
				}
			}
			if (win)
				return true;
		}

		for (int i = 0; i < 4; i++) {
			boolean win = true;
			for (int j = 0; j < 4; j++) {
				if (tablero[j][i] != c && tablero[j][i] != 'T') {
					win = false;
					break;
				}
			}
			if (win)
				return true;
		}
		boolean win = true;
		for (int i = 0; i < 4; i++) {
			if (tablero[i][i] != c && tablero[i][i] != 'T') {
				win = false;
				break;
			}
		}
		if (win)
			return true;

		win = true;
		for (int i = 0; i < 4; i++) {
			if (tablero[i][3 - i] != c && tablero[i][3 - i] != 'T') {
				win = false;
				break;
			}
		}

		return win;
	}

	private void read() {
		for (int i = 0; i < 4; i++) {
			String l = s.next();
			for (int j = 0; j < 4; j++) {
				tablero[i][j] = l.charAt(j);
				if (tablero[i][j] == '.')
					draw = false;
			}
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		new TICTAC();
	}
}
