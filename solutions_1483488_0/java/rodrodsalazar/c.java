import java.util.*;

class c
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1;t<=T;++t)
		{
			int a,b;
			a = in.nextInt();
			b = in.nextInt();
			long pairs = 0;
			for(int i=a;i<=b;++i)
			{
				HashSet<Integer> m = new HashSet<Integer>();
				String istr = "" + i;
				int numDigits = istr.length();
				for(int j=1;j<numDigits;++j)
				{
					String backend = istr.substring(j);
					String frontend = istr.substring(0,j);
					String newstr = backend+frontend;
					int newnum = Integer.parseInt(newstr);
					if(newnum > i && newnum <= b)
					{
						if(!m.contains(newnum))
						{
							++pairs;
							m.add(newnum);
						}
					}
				}
			}
			
			System.out.println("Case #"+t+": " + pairs);
		}
	}
}
