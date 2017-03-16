import java.util.*;
public class c {
public static void main(String[] args)
{
	ArrayList<Long> list = new ArrayList<Long>(), fair = new ArrayList<Long>();
	for(int i = 1; i<=10000000; i++)if(pal(i+"")) list.add((long) i);
	for(long i: list) if(pal(i*i+"")) fair.add(i*i);
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int a = input.nextInt(), b = input.nextInt(), res = 0;
		for(long i: fair) if(i>=a && i<=b) res++;
		System.out.println("Case #"+(t+1)+": "+res);
	}
}
static boolean pal(String s)
{
	boolean good = true;
	for(int i = 0; i<=s.length()/2; i++)
	{
		good &= s.charAt(i) == s.charAt(s.length()-i-1);
	}
	return good;
}
}
