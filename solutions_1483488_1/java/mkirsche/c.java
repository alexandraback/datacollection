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
			for(int i = a; i<=b; i++)
			{
				if(i >= 1000000)
				{
					int next = 1000000*(i%10)+i/10;
					if(next > i && next <= b)
						count++;
					int next2 = 100000*(i%100) + i/100;
					if(next2 > i && next2 <= b && next != next2)
						count++;
					int next3 = 10000*(i%1000)+i/1000;
					if(next3 > i && next3 <= b && next != next3 && next2 != next3)
						count++;
					int next4 = 1000*(i%10000) + i/10000;
					if(next4 > i && next4 <= b && next != next4 && next2 != next4 && next3 != next4)
						count++;
					int next5 = 100*(i%100000) + i/100000;
					if(next5 > i && next5 <= b && next != next5 && next2 != next5 && next3 != next5 && next4 != next5)
						count++;
					int next6 = 10*(i%1000000)+i/1000000;
					if(next6 > i && next6 <= b && next != next6 && next2 != next6 && next3 != next6 && next4 != next6 && next5 != next6)
						count++;
				}
				else if(i >= 100000)
				{
					int next = 100000*(i%10) + i/10;
					if(next > i && next <= b)
						count++;
					int next2 = 10000*(i%100)+i/100;
					if(next2 > i && next2 <= b && next != next2)
						count++;
					int next3 = 1000*(i%1000) + i/1000;
					if(next3 > i && next3 <= b && next != next3 && next2 != next3)
						count++;
					int next4 = 100*(i%10000) + i/10000;
					if(next4 > i && next4 <= b && next != next4 && next2 != next4 && next3 != next4)
						count++;
					int next5 = 10*(i%100000)+i/100000;
					if(next5 > i && next5 <= b && next != next5 && next2 != next5 && next3 != next5 && next4 != next5)
						count++;
				}
				else if(i >= 10000)
				{
					int next = 10000*(i%10)+i/10;
					if(next > i && next <= b)
						count++;
					int next2 = 1000*(i%100) + i/100;
					if(next2 > i && next2 <= b && next2 != next)
						count++;
					int next3 = 100*(i%1000) + i/1000;
					if(next3 > i && next3 <= b && next3 != next && next3 != next2)
						count++;
					int next4 = 10*(i%10000)+i/10000;
					if(next4 > i && next4 <= b && next4 != next3 && next4 != next2 && next4 != next)
						count++;
				}
				else if(i >= 1000)
				{
					int next = 1000*(i%10) + i/10;
					if(next > i && next <= b)
					{
						count++;
					}
					int next2 = 100*(i%100) + i/100;
					if(next2 > i && next2 <= b && next != next2)
					{
						count++;
					}
					int next3 = 10*(i%1000)+i/1000;
					if(next3 > i && next3 <= b && next != next3 && next2 != next3)
					{
						count++;
					}
				}
				else if(i >= 100)
				{
					int next = 100*(i%10) + i/10;
					if(next > i && next <= b)
						count++;
					int next2 = 10*(i%100) + i/100;
					if(next2 > i && next2 <= b && next2 != next)
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
