import java.math.*;
import java.io.*;
class BigIntSqRoot {

public static BigInteger bigIntSqRootFloor(BigInteger x)
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
} // end bigIntSqRootFloorpublic class BigIntSqRoot {
}

class bullsEye {

	public static void main(String args[]) {	
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str;
			str = br.readLine();
			str = br.readLine();
			String inputs[];
			int i=1;
			BigInteger FOUR = new BigInteger("4");
			BigInteger TWO = new BigInteger("2");
			BigInteger EIGHT = new BigInteger("8");
			BigInteger ONE = new BigInteger("1");
			 while (str != null) {
				inputs=str.split(" ");
				//System.out.println(">>" +str  + "<<"  +inputs[0] + " " + inputs[1] );
				str = br.readLine();
                                BigInteger r=new BigInteger(inputs[0]);
                                BigInteger s=new BigInteger(inputs[1]);

                                //BigInteger x=BigIntSqRoot.bigIntSqRootFloor((((r.pow(2)).subtract(r.multiply(FOUR))).add(s.multiply(EIGHT)).add(ONE)));
                                BigInteger x=BigIntSqRoot.bigIntSqRootFloor(((((r.pow(2)).multiply(FOUR)).subtract(r.multiply(FOUR))).add(s.multiply(EIGHT)).add(ONE)));
				BigInteger y=(r.multiply(TWO)).subtract(ONE);
				BigInteger z=(x.subtract(y)).divide(FOUR);

				System.out.println("Case #" + i++ + ": " + z );
			} 
		} catch(IOException E) {
			System.err.println("ERROR");
		}
	}
}
