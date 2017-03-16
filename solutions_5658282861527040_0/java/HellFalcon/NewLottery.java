import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;


public class NewLottery {
	
	static long value(long a, long b, long k, long bit) {
		if (a <= k | b <= k)
			return (a+1)*(b+1);
		while ((a & bit) == 0 & (b & bit) == 0) bit >>>= 1;
		if ((k & bit) > 0) {
			return value(bit-1, bit-1, k, bit) + value(a-bit, bit-1, k, bit) + value(bit-1, b-bit, k, bit) + value(a-bit, b-bit, k-bit, bit);
		}
		else {
			if ((a & bit) > 0 & (b & bit) > 0) {
				return value(a-bit, bit-1, k, bit) + value(bit-1, b-bit, k, bit) + value(bit-1, bit-1, k, bit);
			}
			else if ((a & bit) > 0) {
				return value(a-bit, b, k, bit) + value(bit-1, b, k, bit);
			}
			else { // - if ((b & bit) > 0) {
				return value(a, b-bit, k, bit) + value(a, bit-1, k, bit);
			}
		}
	}
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("B-small-attempt0.in")), 256 << 10));
			PrintStream out = new PrintStream(new File("output.txt"));

			int testsNumber = in.nextInt();
			test:
			for (int testId = 1; testId <= testsNumber; testId++) {
				long a = in.nextInt();
				long b = in.nextInt();
				long k = in.nextInt();
				out.append("Case #" + testId + ": " + value(a-1, b-1, k-1, 1 << 30) + "\n");
			}
			in.close();
			out.close();
		}
		catch (RuntimeException rte) {
			throw rte;
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
