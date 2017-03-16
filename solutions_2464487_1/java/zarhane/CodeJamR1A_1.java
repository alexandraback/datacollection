import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class CodeJamR1A_1 {
	public static void main(String[] args) throws IOException {
	  String fileName = "A-small";
		Scanner s = new Scanner(new FileReader(new File(fileName+".in")));
		PrintWriter out = new PrintWriter(new File(fileName+".out"));
		StringBuilder resultat =new StringBuilder("");
		
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger three = new BigInteger("3");
		BigInteger four = new BigInteger("4");
		BigInteger five = new BigInteger("5");
		BigInteger eigth = new BigInteger("8");
		
		int TC = s.nextInt();
		s.nextLine();
		
    for (int tc = 0; tc < TC; tc++) {
      if(tc!=0)
        resultat.append("\n");
      resultat.append("Case #"+(tc+1)+": ");

      String line = s.nextLine();
      System.out.println(line);
      
      
			String[] rt = line.split(" ");
			
			
			BigInteger R = new BigInteger(rt[0]);
			BigInteger T = new BigInteger(rt[1]);
			
			
			BigInteger b = R.multiply(two);
			b = b.add(three);
			
			
			BigInteger delta = b.multiply(b);
			
			
			
			BigInteger val = R.multiply(two);
			val = val.add(one);
			val = val.subtract(T);
			val = val.multiply(eigth);
			
			delta = delta.subtract(val);
      
			
			
			BigInteger Num = sqrt(delta);
			
			Num = Num.subtract(b);
			
			Num = Num.divide(four);
			
			Num = Num.add(one);
//			BigInteger Res = Num.multiply(Num.add(one));
//			Res = Res.divide(two);
//			Res = Res.add(Num);
//			Res = Res.add(Num.multiply(R.multiply(two)));
			
//			
//			long count = 0;
//			
//			while(T.compareTo(BigInteger.ZERO)>0){
//			  
//			  
//			  T = T.subtract(R.multiply(two));
//			  T = T.subtract(one);
//			  
//			  if(T.compareTo(BigInteger.ZERO)>=0)
//			    count++;
//			  
//			  R = R.add(two);
//			}
//			
//			if(count<1)
//			  count = 1;
//			
			resultat.append(Num.toString());
		}
		
		out.print(resultat);
		out.close();
		s.close();
	}
	
	public static BigInteger sqrt(BigInteger x)
      throws IllegalArgumentException {
  if (x.compareTo(BigInteger.ZERO) < 0) {
      throw new IllegalArgumentException("Negative argument.");
  }
  // square roots of 0 and 1 are trivial and
  // y == 0 will cause a divide-by-zero exception
  if (x == BigInteger.ZERO || x == BigInteger.ONE) {
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
	
	 public static BigDecimal sqrt(BigDecimal x, int scale)
	  {
	      // Check that x >= 0.
	      if (x.signum() < 0) {
	          throw new IllegalArgumentException("x < 0");
	      }

	      // n = x*(10^(2*scale))
	      BigInteger n = x.movePointRight(scale << 1).toBigInteger();

	      // The first approximation is the upper half of n.
	      int bits = (n.bitLength() + 1) >> 1;
	      BigInteger ix = n.shiftRight(bits);
	      BigInteger ixPrev;

	      // Loop until the approximations converge
	      // (two successive approximations are equal after rounding).
	      do {
	          ixPrev = ix;

	          // x = (x + n/x)/2
	          ix = ix.add(n.divide(ix)).shiftRight(1);

	          Thread.yield();
	      } while (ix.compareTo(ixPrev) != 0);

	      return new BigDecimal(ix, scale);
	  }
}
