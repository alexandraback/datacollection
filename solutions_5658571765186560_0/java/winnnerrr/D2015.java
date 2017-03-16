import java.util.Scanner; 

public class D2015 {
	public static String G = "GABRIEL", R = "RICHARD";
	
	public static String D(int a, int b, int c)
	{
		if((b*c)%a != 0)
			return R;
		if(a == 1)
			return G;
		if(a == 2)
			return G;
		if(a == 3)
		{
			if(b==1 || c==1)
				return R;
			return G;
		}
		
		if(a == 4)
		{
			if(b<=2 || c<=2)
				return R;
			return G;
		}
		return R;
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int i = 1; i<=T; i++)
		{
			int X = sc.nextInt();
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			System.out.println("Case #" + i + ": " + D(X,R,C));
		}
	}
}
