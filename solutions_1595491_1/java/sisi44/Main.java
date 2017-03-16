import java.util.*;

public class Main{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<=T; cc++)
		{
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int surprise;
			int normal;
			if(p >= 2)
			{
				surprise = (p-2)*3+2;
				normal = (p-1)*3+1;
			}
			else if(p==1)
			{
				surprise = 31;
				normal =1; 
			}
			else
			{
				surprise = 31;
				normal =0; 
			}
			
			int nbS=0;
			int nbN=0;
			for(int i = 0; i<N;i++)
			{
				int a = in.nextInt();
				if(a>= normal) nbN++;
				else if(a>=surprise) nbS++;
			}
			int res = nbS<= S? nbS:S; 
			System.out.println("Case #"+cc+": "+(res+nbN));
		}
	}
}