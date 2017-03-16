package r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Sol1 {
	public static BufferedWriter log = null;

	public static void main(String[] args) throws IOException {

		long startTime = System.nanoTime();
		Scanner sip = null;
		BufferedWriter brop = null;
		try {
			String ipfile = "A-small-attempt0.in";

			log = new BufferedWriter(new FileWriter(
					"X:\\Un-official\\programming\\CJ13\\R1\\1\\log.txt"));

			sip = new Scanner(new File(
					"X:\\Un-official\\programming\\CJ13\\R1\\1\\" + ipfile));

			// create output file
			brop = new BufferedWriter(new FileWriter(
					"X:\\Un-official\\programming\\CJ13\\R1\\1\\output.txt"));

			int T = sip.nextInt();
			String str = null;
			int n = 0;
			int ans = 0;

			for (int i = 0; i < T; i++) {
				str = sip.next();
				n = sip.nextInt();

				log.write(str + " " + n + "\n");
				ans = calcCount(str, n);
				// print output
				brop.write("Case #" + (i + 1) + ": " + ans);
				if (i < T - 1)
					brop.write("\n");
			}
			long endTime = System.nanoTime();
			log.write("\nTotal execution time: " + (endTime - startTime)
					+ " nano seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000.0 + " micro seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000000.0 + " milli seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000000000.0 + " seconds");

		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("Finally executed");
			if (sip != null)
				sip.close();
			if (brop != null) {
				brop.flush();
				brop.close();
			}
			if (log != null) {
				log.flush();
				log.close();
			}
		}
	}

	private static int calcCount(String str, int n) throws IOException {
		int ans = 0;
		for (int starti = 0; starti + (n - 1) < str.length(); starti++) {
			for (int endi = starti + (n - 1); endi < str.length(); endi++) {
				if (contains(str.substring(starti, endi + 1), n)) {
					ans += str.length() - endi;
					break;
				}
			}
		}
		return ans;
	}

	private static boolean contains(String substr, int n) throws IOException {
		log.write(substr+":");
		int count = 0;
		for (int i = 0; i < substr.length(); i++) {
			if (substr.charAt(i) != 'a' && substr.charAt(i) != 'e'
					&& substr.charAt(i) != 'i' && substr.charAt(i) != 'o'
					&& substr.charAt(i) != 'u') {
				count++;
				if (count == n) {
					log.write("true\n");
					return true;
				}
			} else
				count = 0;
		}
		log.write("false\n");
		return false;
	}
}