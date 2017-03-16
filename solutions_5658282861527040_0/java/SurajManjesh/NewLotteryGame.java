import java.util.*;
import java.io.*;

public class NewLotteryGame
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("NLG_s.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("NLG_s.out"));
		int T=sc.nextInt();
		int A,B,K,i,j,k,count;
		for(i=1;i<=T;i++)
		{
			A=sc.nextInt();
			B=sc.nextInt();
			K=sc.nextInt();
			count=0;
			for(j=0;j<A;j++)
			{
				for(k=0;k<B;k++)
				{
					if((j&k)<K)
						count++;
				}
			}

			pw.println("Case #"+i+": "+count);
		}
		sc.close();
		pw.close();
	}

}