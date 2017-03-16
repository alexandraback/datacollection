import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;


public class A {

	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int caseNum = 0;
		while(testCases>0){
			testCases--;
			caseNum++;
			
			//int r = scan.nextInt();
			//int t = scan.nextInt();
			String r = scan.next();
			String t = scan.next();
			
			BigInteger r1 = new BigInteger(r);
			BigInteger t1 = new BigInteger(t);
			
			BigInteger term1 = (r1.multiply(new BigInteger("2"))).subtract(BigInteger.ONE);//2r-1
			BigInteger term2 = (term1.pow(2)).add(t1.multiply(new BigInteger("8"))); // (2r-1)^2 + 8t
			
			BigInteger term3 = bigIntSqRootFloor(term2);
			BigInteger term4 = ((term3.subtract(term1)).divide(new BigInteger("4")));
			
			
//			int count =(int) Math.floor( (-(2*r-1) + Math.sqrt( (2*r-1)*(2*r-1)+8*t )) /4);
			System.out.print("Case #"+(caseNum)+": ");
			System.out.println(term4.toString());
		}
		
//		System.out.println();
//		for(int a = 0; a<caseNum; a++){
//			System.out.print("Case #"+(a+1)+": ");
//			
//			
//			
//			System.out.println();
//		}
	}
	
	public static BigInteger bigIntSqRootFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)){
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	} // end bigIntSqRootFloor

}
