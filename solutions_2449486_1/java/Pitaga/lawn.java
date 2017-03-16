import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;


public class lawn {
	
	public static void main(String[] args) throws Exception{
			
		
		Scanner qwe = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("lawn.out"));
		int N = qwe.nextInt();
		
		for(int c =1; c <= N; c++)
		{	
			int rows = qwe.nextInt();
			int cols = qwe.nextInt();
			
			int[][] lawn = new int[rows][cols];
			
			for(int r =0; r < rows; r++)
				for(int l =0; l < cols; l++)
				{
					lawn[r][l] = qwe.nextInt();
				}
			
			int[] maxr = new int[rows];
			int[] maxc = new int[cols];
			
			for(int r =0; r < rows; r++)
			{
				int max = 0;
				for(int l =0; l < cols; l++)
				{
					max = Math.max(max, lawn[r][l]);
				}
				maxr[r] = max;
			}
			
			for(int l =0; l < cols; l++)
			{
				int max = 0;
				for(int r =0; r < rows; r++)
				{
					max = Math.max(max, lawn[r][l]);
				}
				maxc[l] = max;
			}
			
			boolean good = true;
			
			for(int r =0; r < rows; r++)
				for(int l =0; l < cols; l++)
				{
					int at = lawn[r][l];
					if(maxr[r] > at && maxc[l] > at)
						good = false;
				}
			
			if(good)
				out.println("Case #" + c + ": YES");
			else out.println("Case #" + c + ": NO");
		}
		
		out.close();
		qwe.close();
		
		
	}
	
	static boolean ispalin(long a)
	{
		String str = Long.toString(a);
		for(int i =0; i < str.length(); i++)
		{
			if(str.charAt(i) != str.charAt(str.length()-1-i))
				return false;
		}
		
		return true;
	}

}
