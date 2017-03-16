import java.util.*;

public class B
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int kk = 1; kk<=tt;kk++)
		{
			int x = sc.nextInt();
			int y = sc.nextInt();
			String temp = "";
			if(x>0)
			{
				for(int i = 0; i<x;i++)
				{
					temp += "WE";
				}
			}
			else
			{
				for(int i = 0; i<-x;i++)
				{
					temp += "EW";
				}
			}
			if(y>0)
			{
				for(int i = 0; i<y;i++)
				{
					temp += "SN";
				}
			}
			else
			{
				for(int i = 0; i<-y;i++)
				{
					temp += "NS";
				}
			}
			System.out.printf("Case #%d: %s\n", kk, temp);
		}	
	}
}