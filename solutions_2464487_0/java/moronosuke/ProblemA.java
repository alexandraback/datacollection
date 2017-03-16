package codejam2013.round1A;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;

public class ProblemA {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-small-attempt0";
			File folder = new File(new File("files", "codejam2013"), "round1A");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				String[] parameters = reader.readLine().split("\\s");
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(new BigInteger(parameters[0]),
								new BigInteger(parameters[1])));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(BigInteger r, BigInteger t) {
		BigInteger two = BigInteger.valueOf(2L);
		BigInteger first = r.multiply(two).add(BigInteger.ONE);
		BigInteger b = first.subtract(two);
		BigInteger delta = (b.multiply(b)).add(BigInteger.valueOf(8L).multiply(t));
		BigDecimal deltaRoot = sqrt(new BigDecimal(delta), 6);
		BigDecimal beforeDivision = deltaRoot.add(BigDecimal.valueOf(2L)).subtract(new BigDecimal(first));
		BigDecimal root = beforeDivision.divide(BigDecimal.valueOf(4L));
		return String.valueOf(root.longValue());
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

    private static BigDecimal sqrt(BigDecimal x, int scale)
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
