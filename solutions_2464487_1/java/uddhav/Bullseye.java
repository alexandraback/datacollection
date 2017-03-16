package name.uddhav.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {
	
	private static BigInteger squareRoot(BigInteger number) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(number.shiftRight(5).add(new BigInteger("8")).toString());
		  
		while (b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			
			if (mid.multiply(mid).compareTo(number) > 0) {
				b = mid.subtract(BigInteger.ONE);
				
			} else {
				a = mid.add(BigInteger.ONE);
				
			}
		}
		
		BigInteger r = a.subtract(BigInteger.ONE);
		
		return r;
	}

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("bullseye-sample");
		Scanner scanner = new Scanner(file);
		
		File out = new File("bullseye-out");
		PrintWriter pw = new PrintWriter(out);
		
		int cases = scanner.nextInt();
		
		int counter = 0;
		while (counter++ < cases) {
			BigInteger r = scanner.nextBigInteger();
			BigInteger t = scanner.nextBigInteger();
			
			BigInteger b = r.shiftLeft(1).add(BigInteger.ONE).add(new BigInteger("-2"));
			BigInteger a = new BigInteger("2");
			
			BigInteger d = a.shiftLeft(2).multiply(t);
			
			BigInteger temp1 = squareRoot(b.pow(2).add(d));
			
			BigInteger candidate = (b.negate().add(temp1)).divide(a.shiftLeft(1));
			
			pw.println("Case #" + counter + ": " + candidate);
		}
		
		pw.close();

	}

}
