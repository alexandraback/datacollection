import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class CodeJamA 
{
	
	static int check(char[][] board, int i, int j, int deltaI, int deltaJ, char cual)
	{
		if(i >= 4 || i < 0 || j >= 4 || j < 0)
			return 0;
		if(board[i][j] == 'T' || board[i][j] == cual)
			return 1 + check(board, i + deltaI, j + deltaJ, deltaI, deltaJ, cual);
		else
			return 0;
	}
	static int check(char[][] board)
	{
		for(int i = 0; i < 4; i++)
		{
			if(check(board, i, 0, 0, 1, 'X') == 4)
				return 1;
			if(check(board, i, 0, 0, 1, 'O') == 4)
				return -1;
			if(check(board, 0, i, 1, 0, 'X') == 4)
				return 1;
			if(check(board, 0, i, 1, 0, 'O') == 4)
				return -1;
		}
		if(check(board, 0, 0, 1, 1, 'X') == 4)
			return 1;
		if(check(board, 0, 0, 1, 1, 'O') == 4)
			return -1;
		if(check(board, 3, 0, -1, 1, 'X') == 4)
			return 1;
		if(check(board, 3, 0, -1, 1, 'O') == 4)
			return -1;
		return 0;
	}
	
	static boolean debug = false;
	
	public static void main(String[] args) throws FileNotFoundException
	{
		if(!debug)
		{
			System.setIn(new FileInputStream("A-small-attempt0.in"));
			System.setOut(new PrintStream("A-small-attempt0.out"));
		}
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for(int caso = 1; caso <= t; caso++)
		{
			char[][] tablero = new char[4][];
			for(int i = 0; i < 4; i++)
				tablero[i] = sc.nextLine().toCharArray();
			sc.nextLine();
			int res = check(tablero);
			if(res == 1)
				System.out.println("Case #" + caso + ": X won");
			else if(res == -1)
				System.out.println("Case #" + caso + ": O won");
			else
			{
				boolean empate = true;
				for(char[] l : tablero)
					for(char c : l)
						if(c == '.')
							empate = false;
				if(empate)
					System.out.println("Case #" + caso + ": Draw");
				else
					System.out.println("Case #" + caso + ": Game has not completed");
			}
		}
		sc.close();
		if(debug)
		{
			System.out.flush();
			System.out.close();
		}
	}

}
