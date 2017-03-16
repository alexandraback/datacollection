package org.blarson.codeJam._2013Round1A;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;

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
	
	static ArrayList<Long> sumOfSquares = new ArrayList<Long>(1000);
	
	static {
		long prev = 0;
		for(int i = 1; i < 1000; i++) {
			long cur = (long)Math.pow(i, 2);
			sumOfSquares.add(cur - prev);
			prev = cur;
		}
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(2);
		int curRing = nums[0];
		//long subtract = sumOfSquares.get(curRing);
		long rings = 0;
		int paint = nums[1];
		//paint += subtract;
		while(true) {
			long next = sumOfSquares.get(curRing);
			if(paint < next) {
				out.print(rings);
				return;
			}
			paint -= next;
			rings++;
			curRing += 2;
		}
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