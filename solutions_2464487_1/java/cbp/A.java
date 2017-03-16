package codejam.y2013.r1a;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;

import codejam.base.ProblemSolver;

public class A extends ProblemSolver {

	public static void main(String[] args) throws java.io.IOException
	{
		A processor;

		processor = new A();
		processor.setFilePrefix("A-large");
		processor.start();
	}
	
	@Override
	public String processCase(int caseNumber) throws IOException {
		BigInteger r = nextBigInteger();
		BigInteger t = nextBigInteger();
		
		BigInteger four = BigInteger.valueOf(4);
		BigInteger eight = BigInteger.valueOf(8);
		BigInteger m = r.multiply(BigInteger.valueOf(2));
		m = m.subtract(BigInteger.ONE);
		BigInteger mSq = m.multiply(m);
		BigInteger disc = mSq.add(t.multiply(eight));
		disc = sqrt(disc);
		
		BigInteger n1 = ((m.negate()).add(disc)).divide(four);
		BigInteger n2 = ((m.negate()).subtract(disc)).divide(four);
		
		BigInteger n = n1.compareTo(n2) == 1 ? n1 : n2;
		
		return n.toString();
	}
	
	public static BigInteger sqrt(BigInteger x) {
	    
	    if ( x == BigInteger.ZERO || x == BigInteger.ONE )
	        return x;
	    
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	}
}
