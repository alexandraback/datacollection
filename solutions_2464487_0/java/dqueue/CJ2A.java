import java.util.*;
import java.io.*;
import java.math.*;

public class CJ2A 
{
	public static BigInteger bigIntSqRootFloor(BigInteger x)
	throws IllegalArgumentException {
		if (x.compareTo(BigInteger.ZERO) < 0) {
			throw new IllegalArgumentException("Negative argument.");
		}
//		square roots of 0 and 1 are trivial and
//		y == 0 will cause a divide-by-zero exception
		if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
			return x;
		} // end if
		BigInteger two = BigInteger.valueOf(2L);
		BigInteger y;
//		starting with y = x / 2 avoids magnitude issues with x squared
		for (y = x.divide(two);
		y.compareTo(x.divide(y)) > 0;
		y = ((x.divide(y)).add(y)).divide(two));
		return y;
	} 

	
	public static void main(String[] args) throws Exception 
	{
		File infile = new File("/Users/dennisqin/Downloads/CodeJam/A-small-attempt2.in.txt");
		File outfile = new File("/Users/dennisqin/Downloads/CodeJam/outputA.txt");
		BufferedReader br = new BufferedReader(new FileReader(infile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile));
		String s;
		int cases = Integer.parseInt(br.readLine());
		for(int i = 0; i < cases; i++)
		{
			s = br.readLine();
			String[] splits = s.split(" ");
			BigInteger r = new BigInteger(splits[0]);
			BigInteger A = new BigInteger(splits[1]);
			
			BigInteger sq = r.multiply(r).multiply(new BigInteger("4"));
			sq = sq.add(A.multiply(new BigInteger("8")));
			sq = sq.multiply(new BigInteger("10000"));
			sq = bigIntSqRootFloor(sq);
			sq = sq.subtract(r.multiply(new BigInteger("200")));
			sq = sq.divide(new BigInteger("400"));
			sq = sq.add(new BigInteger("1"));
			
			//check if off by one
			if (A.compareTo(sq.multiply((new BigInteger("2").multiply(r).add(new BigInteger("1")))).add(new BigInteger("2").multiply(sq.subtract(new BigInteger("1"))).multiply(sq))) < 0)
			{
				sq = sq.subtract(new BigInteger("1"));
			}

			bw.write("Case #" + (i+1) + ": " + sq.toString());
			if((i + 1) < cases)
			{
				bw.write("\n");
			}
			bw.flush();
		}
	}

}