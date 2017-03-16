import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FairAndSquare {

	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\FairAndSquare\\C-small-attempt0.in");
		File outputFile = new File("E:\\Code-Jam\\FairAndSquare\\C-small-attempt0.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		// For small value range, keep 1000
		int[] numberRange = new int[1001];
		for (int i = 0; i < 1001; i++) {
			numberRange[i] = 0;
		}
		int number = 1;
		while (number * number <= 1000) {
			if (checkIfPallindrome(number) && checkIfPallindrome(number * number)) {
				numberRange[number * number] = 1;
			}
			number++;
		}
		int noOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= noOfTestCases; i++) {
			String[] range = reader.readLine().split(" ");
			int minVal = Integer.parseInt(range[0]);
			int maxVal = Integer.parseInt(range[1]);
			int sum = 0;
			for(int j=minVal; j<=maxVal; j++) {
				if(numberRange[j] == 1) {
					sum++;
				}
			}
			String line = "Case #" + i + ": " + sum + "\n";
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	private static boolean checkIfPallindrome(int i) {
		String number = Integer.toString(i);
		int x = 0;
		int y = number.length() - 1;
		while (x < y) {
			if(number.charAt(x) != number.charAt(y)){
				return false;
			}
			x++;
			y--;
		}
		return true;
	}

}
