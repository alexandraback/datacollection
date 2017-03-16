import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class QR2015C
{
	static String mult(char a, char b)
	{
		if (a == '1') return b+"";
		if (b == '1') return a+"";
		if (a == b) return "-1";
		if (a == 'i' && b == 'j') return "k";
		if (a == 'j' && b == 'i') return "-k";
		if (a == 'j' && b == 'k') return "i";
		if (a == 'k' && b == 'j') return "-i";
		if (a == 'k' && b == 'i') return "j";
		if (a == 'i' && b == 'k') return "-j";
		throw new RuntimeException("Bad Mult");
	}
	static String mult(String a, String b)
	{
		String s = mult(a.charAt(a.length()-1),b.charAt(b.length()-1));
		int cnt = s.length()+1 + a.length()+1 + b.length()+1;
		return ((cnt%2==0)?"":"-") + s.charAt(s.length()-1);
	}
	static String mult(String s, boolean fow)
	{
		String acc = "1";
		for (int i = 0; i < s.length(); ++i) acc = fow ? mult(acc,""+s.charAt(i)) : mult(""+s.charAt(i),acc);
		return acc;
	}
	static String pow(String s, long p)
	{
		if (s.equals("1")) return "1";
		if (s.equals("-1")) return p % 2 == 0 ? "1" : "-1";
		if (p % 4 == 0) return "1";
		if (p % 4 == 1) return s;
		if (p % 4 == 2) return "-1";
		if (p % 4 == 3) return s.length() == 2 ? ""+s.charAt(1) : "-"+s.charAt(0);
		throw new RuntimeException("Bad Pow");
	}
	static long findFirst(String s, String f, String acc, boolean fow)
	{
		if (acc.equals(f)) return 0;
		for (int i = 0; i < s.length(); ++i)
		{
			acc = fow ? mult(acc,""+s.charAt(i)) : mult(""+s.charAt(i),acc);
			if (acc.equals(f)) return i+1;
		}
		return -1;
	}
	static long findFirst(String s, String f, boolean fow)
	{
		String all = mult(s,fow);
		for (int i = 0; i < 4; ++i)
		{
			//System.out.printf("Checking s=%s,f=%s,i=%d,m(s)=%s,pow(ms,i)=%s\n",s,f,i,mult(s),pow(mult(s),i));
			long x = findFirst(s,f,pow(all,i),fow);
			if (x > -1) return x + i*all.length();
		}
		return -1;
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; ++t)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			long L = Long.parseLong(st.nextToken()), X = Long.parseLong(st.nextToken());
			String s = in.readLine();
			String rs = new StringBuilder(s).reverse().toString();
			//System.out.printf("s = %s, mult(s) = %s, s^%d=%s\n",s,mult(s),X,pow(mult(s),X));
			boolean test1 = pow(mult(s,true),X).equals("-1");
			long indexI = findFirst(s,"i",true);
			long indexK = findFirst(rs,"k",false);
			//System.out.printf("indexI=%d, indexK=%d, test1=%b, L*X=%d\n",indexI,indexK,test1,L*X);
			boolean bad = !test1 || indexI == -1 || indexK == -1 || indexI + indexK >= L*X;
			System.out.printf("Case #%d: %s\n",t+1,bad?"NO":"YES");
		}
	}
}
