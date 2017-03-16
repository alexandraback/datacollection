import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class LastWord {
	public static void main(String[] args) {
		Scanner inputFile = null;

		PrintWriter fileWriter = null;
		try {
			fileWriter = new PrintWriter("A-small-attempt0-1.out");
			inputFile = new Scanner(new FileReader("A-small-attempt0-1.in"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int numberCases = inputFile.nextInt();
		inputFile.nextLine();
		for (int i = 0; i < numberCases; i++) {
			String line = inputFile.nextLine();
			String result = solve(line);
			fileWriter.println("Case #" + (i+1) + ": " + result);
		}
		inputFile.close();
		fileWriter.close();
	}
	
	public static String solve(String line) {
		String result = "";
		
		for (int i = 0; i < line.length(); i++) {
			char letter = line.charAt(i);
			if (result.length() == 0) {
				result = letter + "";
			} else {
				char frontLetter = result.charAt(0);
				if (letter >= frontLetter) {
					result = letter + result;
				} else {
					result += letter;
				}
			}
		}
		
		return result;
	}
}
