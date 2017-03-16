import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter p = new PrintWriter("out.txt");
		int T = Integer.parseInt(br.readLine());
		int[][]  g  = new int[150][150]; 
		int[] row = new int[150];
		int[] col = new int[150];
		for(int t = 1; t <= T;t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			Arrays.fill(row, 0);
			Arrays.fill(col, 0);
			for(int i = 0 ; i < n ;i++)
			{	
				st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < m ;j++)
				{
					g[i][j] = Integer.parseInt(st.nextToken());
					col[j] =  Math.max(col[j], g[i][j]);
					row[i] =  Math.max(row[i], g[i][j]);
				}
			}
			boolean can = true;
			all:
			for(int i = 0 ; i < n ;i++)
				for(int j = 0 ; j < m ;j++)
					if(g[i][j] < row[i] && g[i][j] < col[j])
					{
						can = false;
						break all;
					}
			String res;
			if(can)
				res = "YES";
			else
				res = "NO";
			p.println("Case #"+t+": "+res);
		}
		p.close();
	}

}
