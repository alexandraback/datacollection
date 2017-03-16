import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;


public class Round1A1 {
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
		outFile = new PrintStream(new FileOutputStream(new File("/home/blarson/output")));
		final int numCases = readInt();
		
		for(int i = 0; i < numCases; i++) {
			out.print("Case #" + (i+1) + ": ");

			solve();
			
			out.println();
		}
		
		out.close();
	}
	
	private static void solve() throws IOException {
		int[] nums = readIntArray(2);
		int numTyped = nums[0];
		int totalChars = nums[1];
		double[] probabilities = readDoubleArray(numTyped);
		double best = totalChars + 2;	// press enter
		for(int i = 0; i < numTyped; i++) {
			double test = calcb1(probabilities, totalChars, i);
			if(test < best) {
				best = test;
			}
		}
		out.print(best);
	}

	private static double calcb1(double[] probabilities, int totalChars, int numBackSpaces) {
		double odds = 1;
		for(int i = 0; i < probabilities.length; i++) {
			if(probabilities.length - i <= numBackSpaces) {
				//odds *= (1.0d-probabilities[i]);
			} else {
				odds *= probabilities[i];
			}
		}
		double charsIfRight = totalChars - probabilities.length + (numBackSpaces*2) + 1;
		double charsIfWrong = charsIfRight + totalChars + 1;
		return ((odds * charsIfRight) + ((1.0d-odds) * charsIfWrong));
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for(int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = new Integer(data[i]);
		}
		return array;
	}
	
	private static double[] readDoubleArray(int maxItems) throws IOException {
		double[] array = new double[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for(int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = new Double(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}

}