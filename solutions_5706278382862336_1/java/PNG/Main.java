import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	// using Google Guava, downloadable from: https://code.google.com/p/guava-libraries/

	public static void main(String[] args) throws Exception {
		File input = null;
		for (File f : new File(".").listFiles()) {
			if (f.isFile() && f.getName().endsWith(".in")) {
				input = f;
				break;
			}
		}
		Scanner s = new Scanner(input);
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		long divisor = (long) Math.pow(2, 40);

		for (int i = 0; i < cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": ");
			String[] split = s.nextLine().split("/");

			long p = Long.parseLong(split[0]);
			long q = Long.parseLong(split[1]);

			long gcm = gcm(p, q);
			p /= gcm;
			q /= gcm;

			String ans = null;

			if (divisor % q != 0) {
				ans = "impossible";
			} else {
				long tempAns = (long) Math.ceil(Math.log(q)/Math.log(2) - Math.log(p)/Math.log(2));
				ans = String.valueOf(tempAns);
			}

			w.write(ans);
			w.write("\n");
		}
		w.close();
	}

	public static long gcm(long a, long b) {
	    return b == 0 ? a : gcm(b, a % b); // Not bad for one line of code :)
	}


}
