import java.util.*;

public class codeJamA
{
	public static void main (String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			char[][] game = new char[4][4];
			boolean hasDots = false;
			boolean hasWinner = false;
			
			for(int i = 0; i < 4; i++)
			{
				String s = sc.next();
				for(int j = 0; j < 4; j++)
				{
					game[i][j] = s.charAt(j);
					if(game[i][j] == '.')
					{
						hasDots = true;
					}
				}
			}
		
			//check rows
			
			for(int i = 0; i < 4; i++)
			{
				boolean same = true;
				char charac = ' ';
				for(int j = 0; j < 4; j++)
				{
					if(game[i][j] == '.')
					{
						same=false; break;
					}
					if(charac == ' ')
					{
						if(game[i][j] == 'T')
							continue;
						else
							charac = game[i][j];
					}
					else if(game[i][j] != charac && game[i][j] != 'T')
					{
						same = false; break;
					}
				}
				if(same)
				{
					System.out.println("Case #"+ testNo + ": "+ charac + " won");
					hasWinner = true;
					break;
				}
			}
			if(hasWinner)
				continue;
				
			
			//check columns
			for(int j = 0; j < 4; j++)
			{
				boolean same = true;
				char charac = ' ';
				for(int i = 0; i < 4; i++)
				{
					if(game[i][j] == '.')
					{
						same=false; break;
					}
					if(charac == ' ')
					{
						if(game[i][j] == 'T')
							continue;
						else
							charac = game[i][j];
					}
					else if(game[i][j] != charac && game[i][j] != 'T')
					{
						same = false; break;
					}
				}
				if(same)
				{
					System.out.println("Case #"+ testNo + ": "+ charac + " won");
					hasWinner = true;
					break;
				}
			}
			if(hasWinner)
				continue;
		
		
			//check diagonals
			
			boolean same = true;
			char charac = ' ';
			for(int i = 0; i < 4; i++)
			{
				if(game[i][i] == '.')
				{
					same=false; break;
				}
				if(charac == ' ')
				{
					if(game[i][i] == 'T')
						continue;
					else
						charac = game[i][i];
				}
				else if(game[i][i] != charac && game[i][i] != 'T')
				{
					same = false; break;
				}
			}
			if(same)
			{
				System.out.println("Case #"+ testNo + ": "+ charac + " won");
				hasWinner = true;
				continue;
			}
			
			same = true;
			charac = ' ';
			for(int i = 0; i < 4; i++)
			{
				if(game[i][3-i] == '.')
				{
					same=false; break;
				}
				if(charac == ' ')
				{
					if(game[i][3-i] == 'T')
						continue;
					else
						charac = game[i][3-i];
				}
				else if(game[i][3-i] != charac && game[i][3-i] != 'T')
				{
					same = false; break;
				}
			}
			if(same)
			{
				System.out.println("Case #"+ testNo + ": "+ charac + " won");
				hasWinner = true;
				continue;
			}
			if(hasDots)
			{
				System.out.println("Case #"+ testNo + ": Game has not completed");
			}
			else
			{
				System.out.println("Case #"+ testNo + ": Draw");
			}
			
		}
	}
}