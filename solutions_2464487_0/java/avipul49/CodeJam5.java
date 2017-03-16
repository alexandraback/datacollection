import java.io.File;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;

public class CodeJam5 {

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
	} // end bigIntSqRootFloor

	public static void main(String[] args) {

		try {
			File f = new File("input.txt");
			File o = new File("OUTPUT.txt");

			InputReaderUtil iru = new InputReaderUtil(new FileInputStream(f));
			PrintWriter out = new PrintWriter(o);
			int T = iru.readInt();
			int j = 0, k = 0;
			for (int i = 1; i <=T; i++) {
				long r=iru.readLong(),t=iru.readLong();
				BigInteger rr=BigInteger.valueOf(r);
				BigInteger tt=BigInteger.valueOf(t);
				BigInteger temp1=rr.multiply(BigInteger.valueOf(2));
				temp1=temp1.subtract(BigInteger.ONE);
				temp1=temp1.multiply(temp1);
				temp1=temp1.add(tt.multiply(BigInteger.valueOf(8)));
				temp1=bigIntSqRootFloor(temp1);
				//System.out.println(temp1);
				temp1=temp1.add(BigInteger.ONE);
				temp1=temp1.subtract(rr.multiply(BigInteger.valueOf(2)));
				temp1=temp1.divide(BigInteger.valueOf(4));
				out.println("Case #"+i+": "+temp1);
			}
			out.close();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
}
