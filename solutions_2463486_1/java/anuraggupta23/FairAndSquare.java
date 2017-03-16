import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class FairAndSquare {

	public static void main(String[] args) throws IOException {
		File inputFile = new File("E:\\Code-Jam\\FairAndSquare\\C-large-1.in");
		File outputFile = new File("E:\\Code-Jam\\FairAndSquare\\C-large-1.out");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		// For small value range, keep 1000
		BigInteger integerLimit = new BigInteger("100000000000000");
		List<BigInteger> numbers = new ArrayList<BigInteger>();
		BigInteger number = new BigInteger("1");
		BigInteger intermediateValue = null;
		while (integerLimit.subtract((intermediateValue = number.multiply(number))).compareTo(BigInteger.ZERO) >= 0) {
			if (checkIfPallindrome(number.toString(10)) && checkIfPallindrome(intermediateValue.toString(10))) {
				numbers.add(intermediateValue);
			}
			number = number.add(BigInteger.ONE);
		}
		int noOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= noOfTestCases; i++) {
			String[] range = reader.readLine().split(" ");
			BigInteger minVal = new BigInteger(range[0]);
			BigInteger maxVal = new BigInteger(range[1]);
			int sum = 0;
			for(BigInteger integer : numbers) {
				if(integer.subtract(minVal).compareTo(BigInteger.ZERO) >= 0 && integer.subtract(maxVal).compareTo(BigInteger.ZERO) <= 0) {
					sum++;
				}
				if(integer.subtract(maxVal).compareTo(BigInteger.ZERO) > 0) {
					break;
				}
			}
			String line = "Case #" + i + ": " + sum + "\n";
			writer.write(line);
		}
		reader.close();
		writer.close();
	}

	private static boolean checkIfPallindrome(String number) {
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
