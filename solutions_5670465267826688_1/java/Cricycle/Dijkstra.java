import java.util.*;

public class Dijkstra
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		//test();
		//if (1 == 1) return;
		int t = in.nextInt();
		for (int testCase = 1; testCase <= t; ++testCase)
		{
			int l = in.nextInt();
			long x = in.nextLong();
			
			String input = in.next();
			// index from left of first time we can make i, -1 if impossible
			long minLeftI = getLeftI(input, x);
			
			// index from right of first time we can make k, -1 if impossible
			long minRightK = getRightK(input, x);
			
			// get overall eval of string
			Qu overall = Qu.ONE;
			for (int i = 0; i < input.length(); ++i)
			{
				overall = overall.multiply(Qu.get(input.charAt(i)));
			}
			
			Qu base = overall;
			for (int i = 0; i < (x-1)%4; ++i)
			{
				overall = overall.multiply(base);
			}
			
			String answer = "NO";
			if (minLeftI < minRightK && minLeftI >= 0 && overall.equals(Qu.M_ONE))
				answer = "YES";
			
			//System.out.printf("input: %s, x: %d\n", input, x);
			//System.out.printf("leftI = %d, rightK = %d, overall = %s\n", minLeftI, minRightK, overall.toString());
			System.out.printf("Case #%d: %s\n", testCase, answer);
		}
	}
	
	public static void test()
	{
		Qu[] q = {Qu.ONE, Qu.M_ONE, Qu.I, Qu.M_I, Qu.J, Qu.M_J, Qu.K, Qu.M_K};
		for (int i = 0; i < q.length; ++i)
		{
			for (int j = 0; j < q.length; ++j)
			{
				System.out.printf("%s x %s = %s\n", q[i], q[j], q[i].multiply(q[j]));
			}
		}
	}
	
	public static long getLeftI(String input, long x)
	{
		Qu start = Qu.ONE;
		long mindex = -1;
		for (int i = 0; i < input.length() * Math.min(4, x); ++i)
		{
			start = start.multiply(Qu.get(input.charAt(i % input.length())));
			if (start.equals(Qu.I))
			{
				mindex = i;
				break;
			}
		}
		
		return mindex;
	}
	
	public static long getRightK(String input, long x)
	{
		Qu start = Qu.ONE;
		long maxdex = -1;
		for (int i = 0; i < input.length() * Math.min(4, x); ++i)
		{
			Qu mult = Qu.get(input.charAt((input.length() - 1 - (i % input.length()))));
			start = mult.multiply(start);
			if (start.equals(Qu.K))
			{
				maxdex = input.length() * x - i - 1;
				break;
			}
		}
		
		return maxdex;
	}
	
}

class Qu
{
	public static final Qu ONE = new Qu(0, 1);
	public static final Qu M_ONE = new Qu(0, -1);
	public static final Qu I = new Qu(1, 1);
	public static final Qu M_I = new Qu(1, -1);
	public static final Qu J = new Qu(2, 1);
	public static final Qu M_J = new Qu(2, -1);
	public static final Qu K = new Qu(3, 1);
	public static final Qu M_K = new Qu(3, -1);
	
	private int type;
	private int sign;
	
	private Qu(int type, int sign)
	{
		this.type = type;
		this.sign = sign;
		if (type < 0 || type > 3)
			throw new RuntimeException("You fail.");
		if (sign != 1 && sign != -1)
			throw new RuntimeException("Damn it.");
	}
	
	public static Qu get(char c)
	{
		switch(c)
		{
			case 'i':
				return Qu.I;
			case 'j':
				return Qu.J;
			case 'k':
				return Qu.K;
			default:
				throw new RuntimeException("What are you doing...");
		}
	}
	
	public Qu multiply(Qu qu)
	{
		int targetType = -1;
		int targetSign = sign * qu.sign;
		if (type == qu.type)
		{
			targetType = 0;
			targetSign *= (type == 0 ? 1 : -1);
		}
		else if (type == 0 || qu.type == 0)
			targetType = Math.max(type, qu.type);
		else
		{
			targetType = 6 - type - qu.type;
			if ((type == 1 && qu.type == 3) || (type == 2 && qu.type == 1) || (type == 3 && qu.type == 2))
			{
				targetSign *= -1;
			}
		}
		
		return new Qu(targetType, targetSign);
	}
	
	public boolean equals(Object o)
	{
		if (!(o instanceof Qu))
			return false;
		
		Qu q = (Qu)o;
		return q.type == type && q.sign == sign;
	}
	
	public String toString()
	{
		return String.format("{%c%c}", sign > 0 ? '+' : '-', getChar(type));
	}
	
	private char getChar(int type)
	{
		switch(type)
		{
			case 0:
				return '1';
			case 1:
				return 'i';
			case 2:
				return 'j';
			case 3:
				return 'k';
			default:
				throw new RuntimeException("Shit.");
		}
	}
}