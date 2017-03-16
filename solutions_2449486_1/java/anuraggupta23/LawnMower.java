import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * 
 * @author anurag
 * 
 */
public class LawnMower {

	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\Lawnmower\\B-large.in");
		File outputFile = new File("E:\\Code-Jam\\Lawnmower\\B-large.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		int noOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= noOfTestCases; i++) {
			String[] dimension = reader.readLine().split(" ");
			int breadth = Integer.parseInt(dimension[0]);
			int length = Integer.parseInt(dimension[1]);
			int[][] fieldRectangle = new int[breadth][length];
			int[][] duplicateRectangle = new int[breadth][length];
			for (int j = 0; j < breadth; j++) {
				String[] input = reader.readLine().split(" ");
				for (int k = 0; k < length; k++) {
					fieldRectangle[j][k] = Integer.parseInt(input[k]);
					duplicateRectangle[j][k] = 100;
				}
			}
			String line = "Case #" + i + ": " + isPatternPossible(fieldRectangle, duplicateRectangle, breadth, length) + "\n";
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	private static String isPatternPossible(int[][] fieldRectangle, int[][] duplicateRectangle, int breadth, int length) {
		String result = "YES";
		int max = 0;
		int[] horizontalMax = new int[breadth];
		int[] verticalMax = new int[length];
		for (int i = 0; i < breadth; i++) {
			max = 0;
			for (int j = 0; j < length; j++) {
				if(fieldRectangle[i][j] > max) {
					max = fieldRectangle[i][j];
				}
			}
			horizontalMax[i] = max;
		}
		for (int i = 0; i < length; i++) {
			max = 0;
			for (int j = 0; j < breadth; j++) {
				if(fieldRectangle[j][i] > max) {
					max = fieldRectangle[j][i];
				}
			}
			verticalMax[i] = max;
		}
		//Cut duplicateRectangle based on the max values
		for(int i=0; i<breadth; i++) {
			max = horizontalMax[i];
			for(int j=0; j<length; j++) {
				if(duplicateRectangle[i][j] >= max) {
					duplicateRectangle[i][j] = max;
				}
			}
		}
		
		for(int i=0; i<length; i++) {
			max = verticalMax[i];
			for(int j=0; j<breadth; j++) {
				if(duplicateRectangle[j][i] >= max) {
					duplicateRectangle[j][i] = max;
				}
			}
		}
		
		for(int i=0; i<breadth; i++) {
			for(int j=0; j<length; j++) {
				if(fieldRectangle[i][j] != duplicateRectangle[i][j]) {
					return "NO";
				}
			}
		}
		
		return result;
	}

}
