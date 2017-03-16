import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class ProjectA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File file = new File(args[0]);
        File ofile = new File(args[0] + ".out");
        
        BufferedReader reader = null;
        BufferedWriter writer = null;
        try {
            reader = new BufferedReader(new FileReader(file));
            writer = new BufferedWriter(new FileWriter(ofile));
            
            String tempString = reader.readLine();
            int T = Integer.parseInt(tempString);
            
            BigInteger[] r = new BigInteger [T];
            BigInteger [] t = new BigInteger [T];
            for(int i = 0; i < T; i++){
            	tempString = reader.readLine();
            	StringTokenizer st = new StringTokenizer(tempString);
            	r[i] = new BigInteger(st.nextToken());
            	t[i] = new BigInteger(st.nextToken());
            }
            
            long[] num = process(r, t, T);
            for(int i = 0; i < T; i++){
            	System.out.println("Case #" + (i+1) + ": " + num[i]);
            	writer.write("Case #" + (i+1) + ": " + num[i]);
            	writer.newLine();
            }
            
            reader.close();
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
	}

	private static long[] process(BigInteger[] r, BigInteger[] t, int T) {
		long[] num = new long[T];
		BigInteger one = BigInteger.ONE;
		BigInteger two = one.add(one);
		BigInteger three = two.add(one);
		BigInteger four = three.add(one);
		for(int i = 0; i < T; i++){
			BigInteger sqrt = bigIntSqRootFloor(one.add(four.negate().multiply(r[i]).add(four.multiply(r[i]).multiply(r[i]))).add(two.multiply(four.multiply(t[i]))));
			num[i] = (long) 1 + sqrt.add(three.negate()).add(two.negate().multiply(r[i])).divide(four).longValue();
		}
		return num;
	}
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
}
