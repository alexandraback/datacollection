package gcj2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Lawnmover {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		for(int t=1;t<=T;++t)
		{
			String[] tok=br.readLine().trim().split(" ");
			int N=Integer.valueOf(tok[0]);
			int M=Integer.valueOf(tok[1]);
			int[][] reqdHeights=new int[N][M];
			for(int i=0;i<N;++i)
			{
				tok=br.readLine().trim().split(" ");
				for(int j=0;j<M;++j)
					reqdHeights[i][j]=Integer.valueOf(tok[j]);
			}
			int[] maxRow=new int[N];
			for(int i=0;i<N;++i)
			{
				int max=-1;
				for(int j=0;j<M;++j)
					max=Math.max(reqdHeights[i][j], max);
				maxRow[i]=max;
			}
			int[] maxCol=new int[M];
			for(int i=0;i<M;++i)
			{
				int max=-1;
				for(int j=0;j<N;++j)
					max=Math.max(max,reqdHeights[j][i]);
				maxCol[i]=max;
			}
			boolean possible=true;
			for(int i=0;i<N;++i)
			{
				for(int j=0;j<M;++j)
				{
					if(reqdHeights[i][j]==maxRow[i] || reqdHeights[i][j]==maxCol[j])
						continue;
					else
						possible=false;
				}
			}
			if(possible)
				System.out.println("Case #"+t+": YES");
			else
				System.out.println("Case #"+t+": NO");
				
		}
	}

}
