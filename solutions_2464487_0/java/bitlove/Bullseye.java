import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye {

	private static BigInteger sqrt(BigInteger b){
		BigInteger l = BigInteger.ZERO;
		BigInteger r = b;
		while(l.compareTo(r.subtract(BigInteger.ONE)) < 0){
			BigInteger m = l.add(r).shiftRight(1);
			BigInteger s = m.multiply(m);
			if(s.compareTo(b) == 0)
				return m;
			else if(s.compareTo(b) > 0){
				r = m.subtract(BigInteger.ONE);
			}else{
				l = m;
			}
		}
		
		BigInteger a = r.multiply(r);
		if(a.compareTo(b) <= 0)
			return r;
		return l;
	}
	
	public static void main(String args[]) throws IOException{
		Scanner s = new Scanner(new FileInputStream("A-small-attempt0 (1).in"));
		PrintWriter writer = new PrintWriter(new FileOutputStream("output.txt"));
		int T = s.nextInt();
		for(int i = 0 ; i < T ; i ++){
			String r = s.next();
			String t = s.next();
			BigInteger br = new BigInteger(r);
			BigInteger bt = new BigInteger(t);
			BigInteger a = new BigInteger("2");
			BigInteger b = br.multiply(a).add(new BigInteger("-1"));
			BigInteger c = BigInteger.ZERO.subtract(bt);
			
			BigInteger x = b.multiply(b).subtract(a.multiply(c).multiply(new BigInteger("4")));
			x = sqrt(x);
			BigInteger result = BigInteger.ZERO.subtract(b).add(x).divide(new BigInteger("4"));
			System.out.println(result);
			writer.println("Case #" + (i + 1) + ": " + result);
		}
		s.close();
		writer.close();
	}
}
