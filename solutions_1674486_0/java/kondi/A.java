import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;






public class A { 

	static String inner = "input.in";
	static Scanner scan;
	static int inf = 999999999;
	public static void main (String[]args) throws IOException
	{
		//taking input starts
		File f = new File (inner);
		File out = new File("output.out");
		FileWriter wr; 
		wr = new FileWriter(out); 
		scan = new Scanner(f); 
		int test = scan.nextInt();
		scan.nextLine();
		for(int m = 0 ; m < test ; m++)
		{
			String ret = "Case #"+ (m+1)+": No";
			//taking individual test case starts 
			int N = scan.nextInt();
			boolean [][] map = new boolean[N][N];
			int [][] floyd = new int[N][N];
			for(int i = 0 ; i <N ; i++ )
				Arrays.fill(floyd[i], inf);
			for(int i = 0 ; i < N ; i++)
			{
				int M = scan.nextInt();
				System.out.println(M);
				for(int j = 0; j < M ; j++){
					int in = scan.nextInt();
					map [i][in -1] = true;
					floyd[i][in -1]=1;
				}
				
			}
			
			for(int k = 0; k < N ; k ++)
			{
				for(int i = 0; i < N ; i++)
				{
					for(int j = 0 ; j < N ;j++)
					{
						if(floyd[i][j] <inf && floyd [i][k]+floyd[k][j] <inf)
						 ret = "Case #"+ (m+1)+": Yes";
						floyd[i][j] = Math.min ( floyd[i][j], floyd[i][k]+floyd[k][j] );
					}
				}
			}
			
			
			//solution of individual test case			
			
			
			
			
			
			//writing output of individual test case
			wr.write(ret+"\n");
		}
		 wr.flush();
	}
	
	
	public static void dummy()
	{
		
	}
}
	 