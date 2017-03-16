import java.io.*;
import java.util.*;

public class elf
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(new BufferedInputStream(System.in)).useDelimiter("[\\s/]+");
		
		int nR=in.nextInt();
		for (int run=1; run<=nR; run++)
		{
			long p=in.nextLong(), q=in.nextLong();
			long gcf=gcf(p,q);
			p/=gcf;
			q/=gcf;
			
			int pow=-1;
			long d=1;
			int min=-1;
			for (int i=0; i<40; i++)
			{
				if (d==q)
					pow=i;
				if (d<=p)
					min=i;
				d*=2;
			}
			
			System.out.print("Case #"+run+": ");
			if (pow>=0)
				System.out.println(pow-min);
			else
				System.out.println("impossible");
		}
	}
	
	static long gcf(long a, long b)
	{
		long t;
		while (b!=0)
		{
			t=a%b;
			a=b;
			b=t;
		}
		return a;
	}
}