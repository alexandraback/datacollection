
import java.io.*;
import java.util.*;

public class TicTacToeTomek
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("TicTacToeTomek-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("TicTacToeTomek-small-attempt0.out", false));

		String line = in.readLine();
		int cases = Integer.parseInt(line); // # of test cases

		for (int i = 1; i <= cases; i++)
		{
			String[] board = new String[4];
			for (int j = 0; j < 4; j++)
			{
				board[j] = in.readLine();
			}

			in.readLine();

			out.write("Case #" + i + ": " + solve(board));
			out.newLine();
		}

		in.close();
		out.close();
	}

	private static String solve(String[] board)
	{
		int u = 0;
		for (int i = 0; i < 4; i++)
		{
			int x = 0, o = 0;
			for (int j = 0; j < 4; j++)
			{
				char c = board[i].charAt(j);
				if (c == 'X' || c == 'T') x++;
				if (c == 'O' || c == 'T') o++;
				if (c != '.') u++;
			}
			if (x == 4) return "X won";
			if (o == 4) return "O won";
		}

		for (int i = 0; i < 4; i++)
		{
			int x = 0, o = 0;
			for (int j = 0; j < 4; j++)
			{
				char c = board[j].charAt(i);
				if (c == 'X' || c == 'T') x++;
				if (c == 'O' || c == 'T') o++;
			}
			if (x == 4) return "X won";
			if (o == 4) return "O won";
		}

		int x = 0, o = 0;
		for (int i = 0; i < 4; i++)
		{
			char c = board[i].charAt(i);
			if (c == 'X' || c == 'T') x++;
			if (c == 'O' || c == 'T') o++;
		}
		if (x == 4) return "X won";
		if (o == 4) return "O won";

		x = 0; o = 0;
		for (int i = 0; i < 4; i++)
		{
			char c = board[i].charAt(3 - i);
			if (c == 'X' || c == 'T') x++;
			if (c == 'O' || c == 'T') o++;
		}
		if (x == 4) return "X won";
		if (o == 4) return "O won";

		if (u < 16) return "Game has not completed";

		return "Draw";
	}

	private static void prt(String s)
	{
		System.out.println(s);
	}
}

