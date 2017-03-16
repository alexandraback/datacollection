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
			int ret = 0;
			int A = in.nextInt();
			int B = in.nextInt();
			
			for(int i=A; i<B; ++i)
			{
				String num = Integer.toString(i);
				int len = num.length();
				HashSet<String> oNums = new HashSet<String>();
				for(int j=1; j<len; ++j)
				{
					num = (num.substring(1,len) + num.substring(0,1));
					if(!oNums.contains(num))
					{
						int val = Integer.parseInt(num);
						if(val > i &&  val <= B)
						{
							++ret;
						}
						oNums.add(num);
					}
				}
			}
			
			System.out.println("Case #" + ++tt + ": " + ret);
		}
	}
}