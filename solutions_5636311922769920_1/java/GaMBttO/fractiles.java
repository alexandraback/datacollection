import java.util.*;

public class fractiles {
	public static void main(String [] args)
	{
		Scanner scn = new Scanner(System.in);
		
		int T = scn.nextInt();
		
		for( int t = 1; t <= T; t++ )
		{
			int K,C,S;
			K = scn.nextInt(); C = scn.nextInt(); S = scn.nextInt();
			
			System.out.print("Case #" + t + ": ");
			
			if(S < Math.ceil((double)(K)/C) )
			{
				System.out.println("IMPOSSIBLE");
			}
			else
			{
				int p = 0;
				
				for( int s = 0; s < (int)Math.ceil((double)(K)/C); s++ )
				{
					//System.out.println("real S " + Math.ceil((double)(K)/C));
					long pos = 0;
					for( int c = 1; c <= C && p < K; c++ )
					{
						long KCmi = 1;
						for( int i = 0; i < C-c; i++ ) KCmi *= K;
						
						//System.out.println(p + " " + KCmi + " " + K + " " + (C-c));
						
						pos += p*KCmi;
						p++;
					}
					
					System.out.print((pos+1) + " ");
				}
				System.out.println();
			}
		}
	}
}
