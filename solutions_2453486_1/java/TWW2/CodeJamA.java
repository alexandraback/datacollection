import java.util.*;

class CodeJamA
{	
	public static void main(String[] arg)
	{
		String[] GAMEWINNER = {"X won", "O won"};
		String DRAWGAME = "Draw";
		String NOTDONEGAME = "Game has not completed";
		Scanner in = new Scanner(System.in);
		int tt = in.nextInt();
		int trial = 0;
		while(trial < tt)
		{
			int[][] horiz = new int[4][2];
			int[][] vert = new int[4][2];
			int[][] diags = new int[2][2];
			boolean gameIsOver = true;
			
			for(int i=0; i<4; ++i)
			{
				String line = in.next();
				for(int j=0; j<4; ++j)
				{
					if(line.charAt(j) == 'X')
					{
						++horiz[i][0];
						++vert[j][0];
						if(i == j)
						{
							++diags[0][0];
						}
						if(i == 3-j)
						{
							//System.err.println("~~X in diag 2 at " + i + " " + j);
							++diags[1][0];
						}
					}else if(line.charAt(j) == 'O')
					{
						++horiz[i][1];
						++vert[j][1];
						if(i == j)
						{
							++diags[0][1];
						}
						if(i == 3-j)
						{
							//System.err.println("~~O in diag 2 at " + i + " " + j);
							++diags[1][1];
						}
					}else if(line.charAt(j) == 'T')
					{
						++horiz[i][0];
						++vert[j][0];
						++horiz[i][1];
						++vert[j][1];
						if(i == j)
						{
							++diags[0][0];
							++diags[0][1];
						}
						if(i == 3-j)
						{
							//System.err.println("~~T in diag 2 at " + i + " " + j);
							++diags[1][0];
							++diags[1][1];
						}
					} else {
						gameIsOver = false;
					}
				}
			}
			
			String ret = "";
			
			weHaveAWinner: while(true)
			{
				for(int j=0; j<2; ++j)
				{
					for(int i=0; i<4; ++i)
					{	
						if(horiz[i][j] == 4 || vert[i][j] == 4)
						{
							ret = GAMEWINNER[j];
							break weHaveAWinner;
						}
					}
					for(int i=0; i<2; ++i)
					{
						if(diags[i][j] == 4)
						{
							ret = GAMEWINNER[j];
							break weHaveAWinner;
						}
					}
				}
				ret = gameIsOver ? DRAWGAME : NOTDONEGAME;
				break weHaveAWinner;
			}
			//System.err.println("~~~~~~~ NEW GAME ~~~~~~~~~~");
			System.out.println("Case #" + ++trial + ": " + ret);
		}
	}
}