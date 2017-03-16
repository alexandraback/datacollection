import java.util.Scanner;
import java.lang.*;
import java.math.BigInteger;

public class Bullseye {

	public BigInteger radius = new BigInteger("0");
	public BigInteger paint_mil = new BigInteger("0");
	public BigInteger max = new BigInteger("1000000000000000000");
			
	public BigInteger TWO = new BigInteger("2");
	public Bullseye(BigInteger r, BigInteger t) {
		radius = r;
		paint_mil = t;
	}
	
	public BigInteger numRings() {
		BigInteger paintUsed = new BigInteger("0");
		BigInteger start = new BigInteger("0");
		BigInteger end = max;
		BigInteger middle = start.add(end).divide(TWO);
		BigInteger n = middle;

		boolean found = false;
		
		//binary search from 0 up to your biggest
		// at each poBigInteger substitute n BigIntegero the equation
		// paBigInteger used = (n+1) * (2n + 2r + 1)
		
		// if paBigInteger used is more than paBigInteger_mil, search lower
		// if paBigInteger used is less than paBigInteger_mil, search higher
		
		// but!
		BigInteger testPaint = new BigInteger("0");
		
		while ((start.compareTo(end) == -1) && !found) {
			paintUsed = n.add(BigInteger.ONE).multiply(n.multiply(TWO).add(radius.multiply(TWO)).add(BigInteger.ONE));
			//System.out.format("Paint used: %d, n: %d, start: %d, end:%d\n", paintUsed, n, start, end);
			if (paintUsed.compareTo(paint_mil) == -1) {
				// if we find one where paBigInteger used is less than paBigInteger mil, and the one above is more, then we go with it.
				n = n.add(BigInteger.ONE);
				testPaint = n.add(BigInteger.ONE).multiply(n.multiply(TWO).add(radius.multiply(TWO)).add(BigInteger.ONE));
				if (testPaint.compareTo(paint_mil) == 1) {
					n = n.subtract(BigInteger.ONE);
					found = true;
				} else {
					start = middle;
					middle = start.add(end).divide(TWO);
					n = middle;
					//System.out.format("n: %d, start: %d, end:%d\n", n, start, end);
				}
			} else if (paintUsed.compareTo(paint_mil) == 1) {
				end = middle;
				middle = start.add(end).divide(TWO);
				//System.out.format("start+end:%d, start+end/2:%d\n", start+end, start+end/2);
				n = middle;
				//System.out.format("n: %d, start: %d, end:%d\n", n, start, end);
			} else {
				found = true;
			}
		}
		
		return n.add(BigInteger.ONE);
	}

}
