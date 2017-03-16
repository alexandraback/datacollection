import java.util.*;
import java.io.*;

public class ttt {
	
	public static void main(String[] args) throws Exception{
		
		
		Scanner qwe = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("a.out"));
		int N = qwe.nextInt();
		
		for(int c =1; c <= N; c++)
		{
			char[][] board = new char[4][4];
			for(int i =0; i < 4; i++)
			{
				String next = qwe.next();
				board[i] = Arrays.copyOf(next.toCharArray(), next.length());
			}
			
			boolean filled = true;			
			boolean X = false;
			boolean O = false;
			
			for(int row = 0; row < 4; row++)
			{
				int xc =0;
				int oc = 0;
				
				for(int i =0; i < 4; i++)
				{
					if(board[row][i] == 'X')
						xc++;
					else if(board[row][i] == 'O')
						oc++;
					else if(board[row][i] == 'T')
					{
						xc++;
						oc++;
					}
					else filled = false;
				}
				
				if(xc == 4)
					X = true;
				if(oc == 4)
					O = true;
			}
			
			for(int col = 0; col < 4; col++)
			{
				int xc =0;
				int oc = 0;
				
				for(int i =0; i < 4; i++)
				{
					if(board[i][col] == 'X')
						xc++;
					else if(board[i][col] == 'O')
						oc++;
					else if(board[i][col] == 'T')
					{
						xc++;
						oc++;
					}
				}
				
				if(xc == 4)
					X = true;
				if(oc == 4)
					O = true;
			}
			
			if(true)
			{
				int xc =0;
				int oc = 0;
				
				for(int i =0; i < 4; i++)
				{
					if(board[i][i] == 'X')
						xc++;
					else if(board[i][i] == 'O')
						oc++;
					else if(board[i][i] == 'T')
					{
						xc++;
						oc++;
					}
				}
				
				if(xc == 4)
					X = true;
				if(oc == 4)
					O = true;
			}
			
			
			if(true)
			{
				int xc =0;
				int oc = 0;
				
				for(int i =0; i < 4; i++)
				{
					if(board[i][3-i] == 'X')
						xc++;
					else if(board[i][3-i] == 'O')
						oc++;
					else if(board[i][3-i] == 'T')
					{
						xc++;
						oc++;
					}
				}
				
				if(xc == 4)
					X = true;
				if(oc == 4)
					O = true;
			}
			
			if(X)
			{
				out.println("Case #" + c + ": X won");
			}
			else if(O)
			{
				out.println("Case #" + c + ": O won");
			}
			else if(filled)
				out.println("Case #" + c + ": Draw");
			else out.println("Case #" + c + ": Game has not completed");
			
		}
		
		out.close();
		qwe.close();
		
	}

}
