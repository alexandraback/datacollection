import java.util.*;

public class D
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		
		int i, sk, st, NR=in.nextInt();
		for (int run=1; run<=NR; run++)
		{
			System.out.print("Case #"+run+": ");
			int count=in.nextInt();
			double[] naomi=new double[count], ken=new double[count];
			for (i=0; i<count; i++)
				naomi[i]=in.nextDouble();
			for (i=0; i<count; i++)
				ken[i]=in.nextDouble();
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			sk=0;	st=0;
			while(sk+st<count)
			{
				if (naomi[sk+st]<ken[st])
					sk++;
				else
					st++;
			}
			System.out.print(count-sk);
			System.out.print(" ");
			
			st=0;
			for (i=0; i<count; i++)
			{
				if (st>=count)
					break;
				if (ken[count-1]<naomi[i])
					break;
				else
				{
					while (ken[st]<naomi[i])
						st++;
					st++;
				}
			}
			System.out.println(count-i);
		}
	}
}