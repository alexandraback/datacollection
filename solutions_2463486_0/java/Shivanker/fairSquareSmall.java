import java.util.Scanner;


public class fairSquareSmall {

	public static boolean squareFair(int n)	{
		long m = n;
		m *= m;
		String s = new String(m+""), s2 = new String(n+"");
		StringBuffer t = new StringBuffer(m+""), t2 = new StringBuffer(n+"");
		return s.equals(t.reverse().toString()) && s2.equals(t2.reverse().toString());
	}
	
	public static void main(String[] args) {
		int count[] = new int[100000000];
		count[0] = 1;
		for(int i = 1; i < 10000001; ++i)	{
			count[i] = count[i-1];
			if(squareFair(i))
				count[i]++;
		}
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for(int i = 1; i <= t; ++i)	{
			System.out.print("Case #"+i+": ");
			long a = Long.parseLong(c.next());
			long b = Long.parseLong(c.next());
			long ra = (long)Math.sqrt(a);
			long rb = (long)Math.sqrt(b);
			if(ra*ra >= a)
				ra--;
			if(rb*rb <= b && (rb+1)*(rb+1) <= b)
				rb++;
			System.out.println(count[(int)rb]-count[(int)ra]);
		}
		c.close();
	}

}
