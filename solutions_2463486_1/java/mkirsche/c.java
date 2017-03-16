import java.util.*;
import java.io.*;
public class c {
public static void main(String[] args) throws IOException
{
	PrintWriter out = new PrintWriter(new File("output.txt"));
	ArrayList<Long> list = new ArrayList<Long>(), fair = new ArrayList<Long>();
	for(int i = 1; i<=10000000; i++)if(pal(i+"")) list.add((long) i);
	for(long i: list) if(pal(i*i+"")) fair.add(i*i);
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		long a = input.nextLong(), b = input.nextLong(), res = 0;
		for(long i: fair) if(i>=a && i<=b) res++;
		out.println("Case #"+(t+1)+": "+res);
	}
	out.close();
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
