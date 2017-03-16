import java.io.*;

public class A {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt3.in.txt"));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("small.out")));
			int T = Integer.parseInt(br.readLine());
			for (int i = 1; i <= T; i++) {
				String[] board = new String[4];
				for (int j = 0; j < 4; j++)
					board[j] = br.readLine();
				check(board, pw, i);
				br.readLine();
			}
			br.close();
			pw.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void check(String[] board, PrintWriter pw, int count) {
		boolean full = true;
		for (int i = 0; i < 4; i++) {
			boolean xrow = true;
			boolean orow = true;
			for (int j = 0; j < 4; j++)
				if (board[i].charAt(j) == '.') {
					xrow = false;
					orow = false;
					full = false;
				} else if (board[i].charAt(j) == 'X')
					orow = false;
				else if (board[i].charAt(j) == 'O')
					xrow = false;
			if (xrow) {
				pw.println("Case #" + count + ": X won");
				return;
			}
			else if (orow) {
				pw.println("Case #" + count + ": O won"); 
				return;
			}
		}
		for (int j = 0; j < 4; j++) {
			boolean xcol = true;
			boolean ocol = true;
			for (int i = 0; i < 4; i++)
				if (board[i].charAt(j) == '.') {
					xcol = false;
					ocol = false;
				} else if (board[i].charAt(j) == 'X')
					ocol = false;
				else if (board[i].charAt(j) == 'O')
					xcol = false;
			if (xcol) {
				pw.println("Case #" + count + ": X won");
				return;
			} else if (ocol) {
				pw.println("Case #" + count + ": O won");
				return;
			}

		}
		boolean xdia = true;
		boolean odia = true;
		for (int i = 0; i < 4; i++) 
			if (board[i].charAt(i) == '.') {
				xdia = false;
				odia = false;
			} else if (board[i].charAt(i) == 'X')
				odia = false;
			else if (board[i].charAt(i) == 'O')
				xdia = false;
		if (xdia) {
			pw.println("Case #" + count + ": X won");
			return;
		} else if (odia) {
			pw.println("Case #" + count + ": O won");
			return;
		}
		xdia = true;
		odia = true;
		for (int i = 0; i < 4; i++)
			if (board[i].charAt(3-i) == '.') {
				xdia = false;
				odia = false;
			} else if (board[i].charAt(3-i) == 'X')
				odia = false;
			else if (board[i].charAt(3-i) == 'O')
				xdia = false;
		if (xdia) {
			pw.println("Case #" + count + ": X won");
			return;
		} else if (odia) {
			pw.println("Case #" + count + ": O won");
			return;
		}
		if (full)
			pw.println("Case #" + count + ": Draw");
		else
			pw.println("Case #" + count + ": Game has not completed");

		
	}
}
