import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {

	public long getCircleCount(long radius, long t) {
		BigInteger lo = new BigInteger("1");
		BigInteger hi = new BigInteger("2000000000000000001");
		BigInteger two = new BigInteger("2");
		BigInteger rad = new BigInteger(String.valueOf(radius));
		BigInteger tt = new BigInteger(String.valueOf(t));
		
		BigInteger mid;
		while(lo.compareTo(hi) < 0) {
			mid = lo.add(hi.subtract(lo).divide(two));
			
			if (hi.compareTo(lo.add(BigInteger.ONE)) == 0) {
				if (hi.multiply(hi.add(rad).multiply(two).subtract(BigInteger.ONE)).compareTo(tt) <= 0) {
					lo = hi;
				}
				break;
			}
			if (mid.multiply(mid.add(rad).multiply(two).subtract(BigInteger.ONE)).compareTo(tt) <= 0) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		
		BigInteger loplus = lo.add(BigInteger.ONE);
		if (loplus.multiply(loplus.add(rad).multiply(two).subtract(BigInteger.ONE)).compareTo(tt) <= 0) {
			lo = loplus;
		}
		
		return lo.longValue();
	}
	
	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner input = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			input = new Scanner(new File(INPUT_FILE_PATH));
			int testCount = input.nextInt();
			String[] output = new String[testCount];

			for (int i = 0; i < testCount; i++) {
				long r = input.nextLong();
				long t = input.nextLong();
				
				System.out.println(i);
				output[i] = "Case #" + (i + 1) + ": " + new Bullseye().getCircleCount(r, t);
			}

			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			for (String line : output) {
				writer.println(line);
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (input != null) input.close();
			if (writer != null) writer.close();
		}
	}

}
