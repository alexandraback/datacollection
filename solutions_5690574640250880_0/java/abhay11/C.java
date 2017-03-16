import java.util.*;
 
 public class C
 {
	static int[] dr={-1, -1, -1, 0, 1, 1, 1, 0};
	static int[] dc={-1, 0, 1, 1, 1, 0, -1, -1};
	
	static int R, C;
	static int[][] grid;
	static boolean[][] vis;
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int nR=in.nextInt();
		for (int run=1; run<=nR; run++)
		{
			System.out.println("Case #"+run+":");
			R=in.nextInt();
			C=in.nextInt();
			int m=in.nextInt();
			vis=new boolean[R][C];
			grid=new int[R][C];
			
			grid[0][0]=2;
			if (R*C-m==1 || recurse(0,0,R*C-m-1))
			{
				System.out.print("c");
				for (int r=0; r<R; r++)
				{
					for (int c=0; c<C; c++)
						if (grid[r][c]==0)
							System.out.print("*");
						else if (r+c>0)
							System.out.print(".");
					System.out.println();
				}
			}
			else
				System.out.println("Impossible");
		}
	}
	
	static boolean recurse(int r, int c, int m)
	{
		grid[r][c]=1;
		int rm=0;
		int mark=0;
		for (int i=0; i<8; i++)
			if (grid(r+dr[i], c+dc[i])==0)
			{
				rm++;
				grid[r+dr[i]][c+dc[i]]=2;
				mark|=(1<<i);
			}
		
		if (rm==m)
			return true;
		if (rm<m)
		{
			for (int i=0; i<8; i++)
				if ((mark&(1<<i))!=0)
					if (recurse(r+dr[i], c+dc[i], m-rm))
						return true;
		}
		for (int i=0; i<8; i++)
			if ((mark&(1<<i))!=0)
				grid[r+dr[i]][c+dc[i]]=0;
		grid[r][c]=2;
		return false;
	}
	
	static int grid(int r, int c)
	{
		if (r<0 || r>=R || c<0 || c>=C)
		return -1;
		return grid[r][c];
	}
}