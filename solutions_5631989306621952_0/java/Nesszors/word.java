import java.util.*;

public class word
{
	static Scanner scan;
	static int N, T;
	
	static void init()
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
	}
	public static void main(String[] args)
	{
		
		init();
		
		
		for(int zz=1; zz<=T; zz++)
		{
			String S= scan.next();
			
			String ans= S.charAt(0)+"";
			
			for(int i=1; i<S.length(); i++)
			{
				if(S.charAt(i)>=ans.charAt(0))
					ans= S.charAt(i)+ans;
				else
					ans= ans+S.charAt(i);
			}
			
			System.out.println("Case #"+zz+": "+ans);
			
		}
	}
}