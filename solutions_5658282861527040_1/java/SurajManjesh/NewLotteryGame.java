import java.util.*;
import java.io.*;

public class NewLotteryGame
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("NLG_l.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("NLG_l.out"));
		int T=sc.nextInt();
		int A,B,K,i,j,k,max,min;
		long count;
		for(i=1;i<=T;i++)
		{
			count=0;
			A=sc.nextInt();
			B=sc.nextInt();
			K=sc.nextInt();
			if(A>B)
			{
				max=A;
				min=B;
			}
			else
			{
				max=B;
				min=A;
			}
			if(min<K)
			{
				count=max*min;
				pw.println("Case #"+i+": "+count);
			}
			else
			{
			count=max*K;
			count+=((min-K)*K);
			for(j=K;j<max;j++)
			{
				for(k=K;k<min;k++)
				{
					if((j&k)<K)
						count++;
				}
			}
			pw.println("Case #"+i+": "+count);
			}

		}
		sc.close();
		pw.close();
	}

}