import java.util.*;

public class Main{
	static int power(int d)
	{
		if(d== 0) return 1;
		else if(d%2 == 0) 
		{
			int a = power(d/2);
			return a*a;
		}
		else
		{
			int a = power(d/2);
			return a*a*10;
		}
	}
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<= T; cc++)
		{
			int A = in.nextInt();
			int B = in.nextInt();
			int Digit = Integer.toString(A).length();
			int tab[] = new int[2000001];
			int base = power(Digit-1);
			for(int i = 0; i<2000001; i++)
			{
				tab[i] = -1;
			}
			for(int i = A; i<B; i++)
			{
				if(tab[i] == -1)
				{
					tab[i] = 1;
					int current = i;
					for(int j = 0; j<Digit-1; j++)
					{
						int a = current%10;
						int b = current/10;
						int next = a*base+b;
						//System.out.println(next);
						if(next >= A && next <=B)
						{
							if(tab[next] == -1)
							{
								tab[next] =0;
								tab[i] ++;
							}
						}
						current = next;
					}
				}
			}
			long res = 0;
			for(int i = A; i<B; i++)
			{
				res += tab[i]*(tab[i]-1)/2;
			}
			System.out.println("Case #"+cc+": "+res);
		}
	}
}