package round1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class B {
	public static B bclass = new B();
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		Scanner sc = new Scanner(new File("input/round1b/B/B-large (1).in"));
		PrintWriter writer = new PrintWriter("output/round1b/test.out", "UTF-8");
		int T = sc.nextInt();
		sc.nextLine();
		for(int casenr = 1; casenr<=T; casenr++)
		{
			String line = sc.nextLine();
			
			ans answer = rec(0, line.split(" ")[0], line.split(" ")[1]);

			String aa = String.valueOf(answer.a);
			while(aa.length()<line.split(" ")[0].length())
				aa = "0" + aa;
			String bb = String.valueOf(answer.b);
			while(bb.length()<line.split(" ")[1].length())
				bb = "0" + bb;
			
			writer.println("Case #" + casenr + ": " + aa + " " + bb);
		}
		sc.close();
		writer.close();
	}

	private static ans rec(long aa, String a, String b) {
		if(a.length()==0)
			return bclass.new ans(aa, aa);
		char ca = a.charAt(0);
		char cb = b.charAt(0);
		if(ca == '?')
		{
			if(cb == '?')
			{
				ans opt = rec(aa*10, a.substring(1), b.substring(1));
				ans opta = bigger(aa*10+1, aa*10, a.substring(1), b.substring(1));
				ans optb = bigger(aa*10+1, aa*10, b.substring(1), a.substring(1));
				optb = bclass.new ans(optb.b, optb.a);
				return min(min(opta, optb),opt);
//				ans opt = bigger(aa*10+1, aa*10, b.substring(1), a.substring(1));
//				opt = bclass.new ans(opt.b, opt.a);
//				return min(min(rec(aa*10, a.substring(1), b.substring(1)), bigger(aa*10+1, aa*10, a.substring(1), b.substring(1))),opt);
			}
			else
			{
				long ib = Integer.parseInt(String.valueOf(cb));
				ans opt = rec(aa*10 + ib, a.substring(1), b.substring(1));
				ans opta = bigger(aa*10+ib+1, aa*10+ib, a.substring(1), b.substring(1));
				ans optb = bigger(aa*10+ib, aa*10+ib-1, b.substring(1), a.substring(1));
				optb = bclass.new ans(optb.b, optb.a);
				if(ib==9)
					opta = null;
				if(ib==0)
					optb = null;
				return min(min(opta, optb),opt);
			}
		}
		else
		{
			if(cb == '?')
			{
				long ia = Integer.parseInt(String.valueOf(ca));
				ans opt = rec(aa*10 + ia, a.substring(1), b.substring(1));
				ans opta = bigger(aa*10+ia, aa*10+ia-1, a.substring(1), b.substring(1));
				ans optb = bigger(aa*10+ia+1, aa*10+ia, b.substring(1), a.substring(1));
				optb = bclass.new ans(optb.b, optb.a);
				if(ia==9)
					optb = null;
				if(ia==0)
					opta = null;
				return min(min(opta, optb),opt);
			}
			else
			{
				long ia = Integer.parseInt(String.valueOf(ca));
				long ib = Integer.parseInt(String.valueOf(cb));
				if(ia == ib)
					return rec(aa*10 + ia, a.substring(1), b.substring(1));
				else
				{
					if(ia>ib)
						return bigger(aa*10+ia, aa*10+ib, a.substring(1), b.substring(1));
					else
					{
						ans opt = bigger(aa*10+ib, aa*10+ia, b.substring(1), a.substring(1));
						return bclass.new ans(opt.b, opt.a);
					}
				}
			}
		}
	}
	
	private static ans min(ans a, ans b) {
		if(a==null)
			return b;
		if(b==null)
			return a;
		if(Math.abs(a.a-a.b) < Math.abs(b.a-b.b))
			return a;
		else if(Math.abs(a.a-a.b) > Math.abs(b.a-b.b))
			return b;
		else if(a.a < b.a || (a.a == b.a && a.b < b.b))
			return a;
		else
			return b;
	}

	private static ans bigger(long aa, long bb, String a, String b) {
		if(a.length()==0)
			return bclass.new ans(aa, bb);
		char ca = a.charAt(0);
		if(ca == '?') ca = '0';
		char cb = b.charAt(0);
		if(cb == '?') cb = '9';
		long ia = Integer.parseInt(String.valueOf(ca));
		long ib = Integer.parseInt(String.valueOf(cb));
		return(bigger(aa*10+ia, bb*10+ib, a.substring(1), b.substring(1)));
	}

	public class ans {
		long a;
		long b;
		public ans(long aa, long bb)
		{
			a = aa;
			b = bb;
		}
	}
}
