import java.util.Scanner;

public class TicTacToeTomek {
	public static void main(String[] args) {
		new TicTacToeTomek().run();
	}
	
	
	
	
	Scanner sc = new Scanner(System.in);
	int count = 1;
	public void run()
	{
		int n = sc.nextInt();
		sc.nextLine();
		for( count = 1; count <= n; count++){
			solve();
			if(sc.hasNext())
				sc.nextLine();
		}
	}
	public void solve()
	{
		String [] table = new String [4];
		for(int i=0;i<4;i++)
			table[i] = sc.nextLine();
		if(checkHorizontal(table))
			return;
		if(checkVertical(table))
			return;
		if(checkDiagonal(table))
			return;
		if(checkIsNotComplete(table))
			System.out.println( "Case #" + count + ": " + "Game has not completed");
		else
			System.out.println( "Case #" + count + ": " + "Draw");
		
		
	}
	
	public boolean checkIsNotComplete(String [] table)
	{
		for(int i=0;i<4;i++)
			if(table[i].contains("."))
				return true;
		return false;
	}
	public boolean checkLine(String line)
	{
		boolean isWin = true;
		char winner = ' ';
		int k;
		if(line.contains("."))
			return false;
		for( k=0 ;k<4;k++)
			if(line.charAt(k) != 'T'){
				winner = line.charAt(k);
				break;
			}
		for(  ; k <4 ; k++ )
			if( line.charAt(k) != winner && line.charAt(k) != 'T'){
				isWin = false;
				break;
			}
		if(isWin)
			System.out.println( "Case #" + count + ": " + winner + " won");	
		return isWin;
	}
	public boolean checkHorizontal(String [] table)
	{
		for(int i=0;i<4;i++)
			if(checkLine(table[i]))
				return true;
		return false;
	}
	
	public boolean checkVertical(String [] table)
	{
		String [] line = new String [4];
		for(int i=0;i<4;i++)
		{
			line[i] = "";
			for(int j=0;j<4;j++)
				line[i] += table[j].charAt(i);
		}
		return checkHorizontal(line);	
	}
	
	public boolean checkDiagonal(String [] table)
	{
		String [] line = new String [2];
		line[0] = "";
		for(int i=0;i<4;i++)
			line[0] += table[i].charAt(i);
		line[1] = "";
		for(int i=0;i<4;i++)
			line[1] += table[i].charAt(3-i);
		
		for(int i=0;i<2;i++)
			if(checkLine(line[i]))
				return true;
		return false;
		
	}
	
	
	
	
	
	
	
	
	
}
