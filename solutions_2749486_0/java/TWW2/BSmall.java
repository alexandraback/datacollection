import java.util.*;

class BSmall
{
	public static void main(String[] arg)
	{
		Scanner in = new Scanner(System.in);
		int tt = in.nextInt();
		for(int i=1; i<= tt; ++i)
		{
			System.out.println("Case #" + i + ": " + doWork(in));
		}
	}
	
	public static String doWork(Scanner in)
	{
		int x = in.nextInt();
		int y = in.nextInt();
		
		StringBuilder ret = new StringBuilder();
		
		boolean xWasZero = x == 0;
		if(x > 0)
		{
			ret.append("E");
			while(--x > 0)
			{
				ret.append("WE");
			}
		} else if(x < 0) {
			ret.append("W");
			while(++x < 0)
			{
				ret.append("EW");
			}
		}
		
		if(y > 0)
		{
			if(xWasZero)
			{
				--y;
				ret.append("N");
			}
			while(y > 0)
			{
				ret.append("SN");
				--y;
			}
		} else if(y < 0)
		{
			if(xWasZero)
			{
				++y;
				ret.append("S");
			}
			while(y < 0)
			{
				ret.append("NS");
				++y;
			}
		}
		
		return ret.toString();
	}
}