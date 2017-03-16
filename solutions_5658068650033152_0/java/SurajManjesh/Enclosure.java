
import java.util.*;
import java.io.*;

public class Enclosure
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("E_s.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("E_s.out"));
		int T=sc.nextInt();
		int N,M,K,y,i,min,max,x;
		for(i=1;i<=T;i++)
		{
			N=sc.nextInt();
			M=sc.nextInt();
			K=sc.nextInt();
			if(N==1||M==1)
			{
				if(K==1)
					y=1;
				else
					y=2;
			}
			else if(N==2||M==2)
			{
				if(K<=4)
					y=K;
				else
					y=4;
			}
			else
			{
				min=(int)Math.min(N,M);
				max=(int)Math.min(N,M);
				x=(int)((K-2*(min-2))/min);
				if(x>max-2)
					x=max-2;
				y=(2*(min-2)+2*x)+(K-(2*(min-2)+min*x));
			}
			pw.println("Case #"+i+": "+y);

		}
		sc.close();
		pw.close();
	}
}