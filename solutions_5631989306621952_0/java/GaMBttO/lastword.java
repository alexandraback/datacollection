import java.util.*;
import java.util.concurrent.DelayQueue;
public class lastword {
	public static void main(String[] args)
	{
		Scanner scn = new Scanner(System.in);
		
		int T = scn.nextInt();
		
		for( int c = 1; c <= T; c++ )
		{
			String S = scn.next();
			
			StringBuilder sB = new StringBuilder();
			
			String b = S.charAt(0) + "";
			
			for( int i = 1; i < S.length(); i++ )
			{
				if(b.charAt(0) <= S.charAt(i))
				{
					b = S.charAt(i) + b;
				}
				else
					b = b + S.charAt(i);
			}
			
			System.out.println("Case #" + c + ": " + b);
		}
	}
}
