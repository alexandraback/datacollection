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
			
			long KCm1 = 1;
			for( int i = 0; i < C-1; i++ ) KCm1 *= K;
			
			System.out.print("Case #" + t + ": ");
			
			long p = 1;
			for( int i = 0; i < S; i++ )
			{
				System.out.print(p + " ");
				p += KCm1;
			}
			System.out.println();
		}
	}
}
