import java.util.*;

class B_Lottery
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int Cases = T;
		while(T-->0)
		{
			int A = sc.nextInt();
			int B = sc.nextInt();
			int K = sc.nextInt();
			
			int count = 0;
			for(int i = 0; i < A; ++i)
			{
				for(int j = 0; j < B; ++j)
				{
				//	if(T == 4)
					//System.out.println(i + ":" + j + ":" + (i&j) + ":"+ K);
					if( (i&j) < K)
						++count;
				}
			}
			
			System.out.println("Case #"+(Cases-T)+": "+count);
		}
	}
}