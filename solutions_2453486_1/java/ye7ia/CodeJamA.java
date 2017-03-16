import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CodeJamA
{
	public static boolean playerWin(char c, char[][] g)
	{
		boolean d = true;
		for (int i = 0; i < 4; i++)
			d &= g[i][i] == c || g[i][i] == 'T';
		
		boolean f = true;
		for(int i = 0 ; i < 4 ; i++)
			f &= g[i][3 - i] == c || g[i][3 - i] == 'T';
		d |= f;
		for (int i = 0; i < 4; i++)
		{
			boolean t1 = true, t2 = true;
			for (int j = 0; j < 4; j++)
			{
				t1 &= g[i][j] == c || g[i][j] == 'T';
				t2 &= g[j][i] == c || g[j][i] == 'T';
			}
			d |= t1 || t2;
		}

		return d;
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("D:\\D\\A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
		int t = in.nextInt();
		for (int tc = 1; tc <= t; tc++)
		{
			int c = 0;
			char[][] g = new char[4][4];
			for (int i = 0; i < 4; i++)
			{
				char[] a = in.next().toCharArray();
				for (int j = 0; j < 4; j++)
				{
					g[i][j] = a[j];
					c += g[i][j] == 'X' || g[i][j] == 'O' || g[i][j] == 'T' ? 1
							: 0;
				}
			}
			out.printf("Case #%d: ", tc);
			if (playerWin('X', g))
				out.println("X won");
			else if (playerWin('O', g))
				out.println("O won");
			else if (c == 16)
				out.println("Draw");
			else
				out.println("Game has not completed");

		}
		out.close();
	}
}
