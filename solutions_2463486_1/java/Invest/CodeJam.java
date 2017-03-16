import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CodeJam {

	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	// public static final String INPUT_FILE_PATH = "D://C-large.in";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner input = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");
			
			input = new Scanner(new File(INPUT_FILE_PATH));
			int testCount = input.nextInt();
			String[] output = new String[testCount];
			
			for (int i = 0; i < testCount; i++) {
				long a = input.nextLong();
				long b = input.nextLong();
				
				output[i] = "Case #" + (i + 1) + ": " + new FairAndSquare().getCount(a, b);
			}
			
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			for (String line : output) {
				writer.println(line);
			}
			writer.flush();
			
			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (input != null) input.close();
			if (writer != null) writer.close();
		}
	}
}
