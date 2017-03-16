import java.util.*;
public class LawnMower{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int c=1;c<=T;c++)
		{
			int N=in.nextInt(),M=in.nextInt();
			int[][] h=new int[N][M];
			for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			h[i][j]=in.nextInt();
			int Possible=1;
			for(int i=0;i<N&&Possible==1;i++)
			for(int j=0;j<M&&Possible==1;j++)
			{
				int max=0;
				for(int k=0;k<M;k++)
				if(h[i][k]>max)
				max=h[i][k];
				if(max>h[i][j])
				{	
					max=0;
					for(int k=0;k<N;k++)
					if(h[k][j]>max)
					max=h[k][j];
					if(max>h[i][j])
					Possible=0;
				}
			}	
			if(Possible==1)
			System.out.println("Case #"+c+": YES");
			else
			System.out.println("Case #"+c+": NO");
		}
	}
}
