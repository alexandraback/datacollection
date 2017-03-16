import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1P3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("small3.out"));
		String inLine;
		int t = Integer.parseInt(in.readLine());
		int counter = 0;
		while ((inLine = in.readLine()) != null) {
			counter++;
			String[] toks = inLine.split(" ");
			long beg = Long.parseLong(toks[0]);
			long end = Long.parseLong(toks[1]);
			long c = 0;
			for (long i = beg; i < end; i++) {
				c += rotateNumber(i, end);
			}
			System.out.println("Case #" + counter + ": " + c);
			bw.write("Case #" + counter + ": " + c);
			bw.newLine();
		}
		in.close();
		bw.close();
	}

	public static long rotateNumber(long number, long end) {
		long start = number;
		int numdigits = (int) Math.log10((double) number); // would return
															// numdigits - 1
		int multiplier = (int) Math.pow(10.0, (double) numdigits);
		long counter = 0;
		while (true) {
			long q = number / 10;
			long r = number % 10;
			number = number / 10;
			number = number + multiplier * r;
			if (start < number && number <= end)
				counter++;
			if (number == start)
				break;
		}
		return counter;
	}

}
