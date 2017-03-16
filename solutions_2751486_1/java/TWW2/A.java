import java.util.*;

class A
{
	public static String vowels = "aeiou";
	
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
		String msg = in.next();
		int L = msg.length();
		int n = in.nextInt();
		
		int min = 0;
		long ret = 0;
		int cnt = 0;
		
		for(int i=0; i<L; ++i)
		{
			if(vowels.indexOf(msg.charAt(i)) == -1)
			{
				++cnt;
				
				if(cnt >= n)
				{
					long addRet = (long)(2+i-n-min) * (long)(L-i);
					//System.err.println(addRet);
					ret += addRet;
					min = 2+i-n;
				}
				
				
			} else {
				cnt = 0;
			}
			//System.err.println(i + " " + cnt);
		}
		
		return Long.toString(ret);
	}
}