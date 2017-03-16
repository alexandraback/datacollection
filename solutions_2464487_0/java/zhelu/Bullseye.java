import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {

	public static void readInputWriteOutput(String input, String output)
			throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			long ans = numRings(sc.nextLong(), sc.nextLong());
			System.out.println("Case #" + i + ": " + ans);
			bw.write("Case #" + i + ": " + ans);
			if (i != cases)
				bw.newLine();
		}
		sc.close();
		bw.close();
	}


	/*
	 * Drawing R rings starting with radius r requires R * (-1 + 2r + 2R) ml
	 * paint.
	 * 
	 * Given R * (-1 + 2r + 2R) = T, R = floor ((1 - 2r + sqrt(1 - 4r +4r^2 +
	 * 8T)) / 4)
	 */

	public static long numRings(long r, long paint) {
		long lo = 0l;
		long hi = 1l;
		;
		while (area(r, hi) < paint) {
			hi = hi << 1;
		}
		if (area(r, hi) == paint)
			return hi;
		while (lo + 1 != hi) {
			long mid = (lo + hi) / 2;
			long a = area(r, mid);
			if (a == paint)
				return mid;
			else if (a < paint) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return lo;
	}


	public static long area(long r, long numRings) {
		BigInteger R = BigInteger.valueOf(r);
		BigInteger N = BigInteger.valueOf(numRings);
		BigInteger A = (((N.multiply(N)).add(R.multiply(N)))
				.multiply(BigInteger.valueOf(2))).subtract(N);
		return A.longValue();
	}


	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Bullseye.readInputWriteOutput("Bullseye-small.in",
				"Bullseye-small-output.txt");
	}

}
