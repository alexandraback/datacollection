import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static BigInteger a = new BigInteger("2");
	static BigInteger one = new BigInteger("1");
	static BigInteger neg = new BigInteger("-1");
	static BigInteger four = new BigInteger("4");
	/**
	 * 
	 * From here: http://faruk.akgul.org/blog/javas-missing-algorithm-biginteger-sqrt/
	 * @param n
	 * @return
	 */
	  public static BigInteger sqrt(BigInteger n) {
		    BigInteger a = BigInteger.ONE;
		    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		    while(b.compareTo(a) >= 0) {
		      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		      else a = mid.add(BigInteger.ONE);
		    }
		    return a.subtract(BigInteger.ONE);
		  }
	public static void main (String[] args) throws IOException
	{
		Scanner sc = new Scanner(new FileReader("input.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.out"));
		int T = sc.nextInt();
		
		for (int i = 1; i <= T; i++)
		{
			BigInteger r = sc.nextBigInteger();
			BigInteger t = sc.nextBigInteger();
			
			BigInteger b = (r.multiply(a)).subtract(one);
			BigInteger c = t.multiply(neg);
			
			//System.out.println(a + " " + b + " " + c);
			BigInteger ans = b.multiply(b);
			//System.out.println(ans);
			ans = ans.subtract((a.multiply(c)).multiply(four));
			//System.out.println(ans);
			ans = sqrt(ans);
			//System.out.println(ans);
			ans = ans.subtract(b);

			ans = ans.divide(four);
			pw.println("Case #" + i + ": " + ans);

		}
		pw.flush();
	}

}
