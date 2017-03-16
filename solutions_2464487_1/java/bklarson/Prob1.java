package org.blarson.codeJam._2013Round1A;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

public class Prob1 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}
	

	private static void solve() throws IOException {
		String[] nums = r.readLine().trim().split(" ");
		long curRing = new Long(nums[0]);
		long paint = new Long(nums[1]);
		long start = curRing * 2 + 1;
		long min = 1;
		long guess = 4;
		while(guess > min) {
			long mostPaint = (guess - 1) * 4 + start;
			if(mostPaint > paint) {
				long newGuess = guess - ((guess - min)/2);
				if(newGuess != guess) {
					guess = newGuess;
				} else {
					guess--;
				}
				continue;
			}
			long multiplier = (guess)/2;
			long totalPaint = (mostPaint + start ) * multiplier;
			if((guess & 1L) != 0) {
				totalPaint += ((mostPaint + start) / 2);
			}
			if(totalPaint > paint) {
				long newGuess = guess - ((guess - min)/2);
				if(newGuess != guess) {
					guess = newGuess;
				} else {
					guess--;
				}
				continue;
			} else {
				min = guess;
				guess = guess * 2;
			}
		}
		out.println(min);
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = new Integer(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}

}