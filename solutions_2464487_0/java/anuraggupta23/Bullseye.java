import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Bullseye {
	
	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\Bullseye\\A-small-attempt0.in");
		File outputFile = new File("E:\\Code-Jam\\Bullseye\\A-small-attempt0.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		int noOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= noOfTestCases; i++) {
			String[] inputs = reader.readLine().split(" ");
			String line = "Case #" + i + ": " + getNoOfRingsDrawn(inputs[0], inputs[1]) + "\n";
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	
	private static int getNoOfRingsDrawn(String input1, String input2) {
		int initialRadius = Integer.parseInt(input1);
		int paintQty = Integer.parseInt(input2);
		int paintConsumed = 0;
		int circleCount = 0;
		int startOffset = 1;
		while((paintConsumed = paintConsumed + (2 * initialRadius + startOffset)) <= paintQty) {
			startOffset += 4;
			circleCount++;
		}
		return circleCount;
	}

}
