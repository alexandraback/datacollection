import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;


public class TicTacToe {
	
	//private static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	private static PrintWriter pw;
	private static String[] xwins={"XXXX","TXXX","XTXX","XXTX","XXXT"};
	private static String[] owins={"OOOO","TOOO","OTOO","OOTO","OOOT"};
	private static boolean dotcheck,printed;
	
	private static String[] board;
	
	private static void checkfordots()
	{
		
		for(int i=0;i<4;++i)
		{
			if(board[i].contains("."))
				{
				dotcheck=true;
				break;
				}
		}
			
	}
	
	private static char check(char x1,char x2,char x3,char x4)
	{
		
		String tmp=String.valueOf(String.valueOf(x1)+String.valueOf(x2)+String.valueOf(x3)+String.valueOf(x4));
		for(int i=0;i<5;++i)
			if(tmp.compareTo(xwins[i])==0)
				return 'X';
		
		for(int i=0;i<5;++i)
			if(tmp.compareTo(owins[i])==0)
				return 'O';
		
		return 'D';		
	}
	
	private static void solve(int tcase)
	{
		if((check(board[0].charAt(0),board[1].charAt(1),board[2].charAt(2),board[3].charAt(3))=='X')||
				(check(board[0].charAt(3),board[1].charAt(2),board[2].charAt(1),board[3].charAt(0))=='X'))
			{
			pw.println("Case #"+tcase+": X won");
			printed=true;
			}
		else
			if((check(board[0].charAt(0),board[1].charAt(1),board[2].charAt(2),board[3].charAt(3))=='O')||
					(check(board[0].charAt(3),board[1].charAt(2),board[2].charAt(1),board[3].charAt(0))=='O'))
				{
				pw.println("Case #"+tcase+": O won");
				printed=true;
				}
			else
			{
		for(int i=0;i<4;++i)
		{
			if((check(board[i].charAt(0),board[i].charAt(1),board[i].charAt(2),board[i].charAt(3))=='X')||
					(check(board[0].charAt(i),board[1].charAt(i),board[2].charAt(i),board[3].charAt(i))=='X'))
				{
				pw.println("Case #"+tcase+": X won");
				printed=true;
				break;
				}
			else
				if((check(board[i].charAt(0),board[i].charAt(1),board[i].charAt(2),board[i].charAt(3))=='O')||
						(check(board[0].charAt(i),board[1].charAt(i),board[2].charAt(i),board[3].charAt(i))=='O'))
					{
					pw.println("Case #"+tcase+": O won");
					printed=true;
					break;
					}
		}
			}
			
		if(!printed)
			{
				if(dotcheck)
					pw.println("Case #"+tcase+": Game has not completed");
				else
					pw.println("Case #"+tcase+": Draw");
			}
					
		
			
		
		
	}
	
	public static void main(String[] args) throws Exception
	{
		
		pw=new PrintWriter("Outputlarge.txt");
		BufferedReader br=new BufferedReader(new FileReader("A-large.in"));
		int testcases=Integer.parseInt(br.readLine());
		
		for(int t=0;t<testcases;++t)
		{
			
			dotcheck=false;
			printed=false;
			board=new String[4];
			for(int i=0;i<4;++i)
				board[i]=new String(br.readLine());
			
			checkfordots();
			solve(t+1);
			
			br.readLine();
			
			
		}
		
		pw.flush();
		pw.close();
	}

}
