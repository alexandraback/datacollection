package org.blarson.codeJam._2013Round1A;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class Prob3 {
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
			out.println("Case #" + (i + 1) + ":");

			solve();

			//out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(4);
		int numSets = nums[0];
		int numNums = nums[1];
		int maxNum = nums[2];
		int numProducts = nums[3];
		for(int i = 0; i < numSets; i++) {
			List<Integer> numsInSet = new ArrayList<Integer>();
			int[] products = readIntArray(numProducts);
			for(int j = 0; j < numProducts; j++) {
				if(products[j] == 1) {
					continue;
				}
				if(products[j] == 2) {
					add(2, numsInSet);
				}
				if(products[j] == 3) {
					add(3, numsInSet);
				}
				if(products[j] == 5) {
					add(5, numsInSet);
				}
				if(products[j] == 6) {
					add(2, numsInSet);
					add(3, numsInSet);
				}
				if(products[j] == 8) {
					add(2, numsInSet);
				}
				if(products[j] == 9) {
					add(3, numsInSet);
				}
				if(products[j] == 10) {
					add(2, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 12) {
					add(3, numsInSet);
				}
				if(products[j] == 15) {
					add(3, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 16) {
					add(4, numsInSet);
				}
				if(products[j] == 18) {
					add(2, numsInSet);
					add(3, 2, numsInSet);
				}
				if(products[j] == 20) {
					add(5, numsInSet);
				}
				if(products[j] == 24) {
					add(2, numsInSet);
					add(3, numsInSet);
					add(4, numsInSet);
				}
				if(products[j] == 25) {
					add(5, 2, numsInSet);
				}
				if(products[j] == 27) {
					add(3, 3, numsInSet);
				}
				if(products[j] == 30) {
					add(2, numsInSet);
					add(3, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 32) {
					add(4, 2, numsInSet);
					add(2, numsInSet);
				}
				if(products[j] == 36) {
					add(3, 2, numsInSet);
					add(4, numsInSet);
				}
				if(products[j] == 40) {
					add(2, numsInSet);
					add(4, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 45) {
					add(3, 2, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 48) {
					add(4, 2, numsInSet);
					add(3, numsInSet);
				}
				if(products[j] == 50) {
					add(5, 2, numsInSet);
					add(2, numsInSet);
				}
				if(products[j] == 60) {
					add(3, numsInSet);
					add(4, numsInSet);
					add(5, numsInSet);
				}
				if(products[j] == 64) {
					add(4, 3, numsInSet);
				}
				if(products[j] == 75) {
					add(3, numsInSet);
					add(5, 2, numsInSet);
				}
				if(products[j] == 80) {
					add(5, numsInSet);
					add(4, 2, numsInSet);
				}
				if(products[j] == 100) {
					add(4, numsInSet);
					add(5, 2, numsInSet);
				}
				if(products[j] == 125) {
					add(5, 3, numsInSet);
				}
			}
			for(int j = numsInSet.size(); j < numNums; j++) {
				numsInSet.add(2);
			}
			for(int j = 0; j < numNums; j++) {
				out.print(numsInSet.get(j));
			}
			out.println();
		}
	}

	private static void add(int i, int j, List<Integer> numsInSet) {
		for(int k = 0; k < numsInSet.size(); k++) {
			if(numsInSet.get(k) == i) {
				j--;
			}
		}
		for(int k = 0; k < j; k++) {
			numsInSet.add(i);
		}
	}

	private static void add(int i, List<Integer> numsInSet) {
		if(!numsInSet.contains(i)) {
			numsInSet.add(i);
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