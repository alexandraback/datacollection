import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Bullseye {
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("A-small-attempt0.in"));
		int T = Integer.parseInt(read.readLine());
		for(int c = 1; c <= T; c++){
			StringTokenizer st = new StringTokenizer(read.readLine());
			BigInteger r = new BigInteger(st.nextToken());
			BigInteger t = new BigInteger(st.nextToken());
			System.out.println("Case #" + c + ": " + quadForm(r, t).toString());
		}

	}
	public static BigInteger quadForm(BigInteger r, BigInteger t) {
		BigInteger b = r.add(r).subtract(BigInteger.ONE);
		return sqrt(b.multiply(b).add(t.multiply(new BigInteger("8")))).subtract(b).divide(new BigInteger("4"));
	}
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
}