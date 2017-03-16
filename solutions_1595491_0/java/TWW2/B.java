import java.util.*;

class Main
{
	public static void main(String[] arg)
	{
		Scanner in = new Scanner(System.in);
		
		int trials = in.nextInt();
		
		int tt = 0;
		while(tt < trials)
		{
			int N = in.nextInt();
			int S = in.nextInt();
			int P = in.nextInt();
			
			int ret = 0;
			for(int i=0; i<N; ++i)
			{
				int val = in.nextInt();
				int score = (int)(((double)val / 3.0) + 0.7);
				if(score >= P)
				{
					++ret;
				} else if(S > 0 && score == P-1 && val % 3 != 1 && val > 0)
				{
					--S;
					++ret;
				}
			}
			
			System.out.println("Case #" + ++tt + ": " + ret);
		}
	}
}