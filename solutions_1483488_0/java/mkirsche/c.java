import java.util.*;
public class c 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int t = 1; t<=T; t++)
		{
			System.out.print("Case #" + t + ": ");
			int a = input.nextInt();
			int b = input.nextInt();
			int count = 0;
			for(int i = a; i<b; i++)
			{
				if(i >= 100)
				{
					int next = 100*(i%10) + i/10;
					if(next > i && next <= b)
						count++;
					next = 10*(i%100) + i/100;
					if(next > i && next <= b)
						count++;
				}
				else if(i >= 10)
				{
					int next = 10*(i%10) + i/10;
					if(next > i && next <=b)
						count++;
				}
			}
			System.out.println(count);
		}
	}
}
