/*
 * 
 */
package codejam2015.round1b.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

/**
 *
 * @author Gabor Bakos
 */
public class HikingDeer {
	private static final boolean easy = true;

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1])
								: new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			if (easy) {
				for (int i = 1; i <= numCases; ++i) {
					int lines = Integer.parseInt(br.readLine());
					if (lines == 0) {
						out.write("Case #" + i + ": " + 0 + lineSep);
					} else {
						long firstTime = 0;
						int firstPos = 0;
						long secondTime = 0;
						int secondPos = 0;
						for (int j = 0; j < lines; ++j) {
							String[] parts = br.readLine().split(" ");
							int pos = Integer.parseInt(parts[0]), count = Integer
									.parseInt(parts[1]);
							long fastest = Long.parseLong(parts[2]);
							if (count == 2) {
								firstPos = secondPos = pos;
								firstTime = fastest;
								secondTime = fastest + 1;
							} else {
								if (j == 0) {
									firstPos = pos;
									firstTime = fastest;
								} else {
									secondPos = pos;
									secondTime = fastest;
								}
							}
						}
						out.write("Case #"
								+ i
								+ ": "
								+ minEncounter(firstPos, firstTime, secondPos,
										secondTime) + lineSep);
					}
				}
			}
		}
	}

	private static int minEncounter(int firstPos, long firstTime,
			int secondPos, long secondTime) {
		if (secondTime == firstTime) {
			return 0;
		}
		double timeFirstReaching360 = firstReach360(firstPos, firstTime), timeSecondReaching360 = firstReach360(
				secondPos, secondTime);
//		System.out.println("first: " + timeFirstReaching360 + " "
//				+ (timeFirstReaching360 + firstTime));
//		System.out.println("second: " + timeSecondReaching360 + " "
//				+ (timeSecondReaching360 + secondTime));
		if (timeFirstReaching360 + firstTime <= timeSecondReaching360
				|| timeSecondReaching360 + secondTime <= timeFirstReaching360) {
			return 1;
		}
		return 0;
	}

	private static double firstReach360(int pos, double time) {
		return (360 - pos) * time / 360.0;
	}
}
