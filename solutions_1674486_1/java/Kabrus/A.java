import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	/**
	 * Reads a file int the specified format (no error controls, the file has to
	 * follow the rules).
	 * 
	 * @param file
	 * @return
	 * @throws IOException
	 */
	String[] read(File file) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(file));
		String line = reader.readLine();
		int lines = Integer.parseInt(line);
		String[] ret = new String[lines];
		for (int i = 0; i < lines; i++) {
			ret[i] = reader.readLine();
		}
		return ret;
	}
	
	protected String run(double[] values, Scanner s) {
		return Arrays.toString(values);
	}
	
	protected String run(int[] values, Scanner s) {
		return Arrays.toString(values);
	}
	
	/**
	 * Parses the given line and returns the result
	 * 
	 * @param line
	 * @return
	 */
	protected String run(Scanner s, Object dummy) {
		int n = s.nextInt();
		if (dummy instanceof Double) {
			double[] values = new double[n];
			for (int i=0;i<n;i++) {
				values[i] = s.nextDouble();
			}
			return run(values, s);
		} else {
			int[] values = new int[n];
			for (int i=0;i<n;i++) {
				values[i] = s.nextInt();
			}
			return run(values, s);
		}
	}
	
	/**
	 * Reads infile and calls {@link #run(String)} for each line
	 * 
	 * @param inFile
	 * @param outFile
	 * @throws IOException
	 */
	protected void run(File inFile, File outFile, Object dummy) throws IOException {
		Scanner s = new Scanner(inFile);
		int lines = s.nextInt();
		PrintWriter out = new PrintWriter(outFile);
		int i = 1;
		try {
			for (int l=0; l<lines; l++) {
				if (i > 1) {
					out.println();
				}
				String retLine = this.run(s, dummy);
				out.print("Case #" + i + ": " + retLine);
				i++;
			}
		} finally {
			out.close();
		}
	}
}
