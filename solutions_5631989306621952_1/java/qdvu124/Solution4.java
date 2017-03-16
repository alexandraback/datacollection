import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Solution4 {
	public static String convert(int array[]){
		StringBuilder sb = new StringBuilder();
		for(int i: array)
			sb.append(i);
		return sb.toString();
	}
	public static void main (String []args) throws IOException{
		File inputFile = new File("C:/Users/dinhq/OneDrive/Documents/Study/College/Sophomore Year/Spring/COSC 290L/Twitter/A-large.in");
		File outputFile = new File("C:/Users/dinhq/OneDrive/Documents/Study/College/Sophomore Year/Spring/COSC 290L/Twitter/Output.txt");
		FileWriter output = new FileWriter(outputFile);
		Scanner input = new Scanner(inputFile);
		int test;
		test = input.nextInt();
		input.nextLine();
		String data;
		char c;
		for(int i = 1; i <= test; i++){
			data = input.nextLine();
			String finalWord = "";
			finalWord += data.charAt(0);
			for(int j = 1; j < data.length(); j++){
				c = data.charAt(j);
				if(c>=finalWord.charAt(0))
					finalWord = c + finalWord;
				else
					finalWord += c;
			}
			output.write("Case #" + i + ": " + finalWord + "\n");
		}
		input.close();
		output.close();
	}
}
