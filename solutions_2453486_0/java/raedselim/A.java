import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class A {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	static int n = 4;
	static char[][] g = new char[n][n];
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter p = new PrintWriter("out.txt");
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T;t++)
		{
			boolean dot = false;
			for(int i = 0; i  < n;i++)
			{
				g[i] = br.readLine().toCharArray();
				for(int j = 0; j < n && !dot;j++)
					if(g[i][j] == '.')
						dot = true;
			}
			if(t < T)
				br.readLine();
			char c = 'T';
			for(int i = 0 ; i < n && c == 'T';i++)
				c = check(i,0 , 0 , 1);
			for(int i = 0 ; i < n && c == 'T';i++)
				c = check(0,i , 1 , 0);
			if(c == 'T')
				c = check(0 ,0  , 1 , 1);
			if(c == 'T')
				c = check(0 ,n-1  , 1 , -1);
			String res = "";
			if(c == 'T')
				if(dot)
					res = "Game has not completed";
				else
					res  = "Draw";
			else
				res = c+" won";
			p.println("Case #"+t+": "+res);
		}
		p.close();
	}

	private static char check(int i, int j, int dx, int dy)
	{
		char c = 'T';
		for(int k = 0 ; k < n;k++ , i+=dx , j += dy)
			if(g[i][j] != 'T')
			{
				if(g[i][j] == '.')
					return 'T';
				if(c == 'T')
					c = g[i][j];
				else
					if(g[i][j] != c)
						return 'T';
			}
		return c;
	}

}
