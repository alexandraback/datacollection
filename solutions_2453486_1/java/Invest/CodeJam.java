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
			input = new Scanner(new File(INPUT_FILE_PATH));
			int testCount = input.nextInt();
			String[] output = new String[testCount];
			
			for (int i = 0; i < testCount; i++) {
				String[] ar = new String[4];
				for (int j = 0; j < ar.length; j++) {
					ar[j] = input.next();
				}
				
				output[i] = "Case #" + (i + 1) + ": " + new TicTacToeTomek().getDescription(ar);
			}
			
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			for (String line : output) {
				writer.println(line);
			}
			writer.flush();
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (input != null) input.close();
			if (writer != null) writer.close();
		}
	}
}
