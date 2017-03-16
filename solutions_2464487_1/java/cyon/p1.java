import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		BigInteger r = new BigInteger(st.nextToken());
		long t0 = Long.parseLong(st.nextToken());
		BigInteger t = BigInteger.valueOf(t0);
		
		BigInteger l=BigInteger.ONE;
		BigInteger h=BigInteger.valueOf(2*(long)(1e18));
		BigInteger m=BigInteger.ONE;
		BigInteger two = BigInteger.valueOf(2);
		while (l.compareTo(h) < 0)
		{
			m = h.add(l).divide(two);
			//debug(l,h,m);
			BigInteger p1=two.multiply(m).multiply(r);
			BigInteger p2=two.multiply(m.subtract(BigInteger.ONE)).multiply(m);
			BigInteger z=p1.add(m).add(p2);
			//debug(z,t,m);
			if (z.compareTo(t) == 0)
				break;
			else if(z.compareTo(t) < 0)
				l = m.add(BigInteger.ONE);
			else
				h = m;
		}
		//m = m.add(BigInteger.ONE);
		BigInteger p1=two.multiply(m).multiply(r);
		BigInteger p2=two.multiply(m.subtract(BigInteger.ONE)).multiply(m);
		BigInteger z=p1.add(m).add(p2);
		//debug(z,t,m);
		if(z.compareTo(t) <= 0) {
			return m.toString();
		}
		else {
			return m.subtract(BigInteger.ONE).toString();
		}
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}