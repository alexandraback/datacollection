import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class TicTacToeTomek {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter writer = new PrintWriter(new File("A-large.out"));

		int t = Integer.parseInt(buf.readLine().trim());
		for (int i = 1; i <= t; i++) {
			char[][] c = new char[4][4];
			for (int j = 0; j < 4; j++)
				c[j] = buf.readLine().trim().toCharArray();
			if (check(c, 0))
				writer.printf("Case #%d: X won\n", i);
			else if (check(c, 1))
				writer.printf("Case #%d: O won\n", i);
			else if (check2(c))
				writer.printf("Case #%d: Draw\n", i);
			else
				writer.printf("Case #%d: Game has not completed\n", i);
			buf.readLine();
		}
		writer.close();
	}

	private static boolean check2(char[][] c) {
		for (int i = 0; i < c.length; i++)
			for (int j = 0; j < c[0].length; j++)
				if (c[i][j] == '.')
					return false;
		return true;
	}

	private static boolean check(char[][] c, int k) {
		char player = (k == 0) ? 'X' : 'O';
		for (int i = 0; i < 4; i++) {
			int cnt1 = 0;
			int cnt2 = 0;
			for (int j = 0; j < 4; j++) {
				if (c[i][j] == player)
					cnt1++;
				else if (c[i][j] == 'T')
					cnt2++;
			}
			if (cnt1 + cnt2 == 4)
				return true;
			cnt1 = 0;
			cnt2 = 0;
			for (int j = 0; j < 4; j++) {
				if (c[j][i] == player)
					cnt1++;
				else if (c[j][i] == 'T')
					cnt2++;
				if (cnt1 + cnt2 == 4)
					return true;
			}
		}
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < 4; i++) {
			if (c[i][i] == player)
				cnt1++;
			else if (c[i][i] == 'T')
				cnt2++;
		}
		if (cnt1 + cnt2 == 4)
			return true;
		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < 4; i++) {
			if (c[i][4 - i - 1] == player)
				cnt1++;
			else if (c[i][4 - i - 1] == 'T')
				cnt2++;
		}
		if (cnt1 + cnt2 == 4)
			return true;
		return false;
	}
}
