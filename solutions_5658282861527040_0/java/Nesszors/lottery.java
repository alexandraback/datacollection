import java.util.*;

public class lottery
{
	static int T,A,B,K; 
	static String out;
	static Scanner scan;
	
	static void init()
	{
		A=scan.nextInt();
		B=scan.nextInt();
		K=scan.nextInt();
		
		
	}
	public static void main(String[] args)
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
		
		for(int t=1; t<=T; t++)
		{			
			init();
			
			int count=0;
			for(int i=0; i<A; i++)
				for(int j=0; j<B; j++)
					for(int k=0; k<K; k++)
						if((i&j)==k)
							count++;
			out=count+"";
			System.out.println("Case #"+t+": "+out);
		}
	}
}