import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class rec {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			System.out.println("Case #" + c + ": " + solve(sc));
		}
	}

	static void debug(Object... objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}
	
	static final int po[]={1,10,100,1000,10000,100000,1000000,10000000};
	
	public static String solve(Scanner sc)
	{
		int A=sc.nextInt();
		int B=sc.nextInt();
		Set<P> s = new HashSet<P>();
		int N = Integer.toString(A).length();
		for(int i=A;i<=B;i++)
		{
			for(int k=1;k<N;k++)
			{
				int m=i%po[k];
				int p=i/po[k];
				int c = m*po[N-k]+p;
				P np=new P(i,c);
				if(i < c && c <= B && !s.contains(np))
				{
					s.add(np);
				}
			}
		}
		return Integer.toString(s.size());
	}
	
	private static class P
	{
		int v;
		int k;
		public P(int v, int k)
		{
			super();
			this.v = v;
			this.k = k;
		}
		@Override
		public boolean equals(Object obj)
		{
			if(obj == this) return true;
			if(!(obj instanceof P)) return false;
			P p = (P)obj;
			return v == p.v && k == p.k;
		}
		@Override
		public int hashCode()
		{
			int res=17;
			res = res*31 + v;
			res = res*31 + k;
			return res;
		}
	}
}